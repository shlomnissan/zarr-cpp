// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include <vector>
#include <string>

#include <fmt/format.h>

#include "zarr/errors.hpp"
#include "zarr/metadata.hpp"

#include "file_system.hpp"

TEST(zarr_metadata, verify_load_metadata) {
    auto store = zarr::FileSystem::Create("fixtures/simple_BE.zarr");
    auto metadata = zarr::load_metadata(store.get());

    EXPECT_EQ(metadata.chunks, std::vector<unsigned int>({2, 8}));
    EXPECT_EQ(metadata.dimension_separator, ".");
    EXPECT_EQ(metadata.dtype, ">i4");
    EXPECT_EQ(metadata.fill_value, 0);
    EXPECT_EQ(metadata.order, "C");
    EXPECT_EQ(metadata.shape, std::vector<unsigned int>({8 , 8}));
    EXPECT_EQ(metadata.zarr_format, 2);
}

TEST(zarr_metadata, validate_zarr_format) {
    EXPECT_NO_THROW(zarr::validate_zarr_format(2));

    for (auto i = 0; i < 5; ++i) {
        if (i == 2) continue;
        EXPECT_THROW(
            zarr::validate_zarr_format(i),
            zarr::FailedToValidateMetadata
        );
    }
}

TEST(zarr_metadata, validate_dtype) {
    auto valid_dtypes = std::vector<std::string> {
        "|u1", "|b1", "<u1", "<i1", "<u2", "<i2", "<u4", "<i4", "<f2", "<f4",
        "<f8", ">u1", ">i1", ">u2", ">i2", ">u4", ">i2", ">f4", ">f2", ">f8"
    };
    for (const auto& dtype : valid_dtypes) {
        EXPECT_NO_THROW(zarr::validate_dtype(dtype));
    }

    auto invalid_dtypes = std::vector<std::string> {
        " ", "", "<i12345", ">f0", "|i", "|i2", "=i4", "<q8", "|i3", "|i1foobar"
    };
    for (const auto& dtype : invalid_dtypes) {
        EXPECT_THROW(
            zarr::validate_dtype(dtype),
            zarr::FailedToValidateMetadata
        );
    }
}

TEST(zarr_metadata, validate_order_valid) {
    EXPECT_NO_THROW(zarr::validate_order("C"));
    EXPECT_NO_THROW(zarr::validate_order("F"));

    auto invalid_order = std::vector<std::string> {
        " ", "", "A", "c", "f", "!"
    };
    for (const auto& order : invalid_order) {
        EXPECT_THROW(
            zarr::validate_order(order),
            zarr::FailedToValidateMetadata
        );
    }
}
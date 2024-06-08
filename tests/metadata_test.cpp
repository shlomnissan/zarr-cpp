// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/directory_store.hpp"
#include "zarr/metadata.hpp"

using namespace zarr;

TEST(zarr_metadata, verify_load_metadata) {
    auto store = DirectoryStore::Create("fixtures/simple_BE.zarr");
    auto metadata = load_metadata(store.get());

    EXPECT_EQ(metadata.chunks, std::vector<unsigned int>({2, 8}));
    EXPECT_EQ(metadata.dimension_separator, ".");
    EXPECT_EQ(metadata.dtype, ">i4");
    EXPECT_EQ(metadata.fill_value, 0);
    EXPECT_EQ(metadata.order, "C");
    EXPECT_EQ(metadata.shape, std::vector<unsigned int>({8 , 8}));
    EXPECT_EQ(metadata.zarr_format, 2);
}

TEST(zarr_metadata, exception_load_metadata_invalid) {
    // TODO: impl.
}

TEST(zarr_metadata, exception_load_metadata_invalid_version) {
    // TODO: impl.
}

TEST(zarr_metadata, exception_zarr_format_not_supported) {
    // TODO: impl.
}
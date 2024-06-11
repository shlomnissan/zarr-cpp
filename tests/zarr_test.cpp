// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/zarr.hpp"
#include "zarr/errors.hpp"

#include "file_system.hpp"

TEST(zarr, read_zarr) {
    EXPECT_NO_THROW({
        auto arr = zarr::Open("fixtures/simple_BE.zarr");
    });
}

TEST(zarr, exception_array_not_found) {
    EXPECT_THROW({
        try {
            auto arr = zarr::Open("bad_path.zarr");
        } catch(const zarr::ArrayNotFound& e) {
            EXPECT_STREQ(e.what(), "array not found at path bad_path.zarr");
            throw;
        }
    }, zarr::ArrayNotFound);
}
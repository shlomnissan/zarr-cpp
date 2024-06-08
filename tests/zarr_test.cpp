// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/zarr.hpp"
#include "zarr/directory_store.hpp"
#include "zarr/errors.hpp"

TEST(zarr, read_zarr) {
    auto arr = zarr::Open(
        zarr::DirectoryStore::Create("fixtures/simple_BE.zarr")
    );
    // TODO: impl.
}

TEST(zarr, exception_array_not_found) {
    EXPECT_THROW({
        try {
            auto arr = zarr::Open(
                zarr::DirectoryStore::Create("bad_path.zarr")
            );
        } catch(const zarr::ArrayNotFound& e) {
            EXPECT_STREQ(e.what(), "array not found at path bad_path.zarr");
            throw;
        }
    }, zarr::ArrayNotFound);
}
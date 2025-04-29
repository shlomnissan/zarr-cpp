// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include <gtest/gtest.h>

#include "store_filesystem.hpp"

#pragma region Open

TEST(StoreFileSystem, OpenValidPath) {
    auto store = zarr::StoreFileSystem::open("fixtures/simple_BE.zarr");

    EXPECT_TRUE(store);
    EXPECT_EQ(store.value()->path(), "fixtures/simple_BE.zarr");
}

TEST(StoreFileSystem, OpenInvalidPath) {
    auto store = zarr::StoreFileSystem::open("invalid_path.zarr");

    EXPECT_FALSE(store);
    EXPECT_EQ(
        store.error(),
        "Unabled to open zarr array at 'invalid_path.zarr'. "
        "The path does not contain a zarr metadata file."
    );
}

#pragma endregion
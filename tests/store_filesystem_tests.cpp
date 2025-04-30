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

#pragma region Exists

TEST(StoreFileSystem, ExistsWithValidKey) {
    auto store = zarr::StoreFileSystem::open("fixtures/simple_BE.zarr");

    EXPECT_TRUE(store.value()->exists("0.0"));
}

TEST(StoreFileSystem, ExistsWithInvalidKey) {
    auto store = zarr::StoreFileSystem::open("fixtures/simple_BE.zarr");

    EXPECT_FALSE(store.value()->exists("invalid_key"));
}

#pragma endregion

#pragma region Get

// TEST(StoreFileSystem, GetTextFile) {
//     auto store = zarr::StoreFileSystem::open("fixtures/simple_BE.zarr");
//     auto result = store.value()->get(".zarray", false);

//     EXPECT_TRUE(result);
// }

TEST(StoreFileSystem, GetBinaryFile) {
    auto store = zarr::StoreFileSystem::open("fixtures/simple_BE.zarr");
    auto result = store.value()->get("0.0", true);

    EXPECT_TRUE(result);
}

TEST(StoreFileSystem, GetInvalidKey) {
    auto store = zarr::StoreFileSystem::open("fixtures/simple_BE.zarr");
    auto result = store.value()->get("invalid_key", true);

    EXPECT_FALSE(result);
    EXPECT_EQ(
        result.error(),
        "Unable to get data from key 'invalid_key'. Key does not exist in the store."
    );
}

TEST(StoreFileSystem, GetEmptyFile) {
    auto store = zarr::StoreFileSystem::open("fixtures/empty.zarr");
    auto result = store.value()->get("empty", false);

    EXPECT_FALSE(result);
    EXPECT_EQ(
        result.error(),
        "Unable to get data from key 'empty'. The file is empty or has an invalid length."
    );
}

#pragma endregion
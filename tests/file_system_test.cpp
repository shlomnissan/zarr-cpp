// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/errors.hpp"

#include "file_system.hpp"
#include "names.hpp"

TEST(zarr_file_system, contains_item) {
    // impl.
}

TEST(zarr_file_system, get_item_binary) {
    // impl.
}

TEST(zarr_file_system, get_item_char_stream) {
    // impl.
}

TEST(zarr_file_system, exception_get_item_key_not_found) {
    EXPECT_THROW({
        try {
            auto store = zarr::FileSystem::Create("fixtures/simple_BE.zarr");
            auto item = store->GetItem("bad_item");
        } catch (const zarr::KeyNotFound& e) {
            EXPECT_STREQ(e.what(), "key bad_item not found");
            throw;
        }
    }, zarr::KeyNotFound);
}
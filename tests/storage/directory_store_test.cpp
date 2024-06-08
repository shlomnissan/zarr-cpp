// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/directory_store.hpp"
#include "zarr/errors.hpp"

#include "names.hpp"

using namespace zarr;

TEST(zarr_directory_store, contains_item) {
    // impl.
}

TEST(zarr_directory_store, get_item_binary) {
    // impl.
}

TEST(zarr_directory_store, get_item_char_stream) {
    // impl.
}

TEST(zarr_directory_store, exception_get_item_key_not_found) {
    EXPECT_THROW({
        try {
            auto store = DirectoryStore::Create("fixtures/simple_BE.zarr");
            auto item = store->GetItem("bad_item");
        } catch (const KeyNotFound& e) {
            EXPECT_STREQ(e.what(), "key bad_item not found");
            throw;
        }
    }, KeyNotFound);
}
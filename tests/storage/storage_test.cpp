// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/directory_store.hpp"

TEST(zarr_storage, contains_array) {
    auto store = zarr::DirectoryStore::Create("fixtures/simple_BE.zarr");

    EXPECT_EQ(contains_array(store.get()), true);
}
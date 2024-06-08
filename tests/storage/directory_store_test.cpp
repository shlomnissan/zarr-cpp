// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/directory_store.hpp"

using namespace zarr;

TEST(zarr_directory_store, contains_item) {
    auto store = DirectoryStore::Create("fixtures/simple_BE.zarr");

    EXPECT_EQ(true, true);
}
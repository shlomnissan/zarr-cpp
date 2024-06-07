// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/directory_store.hpp"

using namespace zarr;

TEST(zarr_storage, contains_array) {
    auto store = DirectoryStore("fixtures/simple_BE.zarr");

    EXPECT_EQ(contains_array(&store), true);
}
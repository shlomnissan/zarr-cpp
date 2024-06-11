// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "file_system.hpp"

TEST(zarr_store, contains_array) {
    auto store = zarr::FileSystem::Create("fixtures/simple_BE.zarr");

    EXPECT_EQ(contains_array(store.get()), true);
}
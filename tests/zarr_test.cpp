// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/zarr.hpp"
#include "zarr/directory_store.hpp"

using namespace zarr;

TEST(zarr, read_zarr) {
    Zarr::Read(
        std::make_unique<DirectoryStore>("path")
    );

    EXPECT_EQ(true, true);
}
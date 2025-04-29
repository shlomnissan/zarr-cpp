// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include <gtest/gtest.h>

#include <zarr/zarr.hpp>

#pragma region open

TEST(Zarr, Open) {
    auto zarr = zarr::ZarrArray::open("test.zarr");

    EXPECT_TRUE(zarr);
}

#pragma endregion
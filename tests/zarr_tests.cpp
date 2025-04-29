// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include <gtest/gtest.h>

#include <zarr/zarr.hpp>

#pragma region Open

TEST(Zarr, Open) {
    auto zarr = zarr::ZarrArray::open("fixtures/empty.zarr");

    EXPECT_TRUE(zarr.has_value());
}

#pragma endregion
// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include <gtest/gtest.h>

#include "zarr/vec2.hpp"

TEST(vec2, magnitude) {
    auto v = zarr::vec2 {3.f, 4.f};

    EXPECT_EQ(v.magnitude(), 0.0f);
    EXPECT_EQ(true, true);
}
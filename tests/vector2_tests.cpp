// Copyright © 2025 - Present, Shlomi Nissan.
// All rights reserved.

#include <gtest/gtest.h>

#include <zarr/vector2.hpp>

TEST(Vector2, DefaultConstructor) {
    zarr::Vector2 v;

    EXPECT_FLOAT_EQ(v.x, 0.0f);
    EXPECT_FLOAT_EQ(v.y, 0.0f);
}

TEST(Vector2, ParameterizedConstructor) {
    zarr::Vector2 v(3.0f, 4.0f);

    EXPECT_FLOAT_EQ(v.x, 3.0f);
    EXPECT_FLOAT_EQ(v.y, 4.0f);
}

TEST(Vector2, Length) {
    zarr::Vector2 v(3.0f, 4.0f);

    EXPECT_FLOAT_EQ(v.Length(), 5.0f);
}
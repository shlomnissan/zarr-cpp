// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/vec2.hpp"

using namespace zarr;

vec2::vec2(float x, float y) : x(x), y(y) {}

auto vec2::magnitude() const -> float {
    return 0.0f;
}
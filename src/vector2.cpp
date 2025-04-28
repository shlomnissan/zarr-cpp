// Copyright © 2025 - Present, Shlomi Nissan.
// All rights reserved.

#include "zarr/vector2.hpp"

#include "math.hpp"

namespace zarr {

auto Vector2::Length() const -> float {
    return zarr::sqrt(x * x + y * y);
}

} // namespace zarr
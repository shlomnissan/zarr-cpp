// Copyright © 2025 - Present, Shlomi Nissan.
// All rights reserved.

#pragma once

#include "zarr_export.h"

namespace ZARR_EXPORT zarr {

struct Vector2 {
    /// @brief X coordinate of the vector.
    float x;

    /// @brief Y coordinate of the vector.
    float y;

    /**
     * @brief Default constructor for Vector2.
     */
    Vector2() : x(0.0f), y(0.0f) {}

    /**
     * @brief Constructor for Vector2 with separate x and y values.
     *
     * @param x X coordinate.
     * @param y Y coordinate.
     */
    Vector2(float x, float y) : x(x), y(y) {}

    /**
     * @brief Calculates the magnitude of the vector.
     *
     * @return float Magnitude of the vector.
     */
    [[nodiscard]] auto Length() const -> float;
};

} // namespace zarr
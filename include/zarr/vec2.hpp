// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include "zarr_export.h"

namespace zarr {
    class ZARR_EXPORT vec2 {
    public:
        float x {0};
        float y {0};

        vec2(float x, float y);

        [[nodiscard]] auto magnitude() const -> float;
    };
}
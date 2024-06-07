// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <stdexcept>
#include <string_view>

#include "zarr_export.h"

namespace zarr {
    struct ZARR_EXPORT ArrayNotFoundError : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
}
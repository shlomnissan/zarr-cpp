// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <stdexcept>
#include <string_view>

#include "zarr_export.h"

namespace zarr {
    struct ZARR_EXPORT ArrayNotFound : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    struct ZARR_EXPORT KeyNotFound : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    struct ZARR_EXPORT FailedToReadData : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    struct ZARR_EXPORT MetadataParseError : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    struct ZARR_EXPORT NotSupported : public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
}
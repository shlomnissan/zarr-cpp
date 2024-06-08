// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include "zarr_export.h"

#include "storage/store.hpp"

namespace zarr {

struct ZARR_EXPORT Metadata {
    unsigned zarr_format;
};

// TODO: add no discard
auto load_metadata(Store* store) -> void;

};
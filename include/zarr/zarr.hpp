// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <string_view>

#include "zarr/zarr_array.hpp"

#include "zarr_export.h"

namespace zarr {

[[nodiscard]]
auto ZARR_EXPORT Open(std::string_view path) -> ZarrArray;

}
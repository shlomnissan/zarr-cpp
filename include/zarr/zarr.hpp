// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <memory>
#include <string_view>

#include "zarr_export.h"

#include "zarr/zarr_array.hpp"
#include "storage/store.hpp"

namespace zarr {

[[nodiscard]]
auto ZARR_EXPORT Open(std::unique_ptr<Store> store) -> ZarrArray;

}
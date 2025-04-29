// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "zarr/zarr.hpp"

namespace zarr {

auto zarr_array::open(const fs::path& path) -> std::expected<zarr_array, std::string> {
    return zarr_array {};
}

} // namespace zarr
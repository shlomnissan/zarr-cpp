// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "zarr/zarr.hpp"

namespace zarr {

auto ZarrArray::open(const fs::path& path) -> std::expected<ZarrArray, std::string> {
    return ZarrArray {};
}

} // namespace zarr
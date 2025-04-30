// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "zarr/zarr.hpp"

#include "zarr/metadata.hpp"

#include "store_filesystem.hpp"

namespace zarr {

auto ZarrArray::open(const fs::path& path) -> std::expected<ZarrArray, std::string> {
    auto store = StoreFileSystem::open(path);
    if (!store) return std::unexpected(store.error());

    auto result = store.value()->get(".zarray", true);
    if (!result) {
        return std::unexpected(result.error());
    }

    auto metadata = Metadata::parse(result.value());
    if (!metadata) return std::unexpected(metadata.error());

    return ZarrArray {std::move(store.value()), metadata.value()};
}

} // namespace zarr
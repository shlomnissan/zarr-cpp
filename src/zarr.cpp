// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "zarr/zarr.hpp"

#include "zarr/metadata.hpp"

#include "store_filesystem.hpp"

namespace zarr {

auto ZarrArray::open(const fs::path& path) -> std::expected<ZarrArray, std::string> {
    auto store = StoreFileSystem::open(path);
    if (!store) return std::unexpected(store.error());

    auto metadata = Metadata::parse(store.value().get());
    if (!metadata) return std::unexpected(metadata.error());

    return ZarrArray {std::move(store.value())};
}

} // namespace zarr
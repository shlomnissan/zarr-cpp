// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "store_filesystem.hpp"

namespace zarr {

auto StoreFileSystem::exists(std::string_view key) -> bool {
    return false;
}

auto StoreFileSystem::get(std::string_view key, bool is_binary) -> std::expected<Buffer, std::string> {
    return Buffer {};
}

auto StoreFileSystem::open(const fs::path& path) -> std::expected<std::unique_ptr<StoreFileSystem>, std::string> {
    // TODO: check if path exists with metadata

    return std::unique_ptr<StoreFileSystem>(new StoreFileSystem(path));
}

} // namespace zarr
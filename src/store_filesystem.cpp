// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "store_filesystem.hpp"

#include <format>
namespace zarr {

auto StoreFileSystem::exists(std::string_view key) -> bool {
    return fs::exists(std::format("{}/{}", path_.string(), key));
}

auto StoreFileSystem::get(std::string_view key, bool is_binary) -> std::expected<Buffer, std::string> {
    return Buffer {};
}

auto StoreFileSystem::path() -> std::string {
    return path_.string();
}

auto StoreFileSystem::open(const fs::path& path) -> std::expected<std::unique_ptr<StoreFileSystem>, std::string> {
    if (!fs::exists(std::format("{}/.zarray", path.string()))) {
        return std::unexpected(std::format(
            "Unabled to open zarr array at '{}'. "
            "The path does not contain a zarr metadata file.",
            path.string()
        ));
    }

    return std::unique_ptr<StoreFileSystem>(new StoreFileSystem(path));
}

} // namespace zarr
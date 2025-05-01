// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "store_filesystem.hpp"

#include <format>
#include <fstream>

namespace zarr {

namespace {
    auto make_error(std::string_view key, std::string_view message) -> std::string {
        return std::format("Unable to get data from key '{}'. {}", key, message);
    }
}

auto StoreFileSystem::exists(std::string_view key) -> bool {
    return fs::exists(std::format("{}/{}", path_.string(), key));
}

auto StoreFileSystem::get(std::string_view key) -> std::expected<Buffer, std::string> {
    if (!exists(key)) {
        return std::unexpected(make_error(key, "Key does not exist in the store."));
    }

    const auto path = std::format("{}/{}", path_.string(), key);
    auto file = std::ifstream(path, std::ios::in | std::ios::binary);
    if (!file) {
        return std::unexpected(make_error(key, "Failed to open the file."));
    }

    file.seekg(0, std::ios::end);
    auto length = std::streamsize {file.tellg()};
    file.seekg(0, std::ios::beg);

    if (length <= 0) {
        return std::unexpected(make_error(key, "The file is empty or has an invalid length."));
    }

    auto buffer = Buffer(length);
    file.read(buffer.data(), length);

    if (file.fail() || file.gcount() != length) {
        return std::unexpected(make_error(key, "Failed to read the file."));
    }

    return buffer;
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
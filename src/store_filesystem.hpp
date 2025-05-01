// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include "zarr/store.hpp"

#include <filesystem>

namespace zarr {

namespace fs = std::filesystem;

class StoreFileSystem : public Store {
public:
    auto exists(std::string_view key) -> bool override;

    auto get(std::string_view key) -> std::expected<Buffer, std::string> override;

    auto path() -> std::string override;

    [[nodiscard]] static auto open(const fs::path& path) -> std::expected<std::unique_ptr<StoreFileSystem>, std::string>;

private:
    fs::path path_;

    explicit StoreFileSystem(const fs::path& path) : path_(path) {}
};

} // namespace zarr
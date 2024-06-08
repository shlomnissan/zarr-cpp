// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/directory_store.hpp"

#include <filesystem>
#include <fstream>

#include <fmt/format.h>

#include "zarr/errors.hpp"

namespace fs = std::filesystem;

using namespace zarr;

DirectoryStore::DirectoryStore(std::string_view path)
    : path_(path) {}

auto DirectoryStore::Create(std::string_view path) -> std::unique_ptr<DirectoryStore> {
    return std::make_unique<DirectoryStore>(path);
}

auto DirectoryStore::Path() -> std::string_view {
    return path_;
}

auto DirectoryStore::ContainsItem(std::string_view item) -> bool {
    auto path = fs::path {fmt::format("{}/{}", path_, item)};
    return fs::exists(path);
}

auto DirectoryStore::GetItem(std::string_view item, bool binary) -> Buffer {
    auto path = fmt::format("{}/{}", path_, item);
    auto file = std::ifstream(path, binary ?  std::ios::binary : std::ios::in);
    if (!file) {
        throw KeyNotFound { fmt::format("key {} not found", item)};
    }

    file.seekg(0, std::ios::end);
    auto length = std::streamsize {file.tellg()};
    file.seekg(0, std::ios::beg);
    if (length < 0) {
        throw FailedToReadData { fmt::format("failed to read data length for key {}", item)};
    }

    auto buffer = Buffer(length);
    file.read(buffer.data(), length);
    if (file.fail() || file.gcount() != length) {
        throw FailedToReadData { fmt::format("failed to read data for key {}", item)};
    }

    return buffer;
}
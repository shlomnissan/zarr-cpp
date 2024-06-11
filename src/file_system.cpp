// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "file_system.hpp"

#include <filesystem>
#include <fstream>

#include <fmt/format.h>

#include "zarr/errors.hpp"

namespace fs = std::filesystem;

using namespace zarr;

FileSystem::FileSystem(std::string_view path) : path_(path) {}

auto FileSystem::Create(std::string_view path) -> std::unique_ptr<FileSystem> {
    return std::unique_ptr<FileSystem>(new FileSystem(path));
}

auto FileSystem::Path() -> std::string_view { return path_; }

auto FileSystem::ContainsItem(std::string_view item) -> bool {
    auto path = fs::path {fmt::format("{}/{}", path_, item)};
    return fs::exists(path);
}

auto FileSystem::GetItem(std::string_view item, bool binary) -> Buffer {
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
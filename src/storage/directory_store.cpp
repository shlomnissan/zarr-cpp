// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/directory_store.hpp"

#include <filesystem>

#include <fmt/format.h>

namespace fs = std::filesystem;

using namespace zarr;

DirectoryStore::DirectoryStore(std::string_view path)
    : path_(path) {}

auto DirectoryStore::ContainsItem(std::string_view item) -> bool {
    auto path = fs::path {fmt::format("{}/{}", path_, item)};
    return fs::exists(path);
}
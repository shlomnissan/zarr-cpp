// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <memory>
#include <string>
#include <string_view>

#include "store.hpp"

namespace zarr {

class FileSystem : public Store {
public:
    static auto Create(std::string_view path) -> std::unique_ptr<FileSystem>;

    auto Path() -> std::string_view override;

    auto ContainsItem(std::string_view item) -> bool override;

    auto GetItem(std::string_view item, bool binary = true) -> Buffer override;

private:
    std::string path_ {};

    explicit FileSystem(std::string_view path);
};

}
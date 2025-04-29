// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include <expected>
#include <string_view>
#include <vector>

namespace zarr {

using Buffer = std::vector<char>;

class Store {
public:
    [[nodiscard]] virtual auto exists(std::string_view key) -> bool = 0;

    [[nodiscard]] virtual auto get(std::string_view key, bool is_binary) -> std::expected<Buffer, std::string> = 0;

    virtual ~Store() = default;
};

} // namespace zarr
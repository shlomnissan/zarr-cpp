// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace zarr {

using Buffer = std::vector<char>;

class Store {
public:
    [[nodiscard]]
    virtual auto Path() -> std::string_view = 0;

    [[nodiscard]]
    virtual auto ContainsItem(std::string_view item) -> bool = 0;

    [[nodiscard]]
    virtual auto GetItem(std::string_view item, bool binary = true) -> Buffer = 0;

    virtual ~Store() {}
};

[[nodiscard]]
auto contains_array(Store*) -> bool;

}
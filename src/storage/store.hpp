// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <string>
#include <string_view>

namespace zarr {

class Store {
public:
    [[nodiscard]] virtual auto ContainsItem(std::string_view path) -> bool = 0;

    [[nodiscard]] virtual auto Path() -> std::string_view = 0;

    virtual ~Store() {}
};

auto contains_array(Store*) -> bool;

}
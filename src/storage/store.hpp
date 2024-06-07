// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

namespace zarr {

class Store {
public:
    [[nodiscard]] virtual auto ContainsItem() -> bool = 0;
};

}
// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <string_view>

#include "zarr_export.h"

#include "storage/store.hpp"

namespace zarr {

class ZARR_EXPORT DirectoryStore : public Store {
public:
    explicit DirectoryStore(std::string_view path);

    auto ContainsItem() -> bool override;
};

}
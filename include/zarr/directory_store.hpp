// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <string>
#include <string_view>

#include "zarr_export.h"

#include "storage/store.hpp"

namespace zarr {

class ZARR_EXPORT DirectoryStore : public Store {
public:
    explicit DirectoryStore(std::string_view path);

    auto ContainsItem(std::string_view item) -> bool override;

    auto Path() -> std::string_view override;

private:
    std::string path_ {};
};

}
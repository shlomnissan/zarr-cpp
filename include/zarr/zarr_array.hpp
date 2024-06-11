// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include <memory>

#include "zarr_export.h"

#include "zarr/metadata.hpp"

#include "store.hpp"

namespace zarr {

class ZARR_EXPORT ZarrArray {
public:
    explicit ZarrArray(std::unique_ptr<Store> store);

private:
    std::unique_ptr<Store> store_;

    Metadata metadata_;
};

}

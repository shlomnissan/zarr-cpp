// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/zarr_array.hpp"

using namespace zarr;

ZarrArray::ZarrArray(std::unique_ptr<Store> store) : store_(std::move(store)) {
    // TODO: load metadata
}
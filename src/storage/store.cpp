// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "store.hpp"

#include "names.hpp"

auto zarr::contains_array(Store* store) -> bool {
    return store->ContainsItem(zarr::ARRAY_META_KEY);
}
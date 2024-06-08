// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/zarr_array.hpp"

#include "zarr/metadata.hpp"

using namespace zarr;

ZarrArray::ZarrArray(std::unique_ptr<Store> store) : store_(std::move(store)) {
    metadata_ = load_metadata(store_.get());
    validate_metadata(metadata_);
}
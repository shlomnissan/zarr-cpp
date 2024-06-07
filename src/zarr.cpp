// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/zarr.hpp"

#include <fmt/format.h>

#include "zarr/errors.hpp"

using namespace zarr;

auto Zarr::Read(std::unique_ptr<Store> store) -> void {
    if (!contains_array(store.get())) {
        throw ArrayNotFoundError {fmt::format(
            "array not found at path {}", store->Path()
        )};
    }

    // TODO: create a ZarrArray
}
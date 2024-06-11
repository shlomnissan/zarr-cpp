// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#pragma once

#include "zarr_export.h"

#include <optional>
#include <string>
#include <vector>

#include "store.hpp"

namespace zarr {

struct ZARR_EXPORT Metadata {
    unsigned int                zarr_format;
    std::string                 dimension_separator;
    std::string                 dtype;
    std::string                 order;
    std::vector<unsigned int>   chunks;
    std::vector<unsigned int>   shape;
    std::optional<unsigned int> fill_value;
};

[[nodiscard]]
auto load_metadata(Store* store) -> Metadata;

auto validate_metadata(const Metadata& metadata) -> void;
auto validate_zarr_format(unsigned int zarr_format) -> void;
auto validate_dtype(std::string dtype) -> void;
auto validate_order(std::string order) -> void;

};
// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include <optional>
#include <string>
#include <vector>

namespace zarr {

/**
 * @struct Metadata
 * @brief Represents the metadata of a Zarr array.
 */
struct Metadata {
public:
    /// @brief Version of Zarr metadata format.
    unsigned int version;

    /// @brief Characters used to separate dimensions in the array.
    char dimension_separator;

    /// @brief Memory layout order of the array.
    char order;

    /// @brief Data type of array elements.
    std::string dtype;

    /// @brief Shape of the array.
    std::vector<unsigned int> shape;

    /// @brief Chunk sizes of the array.
    std::vector<unsigned int> chunks;

    /// @brief Fill value for uninitialized array elements.
    std::optional<unsigned int> fill_value;
};

} // namespace zarr
// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include "zarr_export.h"

#include "zarr/store.hpp"

#include <expected>
#include <optional>
#include <string>
#include <span>
#include <vector>

namespace ZARR_EXPORT zarr {

/**
 * @class Metadata
 * @brief Represents metadata of a Zarr array.
 */
class Metadata {
public:
    /// @brief Version of Zarr metadata format.
    unsigned int zarr_format;

    /// @brief Memory layout order of the array.
    char order;

    /// @brief Data type of array elements.
    std::string dtype;

    /// @brief Characters used to separate dimensions in the array.
    std::string dimension_separator;

    /// @brief Shape of the array.
    std::vector<unsigned int> shape;

    /// @brief Chunk sizes of the array.
    std::vector<unsigned int> chunks;

    /// @brief Fill value for uninitialized array elements.
    std::optional<unsigned int> fill_value;

    /**
     * @brief Parses metadata from the given storage backend.
     *
     * @param store Pointer to the storage backend from which metadata will be parsed.
     * @return std::expected containing the parsed Metadata object if successful, or an error message string.
     */
    [[nodiscard]] static auto parse(std::string_view buffer) -> std::expected<Metadata, std::string>;

private:
    friend class MetadataTest;

    /**
     * @brief Default constructor for Metadata.
     *
     * This constructor is private to enforce controlled creation of Metadata instances.
     */
    explicit Metadata() = default;
};

} // namespace zarr
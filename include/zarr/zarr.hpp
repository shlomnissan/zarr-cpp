// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include "zarr_export.h"

#include <expected>
#include <filesystem>
#include <string>

namespace zarr {

namespace fs = std::filesystem;

/**
 * @class zarr_array
 * @brief Represents a Zarr array and provides methods to interact with it.
 */
class ZARR_EXPORT zarr_array {
public:
    /**
     * @brief Opens a Zarr array from the specified path.
     *
     * @param path Path to the Zarr array.
     * @return std::expected object containing the opened zarr_array or an error message.
     */
    [[nodiscard]] static auto open(const fs::path& path) -> std::expected<zarr_array, std::string>;

private:
    /**
     * @brief Default constructor for zarr_array.
     *
     * This constructor is private to enforce the use of the open() method for creating instances.
     */
    zarr_array() = default;
};

};
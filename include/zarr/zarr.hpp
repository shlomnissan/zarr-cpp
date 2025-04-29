// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include "zarr_export.h"

#include "zarr/store.hpp"

#include <expected>
#include <filesystem>
#include <memory>
#include <string>

namespace zarr {

namespace fs = std::filesystem;

/**
 * @class ZarrArray
 * @brief Represents a Zarr array and provides methods to interact with it.
 */
class ZARR_EXPORT ZarrArray {
public:
    /**
     * @brief Opens a Zarr array from the specified path.
     *
     * @param path Path to the Zarr array.
     * @return std::expected object containing the opened ZarrArray or an error message.
     */
    [[nodiscard]] static auto open(const fs::path& path) -> std::expected<ZarrArray, std::string>;

private:
    /// @brief Pointer to the storage backend.
    std::unique_ptr<Store> store_;

    /**
     * @brief Constructs a ZarrArray with the specified storage backend.
     *
     * @param store Unique pointer to the storage backend.
     */
    ZarrArray(std::unique_ptr<Store> store) : store_(std::move(store)) {}
};

} // namespace zarr
// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include "zarr_export.h"

#include "zarr/metadata.hpp"
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

    /**
     * @brief Retrieves the metadata of the Zarr array.
     *
     * @return Constant reference to the Metadata object associated with the Zarr array.
     */
    [[nodiscard]] auto metadata() const -> const Metadata& {
        return metadata_;
    }

private:
    /// @brief Pointer to the storage backend.
    std::unique_ptr<Store> store_;

    /// @brief Metadata of the Zarr array.
    Metadata metadata_;

    /**
     * @brief Constructs a ZarrArray with the specified storage backend.
     *
     * @param store Unique pointer to the storage backend.
     */
    explicit ZarrArray(std::unique_ptr<Store> store, const Metadata& metadata)
        : store_(std::move(store)), metadata_(metadata) {}
};

} // namespace zarr
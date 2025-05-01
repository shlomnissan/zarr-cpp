// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#pragma once

#include <expected>
#include <string>
#include <string_view>
#include <vector>

namespace zarr {

/**
 * @typedef Buffer
 * @brief Represents a buffer of binary data.
 */
using Buffer = std::vector<char>;

/**
 * @class Store
 * @brief Represents an abstract base class for Zarr storage backends.
 */
class Store {
public:
    /**
     * @brief Checks if a key exists in the store.
     *
     * @param key Key to check existence.
     * @return bool true if the key exists, false otherwise.
     */
    [[nodiscard]] virtual auto exists(std::string_view key) -> bool = 0;

    /**
     * @brief Retrieves the data associated with a key.
     *
     * @param key Key to retrieve data for.
     * @return std::expected containing the data buffer if successful, or an error message string.
     */
    [[nodiscard]] virtual auto get(std::string_view key) -> std::expected<Buffer, std::string> = 0;

    /**
     * @brief Retrieves the path associated with the storage backend.
     *
     * @return std::string representing the path.
     */
    [[nodiscard]] virtual auto path() -> std::string = 0;

    /**
     * @brief Virtual destructor for the Store class.
     */
    virtual ~Store() = default;
};

} // namespace zarr
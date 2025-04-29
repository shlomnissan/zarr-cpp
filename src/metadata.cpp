// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "zarr/metadata.hpp"

namespace zarr {

auto Metadata::parse(Store* store) -> std::expected<Metadata, std::string> {
    auto result = store->get(".zarray", false);
    if (!result) {
        return std::unexpected(result.error());
    }

    auto metadata = result.value();
    // TODO: parse metadata

    return Metadata {};
}

} // namespace zarr
// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/metadata.hpp"

#include <string>

#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include "zarr/errors.hpp"

#include "names.hpp"

auto zarr::load_metadata(Store* store) -> Metadata {
    auto item = store->GetItem(ARRAY_META_KEY);
    auto json_string = std::string(begin(item), end(item));

    auto output = Metadata {};
    try {
        auto j = nlohmann::json::parse(json_string);
        j.at("zarr_format").get_to(output.zarr_format);
        // TODO: copy the rest of the attributes
    } catch(const nlohmann::json::parse_error& e) {
        throw MetadataParseError { e.what() };
    }

    return output;
}

auto zarr::validate_metadata(const Metadata& metadata) -> void {
    if (metadata.zarr_format != 2) {
        throw NotSupported { fmt::format(
            "zarr_format {} is not supported", metadata.zarr_format
        )};
    }
}
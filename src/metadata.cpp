// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/metadata.hpp"

#include <string>

#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include "zarr/errors.hpp"

#include "names.hpp"

// custom serializer for std::optional
namespace nlohmann {
    template<typename T>
    struct adl_serializer<std::optional<T>> {
        static void from_json(const json& j, std::optional<T>& opt) {
            if (!j.is_null()) {
                opt = j.get<T>();
            } else {
                opt = std::nullopt;
            }
        }
    };
}

auto zarr::load_metadata(Store* store) -> Metadata {
    auto item = store->GetItem(ARRAY_META_KEY);
    auto json_string = std::string(begin(item), end(item));

    auto output = Metadata {};
    try {
        auto j = nlohmann::json::parse(json_string);
        j.at("chunks").get_to(output.chunks);
        j.at("dtype").get_to(output.dtype);
        j.at("fill_value").get_to(output.fill_value);
        j.at("order").get_to(output.order);
        j.at("shape").get_to(output.shape);
        j.at("zarr_format").get_to(output.zarr_format);
        output.dimension_separator = j.value("dimension_separator", ".");
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
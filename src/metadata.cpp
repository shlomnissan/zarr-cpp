// Copyright 2024 Betamark Pty Ltd. All rights reserved.
// Author: Shlomi Nissan (shlomi@betamark.com)

#include "zarr/metadata.hpp"
#include "zarr/errors.hpp"

#include <regex>
#include <string>

#include <fmt/format.h>
#include <nlohmann/json.hpp>

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
        throw FailedToParseMetadata { e.what() };
    }
    return output;
}

auto zarr::validate_dimension_separator(std::string_view separator) -> void {
    if (separator != "/" && separator != ".") {
        throw FailedToValidateMetadata { fmt::format(
            "dimension_separator value ({}) is invalid", separator
        )}; 
    }
}

auto zarr::validate_dtype(std::string dtype) -> void {
    const static auto dtype_pattern = std::regex {
        "^([<>]?)([ifbu][1-9]|[ifbu][1-2][0-9]|[ifbu][3][0-2]|\\|(b|u)1)$"
    };
    if (dtype.empty() || !std::regex_match(dtype, dtype_pattern)) {
        throw FailedToValidateMetadata { fmt::format(
            "dtype value ({}) is invalid", dtype
        )};
    }
}

auto zarr::validate_order(std::string order) -> void {
    if (order != "C" && order != "F") {
        throw FailedToValidateMetadata { fmt::format(
            "order value ({}) is invalid", order
        )};
    }
}

auto zarr::validate_zarr_format(unsigned int zarr_format) -> void {
    if (zarr_format != 2) {
        throw FailedToValidateMetadata { fmt::format(
            "zarr_format value ({}) is not supported", zarr_format
        )};
    }
}

auto zarr::validate_metadata(const Metadata& metadata) -> void {
    validate_dimension_separator(metadata.dimension_separator);
    validate_dtype(metadata.dtype);
    validate_order(metadata.order);
    validate_zarr_format(metadata.zarr_format);

    // TODO: validate shape
    // TODO: validate chunks
    // TODO: validate fill_value
}
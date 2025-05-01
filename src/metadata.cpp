// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include "zarr/metadata.hpp"

#include <format>
#include <string>

#include <nlohmann/json.hpp>

namespace nlohmann {
    template<typename T>
    struct adl_serializer<std::optional<T>> {
        static void from_json(const json& j, std::optional<T>& opt) {
            opt = j.is_null() ? std::nullopt : std::make_optional(j.get<T>());
        }
    };
}

namespace zarr {

namespace {

auto validate_order(const char order) -> bool {
    return order == 'C' || order == 'F';
}

}

auto Metadata::parse(std::string_view buffer) -> std::expected<Metadata, std::string> {
    auto json_string = std::string(buffer);
    auto output = Metadata {};

    try {
        auto j = nlohmann::json::parse(json_string);
        j.at("chunks").get_to(output.chunks);
        j.at("dtype").get_to(output.dtype);
        j.at("fill_value").get_to(output.fill_value);
        j.at("shape").get_to(output.shape);
        j.at("zarr_format").get_to(output.zarr_format);
        output.order = j.at("order").get<std::string>().at(0);
        output.dimension_separator = j.value("dimension_separator", ".");
    } catch(const nlohmann::json::exception& e) {
        return std::unexpected(std::format("Failed to parse JSON metadata {}", e.what()));
    }

    if (!validate_order(output.order)) {
        return std::unexpected("Invalid order value. Expected 'C' or 'F'.");
    }

    return output;
}

} // namespace zarr
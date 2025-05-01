// Copyright © 2025, Shlomi Nissan.
// All rights reserved.

#include <gtest/gtest.h>

#include <zarr/metadata.hpp>

#include "store_filesystem.hpp"

auto get_valid_metadata() {
    return R"({
        "chunks": [
            2,
            8
        ],
        "compressor": null,
        "dtype": ">i4",
        "fill_value": 0,
        "filters": null,
        "order": "C",
        "shape": [
            8,
            8
        ],
        "zarr_format": 2
    })";
}

#pragma region Parse

TEST(Metadata, ParseValidMetadata) {
    auto metadata = zarr::Metadata::parse(get_valid_metadata()).value();

    EXPECT_EQ(metadata.zarr_format, 2);
    EXPECT_EQ(metadata.order, 'C');
    EXPECT_EQ(metadata.dtype, ">i4");
    EXPECT_EQ(metadata.shape[0], 8);
    EXPECT_EQ(metadata.shape[1], 8);
    EXPECT_EQ(metadata.chunks[0], 2);
    EXPECT_EQ(metadata.chunks[1], 8);
    EXPECT_EQ(metadata.fill_value.value(), 0);
    EXPECT_EQ(metadata.dimension_separator, ".");
}

#pragma endregion
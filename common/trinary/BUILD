package(default_visibility = ["//visibility:public"])

cc_library(
    name = "bytes",
    hdrs = ["bytes.h"],
    deps = [
        "//common:stdint",
    ],
)

cc_library(
    name = "trits",
    hdrs = ["trits.h"],
    deps = [
        "//common:stdint",
    ],
)

cc_library(
    name = "tryte",
    hdrs = ["tryte.h"],
    deps = [
        "//common:stdint",
    ],
)

cc_library(
    name = "bct",
    srcs = ["bct.c"],
    hdrs = ["bct.h"],
    deps = [":trits"],
)

cc_library(
    name = "ptrits",
    srcs = [
        "ptrit_incr.c",
    ],
    hdrs = [
        "ptrit.h",
        "ptrit_incr.h",
    ],
    deps = [
        "//common:stdint",
    ],
)

cc_library(
    name = "trit_byte",
    srcs = ["trit_byte.c"],
    hdrs = ["trit_byte.h"],
    deps = [
        ":bytes",
        ":trits",
        "//common:defs",
        "//utils:macros",
    ],
)

cc_library(
    name = "trit_tryte",
    srcs = ["trit_tryte.c"],
    hdrs = ["trit_tryte.h"],
    deps = [
        ":trits",
        ":tryte",
        "//common:defs",
    ],
)

cc_library(
    name = "trit_long",
    srcs = ["trit_long.c"],
    hdrs = ["trit_long.h"],
    deps = [
        ":trits",
        "//common:defs",
        "//common:stdint",
    ],
)

cc_library(
    name = "trit_ptrit",
    srcs = ["trit_ptrit.c"],
    hdrs = ["trit_ptrit.h"],
    deps = [
        ":ptrits",
        ":trits",
        "//common:stdint",
    ],
)

cc_library(
    name = "add",
    srcs = ["add.c"],
    hdrs = ["add.h"],
    deps = [
        ":trits",
    ],
)

cc_library(
    name = "tryte_long",
    srcs = ["tryte_long.c"],
    hdrs = ["tryte_long.h"],
    deps = [
        ":tryte",
        "//common:defs",
    ],
)

cc_library(
    name = "tryte_ascii",
    srcs = ["tryte_ascii.c"],
    hdrs = ["tryte_ascii.h"],
    deps = [
        ":tryte",
        "//common:defs",
    ],
)

config_setting(
    name = "trit_encoding_1",
    values = {"define": "trit_encoding=1"},
)

config_setting(
    name = "trit_encoding_3",
    values = {"define": "trit_encoding=3"},
)

config_setting(
    name = "trit_encoding_4",
    values = {"define": "trit_encoding=4"},
)

config_setting(
    name = "trit_encoding_5",
    values = {"define": "trit_encoding=5"},
)

cc_library(
    name = "flex_trit",
    deps = select({
        ":trit_encoding_1": [":flex_trit_1"],
        ":trit_encoding_3": [":flex_trit_3"],
        ":trit_encoding_4": [":flex_trit_4"],
        ":trit_encoding_5": [":flex_trit_5"],
        "//conditions:default": [":flex_trit_3"],
    }),
)

cc_library(
    name = "flex_trit_1",
    srcs = ["flex_trit.c"],
    hdrs = ["flex_trit.h"],
    defines = ["FLEX_TRIT_ENCODING_1_TRIT_PER_BYTE"],
    deps = [
        ":trit_byte",
        ":trit_tryte",
        ":trits",
        "//common:stdint",
        "//utils:macros",
    ],
)

cc_library(
    name = "flex_trit_3",
    srcs = ["flex_trit.c"],
    hdrs = ["flex_trit.h"],
    defines = ["FLEX_TRIT_ENCODING_3_TRITS_PER_BYTE"],
    deps = [
        ":trit_byte",
        ":trit_tryte",
        ":trits",
        "//common:stdint",
        "//utils:macros",
    ],
)

cc_library(
    name = "flex_trit_4",
    srcs = ["flex_trit.c"],
    hdrs = ["flex_trit.h"],
    defines = ["FLEX_TRIT_ENCODING_4_TRITS_PER_BYTE"],
    deps = [
        ":trit_byte",
        ":trit_tryte",
        ":trits",
        "//common:stdint",
        "//utils:macros",
    ],
)

cc_library(
    name = "flex_trit_5",
    srcs = ["flex_trit.c"],
    hdrs = ["flex_trit.h"],
    defines = ["FLEX_TRIT_ENCODING_5_TRITS_PER_BYTE"],
    deps = [
        ":trit_byte",
        ":trit_tryte",
        ":trits",
        "//common:stdint",
        "//utils:macros",
    ],
)

cc_library(
    name = "trit_array",
    srcs = ["trit_array.c"],
    hdrs = ["trit_array.h"],
    deps = [
        ":flex_trit",
        "//common:stdint",
    ],
)

cc_library(
    name = "flex_trit_array",
    srcs = ["flex_trit_array.cc"],
    hdrs = ["flex_trit_array.h"],
    deps = [
        ":flex_trit",
        "//common:stdint",
    ],
)

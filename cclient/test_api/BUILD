cc_binary(
    name = "test_api",
    srcs = ["cclient_test.c"],
    copts = ["-DLOGGER_ENABLE"],
    visibility = ["//visibility:public"],
    deps = [
        ":constant",
        "//cclient:api",
        "//cclient/http:shared",
        "//cclient/serialization:serializer_json",
        "//utils/containers/hash:hash8019_queue",
    ],
)

cc_binary(
    name = "test_send_transfer",
    srcs = ["send_transfer_test.c"],
    copts = ["-DLOGGER_ENABLE"],
    visibility = ["//visibility:public"],
    deps = [
        ":send_transfer_test_common",
        "//cclient:api",
        "//cclient/http:shared",
        "//cclient/serialization:serializer_json",
        "//utils/containers/hash:hash8019_queue",
    ],
)

cc_library(
    name = "constant",
    hdrs = ["cclient_test.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "send_transfer_test_common",
    hdrs = ["send_transfer_test.h"],
    visibility = ["//visibility:public"],
    deps = [
        "//cclient:api",
        "//cclient/http:shared",
        "//cclient/serialization:serializer_json",
        "//common/model:bundle",
        "//common/model:transaction",
        "//utils/containers/hash:hash8019_queue",
    ],
)

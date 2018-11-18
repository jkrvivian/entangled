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

cc_library(
    name = "constant",
    hdrs = ["cclient_test.h"],
    visibility = ["//visibility:public"],
)

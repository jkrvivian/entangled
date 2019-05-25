cc_binary(
    name = "test_api",
    srcs = ["cclient_test.c"],
    copts = ["-DLOGGER_ENABLE"],
    visibility = ["//visibility:public"],
    deps = [
        ":constant",
        "//cclient/api",
        "//cclient/http:shared",
        "//cclient/types",
        "//common/model:transaction",
        "//utils/containers/hash:hash8019_queue",
    ],
)

cc_library(
    name = "constant",
    hdrs = ["cclient_test.h"],
    visibility = ["//visibility:public"],
)

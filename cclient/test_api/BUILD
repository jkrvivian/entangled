cc_binary(
    name = "test_api",
    srcs = ["main.c"],
    copts = ["-DLOGGER_ENABLE"],
    visibility = ["//visibility:public"],
    deps = [
        "//cclient:api",
        "//cclient/http:shared",
        "//cclient/serialization:serializer_json",
    ],
)

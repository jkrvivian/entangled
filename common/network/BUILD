package(default_visibility = ["//visibility:public"])

cc_library(
    name = "endpoint",
    hdrs = ["endpoint.h"],
    deps = [":network"],
)

cc_library(
    name = "network",
    hdrs = ["network.h"],
)

cc_library(
    name = "uri",
    srcs = ["uri.c"],
    hdrs = ["uri.h"],
    deps = [":network"],
)

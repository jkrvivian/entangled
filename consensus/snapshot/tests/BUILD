filegroup(
    name = "snapshot_test_files",
    srcs = [
        "snapshot.txt",
        "snapshot_badly_formatted.txt",
        "snapshot_conf.json",
        "snapshot_inconsistent.txt",
        "snapshot_invalid_supply.txt",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "test_snapshot",
    srcs = ["test_snapshot.c"],
    data = [
        ":snapshot_test_files",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//common/model:transaction",
        "//consensus/snapshot",
        "@unity",
    ],
)

cc_test(
    name = "test_state_delta",
    srcs = ["test_state_delta.c"],
    data = [
        ":snapshot_test_files",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//common/model:transaction",
        "//consensus/snapshot",
        "@unity",
    ],
)

cc_test(
    name = "test_snapshot_metadata",
    srcs = ["test_snapshot_metadata.c"],
    data = [
        ":snapshot_test_files",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//common/model:transaction",
        "//consensus/snapshot:snapshot_metadata",
        "//utils:time",
        "@unity",
    ],
)

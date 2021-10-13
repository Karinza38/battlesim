package(default_visibility = ["//visibility:public"])

cc_library(
    name = "Log",
    hdrs = ["Log.h"],
    srcs = ["Log.cpp"],
)

cc_library(
    name = "ErrnoCheck",
    hdrs = ["ErrnoCheck.h"],
    srcs = ["ErrnoCheck.cpp"],
    deps = [":Log"],
)

cc_library(
    name = "Thread",
    hdrs = [
        "Thread.h",
        "Thread.hpp",
    ],
    srcs = ["Thread.cpp"],
    deps = [":ErrnoCheck"],
)

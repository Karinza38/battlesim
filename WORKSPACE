workspace(name = "battlesim")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "googletest",
    remote = "https://github.com/google/googletest",
    commit = "703bd9caab50b139428cea1aaff9974ebee5742e",
    shallow_since = "1570114335 -0400",
)

# http_archive(
#     name = "bazelregistry_sdl2",
#     strip_prefix = "sdl2-c3efa24f546f0d8be97aaf1609688905e585cd69",
#     urls = ["https://github.com/bazelregistry/sdl2/archive/c3efa24f546f0d8be97aaf1609688905e585cd69.zip"],
#     sha256 = "735b86e808d78c3a6e7db86c4532140be4ad5d7349feea2dbfef7ea1382c31eb",
# )

# new_local_repository(
#   name = "SDL2",
#   path = "/usr/local/include/SDL2",
#   build_file = "SDL2.BUILD",
# )

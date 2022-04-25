load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

commit = {
    "llvm_toolchain": "1eb0a56b27bc38489fe9257e7d2010dd64ff3cf9",
    "rules_cc": "d545fa4f798f2a0b82f556b8b0ec59a93c100df7",
    "googletest": "703bd9caab50b139428cea1aaff9974ebee5742e",
    "benchmark": "8e0b1913d4ea803dfeb2e55567208fcab6b1b6c7",
    "heap_layers": "18966daad7a3f2ef30e9a2ac3750b590bb688ba3",
}

http_archive(
    name = "rules_cc",
    sha256 = "188e88d911b69bb77b391e02a4a5fdec2313dd01f0305d97cd3451e38f7ace10",
    strip_prefix = "rules_cc-{}".format(commit["rules_cc"]),
    urls = [
        "https://github.com/bazelbuild/rules_cc/archive/{}.zip".format(commit["rules_cc"]),
    ],
)

http_archive(
    name = "rules_foreign_cc",
    sha256 = "6041f1374ff32ba711564374ad8e007aef77f71561a7ce784123b9b4b88614fc",
    strip_prefix = "rules_foreign_cc-0.8.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.8.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()


# To find additional information on this release or newer ones visit:
# https://github.com/bazelbuild/rules_rust/releases
http_archive(
    name = "rules_rust",
    sha256 = "39655ab175e3c6b979f362f55f58085528f1647957b0e9b3a07f81d8a9c3ea0a",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_rust/releases/download/0.2.0/rules_rust-v0.2.0.tar.gz",
        "https://github.com/bazelbuild/rules_rust/releases/download/0.2.0/rules_rust-v0.2.0.tar.gz",
    ],
)

load("@rules_rust//rust:repositories.bzl", "rules_rust_dependencies", "rust_register_toolchains")

load("@rules_cc//cc:defs.bzl", "cc_toolchain", "cc_toolchain_suite")

rules_rust_dependencies()

rust_register_toolchains()

# TODO move to a toolchain dir
cc_toolchain_suite(
    name = "cpp",
    toolchains = {
        "k8": ":cc-compiler-clang10",
    },
)

cc_toolchain(
    name = "cc-compiler-clang10",
    all_files = ":empty",
    compiler_files = ":empty",
    dwp_files = ":empty",
    linker_files = ":empty",
    objcopy_files = ":empty",
    strip_files = ":empty",
    supports_param_files = 1,
    toolchain_config = ":clang10_toolchain",
    toolchain_identifier = "clang10_toolchain",
)


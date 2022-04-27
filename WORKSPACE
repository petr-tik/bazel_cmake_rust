workspace(name = "glueing_cmake_rust_bazel")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")


http_archive(
    name = "rules_cc",
    sha256 = "188e88d911b69bb77b391e02a4a5fdec2313dd01f0305d97cd3451e38f7ace10",
    strip_prefix = "rules_cc-d545fa4f798f2a0b82f556b8b0ec59a93c100df7",
    urls = [
        "https://github.com/bazelbuild/rules_cc/archive/d545fa4f798f2a0b82f556b8b0ec59a93c100df7.zip",
    ],
)

load("@rules_cc//cc:repositories.bzl", "rules_cc_toolchains")

rules_cc_toolchains()

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip"],
  sha256 = "5cf189eb6847b4f8fc603a3ffff3b0771c08eec7dd4bd961bfd45477dd13eb73",
  strip_prefix = "googletest-609281088cfefc76f9d0ce82e1ff6c30cc3591e5",
)

http_archive(
    name = "rules_foreign_cc",
    sha256 = "6041f1374ff32ba711564374ad8e007aef77f71561a7ce784123b9b4b88614fc",
    strip_prefix = "rules_foreign_cc-0.8.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.8.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()


http_archive(
    name = "rules_rust",
    sha256 = "e074f1e203607c5fcd549929d956170346f8807d2bbaeb98b2ed213c37e0870f",
    urls = [
        "https://github.com/bazelbuild/rules_rust/releases/download/0.3.1/rules_rust-v0.3.1.tar.gz",
    ],
)

load("@rules_rust//rust:repositories.bzl", "rules_rust_dependencies", "rust_register_toolchains")
load("@rules_rust//tools/rust_analyzer:deps.bzl", "rust_analyzer_deps")


load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "fmt",
    remote = "https://github.com/fmtlib/fmt",
    commit = "7e4ad40171aa552d38cb99a5c181a0d7b150facc",
    shallow_since = "1650811382 -0700",
    patch_cmds = [
        "mv support/bazel/.bazelrc .bazelrc",
        "mv support/bazel/.bazelversion .bazelversion",
        "mv support/bazel/BUILD.bazel BUILD.bazel",
        "mv support/bazel/WORKSPACE.bazel WORKSPACE.bazel",
    ],
)

rules_rust_dependencies()

rust_register_toolchains()

rust_analyzer_deps()

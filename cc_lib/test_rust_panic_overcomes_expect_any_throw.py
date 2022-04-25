#!/usr/bin/env python3
import sys
import subprocess


def test_panic_throw():
    cc_test_executable = sys.argv[1]

    proc = subprocess.run([cc_test_executable],
                          stdout=subprocess.PIPE,
                          stderr=subprocess.PIPE,
                          )
    assert proc.returncode != 0

    expected_stderr_strings = set(
        ["fatal runtime error: Rust panics must be rethrown'",
         "core::option::Option<T>::unwrap"]
    )

    assert all(any(expected in str(line) for line in proc.stderr.splitlines())
               for expected in expected_stderr_strings
    ), "Missing one of the strings"


if __name__ == "__main__":
    test_panic_throw()

#!/usr/bin/env python3
import sys
import subprocess
from typing import Set


def check_strings_in_proc_output(proc_output, expected_strings: Set[str]) -> bool:
    expected_strings_with_counts = {word: 0 for word in expected_strings}
    for line in proc_output.splitlines():
        for expected in expected_strings:
            if expected in str(line):
                expected_strings_with_counts[expected] += 1
    assert all(
        count > 0 for count in expected_strings_with_counts.values()
    ), f"Didn't see: {list([expected for expected, count in expected_strings_with_counts.items() if count == 0])})"


def test_panic_throw():
    cc_test_executable = sys.argv[1]

    proc = subprocess.run(
        [cc_test_executable],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    assert proc.returncode != 0

    expected_stderr_strings = set(
        [
            "fatal runtime error: Rust panics must be rethrown'",
            "core::option::Option<T>::unwrap",
        ]
    )
    check_strings_in_proc_output(proc.stderr, expected_stderr_strings)


if __name__ == "__main__":
    test_panic_throw()

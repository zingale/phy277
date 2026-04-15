#!/bin/env python

from pathlib import Path
import subprocess

OKAY_TO_FAIL = [
    "bounds.cpp",
    "const_reference_example.cpp",
    "fallthrough.cpp",
    "format_too_few.cpp",
    "function_vector.cpp",
    "if-scope.cpp",
    "narrowing.cpp",
    "println.cpp",
    "shadow.cpp",
    "shadowing.cpp",
    "types.cpp",
    "undefined_stacktrace.cpp",
    "unused.cpp",
    "vector_modify.cpp"
]

GCC_OPTS = ["-Wall",
            "-Wextra",
            "-Wshadow",
            "-Werror",
            "-Wpedantic"]

GCC_OPTS_STR = " ".join(GCC_OPTS)

CLANG_OKAY_TO_FAIL = ["absolute.cpp",
                      "function_value_reference.cpp"]

CLANG_OPTS = ["-Wall",
              "-Wextra",
              "-Wpedantic",
              "-Wheader-hygiene",
              "-Wpragma-once-outside-header",
              "-Wquoted-include-in-framework-header",
              "-Werror"]

CLANG_OPTS_STR = " ".join(CLANG_OPTS)


def main():

    for p in Path(".").rglob("*.cpp"):
        file = p.name
        pdir = p.parent

        if file in OKAY_TO_FAIL:
            print(f"skipping {p}")

        else:
            print(f"working on {pdir/file}")
            subprocess.run(f"g++ {GCC_OPTS_STR} -std=c++20 -c {file}",
                           capture_output=False, shell=True, cwd=pdir,
                           check=True)

            if file not in CLANG_OKAY_TO_FAIL:
                subprocess.run(f"clang++ {CLANG_OPTS_STR} -std=c++20 -c {file}",
                               capture_output=False, shell=True, cwd=pdir,
                               check=True)


if __name__ == "__main__":
    main()

#!/bin/env python

from pathlib import Path
import subprocess

OKAY_TO_FAIL = ["function_vector.cpp",
                "vector_modify.cpp",
                "shadowing.cpp",
                "undefined_stacktrace.cpp",
                "println.cpp",
                "format_too_few.cpp",
                "fallthrough.cpp",
                "types.cpp",
                "unused.cpp",
                "narrowing.cpp",
                "bounds.cpp"]


def main():

    for p in Path(".").rglob("*.cpp"):
        file = p.name
        pdir = p.parent

        if file in OKAY_TO_FAIL:
            print(f"skipping {p}")

        else:
            print(f"working on {pdir/file}")
            subprocess.run(f"g++ -Wall -Wextra -Wshadow -Werror -Wpedantic -std=c++20 -c {file}",
                           capture_output=False, shell=True, cwd=pdir, check=True)


if __name__ == "__main__":
    main()



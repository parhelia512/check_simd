# check_simd

Simple, cross platform command line SIMD checker with logger, written in C++.

It uses libhighway for dyanmic dispatch:
https://github.com/google/highway/blob/master/g3doc/quick_reference.md

This also has a handy little logger that could be used as a library.

Currently simply a command line program for Linux and Windows, that checks
if the CPU on the currently running system supports:

---------------------------------------------------------------------------------------------------------
| AVX                                |       AVX                     |      https://www.                |
|                                    |                               |                                  |
|                                    |                               |                                  |
|                                    |                               |                                  |
|                                    |                               |                                  |
|                                    |                               |                                  |
|                                    |                               |                                  |
|                                    |                               |                                  |
|                                    |                               |                                  |
|                                    |                               |                                  |
---------------------------------------------------------------------------------------------------------

The logging.h and logging.cc could be imported into a program. Usage is as follows:

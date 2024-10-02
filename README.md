# OpenMP Code Repository

Welcome to this repository, where you'll find OpenMP code examples and implementations. This repository aims to provide a comprehensive guide on how to use OpenMP for parallel programming in C.

## Table of Contents

1. [Introduction to OpenMP](#introduction-to-openmp)
2. [Compiling and Running OpenMP Code](#compiling-and-running-openmp-code)

## Introduction to OpenMP

OpenMP (Open Multi-Processing) is an application programming interface (API) that supports multi-platform shared memory multiprocessing programming in C, C++, and Fortran. It consists of a set of compiler directives, library routines, and environment variables that influence run-time behavior.

### Key Features of OpenMP

- **Parallelization**: OpenMP allows you to parallelize sections of your code using directives like `#pragma omp parallel`.
- **Thread Management**: It provides functions like `omp_get_thread_num()` to manage threads.
- **Synchronization**: OpenMP supports synchronization primitives such as barriers and locks.

## Compiling and Running OpenMP Code

To compile and run OpenMP code, you need to use a compiler that supports OpenMP. Here are the steps:

### Compiling OpenMP Code

1. **Using GCC**:
   ```bash
   gcc -fopenmp -o program_name program_name.c

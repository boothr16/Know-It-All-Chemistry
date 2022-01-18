# Know-It-All-Chemistry

## Introduction
The Know-It-All-Chemistry repository featured here is a minimum-working example of an application used to interpret output and report key data from various spectroscopic measurements (MS, UV-Vis, IR, NMR, Raman, etc.). Sample spectroscopic data was pulled from the Example folder in Wiley's Know-It-All software package (two-week free trial). This application provides a CLI for reading out key data from log files, depending on the type of measurement indicated by the user.

## Dependencies
* C++ compiler (GCC, clang, etc.)
* GNU Make
* Sample spectra should be placed in `./Samples/X/` where X is the measurement type (UV, MS, etc.). Cloning the examples from this repository ensures the correct file path.

 ![filepath](https://user-images.githubusercontent.com/49886228/149148102-e24e80cc-f2e6-4383-bfe6-f96dd6cce4eb.png)

## How to compile and run application
1. `git clone` this repository.
2. `cd` into the created Know-It-All-Chemistry directory.
3. Compile project using `make` from the command line.
4. Run examples using `./kia <chemical name> <measurement type>` from the command line (drop the angled brackets).
  * `make clean` can be used to clean up directory.

## Example input and output using the files included in this repository
1. Mass Spectrum interpretation:

-![mstrial](https://user-images.githubusercontent.com/49886228/149187100-f2ce5707-6a5b-4138-80bd-2cf2629e9539.png)

2. UV-Vis Spectrum interpretation:

-![uvtrial1](https://user-images.githubusercontent.com/49886228/149187320-a3b2889c-59b5-4d12-ac99-5a2fa2fb17c2.png)

-![uvtrial2](https://user-images.githubusercontent.com/49886228/149187332-a3745a72-5ce8-4f39-9a1b-080d909ba5b5.png)



## TO DO
* Unit testing
* * Throw errors for measurement type mismatch.
* * Throw errors for unexpected delimiters.
* ~~Streamline compilation using a Makefile.~~

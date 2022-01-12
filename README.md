# Know-It-All-Chemistry

## Introduction
The Know-It-All-Chemistry repository featured here is a minimum-working example of an application used to interpret output from various spectroscopic measurements (MS, UV-Vis, IR, NMR, Raman, etc.). Sample spectroscopic data was pulled from the Example folder in Wiley's Know-It-All software package (two-week free trial). This application provides a CLI for reading out key data from log files, depending on the type of measurement indicated by the user.

## Dependencies
* C++ compiler (GCC, clang, etc.)
* Sample spectra should be placed in `./Samples/X/` where X is the measurement type (UV, MS, etc.). Cloning the examples from this repository ensures the correct file path.
* 
![filepath](https://user-images.githubusercontent.com/49886228/149148102-e24e80cc-f2e6-4383-bfe6-f96dd6cce4eb.png)


## TO DO
* Finish this README!
* Unit testing
* * Throw errors for measurement type mismatch.
* * Throw errors for unexpected delimiters.

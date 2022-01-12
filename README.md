# Know-It-All-Chemistry

## Introduction
The Know-It-All-Chemistry repository featured here is a minimum-working example of an application used to interpret output from various spectroscopic measurements (MS, UV-Vis, IR, NMR, Raman, etc.). Sample spectroscopic data was pulled from the Example folder in Wiley's Know-It-All software package (two-week free trial). This application provides a CLI for reading out key data from log files, depending on the type of measurement indicated by the user.

## Dependencies
* C++ compiler (GCC, clang, etc.)
* In the spirit of portraying the application as part of a software bundle, sample/output files must be placed in relative path `./Samples/X/`, where X is the corresponding measurement (UV, MS, etc.), as shown below.
![Screenshot](filepath.jpg)

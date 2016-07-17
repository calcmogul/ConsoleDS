# ConsoleDS

ConsoleDS is a program which implements an FRC Driver Station as a console application via [LibDS](https://github.com/FRC-Utilities/LibDS).

## Dependencies

If one is building on Windows, I recommend using the [MSYS2 compiler](https://msys2.github.io/). The following libraries are required as dependencies and should be installed using either your package manager of choice or MSYS2's pacman:

* Qt5

## Building ConsoleDS

To build the project, first run `qmake dir` within a terminal from the desired build directory, where "dir" is the relative location of the ConsoleDS.pro file. This will generate three makefiles. If a debug build is desired, run `make -f Makefile.Debug`. The default behavior when simply running `make` is to perform a release build.

## Usage

### Command-line Arguments

Pass the FRC team number as the first and only argument to configure the mDNS/IP address.

### Commands

#### `enable`

Enables robot if connected

#### `disable`

Disables robot

#### `test`

Sets control mode to Test

#### `auto`

Sets control mode to Autonomous

#### `operator`

Sets control mode to Operator Control

#### `quit`

Closes ConsoleDS

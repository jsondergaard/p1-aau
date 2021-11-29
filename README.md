## About ##

|            |                           |  
| ---------- | ------------------------- |  
| Title:     | P1        |  
| Author:    | B213       |  
| Date:      | 2021-11-22 |  
| Copyright: | Copyright © 2021-2022 B213.    |  
| Version:   | 0.1.0      |  


### Makefile ###

The overall build process is controlled by the master `Makefile`.  It provides
the following commands:

	make
	make release

Generate the CMake build files for use or distribution.  Once complete you will
need to change to the `build` directory and run `make`, `make test`, and
`cpack` as desired.

	make zip

Direct CPack to create a zip installer rather than a graphical installer.

	make debug

Generate build files for [CuTest] unit testing.  In the `build` directory, 
run `make`, then `make test`.

	make analyze

If you have `clang` installed, this will generate debug build files with the
`scan-build` command.  In the `build` directory, run `scan-build -V make`
to compile the software and view the static analysis results.

	make xcode

Build a project file for Xcode on OS X.

	make windows
	make windows-zip
	make windows-32
	make windows-zip-32

Use the MinGW software to cross-compile for Windows on a *nix machine.  You can
specify the 32 bit option, and also the zip option as indicated.

	make documentation

Build the [Doxygen]-generated documentation.

	make clean

Clean out the `build` directory.  Be sure to run this before running another
command.

## License ##

The `c-template` project is released under the MIT License.

GLibFacade.c and GLibFacade.h are from the MultiMarkdown v4 project:

	https://github.com/fletcher/MultiMarkdown-4/

MMD 4 is released under both the MIT License and GPL.


CuTest is released under the zlib/libpng license. See CuTest.c for the text
of the license.


## The MIT License ##

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

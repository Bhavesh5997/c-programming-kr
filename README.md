C Programming Practice (K&R):

All programs are written and tested on Linux.

```bash
Directory Structure (High Level):
excercises/
├── chapter-1 to chapter-7   # K&R chapter-wise exercises
├── assignment               # App + Library based assignment
```

Build System Overview:
- Each exercise has its own Makefile
- Each chapter has its own Makefile
- There is one top-level Makefile to build all chapters together
- After build, binaries are placed in the bin/ directory of each exercise (for example: chapter-1/ex-1-1/bin/ex-1-1).
- All programs can be executed from the Linux terminal

How to Build and Run:
$ cd excercises
$ make

This will:
- Compile all chapter programs
- Create a bin/ directory
- enerate executable files inside bin/ of chapter-1 to chapter-7

Run any program like:
./chapter-1/ex-1-1/bin/ex-1-1

Clean all build directories from each chapter:
$ make clean

Build a single chapter:
$ cd excercises/chapter-3
$ make

Run any program like:
$ ./ex-3-1/bin/ex-3-1

Clean all execrcises build directories:
$ make clean

Build a Single Exercise (Example):
$ cd chapter-1
$ make -C ex-1-1/build
$ ./ex-1-1/bin/ex-1-1
$ make -C ex-1-1/build clean

```bash
Assignment Directory:
assignment/
├── lib   # Reusable library code
├── app   # Application using the library
└── Makefile
```

Build assignment (recommended way):
$ cd excercises/assignment
$ make

This will:
- Build the library
- Then build the application

Run the application:
$ ./app/bin/app

Clean build:
$ make clean

Manual build (optional):
$ cd lib
$ make -C build
$ cd ../app
$ make -C build

$ ./bin/app

Clean build:
$ make -C build clean
$ cd ../lib
$ make -C build clean

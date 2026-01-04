C Programming Practice (K&R):

All programs are written and tested on Linux.

Directory Structure (High Level):
excercises
   ├── assignment
   │   ├── app
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   └── src
   │   │       └── app.c
   │   ├── lib
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── Doxyfile
   │   │   ├── include
   │   │   │   └── doubly_linked_list.h
   │   │   └── src
   │   │       └── doubly_linked_list.c
   │   └── Makefile
   ├── chapter-1
   │   ├── ex-1-1
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   └── src
   │   │       └── ex-1-1.c
   │   ├── ex-1-11
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   └── src
   │   │       └── ex-1-11.c
   │   ├── ex-1-6
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   └── src
   │   │       └── ex-1-6.c
   │   └── Makefile
   ├── chapter-2
   │   ├── ex-2-4
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── squeeze.h
   │   │   └── src
   │   │       ├── ex-2-4.c
   │   │       └── squeeze.c
   │   ├── ex-2-5
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── any.h
   │   │   └── src
   │   │       ├── any.c
   │   │       └── ex-2-5.c
   │   ├── ex-2-6
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── setbits.h
   │   │   └── src
   │   │       ├── ex-2-6.c
   │   │       └── setbits.c
   │   └── Makefile
   ├── chapter-3
   │   ├── ex-3-1
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── binsearch.h
   │   │   └── src
   │   │       ├── binsearch.c
   │   │       └── ex-3-1.c
   │   ├── ex-3-2
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── escape.h
   │   │   └── src
   │   │       ├── escape.c
   │   │       └── ex-3-2.c
   │   ├── ex-3-3
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── expand.h
   │   │   └── src
   │   │       ├── ex-3-3.c
   │   │       └── expand.c
   │   ├── ex-3-4
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── itoa.h
   │   │   └── src
   │   │       ├── ex-3-4.c
   │   │       └── itoa.c
   │   ├── ex-3-5
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── itob.h
   │   │   └── src
   │   │       ├── ex-3-5.c
   │   │       └── itob.c
   │   ├── ex-3-6
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── include
   │   │   │   └── itoa.h
   │   │   └── src
   │   │       ├── ex-3-6.c
   │   │       └── itoa.c
   │   └── Makefile
   ├── chapter-4
   │   ├── ex-4-11
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-4-11.c
   │   ├── ex-4-12
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-4-12.c
   │   ├── ex-4-4
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-4-4.c
   │   ├── ex-4-5
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-4-5.c
   │   └── Makefile
   ├── chapter-5
   │   ├── ex-5-1
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-5-1.c
   │   ├── ex-5-10
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-5-10.c
   │   ├── ex-5-13
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-5-13.c
   │   ├── ex-5-3
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-5-3.c
   │   ├── ex-5-4
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-5-4.c
   │   ├── ex-5-7
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-5-7.c
   │   ├── ex-5-8
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-5-8.c
   │   └── Makefile
   ├── chapter-6
   │   ├── ex-6-1
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-6-1.c
   │   └── Makefile
   ├── chapter-7
   │   ├── ex-7-3
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-7-3.c
   │   ├── ex-7-5
   │   │   ├── build
   │   │   │   └── Makefile
   │   │   ├── docs
   │   │   │   └── output.txt
   │   │   └── src
   │   │       └── ex-7-5.c
   │   └── Makefile
   ├── Makefile
   └── socket_programming
       ├── client2.c
       ├── client3.c
       ├── client.c
       ├── sample2.txt
       ├── sample3.txt
       ├── sample.txt
       └── server.c

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

Assignment Directory:
assignment/
├── lib   # Reusable library code
├── app   # Application using the library
└── Makefile

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

Socket Programming:
$ gcc server.c -o server
$ gcc client.c -o client
$ ./server 9898
$ ./client 127.0.0.1 9898

- Use 127.0.0.1 if server and client run on the same PC
- Use server’s IP address if running on different machines

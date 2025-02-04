MAKEFLAGS += --no-builtin-rules
QUIET = @
MAKE = make
CLEAN = make clean

all:
	$(QUIET)$(MAKE) -C lib/build
	$(QUIET)$(MAKE) -C app/build
clean:
	$(QUIET)$(CLEAN) -C lib/build
	$(QUIET)$(CLEAN) -C app/build

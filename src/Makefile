# name of your application
export PROJECT = dash

# If no BOARD is found in the environment, use this default:
export BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
export RIOTBASE ?= $(CURDIR)/../../RIOT/

# Uncomment these lines if you want to use platform support from external
# repositories:
#export RIOTCPU ?= $(CURDIR)/../../RIOT/thirdparty_cpu
#export RIOTBOARD ?= $(CURDIR)/../../RIOT/thirdparty_boards

# Uncomment this to enable scheduler statistics for ps:
#CFLAGS += -DSCHEDSTATISTICS

# If you want to use native with valgrind, you should recompile native
# with the target all-valgrind instead of all:
# make -B clean all-valgrind

# Uncomment this to enable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
#CFLAGS += -DDEVELHELP

# Change this to 0 show compiler invocation lines by default:
export QUIET ?= 1

# Modules to include:

USEMODULE += posix
USEMODULE += vtimer

HELPERS = mkinit mksyntax mknodes mksignames
BUILT_SOURCES = builtins.h nodes.h syntax.h token.h token_vars.h
CLEANFILES = $(BUILT_SOURCES) $(HELPERS) builtins.c init.c nodes.c signames.c \
			 syntax.c builtins.def
PROJDEPS = $(BUILT_SOURCES)

CFLAGS = -include $(abspath $(CURDIR)/../config.h) -DSHELL \
	 -DSMALL -DREALLY_SMALL

include $(RIOTBASE)/Makefile.include

SRC = \
	alias.c arith_yacc.c arith_yylex.c cd.c error.c eval.c exec.c expand.c \
	histedit.c input.c jobs.c mail.c main.c memalloc.c miscbltin.c \
	mystring.c options.c parser.c redir.c show.c trap.c output.c \
	printf.c system.c test.c times.c var.c

token.h token_vars.h: mktokens
	$(AD)sh $^

builtins.def: builtins.def.in ../config.h
	$(AD)$(CC) -E -x c -o $@ $<

builtins.c builtins.h: mkbuiltins builtins.def
	$(AD)sh $^

init.c: mkinit $(dash_CFILES)
	$(AD)./$^

nodes.c nodes.h: mknodes nodetypes nodes.c.pat
	$(AD)./$^

syntax.c syntax.h: mksyntax
	$(AD)./$^

signames.c: mksignames
	$(AD)./$^

mksyntax: token.h

$(HELPERS): %: %.c
	$(AD)$(CC) -o $@ $<

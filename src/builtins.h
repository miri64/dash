/*
 * This file was generated by the mkbuiltins program.
 */

#define ALIASCMD (builtincmd + 3)
#define BGCMD (builtincmd + 4)
#define BREAKCMD (builtincmd + 5)
#define CDCMD (builtincmd + 6)
#define COMMANDCMD (builtincmd + 8)
#define DOTCMD (builtincmd + 0)
#define ECHOCMD (builtincmd + 10)
#define EVALCMD (builtincmd + 11)
#define EXECCMD (builtincmd + 12)
#define EXITCMD (builtincmd + 13)
#define EXPORTCMD (builtincmd + 14)
#define FALSECMD (builtincmd + 15)
#define FGCMD (builtincmd + 17)
#define GETOPTSCMD (builtincmd + 18)
#define HASHCMD (builtincmd + 19)
#define HISTCMD (builtincmd + 16)
#define JOBSCMD (builtincmd + 20)
#define KILLCMD (builtincmd + 21)
#define LOCALCMD (builtincmd + 22)
#define PRINTFCMD (builtincmd + 23)
#define PWDCMD (builtincmd + 24)
#define READCMD (builtincmd + 25)
#define RETURNCMD (builtincmd + 27)
#define SETCMD (builtincmd + 28)
#define SHIFTCMD (builtincmd + 29)
#define TESTCMD (builtincmd + 2)
#define TIMESCMD (builtincmd + 31)
#define TRAPCMD (builtincmd + 32)
#define TRUECMD (builtincmd + 1)
#define TYPECMD (builtincmd + 34)
#define UMASKCMD (builtincmd + 35)
#define UNALIASCMD (builtincmd + 36)
#define UNSETCMD (builtincmd + 37)
#define WAITCMD (builtincmd + 38)

#define NUMBUILTINS 39

#define BUILTIN_SPECIAL 0x1
#define BUILTIN_REGULAR 0x2
#define BUILTIN_ASSIGN 0x4

struct builtincmd {
	const char *name;
	int (*builtin)(int, char **);
	unsigned flags;
};

extern const struct builtincmd builtincmd[];
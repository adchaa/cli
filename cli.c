#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef enum
{
    false,
    true
} bool;
typedef struct
{
    char value[550][500];
    int size;
} resulat;
#include "git.h"
#include "utils.h"
#include "react.h"
#include "compilers.h"

void runhelp()
{
    puts("\033[0;32mreact create <name> : \033[0;37mto create react app\n\033[0;32mreact start: \033[0;37mto start react app\n\033[0;32mcommit <message>: \033[0;37mto add and commit files (git)\n\033[0;32mcommit -a <message> : \033[0;37monly commit");
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        puts("no command");
        return 0;
    }
    char name[50];
    strncpy(name, argv[1], 50);
    if (strcmp(name, "react") == 0)
    {
        runreact(argv + 2, argc);
    }
    else if (strcmp(name, "commit") == 0)
    {
        runcommit(argv + 2, argc);
    }
    else if (strcmp(name, "help") == 0)
    {
        runhelp();
    }
    else if (strcmp(name, "c") == 0)
    {
        runc(argv + 2, argc);
    }
}
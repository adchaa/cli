

void runcommit(char *args[], int n)
{
    if (n == 2)
    {
        puts("not enough args");
        exit(1);
    }
    char str[500];
    if (strcmp("-a", args[0]) == 0)
    {
        puts("commiting without adding");
        if (n == 3)
        {
            puts("error:no message");
            exit(1);
        }
        else
        {
            sprintf(str, "git commit -m %s", args[1]);
        }
    }
    else
    {
        puts("add and commit");
        system("git add .");
        sprintf(str, "git commit -m %s", args[0]);
        system(str);
    }
}
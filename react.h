void startreact()
{
    system("npm start");
}
void runreact(char *args[], int n)
{
    FILE *f;
    char ch[500];
    resulat r;
    r = execute("ls", false);
    if (n == 2)
    {
        puts("not enough args");
        exit(1);
    }
    if (strcmp(args[0], "start") == 0)
    {
        startreact();
    }
    else if (strcmp("create", args[0]) == 0)
    {
        if (n == 3)
        {
            puts("no name for the app");
            exit(1);
        }
        char ch[500];
        sprintf(ch, "npx create-react-app %s", args[1]);
        system(ch);
    }
}


void GccCommand(char *name_file, char *ch)
{
    char name_without_extension[50];
    int x = strlen(name_file) - 2;
    strncpy(name_without_extension, name_file, x);

    sprintf(ch, "gcc %s -o %s && ./%s", name_file, name_without_extension, name_without_extension);
}
void runc(char *args[], int n)
{
    char ch[100];
    if (n == 2)
    {
        resulat r;
        r = execute("ls *.c", false);
        for (int i = 0; i < r.size; i++)
        {
            printf("execution of %s", r.value[i]);
            r.value[i][strlen(r.value[i]) - 1] = 0;
            GccCommand(r.value[i], ch);
            system(ch);
        }
    }
    else
    {
        GccCommand(args[0], ch);
        system(ch);
    }
}
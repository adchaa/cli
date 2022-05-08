
void GccCommand(char *name_file, char *ch, char **args, int n)
{
    char name_without_extension[50];
    int x = strlen(name_file) - 2;
    strncpy(name_without_extension, name_file, x);

    sprintf(ch, "gcc %s -o %s && ./%s", name_file, name_without_extension, name_without_extension);
    for (int i = 0; i < n - 3; i++)
    {
        strcat(ch, " ");
        strcat(ch, args[i]);
    }
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
            GccCommand(r.value[i], ch, args + 1, n);
            system(ch);
        }
    }
    else
    {
        GccCommand(args[0], ch, args + 1, n);
        system(ch);
    }
}
void PythonCommand(char *py, char *name_file, char *str, char *args[], int n)
{
    strcpy(str, py);
    strcat(str, " ");
    strcat(str, name_file);
    for (int i = 0; i < n - 3; i++)
    {
        strcat(str, " ");
        strcat(str, args[i]);
    }
}
void runpython(char *args[], int n)
{
    char py[8];
#ifdef _WIN32
    strcpy(py, "python");
#elif __linux__
    strcpy(py, "python3");
#endif
    char str[100];
    if (n == 2)
    {
        resulat r;
        r = execute("ls *.py", false);
        for (int i = 0; i < r.size; i++)
        {
            printf("execution of %s", r.value[i]);
            r.value[i][strlen(r.value[i]) - 1] = 0;
            PythonCommand(py, r.value[i], str, args + 1, n);
            system(str);
        }
    }
    else
    {
        PythonCommand(py, args[0], str, args + 1, n);
        system(str);
    }
}
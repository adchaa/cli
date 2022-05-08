int find(char **t, char *str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, t[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

resulat execute(char *command, bool WithPrint)
{
    resulat r;
    FILE *f;
    char ch[500];
    r.size = 0;
    f = popen(command, "r");
    if (WithPrint == true)
    {

        while (fgets(ch, sizeof(ch) - 1, f))
        {
            printf("%s", ch);
            strncpy(r.value[r.size++], ch, 500);
        }
    }
    else
    {
        while (fgets(ch, sizeof(ch) - 1, f))
        {
            strncpy(r.value[r.size++], ch, 500);
        }
    }
    return r;
}
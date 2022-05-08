
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
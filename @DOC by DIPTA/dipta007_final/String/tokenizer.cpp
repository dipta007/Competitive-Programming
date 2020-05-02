int main ()
{
    char str[] ="- This, a sample string.";
    char * pch;
    // by which charcters string is tokenized that should be given into "(here)"
    pch = strtok (str," ,.-");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        // by which charcters string is tokenized that should be given into "(here)"
        pch = strtok (NULL, " ,.-");
    }
    return 0;
}
/// OUTPUT
This
a
sample
string

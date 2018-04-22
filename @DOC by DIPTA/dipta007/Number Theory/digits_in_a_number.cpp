int num_of_digits(int n, int base)
{
    return floor(log10(n) / log10(base)) + 1;
}

/**
 * cmp - Case insensitive compare two strings and return number of differences
 * @first: The first string
 * @second: The second string
 * @len: The length to which the strings would be compared to
 */
int strcmp(const char *first, const char *second, int len)
{
    int diff_factor = 0;

    if (!len)
        return -1;

    for (int i = 0; i <= len; i++)
    {
        if (tolower(first[i]) != tolower(second[i]))
        {
            diff_factor += 1;
        }
    }

    return diff_factor;
}

char *strcopy(char *source, char *destination, int len)
{
}
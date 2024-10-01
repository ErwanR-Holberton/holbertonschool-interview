#include <stdio.h>
#include <stdlib.h>

int _putchar(char c);

int my_strlen(const char *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;

    return length;
}


int main(int argc, char *argv[])
{
    int i, j, indexA, indexB, memo = 0;
    long long sum;
    char *result;

    if (argc < 3)
    {
        printf("Usage: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    }

    int lenA = my_strlen(argv[1]);
    int lenB = my_strlen(argv[2]);

    result = malloc(lenA + lenB + 2);
    for (i = 0; i < lenA + lenB + 2; i++)
        result[i] = '0';
    result[lenA + lenB + 1] = '\0';

    for (i = 0; i < lenB + lenB; i++)
    {
        sum = 0;
        for (j = 0; j < lenA; j++)
        {
            indexB = lenB - j - 1;
            indexA = (lenA - i - 1) + j;
            if (indexA < lenA && indexA >= 0)
            {
                sum += (argv[2][indexB] - '0') * (argv[1][indexA] - '0');
            }
        }
        if (sum + memo > 0)
            result[lenA + lenB - i] = (sum + memo) % 10 + '0';
        memo = (sum + memo - ((sum + memo)%10))/10;
    }
    for (i = 0; result[i] == '0'; )
        i++;
    for (; result[i] != '\0'; i++)
        _putchar(result[i]);
    _putchar('\n');
    
    free(result);

    return 0;
}
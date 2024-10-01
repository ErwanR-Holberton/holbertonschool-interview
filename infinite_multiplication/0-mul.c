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

void recursive_carry(char *num, int index, int carry)
{
    if (carry == 0 || index < 0)
        return; 

    int sum = (num[index] - '0') + carry;
    num[index] = (sum % 10) + '0';
    carry = sum / 10;

    recursive_carry(num, index - 1, carry);
}


int main(int argc, char *argv[])
{
    int i, j, indexA, indexB;
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

    for (i = 0; i < lenA; i++)
    {
        indexA = lenA - i - 1;
        for (j = 0; j < lenB; j++)
        {
            indexB = lenB - j - 1;
            recursive_carry(result, lenA + lenB - j - i, (argv[2][indexB] - '0') * (argv[1][indexA] - '0'));

        }
    }
    for (i = 0; result[i] == '0'; )
        i++;
    for (; result[i] != '\0'; i++)
        _putchar(result[i]);
    _putchar('\n');
    
    free(result);

    return 0;
}
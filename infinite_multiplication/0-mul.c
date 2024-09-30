#include <stdio.h>

int my_strlen(const char *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;

    return length;
}
void append_char_to_file(char ch)
{
    FILE *file = fopen("dump.txt", "a"); // Open file in append mode
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    
    fputc(ch, file); // Write the character to the file
    fclose(file); // Close the file
}
void print_file_in_reverse() {
    FILE *file = fopen("dump.txt", "r"); // Open the file in read mode
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    // Move to the end of the file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file); // Get the size of the file

    // Read and print in reverse
    for (long i = fileSize - 1; i >= 0; i--) {
        fseek(file, i, SEEK_SET); // Move to the i-th character
        int ch = fgetc(file); // Read the character
        putchar(ch); // Print the character
    }

    fclose(file); // Close the file
}


int main(int argc, char *argv[])
{
    int i, j, sum, indexA, indexB, memo = 0;

    if (argc < 3)
    {
        printf("Usage: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    }

    int lenA = my_strlen(argv[1]);
    int lenB = my_strlen(argv[2]);

    append_char_to_file('\n');

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
                //printf("%d %d: %d * %d = %d\n", indexA, indexB, argv[2][indexB] - '0', argv[1][indexA] - '0', (argv[2][indexB] - '0') * (argv[1][indexA] - '0'));
            }
        }
        if (sum + memo > 0)
            append_char_to_file((sum + memo)%10 + '0');
        memo = (sum + memo - ((sum + memo)%10))/10;
    }
    print_file_in_reverse();

    return 0;
}
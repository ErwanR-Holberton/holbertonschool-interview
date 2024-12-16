#include "substring.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * copy_array - Creates a copy of an array of strings, skipping one index.
 * @words: The original array of strings.
 * @nb_words: The number of strings in the array.
 * @index_to_skip: The index of the string to skip.
 *
 * Return: A new array of strings with one index skipped.
 */
char **copy_array(char const **words, int nb_words, int index_to_skip)
{
	int k, index = 0;
	char **remaining_words = malloc((nb_words - 1) * sizeof(char *));

	for (k = 0; k < nb_words - 1; k++)
	{
		if (k == index_to_skip)
			index = 1;
		remaining_words[k] = strdup(words[k + index]);
	}

	return (remaining_words);
}

/**
 * free_array - free an array of strings.
 * @words: The original array of strings.
 * @nb_words: The number of strings in the array.
 *
 * Return: nothing
 */
void free_array(char **words, int nb_words)
{
	int i;

	for (i = 0; i < nb_words; i++)
		free(words[i]);
	free(words);
}

/**
 * continue_words - Recursively checks if a string contains words in any order.
 * @s: The string to check.
 * @words: The array of words to find.
 * @nb_words: The number of words to check.
 *
 * Return: 1 if the string contains all words in any order, otherwise 0.
 */
int continue_words(char const *s, char const **words, int nb_words)
{
	int j, lengh;
	char **words2;

	if (nb_words == 0)
		return (1);

	for (j = 0; j != nb_words; j++)
	{
		lengh = strlen(words[j]);
		if (strncmp(s, words[j], lengh) == 0)
		{
			words2 = copy_array(words, nb_words, j);
			if (continue_words(&s[lengh], (char const **) words2, nb_words - 1))
			{
				free_array(words2, nb_words - 1);
				return (1);
			}
			free_array(words2, nb_words - 1);
		}
	}
	return (0);
}

/**
 * find_substring - Finds start of substrings containing words in any order.
 * @s: The string to search in.
 * @words: The array of words to find.
 * @nb_words: The number of words in the array.
 * @n: Pointer to the number of matches found.
 *
 * Return: An array of starting indices of substrings, or NULL if none found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i;
	int *indices = NULL;

	*n = 0;
	for (i = 0; s[i] != '\0'; i++)
		if (continue_words(&s[i], words, nb_words))
		{
			indices = realloc(indices, ((*n + 1) * sizeof(int)));
			indices[*n] = i;
			(*n)++;
		}
	return (indices);
}



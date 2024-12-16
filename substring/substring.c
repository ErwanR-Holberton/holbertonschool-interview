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
char const **copy_array(char const **words, int nb_words, int index_to_skip)
{
	int k, index = 0;
	char const **remaining_words = malloc((nb_words - 1) * sizeof(char *));

	for (k = 0; k < nb_words - 1; k++)
	{
		if (k == index_to_skip)
			index = 1;
		remaining_words[k] = strdup(words[k + index]);
	}

	return (remaining_words);
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
	int j, word_len;
	char const **remaining_words;

	if (nb_words == 0)
		return (1);

	for (j = 0; j != nb_words; j++)
	{
		word_len = strlen(words[j]);
		if (strncmp(s, words[j], word_len) == 0)
		{
			remaining_words = copy_array(words, nb_words, j);
			if (continue_words(&s[word_len], remaining_words, nb_words - 1))
				return (1);
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



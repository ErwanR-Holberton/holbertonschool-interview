#include "regex.h"

/**
 * regex_match - Checks if a string matches a given regular expression pattern.
 * @str: The string to be checked.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the string matches the pattern, otherwise 0.
 *
 * Description:
 * - The pattern may include:
 *		'.' which matches any single character.
 *		'*' which matches zero or more of the preceding element.
 * - If the pattern or string is NULL, it is considered a non-match.
 */
int regex_match(char const *str, char const *pattern)
{
	if (str == NULL || pattern == NULL)
		return (0);

	if (pattern[0] != '.' && pattern[1] != '*' && str[0] != pattern[0])
		return (0);

	if (str[0] == '\0' && pattern[0] == '\0')
		return (1);

	if (pattern[0] == '.' && str[0] == '\0')
		return (0);

	if (pattern[0] == '.' && pattern[1] != '*')
		return (regex_match(&str[1], &pattern[1]));

	if (pattern[0] == '.' && pattern[1] == '*')
		return (regex_match(&str[1], &pattern[0]) ||
			regex_match(&str[1], &pattern[2]) ||
			regex_match(&str[0], &pattern[2]));

	if (str[0] == pattern[0] && pattern[1] != '*')
		return (regex_match(&str[1], &pattern[1]));

	if (str[0] == pattern[0] && pattern[1] == '*')
		return (regex_match(&str[0], &pattern[2]) ||
			regex_match(&str[1], &pattern[2]) ||
			regex_match(&str[1], &pattern[0]));

	if (str[0] != pattern[0])
		return (regex_match(&str[0], &pattern[2]));

	return (0);
}

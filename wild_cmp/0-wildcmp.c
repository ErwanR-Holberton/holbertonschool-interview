#include "holberton.h"
#include <stdio.h>
/**
 * wildcmp - Compares two strings considering wildcard '*'.
 * @s1: The first string.
 * @s2: The second string, which may contain the wildcard '*'.
 *
 * Return: 1 if the strings can be considered identical, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	if (s1[0] == '\0' && s2[0] != '*')
		return (0);
	if (s1[0] == s2[0])
		return (wildcmp(&s1[1], &s2[1]));
	if (s2[0] != '*')
		return (0);
	if (s1[0] == '\0')
		return (wildcmp(&s1[0], &s2[1]));
	return (wildcmp(&s1[1], &s2[0]) || wildcmp(&s1[0], &s2[1]));
}
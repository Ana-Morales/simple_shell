#include "holberton.h"

/**
* str_concat - concatenates two strings
* @s1: string 1
* @s2: string 2 to concatenate to s1
*
* Return: Pointer to newly allocated space in mem with s1 + s2
*/
char *str_concat(char *s1, char *s2)
{
	char *conc;
	unsigned int len1 = 0, len2 = 0, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
	{
		len1++;
	}
	while (s2[len2] != '\0')
	{
		len2++;
	}
	conc = malloc(sizeof(char) * (len1 + (len2 + 1)));
	if (conc == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		conc[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		conc[len1] = s2[i];
		i++;
		len1++;
	}
	return (conc);
	free(conc);
}
/**
 * _strlen - returns the length of a string
 * @s: string to get its length
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int i, len;

	i = 0;
	while (s[i] != '\0')
	{
		len = i + 1;
		i++;
	}
	return (len);
}
/**
 * _strcmp - compares two strings.
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if s1 == s2, pos if s1 < s2, neg if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0')
			return (0);
	}
	return (*s1 - *s2);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *           which contains a copy of the string given as a parameter.
 * @str: string to copy
 *
 * Return: Pointer to newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		s[i] = str[i];
		i++;
		len--;
	}
	return (s);
}

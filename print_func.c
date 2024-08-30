#include "shell.h"

/**
 * _strdup - function will duplicate string
 * @str: input
 * Return: str
 */

char *_strdup(char *str)
{
	char *s = NULL;
	unsigned int size = 0, i;

	if (str == NULL)
		return (NULL);

	while (*(str + size))
		size++;

	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(s + i) = *(str + i);

	*(s + size) = '\0';
	return (s);
}

/**
 * _strcat - function will concatenate a string to another
 * @str1: first string
 * @str2: second string
 * Return: concat
 */

char *_strcat(char *str1, char *str2)
{
	char *dest;
	unsigned int i, j, size;

	/*If the array is empty*/
	if (str1 == NULL)
		str1 = "";

	if (str2 == NULL)
		str2 = "";

	/*count size total*/
	size = (_strlen(str1) + _strlen(str2) + 1);

	/*malloc*/
	dest = (char *) malloc(size * sizeof(char));

	if (dest == 0)
	{
		return (NULL);
	}

	/*Concatenate arrays*/
	for (i = 0; *(str1 + i) != '\0'; i++)
		*(dest + i) = *(str1 + i);

	for (j = 0; *(str2 + j) != '\0'; j++)
	{
		*(dest + i) = *(str2 + j);
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcmp - function compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 on success
 */

int _strcmp(char *str1, char *str2)
{
	int i = 0;
	int def;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			def = (str1[i] - str2[i]);
			break;
		}
		else
			def = 0;
	}
	return (def);
}

/**
 * _strlen - function returns length of a string
 * @str: input string
 * Return: length of the input string
 */

int _strlen(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @str1: copy to
 * @str2: copy from
 * Return: string
 */

char *_strcpy(char *str1, char *str2)
{
	int len = 0;

	while (*(str2 + len) != '\0')
	{
		*(str1 + len) = *(str2 + len);
		len++;
	}

	*(str1 + len) = '\0';
	return (str1);
}

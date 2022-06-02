/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:07:59 by creyt             #+#    #+#             */
/*   Updated: 2021/11/09 10:29:50 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		i;
	int		nbwords;

	i = 0;
	nbwords = 0;
	if (s[i] == c || s[0] == '\0')
		nbwords--;
	while (s[i])
	{
		if (s[i] == c && c != s[i + 1] && s[i + 1] != '\0')
			nbwords++;
		i++;
	}
	if (s[i] == '\0')
		nbwords++;
	return (nbwords);
}

static int	count_letters(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

static void	*malloc_error(char **s, int j)
{
	while (j--)
	{
		free(s[j]);
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	int		count;
	int		letters;
	int		j;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	s2 = malloc(sizeof(char *) * (count + 1));
	if (!s2)
		return (NULL);
	j = 0;
	while (count > j)
	{
		while (*s == c && *s)
			s++;
		letters = count_letters (s, c);
		s2[j] = ft_substr(s, 0, letters);
		if (s2[j] == NULL)
			return (malloc_error(s2, j));
		s = s + letters;
		j++;
	}
	s2[j] = NULL;
	return (s2);
}

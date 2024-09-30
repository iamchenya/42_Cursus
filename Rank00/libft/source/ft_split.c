/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpibool <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 01:45:46 by cpibool           #+#    #+#             */
/*   Updated: 2024/09/14 20:46:00 by cpibool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	cnt_word;
	size_t	in_word;

	i = 0;
	cnt_word = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			cnt_word++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (cnt_word);
}

static void	ft_freesplit(char **str)
{
	size_t	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}

static char	**ft_tosplit(char const *s, char c, char **dest, size_t cnt_word)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			dest[cnt_word++] = ft_strndup(&s[start], i - start);
			if (dest[cnt_word - 1] == NULL)
			{
				ft_freesplit(dest);
				return (NULL);
			}
		}
		else
			i++;
	}
	dest[cnt_word] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	cnt_word;

	cnt_word = 0;
	dest = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (dest == NULL)
		return (NULL);
	ft_tosplit(s, c, dest, cnt_word);
	return (dest);
}

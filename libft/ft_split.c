/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarijo- <agarijo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:22:12 by agarijo-          #+#    #+#             */
/*   Updated: 2022/11/03 19:06:17 by agarijo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words_s(char const *s, char c)
{
	int	counter;
	int	amount;
	int	flag;

	amount = 0;
	counter = 0;
	flag = 0;
	while (*(s + counter))
	{
		if (*(s + counter) != c && flag != 1)
		{
			amount++;
			flag = 1;
		}
		else if (*(s + counter) == c)
			flag = 0;
		counter++;
	}
	return (amount);
}

static int	ft_size_word(const char *word, char c)
{
	int	counter;

	counter = 0;
	while (*(word + counter))
	{
		if (*(word + counter) == c)
			return (counter);
		counter++;
	}
	return (counter);
}

static char	*ft_ins_word(const char *s, int word_counter)
{
	int		counter;
	char	*word;

	counter = 0;
	word = malloc((word_counter + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (word_counter--)
	{
		*(word + counter) = *s++;
		counter++;
	}
	*(word + counter) = '\0';
	return (word);
}

static char	**ft_fill_result_array(char **result_array, const char *s, char c)
{
	int		counter;
	int		flag;
	int		result_array_counter;

	counter = 0;
	flag = 0;
	result_array_counter = 0;
	while (*(s + counter))
	{
		if (*(s + counter) != c && flag != 1)
		{
			*(result_array + result_array_counter) = ft_ins_word((s + counter),
					ft_size_word((s + counter), c));
			result_array_counter++;
			flag = 1;
		}
		else if (*(s + counter) == c)
			flag = 0;
		counter++;
	}
	*(result_array + result_array_counter) = NULL;
	return (result_array);
}

char	**ft_split(char const *s, char c)
{
	char	**result_array;

	result_array = malloc((ft_count_words_s(s, c) + 1) * sizeof(char *));
	if (!result_array)
		return (NULL);
	result_array = ft_fill_result_array(result_array, s, c);
	return (result_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:06:13 by mohtsuji          #+#    #+#             */
/*   Updated: 2021/09/17 14:07:38 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*safe_dup(const char *str)
{
	char	*ans;

	ans = ft_strdup(str);
	if (ans == NULL)
		put_error("Error\n in strdup");
	return (ans);
}
/*
char	*safe_join(const char *s1, const char *s2)
{
	char	*ans;

	if (s1 == NULL && s2 != NULL)
		ans = safe_dup(s2);
	else if (s1 != NULL && s2 == NULL)
		ans = safe_dup(s1);
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	else
	{
		ans = ft_strjoin(s1, s2);
		if (ans == NULL)
			exit(EXIT_FAILURE);
	}
	return (ans);
}

char	*safe_join_no_exit(const char *s1, const char *s2)
{
	char	*ans;

	if (s1 == NULL && s2 != NULL)
		ans = ft_strdup(s2);
	else if (s1 != NULL && s2 == NULL)
		ans = ft_strdup(s1);
	else if (s1 == NULL && s2 == NULL)
		return (NULL);
	else
		ans = ft_strjoin(s1, s2);
	return (ans);
}

char	**safe_split(const char *str, char c)
{
	char	**ans;

	ans = ft_split(str, c);
	if (ans == NULL)
		exit(EXIT_FAILURE);
	return (ans);
}

char	*safe_substr(const char *s, unsigned int start, size_t len)
{
	char	*ans;

	ans = ft_substr(s, start, len);
	if (ans == NULL)
		exit(EXIT_FAILURE);
	return (ans);
}*/

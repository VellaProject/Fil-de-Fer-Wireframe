/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:19:28 by avella            #+#    #+#             */
/*   Updated: 2016/02/03 16:21:12 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*ft_join(char const *s1, char const *s2, int len1, int len2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (len1 + len2) + 1);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char			*ft_strjoins(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = ft_join(s1, s2, len1, len2);
	return (join);
}

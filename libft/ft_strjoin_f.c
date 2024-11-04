/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:21:04 by lpetit            #+#    #+#             */
/*   Updated: 2024/10/10 13:52:40 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*jstr;
	size_t	i;
	size_t	w;

	i = -1;
	w = 0;
	if (!s1 || !s2)
		return (NULL);
	jstr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!jstr)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
		while (s1[++i])
			jstr[i] = s1[i];
	if (s2)
		while (s2[w])
			jstr[i++] = s2[w++];
	jstr[i] = '\0';
	free(s1);
	free(s2);
	return (jstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeklik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:57:06 by bkeklik           #+#    #+#             */
/*   Updated: 2022/06/27 14:32:54 by bkeklik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *buff)
{
	size_t	j;
	size_t	i;
	char	*collect;

	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	collect = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (collect == NULL)
		return (NULL);
	j = -1;
	i = 0;
	if (str)
		while (str[++j] != '\0')
			collect[j] = str[j];
	while (buff[i] != '\0')
		collect[j++] = buff[i++];
	collect[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free (str);
	return (collect);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-cor <adel-cor@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 09:39:47 by adel-cor          #+#    #+#             */
/*   Updated: 2021/07/12 09:40:16 by adel-cor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*join_str(const char *s1, const char *s2)
{	
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*temp;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	temp = (char *)ft_calloc(1, stot_len);
	if (!temp)
		return (0);
	ft_memmove(temp, s1, s1_len);
	ft_memmove(temp + s1_len, s2, s2_len);
	temp[stot_len - 1] = '\0';
	free((char *)s1);
	return (temp);
}

void	*ft_calloc(size_t n, size_t s)
{
	void	*str;
	size_t	i;

	i = n * s;
	str = (void *)malloc(i * sizeof (*str));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_memset(str, 0, i);
	return (str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

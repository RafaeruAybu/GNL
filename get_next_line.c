/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igearhea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 10:35:10 by igearhea          #+#    #+#             */
/*   Updated: 2021/01/21 10:35:11 by igearhea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	general_size;
	char	*ptr;
	char	*save_ptr;

	if (!s1 || !s2)
		return (0);
	general_size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(general_size + 1);
	if (!ptr)
		return (ptr);
	save_ptr = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (save_ptr);
}

void		*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			count;

	count = 0;
	ptr = dst;
	if (n != 0)
	{
		while (count < n)
		{
			*ptr = (unsigned char)c;
			ptr++;
			count++;
		}
	}
	return (dst);
}

int			ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

int			check_remain(char **remain, char **line)
{
	char *n_p;
	char *temp;

	if (*remain && (n_p = ft_strchr(*remain, '\n')))
	{
		*n_p = '\0';
		*line = ft_strdup(*remain);
		temp = *remain;
		*remain = ft_strdup(++n_p);
		free(temp);
		return (1);
	}
	else if (*remain && (n_p = ft_strchr(*remain, '\0')))
	{
		*line = ft_strdup(*remain);
		free(*remain);
		*remain = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	unsigned long long	rbyte;
	char				*bf;
	static char			*remain;
	char				*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, "", 0) < 0))
		return (-1);
	if (!(bf = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)))))
		return (-1);
	remain == NULL ? remain = ft_memalloc((1) * sizeof(char)) : NULL;
	while ((!ft_strchr(remain, '\n')) &&
								((rbyte = read(fd, bf, BUFFER_SIZE)) > 0))
	{
		bf[rbyte] = '\0';
		if (!remain)
			remain = ft_strdup(bf);
		else
		{
			tmp = remain;
			remain = ft_strjoin(remain, bf);
			ft_memdel((void **)&tmp);
		}
	}
	free(bf);
	return (check_remain(&remain, line));
}

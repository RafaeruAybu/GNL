#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_memalloc(size_t size);
size_t		ft_strlen(const char *string);
int			ft_memdel(void **ptr);
void		*ft_memset(void *dst, int c, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);

#endif

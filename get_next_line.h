#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char	*ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t  ft_strlen(const char *s);
#endif

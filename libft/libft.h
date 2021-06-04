/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:17:12 by jekim             #+#    #+#             */
/*   Updated: 2021/05/30 03:24:18 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 128
# define OPEN_MAX 256

/*
** list struct
*/
typedef struct		s_list
{
	void			*content;
	struct	s_list	*next;
}					t_list;

/*
** is* functions
*/
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

/*
** put*_fd functions
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

/*
** type conversion functions
*/
char				*ft_itoa(int n);
int					ft_atoi(const char *nptr);

/*
** memory management functions
*/
void				ft_bzero(void *dst, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s);

/*
** mem*.c functions
*/
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *dst, int c, size_t n);
void				*ft_realloc(void *src, size_t size);
void				*ft_scalloc(size_t count, size_t size);

/*
** str*.c functions
*/
char				**ft_split(const char *src, char c);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *src);
char				*ft_strmapi(const char *src, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *src, unsigned int start, size_t len);
int					ft_strerr(char *err);
char				*ft_strnew(char *str, size_t strlen);

/*
** list struct functions
*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));

#endif

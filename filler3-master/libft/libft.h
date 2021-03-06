/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 08:44:57 by egreen            #+#    #+#             */
/*   Updated: 2017/10/06 09:53:41 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s1, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strrchr(const char *s1, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_strtrimc(char **s, char c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_intlen(int value);
int					ft_ispunct(int c);
void				ft_swap(int *a, int *b);
int					ft_isupper(int c);
int					get_next_line(const int fd, char **line);
char				*ft_strfjoin(char *s1, char *s2);
void				ft_fputstr_fd(char *str, int fd);
// char				*ft_strfjoin(char *s1, char *s2);
// int					ft_printf(const char *format, ...);
// char				*ft_ptf_itoabase(uintmax_t val, int base, int opt);
// void				hex_helper(t_format *form, t_spec *ts);
// void				hex_helper2(t_format *form, t_spec *ts);
// int					ft_isflag(char test);
// int					ft_islgth(char c);
// int					flags(t_spec *ts, char *format);
// void				format_wstring(t_print *ptr, t_spec *ts);
// void				format_udecimal(t_print *ptr, t_spec *ts);
// void				format_string(t_print *ptr, t_spec *ts);
// void				format_pointer(t_print *ptr, t_spec *ts);
// void				format_decimal(t_print *ptr, t_spec *ts);
// void				hex_print(t_spec *ts, char print, int times);
// void				format_hex(t_print *ptr, t_spec *ts);
// void				format_octal(t_print *ptr, t_spec *ts);
// void				format_percent(t_spec *ts);
// void				format_char(t_print *ptr, t_spec *ts);
// int					find_flags(t_spec *ts, char *format, int *x);
// void				form_dec_helper(t_format *form, t_spec *ts);
// void				unsigned_casting(t_print *ptr, t_spec *ts);
// void				casting(t_print *ptr, t_spec *ts);

#endif

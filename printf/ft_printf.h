/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtsuji <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 01:12:32 by mohtsuji          #+#    #+#             */
/*   Updated: 2020/08/19 20:28:34 by mohtsuji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_sign
{
	char		*str;
	int			count;
	int			zero;
	int			mi;
	int			pre;
	int			p;
	int			width;
	int			w;
	int			x;
	int			neg;
}				t_sign;

int				ft_printf(const char *fmt, ...);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
t_sign			*di_out(t_sign *sign, va_list ap);
void			put_space(t_sign *sign);
t_sign			*c_out(t_sign *sign, va_list ap);
int				ft_atoi(char **str);
t_sign			*s_out(t_sign *sign, va_list ap);
void			put_char(t_sign *sign, char **tmp);
void			put_mi(t_sign *sign, char **tmp);
t_sign			*u_out(t_sign *sign, va_list ap);
t_sign			*pa_out(t_sign *sign);
t_sign			*x_hontai(t_sign *sign, char *tmp, int size);
t_sign			*x_out(t_sign *sign, va_list ap);
t_sign			*p_hontai(t_sign *sign, char *tmp, int size);
t_sign			*p_out(t_sign *sign, va_list ap);
void			put_zero(t_sign *sign);
t_sign			*ft_clean(t_sign *sign);
t_sign			*di_hontai(t_sign *sign, char *tmp, int size);
t_sign			*u_hontai(t_sign *sign, char *tmp, int size);

#endif

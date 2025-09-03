/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:48:42 by sunlee            #+#    #+#             */
/*   Updated: 2025/07/06 16:48:45 by sunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>  // 가변 인자 함수 처리용
# include <unistd.h>  // write() 사용을 위해 필요
# include <stdlib.h>  // malloc(), free() 사용을 위해 필요

// 메인 함수
int	ft_printf(const char *format, ...);

// 유틸 함수들
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex(unsigned int n, int uppercase);
int	ft_putptr(void *ptr);
int	ft_puthex_ulong(unsigned long long n);

#endif

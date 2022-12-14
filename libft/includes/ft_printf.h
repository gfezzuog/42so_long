/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:41:58 by gfezzuog          #+#    #+#             */
/*   Updated: 2022/10/14 12:42:37 by gfezzuog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const	char *string, ...);
int	ft_putchar(char c);
int	ft_putstr(char *string);
int	ft_print_ptr(unsigned long address, char *hex_vocabulary);
int	ft_print_address(unsigned long address, char *hex_vocabulary);
int	ft_print_int(int number);
int	ft_print_u_int(unsigned int number);
int	ft_print_num_hex(unsigned int hex_number, char *hex_vocabulary);

#endif

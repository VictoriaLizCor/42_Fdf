/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_util.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 00:42:20 by jaeskim           #+#    #+#             */
/*   Updated: 2020/11/17 05:27:36 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DTOA_UTIL_H
# define FT_DTOA_UTIL_H

# include "ft_dtoa_type.h"

char	*ft_dtoa_f(union u_double n, int precision);
char	*ft_dtoa_e(union u_double n, int precision);
char	*ft_dtoa_g(union u_double n, int precision);

void	ft_dtoa_e_round(
			char *integer,
			char *decimal,
			int *integer_len,
			int precision);

int		ft_dtoa_ut_check_round(
			int c,
			char *decimal,
			int precision,
			int is_e_integer_zero);
void	ft_dta_ut_int_reverse(char *a, int a_len);
int		ft_dtoa_ut_get_decimal_start(char *decimal);

void	ft_dtoa_setup_decimal(union u_double n, char *decimal);
int		ft_dtoa_setup_integer(union u_double n, char *integer);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loribeir <loribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 11:08:20 by loribeir          #+#    #+#             */
/*   Updated: 2024/11/24 15:09:24 by loribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *specifier, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, specifier);
	i = 0;
	count = 0;
	while (specifier[i])
	{
		if (specifier[i] == '%')
			check_specifier(args, specifier[++i], &count);
		else
		{
			write(1, &specifier[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	check_specifier(va_list args, char spec, int *count)
{
	if (spec == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (spec == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (spec == 'p')
		ft_print_ptr(va_arg(args, unsigned long), count);
	else if (spec == 'd' || spec == 'i')
		ft_print_decimal(va_arg(args, int), count);
	else if (spec == 'u')
		ft_print_unsigned_dec(va_arg(args, unsigned int), count);
	else if (spec == 'x')
		ft_print_lower_hex(va_arg(args, int), count);
	else if (spec == 'X')
		ft_print_upper_hex(va_arg(args, int), count);
	else if (spec == '%')
		ft_print_sign(count);
	return (*count);
}
/*int main(void)
{
	int	num = 0;
	void *ptr = &num;
	
	printf("size : %d \n", ft_printf("%p", ptr));
	printf("size : %d \n", printf("%p", ptr));
}*/
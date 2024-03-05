/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redrouic <redrouic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:11:55 by redrouic          #+#    #+#             */
/*   Updated: 2024/03/05 18:04:14 by redrouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../icl/minitalk.h"

int my_strlen(char *str)
{
    int len = 0;

    while (*str) {
        str++;
        len++;
    }
    return (len);
}

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s2[i] != s1[i]) {
            return (0);   
        }
    }
    return (1);
}

void my_swap(char *c1, char *c2)
{
    char tmp;

    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void my_strrev(char *str)
{
    int size = my_strlen(str);
    int half = size / 2;
    int y = size - 1;
    
    for (int i = 0; i < half; i++) {
        my_swap(&str[i], &str[y]);
        y--;
    }
}

int my_itoa(int n, char *str, int base)
{
    int rem = 0;
    int i = 0;
    int neg = 0;

    if (n == 0) {
        str[0] = '0';
        str[1] = '\0';
        return 0;
    }
    if (n < 0) {
        n = -n;
        neg = 1;
    }
    while (n != 0) { 
        rem = n % base;
        str[i++] = rem + '0';
        n = n / base;
    }
    if (neg == 1)
       str[i++] = '-'; 
    str[i] = '\0';
    my_strrev(str);
    return 0; 
}

char *my_strconc(char *s1, char *s2)
{
    int tsize = my_strlen(s1) + my_strlen(s2);
    char *str = malloc(sizeof(char) * tsize + 1);
    int w = 0;
    int i = 0;

    for ( ; i < tsize; i++) {
        if (i < my_strlen(s1))
            str[i] = s1[i];
        else {
            str[i] = s2[w];
            w++;
        }
    }
    str[++i] = '\0';
    return str;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

long long int	ft_atoi(const char *nptr)
{
	long long int	b;
	int				sign;

	b = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		b = b * 10 + (*nptr - 48);
		nptr++;
	}
	return (b * sign);
}


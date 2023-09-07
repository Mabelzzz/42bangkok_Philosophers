/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araiva <tsomsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:31:34 by araiva            #+#    #+#             */
/*   Updated: 2022/10/06 18:31:35 by araiva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	ft_isdigit(char c);

int	ft_atoi(const char *nb)
{
	int	prefix;
	int	number;

	number = 0;
	if (*nb == '\0' || *nb == '\e')
		return (0);
	while (*nb <= 32)
		nb++;
	if (*nb == '-')
		prefix = -1;
	else
		prefix = 1;
	if (*nb == '-' || *nb == '+')
		nb++;
	while (ft_isdigit(*nb))
		number = (number * 10) + (*nb++ - '0');
	return (prefix * number);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

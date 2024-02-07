/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baarif <baarif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:58:04 by baarif            #+#    #+#             */
/*   Updated: 2024/02/06 08:59:38 by baarif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

void	my_handler(int num, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;

	(void)context;
	if (SIGUSR1 == num || SIGUSR2 == num)
	{
		c |= (num == SIGUSR2);
		if (++i == 8)
		{
			i = 0;
			if (c == '\0')
			{
				kill(info->si_pid, SIGUSR1);
				write(1, "\n", 1);
				return ;
			}
			write(1, &c, 1);
			c = 0;
		}
		else
			c <<= 1;
	}
}

int	main(void)
{
	struct sigaction	sig_class;

	ft_printf("%u\n", getpid());
	sig_class.sa_sigaction = my_handler;
	sig_class.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_class, 0);
	sigaction(SIGUSR2, &sig_class, 0);
	while (1)
	{
	}
	return (0);
}

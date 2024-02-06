#include "ft_printf/ft_printf.h"
#include <signal.h>
void fire_handler(size_t pid, char c)
{
	int i;

	i = 8;
	while (i--)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void receive_handler(int num)
{
	if (num == SIGUSR1)
		ft_printf("Acknowledged\n");
}

int main(int ac, char *av[])
{	
	size_t	 pid;
	char	*string;
	int	i;

	if (ac !=3)
		return (ft_printf("Can only accept 3 arguments\n"),0);
	i = 0;
	pid =  atoi(av[1]);
	if ((pid > 500000) | !pid)
		return (ft_printf("Invalid PID range\n"),0);
	string = av[2];
	signal(SIGUSR1,receive_handler);
	while (string[i])
	{
		fire_handler(pid, string[i]);
		i++;
	}
	fire_handler(pid, string[i]);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpac <vpac@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:33:42 by vpac              #+#    #+#             */
/*   Updated: 2022/12/28 12:44:45 by vpac             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_strjoin_force(char *s1, char s2)
{
	char	*res;
	int		i;

	if (!s1)
		return (ft_strdup(&s2));
	res = malloc(ft_strlen(s1) + 2);
	if (!res)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i++] = s2;
	res[i] = 0;
	free(s1);
	return (res);
}

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;
	static char	*buf;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit ++;
	if (bit == 8)
	{
		buf = ft_strjoin_force(buf, i);
		bit = 0;
		if (i == '\0')
		{
			ft_printf("%s", buf);
			free(buf);
			buf = 0;
		}
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong format");
		return (0);
	}
	pid = getpid();
	ft_printf("PID -> %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}

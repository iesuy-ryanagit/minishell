/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmotoyam <kmotoyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:59:42 by ryanagit          #+#    #+#             */
/*   Updated: 2024/02/20 15:41:16 by kmotoyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"built.h"

size_t	len_command(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	check_flag_nopution(char *str)
{
	if (ft_strncmp(str, "-n", 3))
		return ((size_t)0);
	else
		return ((size_t)1);
}

void	built_echo(int fd, char **str)
{
	size_t		i;
	size_t		flag;

	if (len_command(str) == 1)
	{
		write(fd, "\n", 1);
		return ;
	}
	flag = check_flag_nopution(str[1]);
	i = flag + 1;
	while (str[i])
	{
		if (i > flag + 1)
			write(fd, " ", 1);
		ft_putstr_fd(str[i], fd);
		i++;
	}
	if (flag == 0)
		write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char *str[]={"echo",NULL};
// 	echo(STDIN_FILENO,str);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egreen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:18:49 by egreen            #+#    #+#             */
/*   Updated: 2017/12/01 16:18:54 by egreen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/nfs/2017/e/egreen/Desktop/restruct/libft/libft.h"

void	ft_fputstr_fd(char *str, int fd)
{
	int x;

	x = -1;
	while (str[++x] != '\0')
		;
	write(fd, str, x);
}

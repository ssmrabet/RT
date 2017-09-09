/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:59:40 by smrabet           #+#    #+#             */
/*   Updated: 2017/09/09 16:32:05 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int			verif_input(char *file)
{
	char	buf[6];
	FILE	*fp;
	int		len;

	len = ft_strlen(file);
	if (strcmp(file + len - 3, ".rt"))
		return (0);
	if (!(fp = fopen(file, "r")) || !fread(buf, 1, 5, fp))
		return (0);
	buf[5] = '\0';
	if (ft_strcmp(buf, "scene") != 0)
		return (0);
	fclose(fp);
	return (1);
}

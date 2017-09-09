/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:13:41 by smrabet           #+#    #+#             */
/*   Updated: 2017/09/05 15:47:18 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		verif(t_color col)
{
	ft_clamp(col.red, 0.0, 255.0);
	ft_clamp(col.green, 0.0, 255.0);
	ft_clamp(col.blue, 0.0, 255.0);
}

static void		ft_sepia(t_obj *tmp)
{
	while (tmp)
	{
		tmp->col.red = 0.393 * tmp->col.red + 0.769 *
			tmp->col.green + 0.189 * tmp->col.blue;
		tmp->col.green = 0.349 * tmp->col.red + 0.686 *
			tmp->col.green + 0.168 * tmp->col.blue;
		tmp->col.blue = 0.272 * tmp->col.red + 0.534 *
			tmp->col.green + 0.131 * tmp->col.blue;
		verif(tmp->col);
		tmp = tmp->next;
	}
}

static void		ft_grayscale(t_obj *tmp)
{
	float		gray;

	while (tmp)
	{
		gray = (tmp->col.red + tmp->col.green + tmp->col.blue) / 3;
		tmp->col.red = gray;
		tmp->col.green = gray;
		tmp->col.blue = gray;
		verif(tmp->col);
		tmp = tmp->next;
	}
}

static void		ft_negatif(t_obj *tmp)
{
	while (tmp)
	{
		if (!tmp->type)
			while (tmp && (tmp->col.red == tmp->col.green
						&& tmp->col.green == tmp->col.blue))
				tmp = tmp->next;
		if (tmp)
		{
			tmp->col.red = 255 - tmp->col.red;
			tmp->col.green = 255 - tmp->col.green;
			tmp->col.blue = 255 - tmp->col.blue;
			verif(tmp->col);
			tmp = tmp->next;
		}
	}
}

int				ft_key_color(t_mlx *mlx)
{
	t_obj		*tmp;
	t_obj		*tmp_light;

	tmp = mlx->obj;
	tmp_light = mlx->light;
	if (mlx->type_color == 2)
	{
		ft_grayscale(tmp);
		ft_grayscale(tmp_light);
	}
	else if (mlx->type_color == 0)
	{
		ft_negatif(tmp);
		ft_negatif(tmp_light);
	}
	else if (mlx->type_color == 1)
	{
		ft_sepia(tmp);
		ft_sepia(tmp_light);
	}
	if (mlx->type_color < 3)
		mlx->type_color++;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_attr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:40:30 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:48:06 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_ATTR_H
# define GET_ATTR_H

typedef struct s_lst			t_lst;
typedef struct s_matrix_list	t_mlst;
typedef struct s_data			t_data;

int								get_attr(t_mlst *mlst, t_data *data);
int								set_ceiling_floor(t_lst *lst, t_data *data);
int								set_path_texture(t_lst *lst, t_data *data);

#endif
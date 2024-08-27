/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:57:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 17:42:58 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
 #define PARSE_H

struct t_data;
typedef struct s_matrix_list t_mlst;

t_data	*parse(int argc, char **argv);
t_mlst	*get_file(char *file);
int		get_texture_in_file(t_mlst *mlst, t_data *data);
int		get_ceiling_floor(t_mlst *mlst, t_data *data);

#endif
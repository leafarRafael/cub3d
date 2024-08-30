/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:57:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 08:20:37 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
 #define PARSE_H

typedef struct s_matrix_list t_mlst;
typedef struct s_data t_data;

void	valid_arguments(int argc, char **argv);
t_data	*parse(int argc, char **argv);
t_mlst	*read_file(char *file);

#endif
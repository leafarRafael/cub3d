/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 11:57:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
 #define PARSE_H

typedef struct s_matrix_list t_mlst;
struct t_data;

void	valid_arguments(int argc, char **argv);
t_data	*parse(int argc, char **argv);
t_mlst	*read_file(char *file);

#endif
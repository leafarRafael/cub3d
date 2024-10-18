/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:39:13 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:48:49 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

typedef struct s_matrix_list	t_mlst;

t_mlst							*read_file(char *file);

#endif
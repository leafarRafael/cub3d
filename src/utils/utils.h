/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:15:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/30 10:03:07 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
 #define UTILS_H

int	ft_color(int r, int g, int b, int a);
int	error_handler(char *s1, char *s2, char *s3, char *s4);
int is_new_line(char c);
int is_space_tab(int c);

#endif
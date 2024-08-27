/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:45:48 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/27 10:43:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERROR_H
 #define ERROR_H

enum e_parser_errors {
	E_OK,
	E_ARG_INVNUM,
	E_ARG_INVEXT,
	E_FILE_ISDIR,
	E_FILE_FAILOPEN,
	E_FILE_EMPTY,
	E_IDENT_INV,
	E_IDENT_DUP,
	E_IDENT_EMPTY_CONTENT,
	E_RGB_INVAMOUNT,
	E_RGB_DIGIT,
	E_RGB_INVRANGE,
	E_MEM_RGB_MATRIX,
	E_MEM_RGB_STRING,
	E_MAP_EMPTY_LINE,
	E_MAP_INV_ELEM,
	E_NOT_FOUND,
	E_BAD_PERMISSION
};

const char	*msg_error(int error);
int			error_handler(const char *s1, const char *s2, const char *s3, const char *s4);

#endif
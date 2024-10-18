/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:41:59 by rbutzke           #+#    #+#             */
/*   Updated: 2024/09/04 11:08:05 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# define E_F_R_F "Fail to read file\n"
# define E_INDEN "Invalid indentifier\n"
# define E_RGB "Invalid color\n"
# define E_ARGS "Invalid arguments\n"
# define E_INVALID_MAP "Invalid map\n"
# define E_MEM "Memory error\n"
# define E_MLX "Instances png, window or image\n"
# define NBR_MSG 8

typedef struct s_data	t_data;

/**
 * @brief Manages error messages
 *
 * This function handles error messages by returning the status value
 * and writing the corresponding message to the standard error output.
 *
 * @param e_error Status and index of the error message.
 *
 * @return int The termination status of the program.
 *
 * Function overview:
 *
 * - If e_error is 0,
 *    the function returns immediately without printing anything.
 *
 * - If errno is set (indicating an error occurred),
 *   the corresponding error string is printed
 *   and the function returns errno.
 *
 * - In other cases,
 *   e_error represents the program's exit status and is used as an index
 *
 * to retrieve and print the appropriate error message from a predefined array.
 *
 * - The function calls destroy_data to free any allocated resources.
 */
int						error_handler(int e_error);

/**
 * @brief Frees all memory allocated for program execution.
 *
 * The function handles heap memory release.
 * It checks that the pointer has been 
 * allocated and calls the memory release function.
 *
 * @param data A pointer to the main game data structure (t_data).
 *
 * @return int Returns 0 for all cases for convenience
 *
 * Function overview:
 *	- ft_free():
 *    Checks for a null pointer before invoking the free function.
 *    After freeing, the pointer is set to NULL.
 * 
 * 	- All other pointers are checked,
 *    and their respective release functions are called.
 *
 * 	- Functions prefixed with `MLX` handle the
 * 	  release of resources related to the MLX library.
 * 
 * 	- ft_delcmtrx() frees the memory of a 2D matrix.
 * 
 *	- ft_delete_matrix() frees memory associated with a linked list.
 */
int						destroy_data(t_data *data);

typedef enum s_error
{
	E_OK = 0,
	E_ARGUMENTS,
	E_MEMORY,
	E_READ,
	E_IDENTIFIER,
	E_MAP,
	E_COLOR,
	E_MLX42,
	E_EMPYT,
}						t_error;

#endif
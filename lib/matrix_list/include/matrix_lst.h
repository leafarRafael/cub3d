/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:34:14 by rbutzke           #+#    #+#             */
/*   Updated: 2024/08/23 14:51:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_LST_H
# define MATRIX_LST_H

# include "array_lst.h"
# include <stdlib.h>

typedef struct s_lst_line
{
	t_lst				*lst;
	struct s_lst_line	*next;
	struct s_lst_line	*prev;
}						t_llst;

typedef struct s_matrix_list
{
	t_llst				*head;
	t_llst				*last;
	int					size;
}						t_mlst;

typedef struct s_variables_matrix_list
{
	t_llst				*current_lst;
	t_llst				*second_lst;
	t_llst				*prev_lst;
	t_llst				*next_lst;
	t_llst				*head_lst;
	t_llst				*last_lst;
	t_node				*node;
	char				**matrix;
	int					i;
	int					index;
	int					i_m;
	int					i_l;
	int					size;

}						t_var_matrix;

t_mlst					*init_mlst(void);
t_llst					*ft_init_line_lst(void);
int						ft_add_list_front(t_mlst *matrix_lst, t_lst *lst);
int						ft_add_list_back(t_mlst *matrix_lst, t_lst *lst);
int						ft_rmv_spcfc_lst_mtrx(t_mlst *matrix, t_llst *line_lst);
int						ft_remove_lst_front(t_mlst *m_lst);
int						ft_remove_list_back(t_mlst *m_lst);
int						ft_delete_matrix(t_mlst *matrix);
char					**ft_cpy_mtrllst_to_cmtrx(t_mlst *lst_matrix);
t_mlst					*ft_cmtrix_to_mtrx_lst(char **matrix);
t_lst					*find_str_in_matrixlst(t_mlst *m_lst, char *str,
							int size);
int						insert_lnode_between(t_mlst *mlst, t_llst *lnode,
							t_mlst *new_mlst);
t_llst					*mlst_rmv_return_lnode(t_mlst *mlst, t_llst *lnode);
int						ft_add_mlstnode_back(t_mlst *mlst, t_llst *lnode);
int						ft_add_mlstnode_front(t_mlst *mlst, t_llst *lnode);
int						add_lexicographic_value(t_mlst *mlst, char limiter);
t_mlst					*ft_bubble_sort(t_mlst *mlst);

#endif
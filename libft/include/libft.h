/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atalaver <atalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:48:42 by jahernan          #+#    #+#             */
/*   Updated: 2023/03/27 17:22:53 by atalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>

char	*ft_strcpy_range(char *str, int i, int j);
int		ft_isspace(char c);
int		ft_strlen(char *str);
int		ft_min(int a, int b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
#endif

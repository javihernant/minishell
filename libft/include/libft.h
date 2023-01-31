/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahernan <jahernan@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:48:42 by jahernan          #+#    #+#             */
/*   Updated: 2023/01/31 13:34:02 by jahernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>

char	*ft_strcpy_range(char *str, int i, int j);
int		ft_isspace(char c);
int		ft_strlen(char *str);
int		ft_min(int a, int b);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
#endif

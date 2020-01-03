/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:15:42 by clbergon          #+#    #+#             */
/*   Updated: 2019/12/12 17:16:07 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUF_H
# define FT_BUF_H

# include "ft_mem.h"
# include "utils.h"

# define DEFAULT_CAPACITY 8

typedef struct s_buf	t_buf;

struct					s_buf
{
	char	*content;
	size_t	len;
	size_t	capacity;
};

t_buf					*buf_new(void);
t_buf					*buf_new_with_size(size_t size);
int						buf_grow(t_buf *buf);
int						buf_grow_with_size(t_buf *buf, size_t size);
int						buf_push(t_buf *buf, const char *s, const size_t len);
int						buf_push_one(t_buf *buf, const char c);
int						buf_push_d(t_buf *buf, long long d, size_t n);
int						buf_push_base(t_buf *buf, unsigned long long ull,
										size_t n, char *base);
int						buf_push_n(t_buf *buf, const char c, size_t n);
void					buf_free(t_buf **buf);

#endif

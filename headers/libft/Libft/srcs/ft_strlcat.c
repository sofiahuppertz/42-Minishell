/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuppert <shuppert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:52:03 by shuppert          #+#    #+#             */
/*   Updated: 2023/05/10 16:31:57 by shuppert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t	dstlen = ft_strlen(dst);
    size_t	srclen = ft_strlen(src);

    if (dstlen >= size)
        return (size + srclen);
    if (srclen < size - dstlen)
        ft_memcpy(dst + dstlen, src, srclen + 1);
    else
    {
        ft_memcpy(dst + dstlen, src, size - dstlen - 1);
        dst[size - 1] = '\0';
    }
    return (dstlen + srclen);
}
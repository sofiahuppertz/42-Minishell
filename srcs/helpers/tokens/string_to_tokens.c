
#include "../../../headers/minishell.h"

int	split_string_cur_cmdl(t_cmd_line **simple_cmd)
{
	int		cur;
	int		start;
	int		len;

	cur = 0;
	len = 0;
	if ((*simple_cmd)->string)
		len = ft_strlen((*simple_cmd)->string);
	while (cur < len)
	{
		ft_add_while_true(&cur, (*simple_cmd)->string, &ft_iswhitespace);
		start = cur;
        get_token_length(&cur, (*simple_cmd)->string);

		if ((*simple_cmd)->string[cur] && is_redirection((*simple_cmd)->string[cur]))
			iter_to_end_or_redirection((*simple_cmd)->string, &cur);
		else
		{
			iter_to_end_arg(&cur, (*simple_cmd)->string);
		}
		if (create_add_back_token(cur, start, (*simple_cmd)->string, simple_cmd) > 0)
			return (50);
	}
	return (0);
}
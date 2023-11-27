
#include "../../../headers/minishell.h"

void delete_tokens(t_token *head)
{
    t_token *temp;

    while (head)
    {
        temp = head;           
        head = head->next; 
        ft_memdel(temp);     
    }
}
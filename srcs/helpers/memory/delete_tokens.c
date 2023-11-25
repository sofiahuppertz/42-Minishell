
#include "../../../headers/minishell.h"

void delete_tokens(t_token *head)
{
    t_token *temp;

    while (head)
    {
        ft_memdel(head->str);  
        temp = head;           
        head = head->next; 
        ft_memdel(temp);     
    }
}
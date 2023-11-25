
#include "../../../headers/minishell.h"

int	init_signals(void)
{
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
	g_sig.pid = 0;
	g_sig.exit_status = 0;
    signal(SIGINT, &sig_int);
	signal(SIGQUIT, &sig_quit);
	return (1);
}
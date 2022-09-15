#ifndef SIGNAL_H
# define SIGNAL_H

# include "../includes/minishell.h"

void	sigint_handler(int sig);
void	sigquit_handler(int sig);
void	ft_sig_ign(int sig);
void	sig_msg(int sig);
void	signal_handler_pipe(int status);
#endif
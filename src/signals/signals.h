#ifndef SIGNALS_H
# define SIGNALS_H

// Include any necessary headers here
# include "config.h"
# include "minishell.h"

// Declare your function prototypes here
void	signal_handler(int signal);
void	signal_setup(void(funtion)(int signal));
int		send_signal(int pid, int signal);

#endif // SIGNALS_H
#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../tokenizer/tokenizer.h"
# include "../parcer/parcer.h"
# include "../expansion/expansion.h"
# include "../executer/executer.h"
# include "../utls/utls.h"
# include "../signal/signal.h"
# include "../terminal/my_term.h"
# include "../builtins/buildin.h"

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h> 
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <stdbool.h>
# include <signal.h>
# include <errno.h>

# define PROMPT "minishell $ "
# define STOP_LOOP 0
# define LOOP 1
# define INITSHELL 0
# define DELETESHELL 1

#endif

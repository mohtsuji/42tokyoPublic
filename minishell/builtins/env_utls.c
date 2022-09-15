#include "../includes/minishell.h"

t_env	*env_oneclear(t_env *target)
{
	t_env	*pre;
	t_env	*nex;

	pre = target->prev;
	nex = target->next;
	safe_free(&(target->key));
	safe_free(&(target->value));
	free(target);
	pre->next = nex;
	if (nex == NULL)
		return (pre);
	nex->prev = pre;
	return (pre);
}

void	env_init_change(t_env **env)
{
	t_env	*tmp;

	tmp = (*env)->next;
	free(*env);
	*env = tmp;
}

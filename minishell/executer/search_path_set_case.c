#include "executer.h"

static _Bool	dup_and_found(char *path_list, char **ans)
{
	safe_free(ans);
	*ans = safe_dup(path_list);
	return (FOUND);
}

static int	traverse_pathlist(char **path_list, char **ans)
{
	int			i;
	struct stat	buf;
	_Bool		found_but_perm;

	i = 0;
	found_but_perm = false;
	while (path_list[i] != NULL)
	{
		if (lstat(path_list[i], &buf) == 0)
		{
			if (buf.st_mode & S_IXUSR && buf.st_mode & S_IRUSR)
				return (dup_and_found(path_list[i], ans));
			if (!found_but_perm)
			{
				found_but_perm = true;
				*ans = safe_dup(path_list[i]);
			}
		}
		++i;
	}
	if (found_but_perm)
		return (NOTFOUND_PERM);
	return (NOTFOUND_CMD);
}

int	path_set_case(char *file, t_shell *shell, char **ans)
{
	char	**path_list;
	int		res;

	path_list = make_path_list(shell->envlist, file, "PATH");
	res = traverse_pathlist(path_list, ans);
	free_multi(&path_list);
	return (res);
}

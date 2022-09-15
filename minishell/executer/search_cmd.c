#include "executer.h"

int	path_contains_file(char *file)
{
	char		*cpy;
	char		*last_slash;
	struct stat	buf;

	cpy = safe_dup(file);
	while (1)
	{
		last_slash = ft_strrchr(cpy, '/');
		if (last_slash == NULL)
			break ;
		*last_slash = '\0';
		if (lstat(cpy, &buf) == 0)
		{
			if ((buf.st_mode & S_IFMT) == S_IFREG)
			{
				free(cpy);
				return (NOTFOUND_NOTDIR);
			}
		}
	}
	free(cpy);
	return (NOTFOUND_FILE);
}

int	slash_case(char *file, char **ans)
{
	struct stat	buf;

	if (lstat(file, &buf) != 0)
		return (path_contains_file(file));
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (NOTFOUND_DIR);
	*ans = safe_dup(file);
	return (FOUND);
}

int	path_not_set_case(char *file, char **ans)
{
	char	*cd_filename;
	int		res;

	cd_filename = safe_join("./", file);
	res = slash_case(cd_filename, ans);
	safe_free(&cd_filename);
	if (res != FOUND)
		return (NOTFOUND_FILE);
	return (res);
}

int	no_slash_case(char *file, t_shell *shell, char **ans)
{
	t_env	*path;

	path = ft_getenv("PATH", shell->envlist);
	if (path == NULL || path->value == NULL || ft_strlen(path->value) == 0)
		return (path_not_set_case(file, ans));
	return (path_set_case(file, shell, ans));
}

int	search_cmd(char *file, t_shell *shell, char **ans)
{
	int	res;

	if (ft_strchr(file, '/') != NULL)
		res = slash_case(file, ans);
	else
		res = no_slash_case(file, shell, ans);
	if (res != FOUND && res != NOTFOUND_PERM)
		safe_free(ans);
	return (res);
}

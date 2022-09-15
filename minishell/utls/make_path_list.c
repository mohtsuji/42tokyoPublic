#include "utls.h"

static char	*check_consective_colon(char *cpy)
{
	int		i;
	int		count;
	char	*ans;
	char	*ret;

	i = 0;
	count = 0;
	while (cpy[i + 1] != '\0')
	{
		if (cpy[i] == ':' && cpy[i + 1] == ':')
			++count;
		++i;
	}
	if (count == 0)
		return (safe_dup(cpy));
	ans = (char *)safe_calloc(ft_strlen(cpy) + count + 1, sizeof(char));
	ret = ans;
	while (*cpy != '\0')
	{
		*ans++ = *cpy++;
		if (*(cpy - 1) == ':' && *cpy == ':')
			*ans++ = '.';
	}
	return (ret);
}

static char	*make_path_canonical(char *pathstr)
{
	char	*done;
	char	*cpy;
	char	*ans;
	int		i;

	cpy = safe_dup(pathstr);
	if (cpy[0] == ':')
	{
		done = cpy;
		cpy = safe_join(".", cpy);
		safe_free(&done);
	}
	i = 0;
	while (cpy[i + 1] != '\0')
		++i;
	if (cpy[i] == ':')
	{
		done = cpy;
		cpy = safe_join(cpy, ".");
		safe_free(&done);
	}
	ans = check_consective_colon(cpy);
	safe_free(&cpy);
	return (ans);
}

static _Bool	end_slash(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1] != '\0')
		++i;
	if (str[i] == '/')
		return (true);
	return (false);
}

static void	append_filename(char **pathlist, char *file)
{
	char	*done;
	char	*file_with_slash;
	int		i;

	i = 0;
	file_with_slash = safe_join("/", file);
	while (pathlist[i] != NULL)
	{
		done = pathlist[i];
		if (end_slash(pathlist[i]))
			pathlist[i] = safe_join(pathlist[i], file);
		else
			pathlist[i] = safe_join(pathlist[i], file_with_slash);
		safe_free(&done);
		++i;
	}
	safe_free(&file_with_slash);
}

char	**make_path_list(t_env *env, char *file, char *str)
{
	char	**ans;
	char	*path_str;
	t_env	*path;

	path = ft_getenv(str, env);
	if (path == NULL)
		return (NULL);
	path_str = make_path_canonical(path->value);
	ans = safe_split(path_str, ':');
	safe_free(&path_str);
	append_filename(ans, file);
	return (ans);
}

#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

int	put_error(std::string message)
{
	std::cerr << message << std::endl;
	return (1);
}

void	create_filename(std::string i_file, std::string &o_file)
{
	for (int i = 0; i_file[i]; i++)
		o_file += std::toupper(i_file[i]);
	o_file += ".replace";
}

std::string	replace(std::string str, size_t p, std::string s1, std::string s2)
{
	std::string	re(str, 0, p);
	std::string	tmp = str;
	size_t		size;

	if (p + s1.size() > tmp.size())
	{
		re += s2;
		return (re);
	}
	else
		tmp = str.assign(tmp, p + s1.size(), tmp.size());
	re += s2;
	while (1)
	{
		p = str.find(s1);
		if (p != std::string::npos)
		{
			size = tmp.size();
			re += tmp.assign(str, 0, p);
			re += s2;
			if (p + s1.size() > size)
				return (re);
			else
				str.assign(str, p + s1.size(), size);
		}
		else
			break ;
		tmp = str;
	}
	re += str;
	return (re);
}

int	main(int argc, char **argv)
{
	std::string	s1;
	std::string	s2;
	std::string	i_file;
	std::string	o_file;
	std::string	tmp;
	std::string	re;
	size_t		p;
/*必要なものを準備*/
	if (argc != 4)
		return (put_error("argument error"));
	i_file = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (s1 == "" || s2 == "")
		return (put_error("argument error"));
	create_filename(i_file, o_file);
/*file open*/
	std::ifstream	ifs(i_file);
	if (!ifs)
		return (put_error("file open error"));
	std::ofstream	ofs;
	ofs.open(o_file, std::ios::app);
/*read and replace*/
	while (getline(ifs, tmp))
	{
		p = tmp.find(s1);
		if (p != std::string::npos)
		{
			re = replace(tmp, p, s1, s2);
			ofs << re << std::endl;
		}
		else
			ofs << tmp << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}

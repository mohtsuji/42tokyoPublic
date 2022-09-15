#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <cmath>

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RES "\e[0m"

class Convert {

private:
	std::string	str;
	std::string	type;

public:
	Convert();
	~Convert();
	Convert(std::string);
	Convert(const Convert &c);

	Convert &operator=(const Convert &c);

	std::string		getStr() const;
	void			setStr(std::string);
	std::string		getType() const;
	void			setType(std::string);

	virtual void	toChar() = 0;
	virtual void	toInt() = 0;
	virtual void	toFloat() = 0;
	virtual void	toDouble() = 0;

};

#endif

#ifndef CHAR_HPP
# define CHAR_HPP

#include "Convert.hpp"

class Char : public Convert {

private:
	Char();

public:
	~Char();
	Char(std::string);
	Char(const Char &c);

	Char &operator=(const Char &c);

	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

};

#endif

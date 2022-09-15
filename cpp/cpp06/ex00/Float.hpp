#ifndef FLOAT_HPP
# define FLOAT_HPP

#include "Convert.hpp"

class Float : public Convert {

private:
	Float();
	double	d;
	bool	overflow;

public:
	~Float();
	Float(std::string);
	Float(const Float &c);

	Float &operator=(const Float &c);

	double	getFloat() const;

	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

};

#endif

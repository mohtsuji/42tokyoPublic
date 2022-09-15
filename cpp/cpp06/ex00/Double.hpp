#ifndef DOUBLE_HPP
# define DOUBLE_HPP

#include "Convert.hpp"

class Double : public Convert {

private:
	Double();
	double	d;
	bool	overflow;

public:
	~Double();
	Double(std::string);
	Double(const Double &c);

	Double &operator=(const Double &c);

	double	getDouble() const;

	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

};

#endif


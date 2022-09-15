#ifndef INT_HPP
# define INT_HPP

#include "Convert.hpp"

class Int : public Convert {

private:
	Int();
	int	i;

public:
	~Int();
	Int(std::string);
	Int(const Int &c);

	Int &operator=(const Int &c);

	int		getInt() const;

	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

};

#endif

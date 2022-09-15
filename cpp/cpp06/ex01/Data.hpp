#ifndef DATA_HPP
# define DATA_HPP

class	Data {

private:
	int	i;
	Data();

public:
	~Data();
	Data(int);
	Data(const Data &c);

	Data& operator=(const Data &c);

	int	getInt() const;

};

#endif

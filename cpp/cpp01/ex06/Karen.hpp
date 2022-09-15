#ifndef KAREN_H
# define KAREN_H

#include <string>
#include <iostream>
#define RED "\e[0;31m"
#define RES "\033[m"

class Karen {

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	void complain( std::string level );
};

#endif

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

template < class T >
typename T::iterator	easyfind(T &c, int i)
{
	return (std::find(c.begin(), c.end(), i));
}

template < class T >
typename T::const_iterator	easyfind(const T &c, int i)
{
	return (std::find(c.begin(), c.end(), i));
}


#endif

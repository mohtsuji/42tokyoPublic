#ifndef TESTER_HPP
# define TESTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "../header/VectorIterator.hpp"
#include "../header/iterator.hpp"
#include "../header/iterator_traits.hpp"
#include "../header/vector.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define RES "\e[0m"

//template <class T = std::stringstream>
class Tester {

private:


public:
	Tester();
	~Tester();
	Tester(const Tester &c);
	Tester& operator=(const Tester &c);

	void	btitle(std::string);
	void	title(std::string);

	template<class T>
	void	comp(T s, T f)
	{
		if (s == f)
		{
			std::cout << "std = " << s << std::endl;
			std::cout << "ft  = " << f << std::endl;
			std::cout << CYN << "OK" << RES << std::endl;
		}
		else
		{
			std::cout << "std = " << s << std::endl;
			std::cout << "ft  = " << f << std::endl;
			std::cout << RED << "NG" << RES << std::endl;
			exit(1);
		}
	}

	template<class S, class F>
	void	v_contents_comp(S s, F f)
	{
		typename S::iterator	si = s.begin();
		typename F::iterator	fi = f.begin();
		for (typename S::iterator v = s.begin(); v != s.end(); v++)
		{
			if (*si != *fi)
			{
				std::cout << RED << "NG" << RES << std::endl;
				exit(1);
			}
			si++;
			fi++;
		}
		std::cout << CYN << "OK" << RES << std::endl;
	}

	template<class S, class F>
	void	v_comp(S &s, F &f)
	{
		std::cout << "===contents===" << std::endl;
		std::cout << "*std = ";
		for (size_t i = 0; i < s.size(); i++)
			std::cout << s[i] << ", ";
		std::cout << std::endl;

		std::cout << "*ft = ";
		for (size_t i = 0; i < f.size(); i++)
			std::cout << f[i] << ", ";
		std::cout << std::endl;

		v_contents_comp(s, f);

		std::cout << "===size()===" << std::endl;
		comp(s.size(), f.size());
		std::cout << "===empty()===" << std::endl;
		comp(s.empty(), f.empty());
		std::cout << "===capacity()===" << std::endl;
		comp(s.capacity(), f.capacity());
	}
};


#endif

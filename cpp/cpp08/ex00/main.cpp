#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>

int	main()
{
	{
	std::cout << "-----test vector-----" << std::endl;

	std::vector<int> v(5);
	int			i = 1;
	std::vector<int>::iterator	re;

	for (std::vector<int>::iterator p = v.begin(); p != v.end(); p++)
	{
		*p = i++;
		std::cout << "*p = " << *p << std::endl;
	}
	re = easyfind(v, 100);
	if (v.end() == re)
		std::cout << "easyfind(v, 100) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 100) = " << *re << std::endl;
	re = easyfind(v, 1);
	if (v.end() == re)
		std::cout << "easyfind(v, 1) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 1) = " << *re << std::endl;
	}

	{
	std::cout << "-----test const vector-----" << std::endl;

	const std::vector<int> v(5);
	std::vector<int>::const_iterator	re;

	for (std::vector<int>::const_iterator p = v.begin(); p != v.end(); p++)
	{
		std::cout << "*p = " << *p << std::endl;
	}
	re = easyfind(v, 100);
	if (v.end() == re)
		std::cout << "easyfind(v, 100) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 100) = " << *re << std::endl;
	if (v.end() == re)
		std::cout << "easyfind(v, 1) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 1) = " << *re << std::endl;
	}

	{
	std::cout << "-----test deque-----" << std::endl;

	std::deque<int> v(5);
	int			i = 1;
	std::deque<int>::iterator	re;

	for (std::deque<int>::iterator p = v.begin(); p != v.end(); p++)
	{
		*p = i++;
		std::cout << "*p = " << *p << std::endl;
	}
	re = easyfind(v, 100);
	if (v.end() == re)
		std::cout << "easyfind(v, 100) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 100) = " << *re << std::endl;
	re = easyfind(v, 1);
	if (v.end() == re)
		std::cout << "easyfind(v, 1) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 1) = " << *re << std::endl;
	}


	{
	std::cout << "-----test list-----" << std::endl;

	std::list<int> v(5);
	int			i = 1;
	std::list<int>::iterator	re;

	for (std::list<int>::iterator p = v.begin(); p != v.end(); p++)
	{
		*p = i++;
		std::cout << "*p = " << *p << std::endl;
	}
	re = easyfind(v, 100);
	if (v.end() == re)
		std::cout << "easyfind(v, 100) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 100) = " << *re << std::endl;
	re = easyfind(v, 1);
	if (v.end() == re)
		std::cout << "easyfind(v, 1) = not found" << std::endl;
	else
		std::cout << "easyfind(v, 1) = " << *re << std::endl;
	}
	{
	std::cout << "-----test multiset-----" << std::endl;

	std::multiset<int> m;
	std::multiset<int>::iterator	re;

	m.insert(1);
	m.insert(2);
	m.insert(3);
	m.insert(4);
	for (std::multiset<int>::iterator p = m.begin(); p != m.end(); p++)
	{
		std::cout << "*p = " << *p << std::endl;
	}
	re = easyfind(m, 100);
	if (m.end() == re)
		std::cout << "easyfind(m, 100) = not found" << std::endl;
	else
		std::cout << "easyfind(m, 100) = " << *re << std::endl;
	re = easyfind(m, 1);
	if (m.end() == re)
		std::cout << "easyfind(m, 1) = not found" << std::endl;
	else
		std::cout << "easyfind(m, 1) = " << *re << std::endl;
	}
	{
	std::cout << "-----test set-----" << std::endl;

	std::set<int> m;
	std::set<int>::iterator	re;

	m.insert(1);
	m.insert(2);
	m.insert(3);
	m.insert(4);
	for (std::set<int>::iterator p = m.begin(); p != m.end(); p++)
	{
		std::cout << "*p = " << *p << std::endl;
	}
	re = easyfind(m, 100);
	if (m.end() == re)
		std::cout << "easyfind(m, 100) = not found" << std::endl;
	else
		std::cout << "easyfind(m, 100) = " << *re << std::endl;
	re = easyfind(m, 1);
	if (m.end() == re)
		std::cout << "easyfind(m, 1) = not found" << std::endl;
	else
		std::cout << "easyfind(m, 1) = " << *re << std::endl;
	}
}

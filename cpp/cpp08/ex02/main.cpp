#include "mutantstack.hpp"


int	main()
{
	std::cout << "=====default test=====" << std::endl;
	MutantStack<int>	mstack;

	std::cout << "empty() = " << mstack.empty() << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "top() = " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size() = " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	{
	MutantStack<int>::iterator it = mstack.begin();
		std::cout << "begin = " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();

	++it;
		std::cout << "++it = " << *it << std::endl;
	--it;
		std::cout << "--it = " << *it << std::endl;

	while (it != ite) {
		std::cout << " *it = " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	}

	{
	std::cout << "=====reverse_itaretor test=======" << std::endl;

	MutantStack<int>::reverse_iterator it = mstack.rbegin();
		std::cout << "rbegin = " << *it << std::endl;
	MutantStack<int>::reverse_iterator ite = mstack.rend();

	while (it != ite) {
		std::cout << " *it = " << *it << std::endl;
		++it;
	}
	}

	{
	std::cout << "=====const_itaretor test=======" << std::endl;

	MutantStack<int>::const_iterator it = mstack.begin();
		std::cout << "begin = " << *it << std::endl;
	MutantStack<int>::const_iterator ite = mstack.end();

//	*it = 1; //const test
	while (it != ite) {
		std::cout << " *it = " << *it << std::endl;
		++it;
	}
	}

	{
	std::cout << "=====const_reverse_itaretor test=======" << std::endl;

	MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
		std::cout << "rbegin = " << *it << std::endl;
	MutantStack<int>::const_reverse_iterator ite = mstack.rend();

//	*it = 1; //const test
	while (it != ite) {
		std::cout << " *it = " << *it << std::endl;
		++it;
	}
	}

	std::cout << "=====copy test=======" << std::endl;

	MutantStack<int>	copy = mstack;

	MutantStack<int>::iterator cb = copy.begin();
		std::cout << "begin = " << *cb << std::endl;
	MutantStack<int>::iterator ce = copy.end();
	while (cb != ce) {
		std::cout << *cb << std::endl;
		++cb;
	}

	std::cout << "=====assignation test=======" << std::endl;

	MutantStack<int>	a;

	a = mstack;

	MutantStack<int>::iterator ab = a.begin();
	std::cout << "begin = " << *ab << std::endl;
	MutantStack<int>::iterator ae = a.end();
	while (ab != ae) {
		std::cout << *ab << std::endl;
		++ab;
	}

	return 0;
}

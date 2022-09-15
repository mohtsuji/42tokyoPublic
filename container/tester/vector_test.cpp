#include "Tester.hpp"
#include "../header/VectorIterator.hpp"
#include "../header/iterator.hpp"
#include "../header/reverse_iterator.hpp"
#include "../header/iterator_traits.hpp"
#include "../header/vector.hpp"
#include <vector>
#include <list>

__attribute__((destructor))
static void destructor()
{
    system("leaks a.out");
}

int	main()
{
	Tester	tester;

	tester.btitle("vector constructor test");

	tester.btitle("(1)");
	tester.title("(1) ft::vector<int> f");
	{
		std::vector<int>	s;
		ft::vector<int>		f;
		tester.v_comp(s, f);
	}

	tester.title("(1) ft::vector<std::string> f");
	{
		std::vector<std::string>	s;
		ft::vector<std::string>		f;
		tester.v_comp(s, f);
	}

	tester.btitle("(3) int");
	tester.title("(3) ft::vector<int> f(2)");
	{
		std::vector<int>	s(2);
		ft::vector<int>		f(2);

		tester.v_comp(s, f);
	}

	tester.btitle("(3) std::string");
	tester.title("(3) ft::vector<std::string> f(2)");
	{
		std::vector<std::string>	ss(2);
		ft::vector<std::string>		fs(2);

		tester.v_comp(ss, fs);
	}

	tester.btitle("(3) int");
	tester.title("(3) ft::vector<int> f(4, 2)");
	{
		std::vector<int>	s(4, 2);
		ft::vector<int>		f(4, 2);

		tester.v_comp(s, f);

	tester.btitle("(3) std::string");
	tester.title("(3) ft::vector<std::string> f(4, tako)");

		std::vector<std::string>	ss(4, "tako");
		ft::vector<std::string>		fs(4, "tako");

		tester.v_comp(ss, fs);

//(5)
	tester.btitle("(5) int");
	tester.title("(5) ft::vector<int> f5BeginEnd(f.begin(), f.end())");

		std::vector<int>	s5BeginEnd(s.begin(), s.end());
		ft::vector<int>		f5BeginEnd(f.begin(), f.end());

		tester.v_comp(s5BeginEnd, f5BeginEnd);

	tester.title("*(f5BeginEnd.begin() = 5)");
		*(s5BeginEnd.begin()) = 5;
		*(f5BeginEnd.begin()) = 5;

		tester.v_comp(s5BeginEnd, f5BeginEnd);

	tester.title("コピー元は変わってないことを確認, v_comp(s, f)");
		tester.v_comp(s, f);

	tester.title("(5) ft::vector<int> f5BeginEnd_one(f.begin(), (f.end() - 1))");
		std::vector<int>	s5BeginEnd_one(s.begin(), (s.end() - 1));
		ft::vector<int>		f5BeginEnd_one(f.begin(), (f.end() - 1));

		tester.v_comp(s5BeginEnd_one, f5BeginEnd_one);

	tester.btitle("(5) std::string");
	tester.title("(5) ft::vector<std::string> fs5BeginEnd(fs.begin(), fs.end())");

		std::vector<std::string>	ss5BeginEnd(ss.begin(), ss.end());
		ft::vector<std::string>		fs5BeginEnd(fs.begin(), fs.end());

		tester.v_comp(ss5BeginEnd, fs5BeginEnd);

	tester.title("*(fs5BeginEnd.begin() = a)");
		*(ss5BeginEnd.begin()) = "a";
		*(fs5BeginEnd.begin()) = "a";

		tester.v_comp(ss5BeginEnd, fs5BeginEnd);

	tester.title("コピー元は変わってないことを確認");
		tester.v_comp(ss, fs);

	tester.title("(5) ft::vector<std::string> fs5BeginEnd_one(fs.begin(), (fs.end() - 1))");
		std::vector<std::string>	ss5BeginEnd_one(ss.begin(), (ss.end() - 1));
		ft::vector<std::string>		fs5BeginEnd_one(fs.begin(), (fs.end() - 1));

		tester.v_comp(ss5BeginEnd_one, fs5BeginEnd_one);

//(6)
	tester.btitle("(6) int");
	tester.title("(6) ft::vector<int> cf(f.begin(), f.end())");

		std::vector<int>	cs(s);
		ft::vector<int>		cf(f);

		tester.v_comp(cs, cf);

	tester.title("*(cf.begin() = 10)");
		*(cs.begin()) = 10;
		*(cf.begin()) = 10;

		tester.v_comp(cs, cf);

	tester.title("コピー元は変わってないことを確認, v_comp(s, f)");
		tester.v_comp(s, f);

	tester.btitle("(6) std::string");
	tester.title("(6) ft::vector<std::string> cf(fs.begin(), fs.end())");

		std::vector<std::string>	css(ss);
		ft::vector<std::string>		cfs(fs);

		tester.v_comp(css, cfs);

	tester.title("*(cfs.begin() = a)");
		*(css.begin()) = "a";
		*(cfs.begin()) = "a";

		tester.v_comp(css, cfs);

	tester.title("コピー元は変わってないことを確認, v_comp(ss. fs)");
		tester.v_comp(ss, fs);

	tester.btitle("assignation int");
	tester.title("ft::vector<int> af; af = f");

		std::vector<int>	as;
		ft::vector<int>		af;

		as = s;
		af = f;

		tester.v_comp(as, af);

	tester.title("*(af.begin()) = 20");
		*(as.begin()) = 20;
		*(af.begin()) = 20;

		tester.v_comp(as, af);

	tester.title("コピー元は変わってないことを確認, v_comp(s, f)");
		tester.v_comp(s, f);

	tester.btitle("get_allocator");

		std::allocator<int>	b;
		std::allocator<int>	salo = s.get_allocator();
		std::allocator<int>	falo = f.get_allocator();
		try {
			tester.title("b = dynamic_cast<std::allocator<int>&>(s.get_allocator())");
			b = dynamic_cast<std::allocator<int>&>(salo);
			std::cout << "this is std::allocator" << std::endl;
		}
		catch (std::bad_cast)
		{
		}
		try {
			tester.title("b = dynamic_cast<std::allocator<int>&>(f.get_allocator())");
			b = dynamic_cast<std::allocator<int>&>(falo);
			std::cout << "this is std::allocator" << std::endl;
		}
		catch (std::bad_cast)
		{
		}
	}

	{
//at and operator[]
	tester.btitle("at and operator[]");

		tester.title("std::vector<int>s & ft::vector<int> f");
		std::vector<int>	s(5);
		ft::vector<int>		f(5);

		int	j = 0;
		for (std::vector<int>::iterator i = s.begin(); i < s.end(); i++)
			*i = j++;
		j = 0;
		for (ft::vector<int>::iterator i = f.begin(); i < f.end(); i++)
			*i = j++;
		tester.v_comp(s, f);

		tester.title("f.at(0)");
		tester.comp(s.at(0), f.at(0));;

		tester.title("f[0]");
		tester.comp(s[0], f[0]);;

		tester.title("f.at(1)");
		tester.comp(s.at(1), f.at(1));;

		tester.title("f[1]");
		tester.comp(s[1], f[1]);;

		tester.title("f.at(1) = 10");
		s.at(1) = 10;
		f.at(1) = 10;
		tester.v_comp(s, f);

		tester.title("f.at[1] = 1");
		s[1] = 1;
		f[1] = 1;
		tester.v_comp(s, f);

		tester.title(".at(5) -> out of range");
		try { std::cout << s.at(5) << std::endl;}
		catch (std::exception &e) { std::cout << e.what() << std::endl;}
		try { std::cout << f.at(5) << std::endl;}
		catch (std::exception &e) { std::cout << e.what() << std::endl; }
//at (const vector)
		tester.title("const std::vector<int>cs & const ft::vector<int> cf");
		const std::vector<int>	cs(5, 5);
		const ft::vector<int>	cf(5, 5);
		tester.v_comp(cs, cf);

		tester.title("f.at(0)");
		tester.comp(cs.at(0), cf.at(0));;

		tester.title("f[0]");
		tester.comp(cs[0], cf[0]);;

/*//constなのでコンパイルエラー
		tester.title(".at(1) = 10");
		cs.at(1) = 10;
		cf.at(1) = 10;
		tester.v_comp(cs, cf);
*/
/*//constなのでコンパイルエラー
		tester.title("f[1] = 10");
		cs[1] = 10;
		cf[1] = 10;
		tester.v_comp(cs, cf);
*/
		tester.title(".at(5) -> out of range");
		try { std::cout << cs.at(5) << std::endl;}
		catch (std::exception &e) { std::cout << e.what() << std::endl;}
		try { std::cout << cf.at(5) << std::endl;}
		catch (std::exception &e) { std::cout << e.what() << std::endl; }

//front and front
	tester.btitle("front and back");

		tester.title("std::vector<int>s & ft::vector<int> f");
		tester.v_comp(s, f);

		tester.title("f.front()");
		tester.comp(s.front(), f.front());
		tester.title("f.back()");
		tester.comp(s.back(), f.back());

		tester.title("f.front() = 20");
		s.front() = 20;
		f.front() = 20;

		tester.title("f.back() = 30");
		s.back() = 30;
		f.back() = 30;

		tester.v_comp(s, f);
	//const
		tester.title("const std::vector<int>cs & const ft::vector<int> cf");
		tester.v_comp(cs, cf);

		tester.title("cf.front()");
		tester.comp(cs.front(), cf.front());
		tester.title("cf.back()");
		tester.comp(cs.back(), cf.back());
/* //const なのでコンパイルエラー
		tester.title("cf.front() = 20");
		cs.front() = 20;
		cf.front() = 20;

		tester.title("cf.back() = 30");
		cs.back() = 30;
		cf.back() = 30;
*/
	}

	{
//front and front
	tester.btitle("max_size");

		tester.title("std::vector<int>s & ft::vector<int> f");
		std::vector<int>	si(5);
		ft::vector<int>		fi(5);
		tester.comp(si.max_size(), fi.max_size());

		tester.title("std::vector<string>s & ft::vector<string> f");
		std::vector<std::string>	ss(5);
		ft::vector<std::string>		fs(5);
		tester.comp(ss.max_size(), fs.max_size());

		tester.title("std::vector<char>s & ft::vector<char> f");
		std::vector<char>	sc(5);
		ft::vector<char>	fc(5);
		tester.comp(sc.max_size(), fc.max_size());

		tester.title("omake std::numeric_limits<std::ptrdiff_t(difference_type)>::max()");
		std::cout << std::numeric_limits<std::ptrdiff_t>::max() << std::endl;

//reserve
	tester.btitle("reserve");

		tester.title("si and fi - 前提の確認 -");
		int	j = 0;
		for (std::vector<int>::iterator i = si.begin(); i < si.end(); i++)
			*i = j++;
		j = 0;
		for (ft::vector<int>::iterator i = fi.begin(); i < fi.end(); i++)
			*i = j++;
		tester.v_comp(si, fi);

		tester.title("fi.reserve(1) -> 1 <= 5 nochange");
		si.reserve(1);
		fi.reserve(1);
		tester.v_comp(si, fi);

		tester.title("fi.reserve(5) -> 5 <= 5 nochange");
		si.reserve(5);
		fi.reserve(5);
		tester.v_comp(si, fi);

		tester.title("fi.reserve(100) -> 100 > 5 change");
		si.reserve(100);
		fi.reserve(100);
		tester.v_comp(si, fi);

		tester.title("copy constructor (cf = fi) -> capacity = size");
		std::vector<int>	cs = si;
		ft::vector<int>	cf = fi;
		tester.v_comp(cs, cf);

		tester.title("assignation (af = fi) -> capacity = size");
		std::vector<int>	as;
		ft::vector<int>		af;
		as = si;
		af = fi;
		tester.v_comp(as, af);

		tester.title("reserve(ll) -> ll > max_size()");
		unsigned long long ll = 9223372036854775807;
		try {
			si.reserve(ll);
			std::cout << si.capacity() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			fi.reserve(ll);
			std::cout << fi.capacity() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

//clear
	tester.btitle("clear");

		tester.title("si and fi - 前提の確認 -");
		tester.v_comp(si, fi);

		tester.title("fi.clear()");
		si.clear();
		fi.clear();
		tester.v_comp(si, fi);

	}
	{
//insert
	tester.btitle("insert");

		tester.title("s and f - 前提の確認 -");
		std::vector<int>	s(5);
		ft::vector<int>		f(5);
		int j = 0;
		for (std::vector<int>::iterator i = s.begin(); i < s.end(); i++)
			*i = j++;
		j = 0;
		for (ft::vector<int>::iterator i = f.begin(); i < f.end(); i++)
			*i = j++;
		tester.v_comp(s, f);

		tester.title("f.insert(begin(), 30)");
		std::vector<int>::iterator	si = s.begin();;
		ft::vector<int>::iterator	fi = f.begin();;
		s.insert(si, 30);
		f.insert(fi, 30);
		tester.v_comp(s, f);

		for (std::vector<int>::iterator i = s.begin(); i < s.end(); i++)
			std::cout << *i << ", ";
		std::cout << std::endl;

		for (int i = 0; i < 30; i++)
		{
			s.insert(s.begin(), 1);
			std::cout << "s.size() = " << s.size() << std::endl;
			std::cout << "s.capacity() = " << s.capacity() << std::endl;
		}
	}
















}}

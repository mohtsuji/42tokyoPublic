#include "Tester.hpp"
#include "../header/VectorIterator.hpp"
#include "../header/iterator.hpp"
#include "../header/reverse_iterator.hpp"
#include "../header/iterator_traits.hpp"
#include "../header/vector.hpp"
#include <vector>
#include <list>

int	main()
{
	Tester	tester;

	tester.btitle("reverse iterator default constructor");
	{
		tester.title("default constructor");
		std::vector<int>::iterator	std;
		ft::vector<int>::iterator	ft;
		std::reverse_iterator<std::vector<int>::iterator>	s;
		ft::reverse_iterator<ft::vector<int>::iterator>	f;
	}

	tester.btitle("copy constructor test (reverse_iterator( const reverse_iterator<U>& other );)");
	{
		//準備
		std::vector<int>	sv(3);
		std::vector<int>::iterator	std;
		std = sv.begin();

		ft::vector<int>	fv(3);
		ft::vector<int>::iterator	ft;
		ft = fv.begin();
//中身を入れる
		int	i = 0;
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			*v = i++;
		std::cout << "*sv = ";
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		i = 0;
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			*v = i++;
		std::cout << "*fv = ";
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
//reverse_iterator
		tester.title("fi(reverse_iterator)の中身");

		std::reverse_iterator<std::vector<int>::iterator>	si(std);
		ft::reverse_iterator<ft::vector<int>::iterator>	fi(ft);

		std::cout << "*(--si) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--si) << ", ";
		std::cout << std::endl;

		std::cout << "*(--fi) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--fi) << ", ";
		std::cout << std::endl;
//戻す
		for(int j = 0; j < 3; j++)
			++si;
		for(int j = 0; j < 3; j++)
			++fi;
//copy constructor
		tester.title("fi2(fi)");

		std::reverse_iterator<std::vector<int>::iterator>	si2(si);
		ft::reverse_iterator<ft::vector<int>::iterator>	fi2(fi);

		std::cout << "*(--si2) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--si2) << ", ";
		std::cout << std::endl;

		std::cout << "*(--fi2) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--fi2) << ", ";
		std::cout << std::endl;

//NG pattern
//		std::reverse_iterator<std::vector<char>::iterator>	sc(si);
//		ft::reverse_iterator<ft::vector<char>::iterator>	fc(fi);

//		std::reverse_iterator<std::list<int>::iterator>	si3(si);
//		ft::reverse_iterator<ft::list<int>::iterator>	fi3(fi);

	}

	tester.btitle("constructor test (ft::reverse_iterator<Iter> rf(fv.begin()))");
	{
		tester.title("fvの中身");
		//準備
		std::vector<int>	sv(3);
		std::vector<int>::iterator	std;
		std = sv.begin();

		ft::vector<int>	fv(3);
		ft::vector<int>::iterator	ft;
		ft = fv.begin();
		//中身を入れる
		int	i = 0;
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			*v = i++;
		std::cout << "*sv = ";
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		i = 0;
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			*v = i++;
		std::cout << "*fv = ";
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		tester.title("rfの中身");
		//constructor test
		std::reverse_iterator<std::vector<int>::iterator>	rs(std);
		ft::reverse_iterator<ft::vector<int>::iterator>		rf(ft);

		//reverse_iteratorの中身を確かめてみる
		i = 0;
		std::cout << "*(--rs) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rs) << ", ";
		std::cout << std::endl;

		i = 0;
		std::cout << "*(--rf) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rf) << ", ";
		std::cout << std::endl;
	}

	{
//assignation
		tester.btitle("assignation");

		//準備
		std::vector<int>	sv(3);
		std::vector<int>::iterator	std;
		std = sv.begin();

		ft::vector<int>	fv(3);
		ft::vector<int>::iterator	ft;
		ft = fv.begin();
		//中身を入れる
		int	i = 0;
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			*v = i++;
		std::cout << "*sv = ";
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		i = 0;
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			*v = i++;
		std::cout << "*fv = ";
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		tester.title("rfの中身");

		std::reverse_iterator<std::vector<int>::iterator>	rs(std);
		ft::reverse_iterator<ft::vector<int>::iterator>		rf(ft);

		std::cout << "*(--rs) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rs) << ", ";
		std::cout << std::endl;

		std::cout << "*(--rf) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rf) << ", ";
		std::cout << std::endl;
		//戻す
		for(int j = 0; j < 3; j++)
			++rs;
		for(int j = 0; j < 3; j++)
			++rf;

		//assignation test
		tester.title("rrf = rf");
		std::reverse_iterator<std::vector<int>::iterator>	rrs;
		ft::reverse_iterator<ft::vector<int>::iterator>		rrf;

		rrs = rs;
		rrf = rf;

		tester.title("*rf = 10");
		*--rs = 10;
		*--rf = 10;
		//rfの中身
		std::cout << "*(rs--) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(rs--) << ", ";
		std::cout << std::endl;

		std::cout << "*(rf--) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(rf--) << ", ";
		std::cout << std::endl;

		//戻す
		for(int j = 0; j < 3; j++)
			++rs;
		for(int j = 0; j < 3; j++)
			++rf;

		//rrfの中身
		std::cout << "*(--rrs) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rrs) << ", ";
		std::cout << std::endl;

		std::cout << "*(--rrf) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rrf) << ", ";
		std::cout << std::endl;

		//戻す
		for(int j = 0; j < 3; j++)
			++rs;
		for(int j = 0; j < 3; j++)
			++rf;
	}

	{
//base test
		tester.btitle("base test");

		//準備
		std::vector<int>	sv(3);
		std::vector<int>::iterator	std;
		std = sv.begin();

		ft::vector<int>	fv(3);
		ft::vector<int>::iterator	ft;
		ft = fv.begin();

		//中身を入れる
		int	i = 0;
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			*v = i++;
		std::cout << "*sv = ";
		for(std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		i = 0;
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			*v = i++;
		std::cout << "*fv = ";
		for(ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		tester.title("ftをbaseにしてrf(reverse_iterator）を作成");
		std::reverse_iterator<std::vector<int>::iterator>	rs(std);
		ft::reverse_iterator<ft::vector<int>::iterator>		rf(ft);

		//メモ reverse_iteratorはbegin() - 1から始まり，baseはbegin()から始まる
		//メモ reverse_iteratorをincrementなどするとbaseも同じように動く
		tester.title("iterator == reverse_iterator.base() -> true");
		tester.comp((std == rs.base()), (ft == rf.base()));

		tester.title("*(reverse_iterator.base())");
		tester.comp(*(rs.base()), *(rf.base()));

		tester.title("*(--rf)");
		tester.comp(*(--rs), *(--rf));

		tester.title("iterator(base) == reverse_iterator.base() -> false");
		tester.comp((std == rs.base()), (ft == rf.base()));

		tester.title("*(reverse_iterator.base())");
		tester.comp(*(rs.base()), *(rf.base()));
	}

	{
		tester.btitle("operator->");

		//準備
		std::vector<std::string>	sv(3);
		std::vector<std::string>::iterator	std;
		std = sv.begin();

		ft::vector<std::string>		fv(3);
		ft::vector<std::string>::iterator	ft;
		ft = fv.begin();

		//中身を入れる
		*std = "a";
		*(std + 1) = "ii";
		*(std + 2) = "uuu";
		*ft = "a";
		*(ft + 1) = "ii";
		*(ft + 2) = "uuu";

		//reverse_iteratorの作成
		std::reverse_iterator<std::vector<std::string>::iterator>	rs(std);
		ft::reverse_iterator<ft::vector<std::string>::iterator>		rf(ft);

		//中身の確認
		std::cout << "*(--rs) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rs) << ", ";
		std::cout << std::endl;

		std::cout << "*(--rf) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rf) << ", ";
		std::cout << std::endl;

		//戻す
		for(int j = 0; j < 3; j++)
			++rs;
		for(int j = 0; j < 3; j++)
			++rf;

		//本命
		tester.title("(--rf)->size()");
		for(int j = 0; j < 3; j++)
			tester.comp((int)(--rs)->size(), (int)(--rf)->size());

		//戻す
		for(int j = 0; j < 3; j++)
			++rs;
		for(int j = 0; j < 3; j++)
			++rf;

//operator[]
		tester.btitle("operator[]");

		tester.title("rf[j]");
		for(int j = -1; j > -4; j--)
			tester.comp(rs[j], rf[j]);

//operator-
		tester.btitle("operator-");
		tester.title("*(rf - 1)");
		tester.comp(*(rs - 1), *(rf - 1));
		tester.title("*(rf - 2)");
		tester.comp(*(rs - 2), *(rf - 2));

		rs = sv.rbegin();
		std::cout << *rs << std::endl;
		rf = fv.rbegin();
		std::cout << *rf << std::endl;

//operator+ (iter + n)
		tester.btitle("operator+");
		tester.title("*(rf)");
		tester.comp(*(rs), *(rf));
		tester.title("*(rf + 1)");
		tester.comp(*(rs + 1), *(rf + 1));

//operator+ (n + iter)
		tester.btitle("operator+");
		tester.title("*(rf)");
		tester.comp(*(rs), *(rf));
		tester.title("*(1 + rf)");
		tester.comp(*(1 + rs), *(1 + rf));
		tester.comp(*(rs), *(rf));

//operator-=
		tester.btitle("operator-=");
		rs = sv.rend();
		std::cout << *rs << std::endl;
		rf = fv.rend();
		std::cout << *rf << std::endl;

		tester.title("*(--rf)");
		tester.comp(*(--rs), *(--rf));

		tester.title("*(rf -= 1)");
		tester.comp(*(rs -= 1), *(rf -= 1));

//operator+=
		tester.btitle("operator+=");
		tester.title("*(rf)");
		tester.comp(*(rs), *(rf));
		tester.title("*(rf += 1)");
		tester.comp(*(rs += 1), *(rf += 1));

	}

	{
//operator==
		tester.btitle("operator==");

		std::vector<std::string>		sv(3);
		std::reverse_iterator<std::vector<std::string>::iterator>	s1;
		std::reverse_iterator<std::vector<std::string>::iterator>	s2;

		ft::vector<std::string>		fv(3);
		ft::reverse_iterator<ft::vector<std::string>::iterator>	f1;
		ft::reverse_iterator<ft::vector<std::string>::iterator>	f2;

		s1 = sv.rend();
		s2 = sv.rend();

		f1 = fv.rend();
		f2 = fv.rend();

		tester.title("rend() == rend() -> true");
		tester.comp((s1 == s2), (f1 == f2));
		tester.title("rend() == (rend() + 1) -> false");
		tester.comp((s1 == (s2 + 1)), (f1 == (f2 + 1)));

//operator!=
		tester.btitle("operator!=");

		tester.title("rend() != rend() -> false");
		tester.comp((s1 != s2), (f1 != f2));
		tester.title("rend() == (rend() + 1) -> true");
		tester.comp((s1 != (s2 + 1)), (f1 != (f2 + 1)));

//operator<
		tester.btitle("operator<");

		tester.title("rend() < rend() -> false");
		tester.comp((s1 < s2), (f1 < f2));
		tester.title("rend() < (rend() + 1) -> true");
		tester.comp((s1 < (s2 + 1)), (f1 < (f2 + 1)));

//operator<=
		tester.btitle("operator<=");

		tester.title("rend() <= rend() -> true");
		tester.comp((s1 <= s2), (f1 <= f2));
		tester.title("rend() <= (rend() + 1) -> true");
		tester.comp((s1 <= (s2 + 1)), (f1 <= (f2 + 1)));
		tester.title("rend() <= (rend() - 1) -> false");
		tester.comp((s1 <= (s2 - 1)), (f1 <= (f2 - 1)));

//operator>
		tester.btitle("operator>");

		tester.title("rend() > rend() -> false");
		tester.comp((s1 > s2), (f1 > f2));
		tester.title("rend() > (rend() - 1) -> true");
		tester.comp((s1 > (s2 - 1)), (f1 > (f2 - 1)));

//operator>=
		tester.btitle("operator>=");

		tester.title("rend() >= rend() -> true");
		tester.comp((s1 >= s2), (f1 >= f2));
		tester.title("rend() >= (rend() + 1) -> false");
		tester.comp((s1 >= (s2 + 1)), (f1 >= (f2 + 1)));
		tester.title("rend() >= (rend() - 1) -> true");
		tester.comp((s1 >= (s2 - 1)), (f1 >= (f2 - 1)));

//difference_type operator-
		tester.btitle("difference operator-");

		tester.title("rend() - rend()");
		tester.comp((s1 - s2), (f1 - f2));
		tester.title("rend() - (rend() + 1)");
		tester.comp((s1 - (s2 + 1)), (f1 - (f2 + 1)));
	}

	{
//const_reverse_iterator
	tester.btitle("const_reverse_iterator");

		//準備
		std::vector<std::string>			sv(3);
		std::vector<std::string>::iterator	std;
		std = sv.begin();

		ft::vector<std::string>		fv(3);
		ft::vector<std::string>::iterator	ft;
		ft = fv.begin();

		//中身を入れる
		*std = "a";
		*(std + 1) = "ii";
		*(std + 2) = "uuu";
		*ft = "a";
		*(ft + 1) = "ii";
		*(ft + 2) = "uuu";

		//const_iteratorの作成
		std::vector<std::string>::const_iterator	c_std;
		ft::vector<std::string>::const_iterator	c_ft;
		c_std = sv.begin();
		c_ft = fv.begin();

		//const_reverse_iteratorの作成
//		std::reverse_iterator<std::vector<std::string>::iterator>	rs(c_std);
//		ft::reverse_iterator<ft::vector<std::string>::iterator>		rf(c_ft);
		std::reverse_iterator<std::vector<std::string>::const_iterator>	rs(c_std);
		ft::reverse_iterator<ft::vector<std::string>::const_iterator>		rf(c_ft);

		//中身の確認
		std::cout << "*(--rs) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rs) << ", ";
		std::cout << std::endl;

		std::cout << "*(--rf) = ";
		for(int j = 0; j < 3; j++)
			std::cout << *(--rf) << ", ";
		std::cout << std::endl;
/*
		//NG pattern
		for(int j = 0; j < 3; j++)
			*(--rs)  = j;

		for(int j = 0; j < 3; j++)
			*(--rf)  = j;
*/
	//const rbegin() and const rend()
	tester.btitle("const rbegin() and const rend()");
		const	std::vector<int>	cs(3, 3);
		const	ft::vector<int>		cf(3, 3);

		std::vector<int>::const_reverse_iterator crs = cs.rbegin();
		ft::vector<int>::const_reverse_iterator crf = cf.rbegin();

		std::cout << "std = ";
		for (; crs < cs.rend(); crs++)
			std::cout << *crs << ", ";
		std::cout << std::endl;

		std::cout << "ft = ";
		for (; crf < cf.rend(); crf++)
			std::cout << *crf << ", ";
		std::cout << std::endl;
/*
		std::cout << "ft = ";
		for (reverse_iterator i = fv.rbegin(); i > sv.rend(); i++)
			std::cout << *i << ", ";
		std::cout << std::endl;
*/
	}


}

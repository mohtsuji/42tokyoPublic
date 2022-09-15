#include "Tester.hpp"
#include "../header/VectorIterator.hpp"
#include "../header/iterator.hpp"
#include "../header/iterator_traits.hpp"
#include "../header/vector.hpp"
#include <vector>

int	main()
{
//	Tester<int>	tester;
	Tester	tester;

	tester.btitle("vector iterator default constructor");
	{
		tester.title("default constructor");
		std::vector<int>::iterator	std;
		ft::vector<int>::iterator	ft;
	}

	{
		//test operator=
		tester.btitle("operator=");
		tester.title("operator=");
		std::vector<int>::iterator	std;
		ft::vector<int>::iterator	ft;

		std::vector<int>	sv(3, 1);
		ft::vector<int>		fv(3, 1);

		std = sv.begin();
		ft = fv.begin();
		tester.comp(*std, *ft);

		//test ++operator
		tester.btitle("++operator");

		//stdとftにそれぞれ0-2を入れる
		tester.title("test preparetion");
		int	i = 0;
		std::cout << "*std = ";
		for (std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
		{
			*v = i++;
			std::cout << *v << ", ";
		}
		std::cout << std::endl;
		i = 0;
		std::cout << "*ft = ";
		for (ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
		{
			*v = i++;
			std::cout << *v << ", ";
		}
		std::cout << std::endl;

		//++hogeでstdとftを回して中身を見る
		tester.title("++hoge");
		tester.comp(*(std), *(ft));
		for (int j = 0; j < 2; j++)
			tester.comp(*(++std), *(++ft));

		//test operator++
		tester.btitle("operator++");

		tester.title("begin()++");
		std = sv.begin();
		ft = fv.begin();
		//a++でstdとftを回して中身を見る
		for (int j = 0; j < 3; j++)
			tester.comp(*(std++), *(ft++));
		//*a++でreferenceが返ってきているかの確認
		std = sv.begin();
		ft = fv.begin();
		for (int j = 10; j < 13; j++)
		{
			*std++ = j;
			*ft++ = j; //これが大事
		}
		std = sv.begin();
		ft = fv.begin();
		i = 0;

		tester.title("test preparation");
		std::cout << "*std = ";
		for (std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
		i = 0;
		std::cout << "*ft = ";
		for (ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		tester.title("*a++ = int");
		for (int j = 0; j < 3; j++)
			tester.comp(*std++, *ft++);

		//test operator--
		tester.btitle("operator--");

		tester.title("(end() - 1)--");
		std = sv.end() - 1;
		ft = fv.end() - 1;
		//a--でstdとftを回して中身を見る
		for (int j = 0; j < 3; j++)
			tester.comp(*(std--), *(ft--));
		//*a--でreferenceが返ってきているかの確認
		std = sv.end() - 1;
		ft = fv.end() - 1;
		for (int j = 23; 20 < j; j--)
		{
			*std-- = j;
			*ft-- = j; //これが大事
		}
		std = sv.end() - 1;
		ft = fv.end() - 1;
		i = 0;

		tester.title("test preparation");
		std::cout << "*std = ";
		for (std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
		i = 0;
		std::cout << "*ft = ";
		for (ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		tester.title("*a-- = int");
		for (int j = 0; j < 3; j++)
			tester.comp(*std--, *ft--);

		//test --operator
		tester.btitle("--operator");

		tester.title("*(--end())");
		std = sv.end();
		ft = fv.end();
		//--aでstdとftを回して中身を見る
		for (int j = 0; j < 3; j++)
			tester.comp(*(--std), *(--ft));

		tester.title("*(--a) = int");
		std = sv.end();
		ft = fv.end();
		for (int j = 3; 0 < j; j--)
		{
			*(--std) = j;
			*(--ft) = j;
		}
		std = sv.end();
		ft = fv.end();
		for (int j = 0; j < 3; j++)
			tester.comp(*(--std), *(--ft));



		//test operator==
		tester.btitle("operator==");
		std::cout << "*std = ";
		for (std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
		i = 0;
		std::cout << "*ft = ";
		for (ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
		tester.title("begin() == begin() -> true");
		std::vector<int>::iterator	s1;
		ft::vector<int>::iterator	f1;
		std::vector<int>::iterator	s2;
		ft::vector<int>::iterator	f2;
		s1 = sv.begin();
		s2 = sv.begin();
		f1 = fv.begin();
		f2 = fv.begin();
		tester.comp((s1 == s2), (f1 == f2));

		tester.title("begin() == (begin()++) -> false");
		s2++;
		f2++;
		tester.comp((s1 == s2), (f1 == f2));

		//test operator!=
		tester.btitle("operator!=");
		tester.title("begin() != begin() -> false");
		s1 = sv.begin();
		s2 = sv.begin();
		f1 = fv.begin();
		f2 = fv.begin();
		tester.comp((s1 != s2), (f1 != f2));

		tester.title("begin() != (begin()++) -> true");
		s2++;
		f2++;
		tester.comp((s1 != s2), (f1 != f2));

		//test operator<
		tester.btitle("operator<");
		tester.title("begin() < begin() -> false");
		s1 = sv.begin();
		s2 = sv.begin();
		f1 = fv.begin();
		f2 = fv.begin();
		tester.comp((s1 < s2), (f1 < f2));

		tester.title("begin() < (begin()++) -> true");
		s2++;
		f2++;
		tester.comp((s1 < s2), (f1 < f2));

		tester.title("begin()++ < begin() -> false");
		tester.comp((s2 < s1), (f2 < f1));

		//test operator>
		tester.btitle("operator>");
		tester.title("begin() > begin() -> false");
		s1 = sv.begin();
		s2 = sv.begin();
		f1 = fv.begin();
		f2 = fv.begin();
		tester.comp((s1 > s2), (f1 > f2));

		tester.title("begin() > (begin()++) -> false");
		s2++;
		f2++;
		tester.comp((s1 > s2), (f1 > f2));

		tester.title("begin()++ > begin() -> true");
		tester.comp((s2 > s1), (f2 > f1));

		//test operator<=
		tester.btitle("operator<=");
		tester.title("begin() <= begin() -> true");
		s1 = sv.begin();
		s2 = sv.begin();
		f1 = fv.begin();
		f2 = fv.begin();
		tester.comp((s1 <= s2), (f1 <= f2));

		tester.title("begin() <= (begin()++) -> true");
		s2++;
		f2++;
		tester.comp((s1 <= s2), (f1 <= f2));

		tester.title("begin()++ <= begin() -> false");
		tester.comp((s2 <= s1), (f2 <= f1));

		//test operator>=
		tester.btitle("operator>=");
		tester.title("begin() >= begin() -> true");
		s1 = sv.begin();
		s2 = sv.begin();
		f1 = fv.begin();
		f2 = fv.begin();
		tester.comp((s1 >= s2), (f1 >= f2));

		tester.title("begin() >= (begin()++) -> false");
		s2++;
		f2++;
		tester.comp((s1 >= s2), (f1 >= f2));

		tester.title("begin()++ >= begin() -> true");
		tester.comp((s2 >= s1), (f2 >= f1));

		//test iterator - iterator
		tester.btitle("iterator - iterator");
		tester.title("ft.end() - ft.begin()");
		s1 = sv.end();
		s2 = sv.begin();
		f1 = fv.end();
		f2 = fv.begin();
		tester.comp((s1 - s2), (f1 - f2));

		//test iterator + n
		tester.btitle("iterator + n");
		tester.title("ft.begin() + 1");
		s1 = sv.begin();
		f1 = fv.begin();
		s1 = s1 + 1;
		f1 = f1 + 1;
		s1 + 1;
		f1 + 1;
		tester.comp(*s1, *f1);
		tester.title("ft.begin() + 1 + 1");
		s1 = 1 + s1;
		f1 = 1 + f1;
		1 + s1;
		1 + f1;
		tester.comp(*s1, *f1);

		//test iterator - n
		tester.btitle("iterator - n");
		tester.title("ft.end() - 1");
		s1 = sv.end();
		f1 = fv.end();
		s1 = s1 - 1;
		f1 = f1 - 1;
		s1 - 1;
		f1 - 1;
		tester.comp(*s1, *f1);
		tester.title("ft.begin() - 1 - 1");
		s1 = s1 - 1;
		f1 = f1 - 1;
		tester.comp(*s1, *f1);

		//test iterator += n
		tester.btitle("iterator += n");

		std::cout << "*std = ";
		for (std::vector<int>::iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
		i = 0;
		std::cout << "*ft = ";
		for (ft::vector<int>::iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		tester.title("ft.begin() += 1");
		s1 = sv.begin();
		f1 = fv.begin();
		s1 += 1;
		f1 += 1;
		tester.comp(*s1, *f1);
		tester.title("ft += -1");
		s1 += -1;
		f1 += -1;
		tester.comp(*s1, *f1);

		//test iterator -= n
		tester.btitle("iterator -= n");
		tester.title("ft.end() -= 2");
		s1 = sv.end();
		f1 = fv.end();
		s1 -= 2;
		f1 -= 2;
		tester.comp(*s1, *f1);
		tester.title("ft -= -1");
		s1 -= -1;
		f1 -= -1;
		tester.comp(*s1, *f1);
	}
	{
		//test operator[]
		tester.btitle("operator[]");
		tester.title("v = ft.begin(), v[k], k = 3-0");
		std::vector<int>	sv(4);
		ft::vector<int>		fv(4);
		std::vector<int>::iterator	std;
		ft::vector<int>::iterator	ft;
		std = sv.begin();
		ft = fv.begin();
		int	i = 3;
		int	j = 0;
		for (std::vector<int>::iterator v = sv.begin(); j < 4; j++)
		{
			v[j] = i--;
			std::cout << "std[j] = " << v[j] << std::endl;
		}
		i = 3;
		j = 0;
		for (ft::vector<int>::iterator v = fv.begin(); j < 4; j++)
		{
			v[j] = i--;
			std::cout << "ft[j]  = " << v[j] << std::endl;
		}
		for (int k = 0; k < 4; k++)
			tester.comp(std[k], ft[k]);

		tester.title("v = ft.begin() + 1, v[k], k = 2-0");
		std += 1;
		ft += 1;
		for (int k = 0; k < 3; k++)
			tester.comp(std[k], ft[k]);
	}
	{
		//swap_iter
		tester.btitle("swappable");
		tester.title("swap_iter");
		std::vector<int>	sv(4, 1);
		std::vector<int>	sv2(4, 2);
		std::vector<int>::iterator	std;
		std::vector<int>::iterator	std2;
		std = sv.begin();
		std2 = sv2.begin();
		ft::vector<int>	fv(4, 1);
		ft::vector<int>	fv2(4, 2);
		ft::vector<int>::iterator	ft;
		ft::vector<int>::iterator	ft2;
		ft = fv.begin();
		ft2 = fv2.begin();
		//std[i]の中身
		std::cout << "std[i] = ";
		for (int i = 0; i < 4; i++)
			std::cout << std[i] << ", ";
		std::cout << std::endl;
		//std2[i]の中身
		std::cout << "std2[i] = ";
		for (int i = 0; i < 4; i++)
			std::cout << std2[i] << ", ";
		std::cout << std::endl;
		//ft[i]の中身
		std::cout << "ft[i] = ";
		for (int i = 0; i < 4; i++)
			std::cout << ft[i] << ", ";
		std::cout << std::endl;
		//ft2[i]の中身
		std::cout << "ft2[i] = ";
		for (int i = 0; i < 4; i++)
			std::cout << ft2[i] << ", ";
		std::cout << std::endl;

		tester.title("before swap(std, std1) and swap(ft, ft1) -> compare (std[i], ft[i]) ");
		for (int i = 0; i < 4; i++)
			tester.comp(std[i], ft[i]);
		//stdとftをそれぞれswapする
		std::iter_swap(std, std2);
		std::iter_swap(ft, ft2);
		tester.title("after swap(std, std1) and swap(ft, ft1) -> compare (std[i], ft[i]) ");
		for (int i = 0; i < 4; i++)
			tester.comp(std[i], ft[i]);
	}
	{
		//operator->
		tester.btitle("operator->");
		tester.title("ft->size()");
		std::vector<std::string>			sv(2);
		ft::vector<std::string>				fv(2);
		std::vector<std::string>::iterator	std;
		ft::vector<std::string>::iterator	ft;
		std = sv.begin();
		ft = fv.begin();
		*std = "tako";
		*(std + 1) = "ika";
		*ft = "tako";
		*(ft + 1) = "ika";
		//中身を確かめてみる
		for (int i =0; i < 2; i++)
		{
			std::cout << "std[i] = " << std[i] << ", size = " << (&std[i])->size() << std::endl;
			std::cout << "ft[i]  = " << ft[i]  << ", size = " << (&ft[i])->size() << std::endl;
		}
		int	s;
		int	f;
		for (int i =0; i < 2; i++)
		{
			s = std->size();
			f = ft->size();
			std++;
			ft++;
			tester.comp(s, f);
		}

	}


}

#include "Tester.hpp"
#include "../header/VectorIterator.hpp"
#include "../header/iterator.hpp"
#include "../header/iterator_traits.hpp"
#include "../header/vector.hpp"
#include <vector>

int	main()
{
	Tester	tester;

	tester.btitle("const vector iterator default constructor");
	{
		tester.title("default constructor");
		std::vector<int>::const_iterator	std;
		ft::vector<int>::const_iterator		ft;
	}

	{
		//test operator=
		tester.btitle("operator=");
		tester.title("operator=");
		std::vector<int>::const_iterator	std;
		ft::vector<int>::const_iterator		ft;

		std::vector<int>	sv(3, 1);
		ft::vector<int>		fv(3, 1);

		std = sv.begin();
		ft = fv.begin();
		tester.comp(*std, *ft);
	}

	{
		//test ++operator
		tester.btitle("++operator");

		std::vector<int>::const_iterator	c_std;
		ft::vector<int>::const_iterator		c_ft;
		std::vector<int>::iterator			std;
		ft::vector<int>::iterator			ft;

		std::vector<int>	sv(3, 1);
		ft::vector<int>		fv(3, 1);
		std = sv.begin();
		c_std = sv.begin();
		ft = fv.begin();
		c_ft = fv.begin();

		//stdとftにそれぞれ0-2を入れる->非constなので成功する
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
/*
		//stdとftにそれぞれ0-2を入れる->失敗する
		tester.title("test preparetion");
		i = 0;
		std::cout << "*c_std = ";
		for (std::vector<int>::const_iterator v = sv.begin(); v != sv.end(); v++)
		{
			*v = i++; //const_iteratorなので不可
			std::cout << *v << ", ";
		}
		std::cout << std::endl;
		i = 0;
		std::cout << "*c_ft = ";
		for (ft::vector<int>::const_iterator v = fv.begin(); v != fv.end(); v++)
		{
			*v = i++; //const_iteratorなので不可
			std::cout << *v << ", ";
		}
		std::cout << std::endl;
*/

		//++hogeでstdとftを回して中身を見る
		tester.title("*(++hoge)");
		tester.comp(*(std), *(ft));
		for (int j = 0; j < 2; j++)
			tester.comp(*(++std), *(++ft));


		//test operator++
		tester.btitle("operator++");

		tester.title("*(begin()++)");
		c_std = sv.begin();
		c_ft = fv.begin();
		//a++でstdとftを回して中身を見る
		for (int j = 0; j < 3; j++)
			tester.comp(*(c_std++), *(c_ft++));
/*
		// *a++でreferenceが返ってきているかの確認->constなので失敗する
		c_std = sv.begin();
		c_ft = fv.begin();
		for (int j = 10; j < 13; j++)
		{
			*c_std++ = j;
			*c_ft++ = j;
		}
*/

		//test operator--
		tester.btitle("operator--");

		tester.title("*((end() - 1)--)");
		c_std = sv.end() - 1;
		c_ft = fv.end() - 1;
		//a--でstdとftを回して中身を見る
		for (int j = 0; j < 3; j++)
			tester.comp(*(c_std--), *(c_ft--));
/*
		// *a--でreferenceが返ってきているかの確認->constなので失敗する
		c_std = sv.end() - 1;
		c_ft = fv.end() - 1;
		for (int j = 23; 20 < j; j--)
		{
			*(c_std)-- = j;
			*(c_ft)-- = j;
		}
*/

		//test --operator
		tester.btitle("--operator");

		tester.title("*(--end())");
		c_std = sv.end();
		c_ft = fv.end();
		//--aでstdとftを回して中身を見る
		for (int j = 0; j < 3; j++)
			tester.comp(*(--c_std), *(--c_ft));
/*
		tester.title("*(--a) = int");//constなので失敗する
		c_std = sv.end();
		c_ft = fv.end();
		for (int j = 3; 0 < j; j--)
		{
			*(--c_std) = j;
			*(--c_ft) = j;
		}
		c_std = sv.end();
		c_ft = fv.end();
		for (int j = 0; j < 3; j++)
			tester.comp(*(--c_std), *(--c_ft));
*/

		//test operator==
		tester.btitle("operator==");

		std::cout << "*std = ";
		for (std::vector<int>::const_iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
		i = 0;
		std::cout << "*ft = ";
		for (ft::vector<int>::const_iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		std::vector<int>::const_iterator	c_s1;
		std::vector<int>::const_iterator	c_s2;
		ft::vector<int>::const_iterator		c_f1;
		ft::vector<int>::const_iterator		c_f2;
		std::vector<int>::iterator			s;
		ft::vector<int>::iterator			f;
		c_s1 = sv.begin();
		c_s2 = sv.begin();
		c_f1 = fv.begin();
		c_f2 = fv.begin();
		s = sv.begin();
		f = fv.begin();

		tester.title("(const)begin() == (const)begin() -> true");
		tester.comp((c_s1 == c_s2), (c_f1 == c_f2));

		tester.title("(const)begin() == (const)(begin()++) -> false");
		c_s2++;
		c_f2++;
		tester.comp((c_s1 == c_s2), (c_f1 == c_f2));

		tester.title("(const)begin() == begin() -> true");
		tester.comp((c_s1 == s), (c_f1 == f));

		tester.title("begin() == (const)begin() -> true");
		tester.comp((s == c_s1), (f == c_f1));

		//test operator!=
		tester.btitle("operator!=");

		c_s2 = sv.begin();
		c_f2 = fv.begin();
		tester.title("(const)begin() != (const)begin() -> false");
		tester.comp((c_s1 != c_s2), (c_f1 != c_f2));

		tester.title("(const)begin() != (const)(begin()++) -> true");
		c_s2++;
		c_f2++;
		tester.comp((c_s1 != c_s2), (c_f1 != c_f2));

		tester.title("(const)begin() != begin() -> false");
		tester.comp((c_s1 != s), (c_f1 != f));

		tester.title("begin() != (const)begin() -> false");
		tester.comp((s != c_s1), (f != c_f1));

		//test operator<
		tester.btitle("operator<");

		c_s2 = sv.begin();
		c_f2 = fv.begin();
		tester.title("(const)begin() < (const)begin() -> false");
		tester.comp((c_s1 < c_s2), (c_f1 < c_f2));

		tester.title("(const)begin() < (const)(begin()++) -> true");
		c_s2++;
		c_f2++;
		tester.comp((c_s1 < c_s2), (c_f1 < c_f2));

		tester.title("(const)begin() < begin() -> false");
		tester.comp((c_s1 < s), (c_f1 < f));

		tester.title("begin() < (const)begin() -> false");
		tester.comp((s < c_s1), (f < c_f1));

		//test operator>
		tester.btitle("operator>");

		c_s2 = sv.begin();
		c_f2 = fv.begin();
		tester.title("(const)begin() > (const)begin() -> false");
		tester.comp((c_s1 > c_s2), (c_f1 > c_f2));

		tester.title("(const)begin() > (const)(begin()++) -> false");
		c_s2++;
		c_f2++;
		tester.comp((c_s1 > c_s2), (c_f1 > c_f2));

		tester.title("(const)begin()++ > begin() -> true");
		tester.comp((c_s2 > s), (c_f2 > f));

		tester.title("begin() > (const)begin() -> false");
		tester.comp((s > c_s1), (f > c_f1));

		//test operator<=
		tester.btitle("operator<=");

		c_s2 = sv.begin();
		c_f2 = fv.begin();
		tester.title("(const)begin() <= (const)begin() -> true");
		tester.comp((c_s1 <= c_s2), (c_f1 <= c_f2));

		tester.title("(const)begin()++ <= (const)(begin()) -> false");
		c_s2++;
		c_f2++;
		tester.comp((c_s2 <= c_s1), (c_f2 <= c_f1));

		tester.title("(const)begin() <= begin() -> true");
		tester.comp((c_s1 <= s), (c_f1 <= f));

		tester.title("begin() <= (const)begin() -> true");
		tester.comp((s <= c_s1), (f <= c_f1));

		//test operator>=
		tester.btitle("operator>=");

		c_s2 = sv.begin();
		c_f2 = fv.begin();
		tester.title("(const)begin() >= (const)begin() -> true");
		tester.comp((c_s1 >= c_s2), (c_f1 >= c_f2));

		tester.title("(const)begin() >= (const)(begin()++) -> false");
		c_s2++;
		c_f2++;
		tester.comp((c_s1 >= c_s2), (c_f1 >= c_f2));

		tester.title("(const)begin()++ >= begin() -> true");
		tester.comp((c_s2 >= s), (c_f2 >= f));

		tester.title("begin() >= (const)begin() -> true");
		tester.comp((s >= c_s1), (f >= c_f1));

		//test iterator - iterator
		tester.btitle("const_iterator - const_iterator");
		c_s1 = sv.end();
		c_s2 = sv.begin();
		c_f1 = fv.end();
		c_f2 = fv.begin();
		s = sv.begin();
		f = fv.begin();

		tester.title("(const_iterator)ft.end() - (const_iterator)ft.begin()");
		tester.comp((c_s1 - c_s2), (c_f1 - c_f2));

		tester.title("(const_iterator)ft.end() - (iterator)ft.begin()");
		tester.comp((c_s1 - s), (c_f1 - f));

		tester.title("(iterator)ft.end() - (const_iterator)ft.begin()");
		s = sv.end();
		f = fv.end();
		tester.comp((s - c_s2), (f - c_f2));

		//test const_iterator + n
		tester.btitle("const_iterator + n");
		tester.title("ft.begin() + 1");
		c_s1 = sv.begin();
		c_f1 = fv.begin();
		c_s1 = c_s1 + 1;
		c_f1 = c_f1 + 1;
		c_s1 + 1;
		c_f1 + 1;
		tester.comp(*c_s1, *c_f1);
		tester.title("ft.begin() + 1 + 1");
		c_s1 = 1 + c_s1;
		c_f1 = 1 + c_f1;
		1 + c_s1;
		1 + c_f1;
		tester.comp(*c_s1, *c_f1);

		//test const_iterator - n
		tester.btitle("const_iterator - n");
		tester.title("ft.end() - 1");
		c_s1 = sv.end();
		c_f1 = fv.end();
		c_s1 = c_s1 - 1;
		c_f1 = c_f1 - 1;
		c_s1 - 1;
		c_f1 - 1;
		tester.comp(*c_s1, *c_f1);
		tester.title("ft.begin() - 1 - 1");
		c_s1 = c_s1 - 1;
		c_f1 = c_f1 - 1;
		tester.comp(*c_s1, *c_f1);

		//test const_iterator += n
		tester.btitle("const_iterator += n");

		std::cout << "*std = ";
		for (std::vector<int>::const_iterator v = sv.begin(); v != sv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;
		i = 0;
		std::cout << "*ft = ";
		for (ft::vector<int>::const_iterator v = fv.begin(); v != fv.end(); v++)
			std::cout << *v << ", ";
		std::cout << std::endl;

		tester.title("ft.begin() += 1");
		c_s1 = sv.begin();
		c_f1 = fv.begin();
		c_s1 += 1;
		c_f1 += 1;
		tester.comp(*c_s1, *c_f1);
		tester.title("ft += -1");
		c_s1 += -1;
		c_f1 += -1;
		tester.comp(*c_s1, *c_f1);

		//test const_iterator -= n
		tester.btitle("const_iterator -= n");
		tester.title("ft.end() -= 2");
		c_s1 = sv.end();
		c_f1 = fv.end();
		c_s1 -= 2;
		c_f1 -= 2;
		tester.comp(*c_s1, *c_f1);
		tester.title("ft -= -1");
		c_s1 -= -1;
		c_f1 -= -1;
		tester.comp(*c_s1, *c_f1);

		//test operator[]
		tester.btitle("operator[]");
		tester.title("v = ft.begin(), v[k], k = 3-0");
		c_std = sv.begin();
		c_ft = fv.begin();
		i = 3;
		int	j = 0;
		for (std::vector<int>::const_iterator v = sv.begin(); j < 3; j++)
		{
//			v[j] = i--; //const_iteratorなので不可
			std::cout << "std[j] = " << v[j] << std::endl;
		}
		i = 3;
		j = 0;
		for (ft::vector<int>::const_iterator v = fv.begin(); j < 3; j++)
		{
//			v[j] = i--; //const_iteratorなので不可
			std::cout << "ft[j]  = " << v[j] << std::endl;
		}
		for (int k = 0; k < 3; k++)
			tester.comp(c_std[k], c_ft[k]);

		tester.title("v = ft.begin() + 1, v[k]");
		c_std += 1;
		c_ft += 1;
		for (int k = 0; k < 2; k++)
			tester.comp(c_std[k], c_ft[k]);
	}
/*const_iteratorはswap不可
	{
		//swap_iter
		tester.btitle("swappable");
		tester.title("swap_iter");

		std::vector<int>	sv(4, 1);
		std::vector<int>	sv2(4, 2);
		std::vector<int>::const_iterator	std;
		std::vector<int>::const_iterator	std2;
		std = sv.begin();
		std2 = sv2.begin();
		ft::vector<int>	fv(4, 1);
		ft::vector<int>	fv2(4, 2);
		ft::vector<int>::const_iterator	ft;
		ft::vector<int>::const_iterator	ft2;
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
//		std::iter_swap(std, std2);
//		std::iter_swap(ft, ft2);
		tester.title("after swap(std, std1) and swap(ft, ft1) -> compare (std[i], ft[i]) ");
		for (int i = 0; i < 4; i++)
			tester.comp(std[i], ft[i]);
	}
*/
	{
		//operator->
		tester.btitle("operator->");
		tester.title("ft->size()");
		std::vector<std::string>			sv(2);
		ft::vector<std::string>				fv(2);
		std::vector<std::string>::iterator	std;
		ft::vector<std::string>::iterator	ft;
		std::vector<std::string>::const_iterator	c_std;
		ft::vector<std::string>::const_iterator		c_ft;
		std = sv.begin();
		ft = fv.begin();
		c_std = sv.begin();
		c_ft = fv.begin();
		*std = "tako";
		*(std + 1) = "ika";
		*ft = "tako";
		*(ft + 1) = "ika";
		//中身を確かめてみる
		for (int i =0; i < 2; i++)
		{
			std::cout << "c_std[i] = " << c_std[i] << ", size = " << (&c_std[i])->size() << std::endl;
			std::cout << "c_ft[i]  = " << c_ft[i]  << ", size = " << (&c_ft[i])->size() << std::endl;
		}
		int	s;
		int	f;
		for (int i =0; i < 2; i++)
		{
			s = c_std->size();
			f = c_ft->size();
			c_std++;
			c_ft++;
			tester.comp(s, f);
		}
	}

	{
		//const_vector -> const_vector
		tester.btitle("const_vector");

		const std::vector<int>	sv(2, 1);
		const ft::vector<int>	fv(2, 1);

		std::vector<int>::iterator			std;
		std::vector<int>::const_iterator	c_std;
		ft::vector<int>::iterator			ft;
		ft::vector<int>::const_iterator		c_ft;

//		std = sv.begin();
		c_std = sv.begin();
//		ft = fv.begin();
		c_ft = fv.begin();

//		std = sv.end();
		c_std = sv.end();
//		ft = fv.end();
		c_ft = fv.end();
		tester.title("const_vector -> const_iterator OK");

	}



}

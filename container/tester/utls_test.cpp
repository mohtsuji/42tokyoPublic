#include "Tester.hpp"
#include "../header/VectorIterator.hpp"
#include "../header/iterator.hpp"
#include "../header/reverse_iterator.hpp"
#include "../header/iterator_traits.hpp"
#include "../header/vector.hpp"
#include "../header/is_integral.hpp"
#include "../header/enable_if.hpp"
#include <vector>
#include <list>
#include <typeinfo>


// integral_constant::operator value_type example
#include <iostream>
#include <type_traits>

int main() {
//integral_constant

	Tester	tester;

	tester.btitle("integral_constant");
	{
	tester.title("");

	std::integral_constant<int, 10>	si;//(1)
	std::integral_constant<char, 'c'>	sc;
	std::true_type	st;
	std::false_type	sf;

	ft::integral_constant<int, 10>	fi;//(1)
	ft::integral_constant<char, 'c'>	fc;
	ft::true_type	ft;
	ft::false_type	ff;

	tester.title("::integral_constant<int, 10>");
	tester.comp(static_cast<int>(si), static_cast<int>(fi));

	tester.title("::integral_constant<char, 'c'>");
	tester.comp(static_cast<char>(sc), static_cast<char>(fc));

	tester.title("::true_type");
	tester.comp(static_cast<bool>(st), static_cast<bool>(ft));

	tester.title("::false_type");
	tester.comp(static_cast<bool>(sf), static_cast<bool>(ff));

	tester.title("::integral_constant<int, 10>()");
	tester.comp(static_cast<int>(std::integral_constant<int, 10>()), static_cast<int>(ft::integral_constant<int, 10>())); //多分default constructorが走ってるだけなので，実際やっていることは(1) と同じだと思う

	tester.title("cout << ::integral_constant<int, 10> << endl; -> conversion function test");
	std::cout << "si = " << si << std::endl;//これが可能なのは多分integral_constantはconvert functionを持っているから
	std::cout << "fi = " << fi << std::endl;//これが可能なのは多分integral_constantはconvert functionを持っているから

	tester.title("::true_type t.value");
	tester.comp(st.value, ft.value);//変数の中のメンバ変数にアクセスするときはドット

	tester.title("::true_type::value");
	tester.comp(std::true_type::value, ft::true_type::value);//型のメンバ変数にアクセスするときは::

	}

	tester.btitle("is_integral");
	{
		tester.title("::is_integral<int>()");
		tester.comp(static_cast<bool>(std::is_integral<int>()), static_cast<bool>(ft::is_integral<int>()));

		tester.title("::is_integral<int>::value");
		tester.comp(static_cast<bool>(std::is_integral<int>::value), static_cast<bool>(ft::is_integral<int>::value));

		tester.title("::is_integral<bool>::value");
		tester.comp(static_cast<bool>(std::is_integral<bool>::value), static_cast<bool>(ft::is_integral<bool>::value));
		tester.title("::is_integral<float>::value");
		tester.comp(static_cast<bool>(std::is_integral<float>::value), static_cast<bool>(ft::is_integral<float>::value));

	}

	tester.btitle("enable_if");
	{
		tester.title("::enable_if<::is_integral<int>::value, int>::type");

		tester.comp(typeid(std::enable_if<std::is_integral<int>::value, int>::type).name(), typeid(ft::enable_if<ft::is_integral<int>::value, int>::type).name());

		tester.title("::enable_if<::is_integral<int>::value, float>::type");
		tester.comp(typeid(std::enable_if<std::is_integral<int>::value, float>::type).name(), typeid(ft::enable_if<ft::is_integral<int>::value, float>::type).name());

		tester.title("::enable_if<::is_integral<float>::value, float>::type -> floatに対してはintegralがfalseを返した結果typeが生成されないので，compile errorになる");
//		tester.comp(typeid(std::enable_if<std::is_integral<float>::value, float>::type).name(), typeid(ft::enable_if<ft::is_integral<float>::value, float>::type).name());


	}

  return 0;
}

#include <string>
#include <iostream>
#include <cstdint>

#include "Data.hpp"

std::uintptr_t	serialize(Data* ptr)
{
	std::uintptr_t	value_pointer;

	value_pointer = reinterpret_cast<std::uintptr_t>(ptr);
	return (value_pointer);
}

Data*		deserialize(uintptr_t raw)
{
	Data*	d;

	d = reinterpret_cast<Data *>(raw);
	return (d);
}

int	main()
{
	Data			data(21);
	std::uintptr_t	u;
	Data			*re;

	std::cout << "---------start--------------" << std::endl;
	std::cout << "data.pointer = " << &data << std::endl;
	std::cout << "data.getInt() = " << data.getInt() << std::endl;

	std::cout << "---------serialize--------------" << std::endl;
	u = serialize(&data);
	std::cout << "u = " << u << std::endl;

	std::cout << "---------deserialize--------------" << std::endl;
	re = deserialize(u);
	std::cout << "re.pointer = " << re << std::endl;
	std::cout << "re.getInt() = " << re->getInt() << std::endl;
}

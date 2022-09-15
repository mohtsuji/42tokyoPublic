#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << RED"j type is " << j->getType() << RES << std::endl;
	std::cout << RED"i type is " << i->getType() << RES << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << BLE"---Wrong Patern-----"RES << std::endl;

	const WrongAnimal* w = new WrongCat();

	std::cout << RED"w type is " << w->getType() << RES << std::endl;
	w->makeSound();

	delete w;
}

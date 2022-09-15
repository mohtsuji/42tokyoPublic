#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*__attribute__((destructor))
static void destructor()
{
    system("leaks animal");
}*/

int	main()
{
	Dog basic;
	{
		Dog tmp = basic;
	}

	const Animal *animals[4];
	Brain *dogBrain;
	Brain *catBrain;

	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	dogBrain = animals[0]->getBrain();
	dogBrain->setIdeas("inu!", 0);
	dogBrain->setIdeas("totyuu wan!", 50);
	dogBrain->setIdeas("finish wan!", 99);

	catBrain = animals[2]->getBrain();
	catBrain->setIdeas("neko!", 0);
	catBrain->setIdeas("totyuu nyan!", 50);
	catBrain->setIdeas("finish nyan!", 99);

	std::cout << "------ここから犬------" << std::endl;

	for (int i = 0; i < 100; i++)
		std::cout << RED << dogBrain->getIdeas(i) << RES << std::endl;

	std::cout << "------ここから猫------" << std::endl;

	for (int i = 0; i < 100; i++)
		std::cout << GRN << catBrain->getIdeas(i) << RES << std::endl;

/*A copy of a Cat or Dog must be "deep".*/
	std::cout << "------ここからコピーチェック------" << std::endl;

	std::cout << "------ここから犬------" << std::endl;

	Animal *dogCopy = new Dog();
	*dogCopy = *animals[0];
	Brain *dogBcopy = dogCopy->getBrain();

	dogBcopy->setIdeas("copy Dog!", 0);

	for (int i = 0; i < 100; i++)
		std::cout << BLE << dogBcopy->getIdeas(i) << RES << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << RED << dogBrain->getIdeas(i) << RES << std::endl;

	std::cout << "------ここから猫------" << std::endl;

	Animal *catCopy = new Cat();
	*catCopy = *animals[2];
	Brain *catBcopy = catCopy->getBrain();

	catBcopy->setIdeas("copy Cat!", 0);

	for (int i = 0; i < 100; i++)
		std::cout << GRN << catBcopy->getIdeas(i) << RES << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << GRN << catBrain->getIdeas(i) << RES << std::endl;

	for (int i = 0; i < 4; i++)
		delete animals[i];
	delete dogCopy;
	delete catCopy;
}

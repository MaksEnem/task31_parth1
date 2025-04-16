#include <iostream>
#include <string>
#include <memory>

class Toy
{
private:
	std::string name;
public:
	Toy(std::string inName) : name(inName) {};
	Toy() : name("SomeToy") {};

	std::string getToyName()
	{
		return name;
	}

	~Toy() {
		std::cout << "Toy " << name << " was dropped " << std::endl;
	}
};


class Dog
{
private:
	std::string name = "Unknow name";
	int age = 0;
	std::shared_ptr<Toy> lovelyToy;
	
public:

	/*Dog(std::string inName, std::shared_ptr<Toy> toy, int inAge) : name(inName), lovelyToy(toy)
	{
		age = inAge;
	}*/

	Dog(std::string inName, int inAge) : name(inName)
	{
		if (inAge > 0 && inAge < 30)
		{
			age = inAge;			
		}
	}

	void getToy(const Toy& oth)
	{
		if (lovelyToy == nullptr)
		{
			std::cout << "nullptr" << std::endl;
			
		}
	}


	std::string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}


	std::string getToyName()
	{
		return lovelyToy->getToyName();
	}

	

	

};



int main()
{
	/*std::shared_ptr<Toy> toy = std::make_shared<Toy>("SomeToy");	

	std::shared_ptr<Dog> a = std::make_shared<Dog>("Sharik", toy, 10);	

	toy.reset();

	std::cout << "a: " <<  a->getToyName() << std::endl;*/
	

	std::shared_ptr<Toy> toy = std::make_shared<Toy>("SomeToy");
	std::cout << toy->getToyName() << std::endl;

	

	std::shared_ptr<Dog> dog = std::make_shared<Dog>("Sharik", 10);
	
	std::cout << dog->getName() << " " << dog->getAge() << std::endl;
	dog->getToy(*toy);

	return 0;
}
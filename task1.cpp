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
		//std::cout << "Toy " << name << " was dropped " << std::endl;
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

	Dog() {};

	Dog(std::string inName, int inAge) : name(inName)
	{
		if (inAge > 0 && inAge < 30)
		{
			age = inAge;			
		}
	}

	void getToy(const std::shared_ptr<Toy>& inToy)
	{
		
		if (lovelyToy == nullptr && (inToy.use_count() - 1 == 0))
		{			
			lovelyToy = inToy;		
			std::cout << name << ": The toy has been picked up." << std::endl;
		}
		else if (lovelyToy != nullptr)
		{
			std::cout << name << ": I already have this toy." << std::endl;
		}
		else
		{
			std::cout << name << ": Another dog is playing with this toy." << std::endl;
		}		
	}




	void dropToy()
	{
		if (lovelyToy != 0)
		{
			lovelyToy.reset();	
			std::cout << name << ": threw the toy" << std::endl;
		}
		else
		{
			std::cout << name << ": Nothing to drop." << std::endl;
		}
		
	}



	std::string getToyName()
	{
		return lovelyToy->getToyName();
		
	}

	
	std::string getDogName()
	{
		return name;
	}
	int getDogAge()
	{
		return age;
	}


	void setName()
	{
		std::cout << "Enter dog's name: ";
		std::cin >> name;
	}
	void setAge()
	{
		std::cout << "Enter dog's age: ";
		std::cin >> age;
	}

	~Dog()
	{
		
	}
};



int main()
{
	/*std::shared_ptr<Toy> toy = std::make_shared<Toy>("SomeToy");	

	std::shared_ptr<Dog> a = std::make_shared<Dog>("Sharik", toy, 10);	

	toy.reset();

	std::cout << "a: " <<  a->getToyName() << std::endl;*/
	





	//std::shared_ptr<Toy> toy = std::make_shared<Toy>("SomeToy");
	//std::cout << "Name of the toy: " << toy->getToyName() << std::endl;
	//
	//
	//std::shared_ptr<Dog> dog = std::make_shared<Dog>("Sharik", 10);
	//
	//
	////std::cout<< "Dog name and age: " << dog->getName() << " " << dog->getAge() << std::endl;
	//dog->getToy(toy);	
	//dog->dropToy();
	//dog->count(toy);
	

	





	//std::shared_ptr<Toy> toy = std::make_shared<Toy>("SomeToy");
	////std::cout << toy.use_count() << std::endl;

	//std::shared_ptr<Dog> a = std::make_shared<Dog>("Sharik", 10);
	//std::shared_ptr<Dog> b = std::make_shared<Dog>("Bobik", 12);
	//std::shared_ptr<Dog> c = std::make_shared<Dog>("Druzhok", 11);



	//a->getToy(toy);		
	//b->getToy(toy);
	//
	////b->getToy(toy);
	//
	//a->dropToy();

	//b->getToy(toy);
	
	

	std::shared_ptr<Toy> toy = std::make_shared<Toy>("SomeToy");

	
	Dog* dog[3];
	dog[0] = new Dog("Sharik", 10);
	dog[1] = new Dog("Bobik", 12);
	dog[2] = new Dog("Druzhok", 11);

	
	dog[0]->getToy(toy);
	dog[1]->getToy(toy);
	
	//b->getToy(toy);
	
	dog[0]->dropToy();

	dog[1]->getToy(toy);


	return 0;
}
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

};


int main()
{
	
	std::string command;
	int number;
	std::shared_ptr<Toy> toy = std::make_shared<Toy>("SomeToy");

	
	Dog* dog[3];
	dog[0] = new Dog("Sharik", 10);
	dog[1] = new Dog("Bobik", 12);
	dog[2] = new Dog("Druzhok", 11);

	do {
		std::cout << "Enter \"getToy\" to make dog pick up toy." << std::endl;
		std::cout << "Enter \"dropToy\" to make dog throw toy" << std::endl;
		std::cout << "To terminate the program, enter exit." << std::endl;
		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "getToy")
		{
			std::cout << "Enter the name of the dog number \"1-3\": " << std::endl;
			std::cin >> number;
			--number;
			dog[number]->getToy(toy);			
		}
		else if (command == "dropToy")
		{
			std::cout << "Enter the name of the dog number \"1-3\": " << std::endl;
			std::cin >> number;
			--number;
			dog[number]->dropToy();
		}
		
	} while (command != "exit");

	return 0;
}
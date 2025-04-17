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

	void getToy(const std::shared_ptr<Toy>& inToy)
	{
		if (lovelyToy == nullptr)
		{			
			lovelyToy = inToy;					
		}
		else if (lovelyToy != nullptr)
		{
			std::cout << "I already have this toy." << std::endl;
		}
	}


	void count(std::shared_ptr<Toy> inToy)
	{
		std::cout << "in fun(): sp.use_count() == " << inToy.use_count()
			<< " (object @ " << inToy << ")\n";
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
	std::cout << "Name of the toy: " << toy->getToyName() << std::endl;
	
	
	std::shared_ptr<Dog> dog = std::make_shared<Dog>("Sharik", 10);
	std::shared_ptr<Dog> dog2 = std::make_shared<Dog>("Sharik", 10);
	
	//std::cout<< "Dog name and age: " << dog->getName() << " " << dog->getAge() << std::endl;
	dog->getToy(toy);
	dog2->getToy(toy);
	
	
	dog->count(toy);
	dog2->count(toy);
	return 0;
}
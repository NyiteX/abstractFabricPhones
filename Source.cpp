#include <iostream>
#include <vector>
using namespace std;

class Phone
{
public:
	virtual void CreatePhone() = 0;
	virtual ~Phone() {}
};

class Smartphone :public Phone
{
public:
	void CreatePhone() override
	{
		cout << "Creating smartphone...\n";
	}
};
class ClassicPhone :public Phone
{
public:
	void CreatePhone() override
	{
		cout << "Creating classic Phone...\n";
	}
};


class Factory
{
public:
	virtual	Phone* createPhone() = 0;
	virtual ~Factory() {};
};

class SmartFactory:public Factory
{
public:
	Phone* createPhone() override { return new Smartphone; }
};

class ClassicFactory :public Factory
{
public:
	Phone* createPhone() override { return new ClassicPhone; }
};

class Army
{
public:
	vector<Phone* > vi;
	~Army()
	{
		int i;
		for (i = 0; i < vi.size(); i++) delete vi[i];
	}
	void info()
	{
		int i;
		for (i = 0; i < vi.size(); i++)  vi[i]->CreatePhone();
	}
};
class Game
{
public:
	Army* createArmy(Factory& factory)
	{
		Army* p = new Army;
		p->vi.push_back(factory.createPhone());
		return p;
	}
};

int main()
{	
	SmartFactory SP_factory;
	ClassicFactory CP_factory;

	vector<Phone*>t;
	t.push_back(SP_factory.createPhone());
	t.push_back(CP_factory.createPhone());
	t.push_back(SP_factory.createPhone());
	t.push_back(CP_factory.createPhone());
	int i;
	for (i = 0; i < t.size(); i++)  t[i]->CreatePhone();
	for (i = 0; i < t.size(); i++) delete t[i];
	return 1;

	//garbage
	Game game;

	Army* SP = game.createArmy(SP_factory);
	Army* CP = game.createArmy(CP_factory);
	SP->info();
	CP->info();

}
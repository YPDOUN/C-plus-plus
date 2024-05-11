#include<iostream>
#include<string>
using namespace std;
/*
	虚函数通过在基类（父类）中声明虚函数，然后在派生类（子类）中对其进行重写，实现多态

	关键词：virtual是用于基类中声明函数的关键字，用来表示该函数是虚函数，可以被派生类重写（覆盖）
		   override用于在派生类中 显式地 标识对基类中虚函数的重写

		   override提高了代码可读性，同时可以帮助检测是否 正确地 重写了基类中的虚函数
		   前提是基类标记virtual声明虚函数 override显示地表面是对虚函数的重写
*/

class Entity
{
public:
	virtual string GetName() { return "Entity"; }

};

class Player :public Entity
{
private:
	string m_Name;
public:
	Player(const char* name)
		: m_Name(name) {};

	string GetName() override { return m_Name; }
};

void PrintName(Entity* entity)
{
	cout << entity->GetName() << endl;
}


int main()
{
	Entity* e = new Entity();
	PrintName(e);

	Player* p = new Player("yes");
	PrintName(p);
	return 0;
}
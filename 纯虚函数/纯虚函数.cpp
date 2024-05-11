#include<iostream>
using namespace std;
/*
	   纯虚函数：在基类中声明没有提供实现，需要在子类中进行重写
			   本身不能被实例化，只能作为接口供其他类继承，子类没有进行重写就不能进行实例化
	   定义：virtual void func() = 0

	   纯虚函数与虚函数的区别：
	   基类如果所有都是 纯虚函数 则其子类要逐一进行重写 否则子类也是抽象类不能被实例化
	   而只存在虚函数可以选择性地对虚函数进行重写，进而实现多态

	   接口：包含未实现的函数 供子类进行重写
*/

//创建一个纯虚函数作为接口
class Printable
{
public:
	virtual string GetClassName() = 0;//定义一个未实现的函数
};


class Entity: public Printable
{
public: 
	string GetClassName() override { return "Entity"; }
};

class Player :public Entity
{
public:
	Player(const char* name)
		:m_Name(name) {};

	string GetClassName() override { return m_Name; }

private:
	string m_Name;
};

void Print(Printable* obj)
{
	cout << obj->GetClassName() << endl;
}
int main()
{
	//Printable* e = new Printable(); 不能对接口进行实例化

	Entity* e = new Entity();
	Print(e);

	Player* p = new Player("Player");
	Print(p);

	return 0;
}
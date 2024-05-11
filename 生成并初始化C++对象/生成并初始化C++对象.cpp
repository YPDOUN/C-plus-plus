#include<iostream>
#include<string.h>
using namespace std;
/*
   创建对象的两个区域：栈区和堆区
   栈区创建：生命周期与所在函数的生命周期相同 函数执行完毕会自动销毁
   堆区创建：用new关键字在堆区申请内存 后续需要用delete释放内存 否则不会自动销毁

*/
class Entity
{
private:
	string m_Name;
public:
	Entity() :m_Name("Unknown") {};
	Entity(const string Name) :m_Name(Name) {};

	const string& GetName() const { return m_Name; }
};

int main()
{
	//栈上创建对象并调用构造函数进行赋值

	/*Entity e1;
	cout << e1.GetName() << endl;

	Entity e2("cheron");
	cout << e2.GetName() << endl;*/

	//堆上创建对象
	Entity* e;
	{
		Entity* entity = new Entity("cheron");
		e = entity;
		cout << e->GetName() << endl;
	}

	delete e;
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
/*
      隐式转换：编程语言自动将一种数据类型转换为另一种数据类型的过程，而无需程序员显式地进行转换
	  explicit：explicit是一个关键字，用于修饰类的单参数构造函数，防止隐式转换

	  '=' 用来初始化一个变量或赋值可能会发生类型转换，这种类型转换可能会是隐式的

	  MyClass obj = 10  此过程发生了隐式转换 10被隐式地转换成了MyClass对象

*/
class Entity
{
private:
	string m_Name;
	int m_Age;
public:
	Entity(const string& name) :m_Name(name), m_Age(-1) {};
	Entity(int age) :m_Name("Unknown"), m_Age(age) {};
};

void Print(const Entity& entity)
{
	
}
int main()
{
	Entity a = 10;

	Print(10);//10可以传过去

	//Print("cheron");char类型的
	Print(string("cheron"));//用string显式地把char类型转换成string 
	return 0;
}
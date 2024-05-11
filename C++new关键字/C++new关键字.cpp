#include<iostream>
using namespace std;
/*
		C++中 new关键字和malloc()函数：
		new 使用new进行内存分配的时候会自动调用构造函数进行数据的初始化 并且内部会自动计算类型的空间大小 不必像malloc手动分配

		两者区别：
		new是关键字，可以被重载
		malloc是函数 会返回一个 void* 的指针，所以还需要手动进行类型转换
		new分配内存的同时会调用构造函数
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
	int a = 2;
	int* b = new int[5];
	delete[] b;

	Entity* e = new Entity();
	delete e;
	//== Entity* e = (Entity*)malloc(sizeof(Entity))
	return 0;
}
#include<iostream>
using namespace std;
/*
      1.可以用来访问对象的成员 该对象是指针所指向的结构体或者类 entity e； entity* ptr = &pe；  pe->成员
      2.->的重写Entity* operator->()
	  3.获取内存中某个成员变量的偏移量
*/
class Entity
{
public:
	void Print() const { cout << "Hello" << endl; }
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		:m_Obj(entity)
	{

	}
	~ScopedPtr()
	{
		delete m_Obj;
	}
	Entity* operator->()
	{
		return m_Obj;
	}
};

struct vector
{
	float x, y, z;
};
int main()
{
	ScopedPtr entity = new Entity();
	entity->Print();

	int offerset = (int) & ((vector*)nullptr)->x;
	cout << offerset << endl;

	offerset = (int)&((vector*)nullptr)->y;
	cout << offerset << endl;

	offerset = (int)&((vector*)nullptr)->z;
	cout << offerset << endl;
	return 0;
}
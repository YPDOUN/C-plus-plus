#include<iostream>
using namespace std;
/*
	构造函数是一种特殊类型的方法，每次构造一个对象都会调用的方法
	无返回类型，并且名称必须与类的名称相同
	不实例化对象将不会运行

	构造函数————初始化对象的内存空间
*/
class Entity
{
public:
	float X, Y;

	//构造函数
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	void Print()
	{
		cout << X << "," << Y << endl;
	}
};
int main()
{
	Entity e;
	cout << e.X << e.Y << endl;
	e.Print();
	return 0;
}
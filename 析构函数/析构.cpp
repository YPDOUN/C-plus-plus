/*
    析构函数是在对象被销毁时自动调用的特殊成员函数

	作用是释放对象占用的资源或执行清理工作，以确保对象在销毁时能够正确地释放资源，防止内存泄露
*/

#include<iostream>
using namespace std;

class Entity
{
public:
	float X, Y;

	//构造函数
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
		cout << "created Entity" << endl;
	}

	//析构函数
	~Entity()
	{
		cout << "destroyed Entity" << endl;
	}


	void Print()
	{
		cout << X << "," << Y << endl;
	}
};

//主函数内使用的话 因为是在栈上创建 只会在程序结束时调用析构函数
void Function()
{
	Entity e;
	cout << e.X << e.Y << endl;
	e.Print();
}

int main()
{
	Function();
	return 0;
}
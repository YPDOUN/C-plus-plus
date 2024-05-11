#include<iostream>
using namespace std;

/*
     用于类 
	 const放置在方法(函数)后面 主要是为了定义不可变的成员函数(即常量成员函数) 且承诺不会修改类的任何成员变量
	 常对象 只能调用常量成员函数
	 是只读的

*/
class Entity
{
private:
	int m_X, m_Y;
	mutable int ver;
public:
	int GetX() const //一个方法承诺不修改数据成员 内部写的内容不能进行修改 当有mutable修饰的数据成员时可以被修改
	{
		ver = 2;
		return m_X;
	}
};

void PrintEntity(const Entity& e1)
{
	//将类里面的const删掉 以下不能运行 因为形参是常量对象 只能调用常量成员函数 而删掉const后类中就不具备常量成员函数了
	cout << e1.GetX() << endl;
}
int main()
{
	Entity e;
	PrintEntity(e);




	/*
	      用于普通变量
	*/

	const int MAX_AGE = 100;
	//a = 2;无法被修改

	/*
		  用于指针变量
	*/

	const int* a = new int;//==int const* a

	//*a = 2;//限定了a存储的值 而指针指向可以修改
	a = (int*)&MAX_AGE;
	cout << *a << endl;

	int* const b = new int;

	*b = 2;
	//b = (int*)&MAX_AGE;限定了b的指向 但b的内容可以被修改
	cout << *b << endl;

	return 0;
}
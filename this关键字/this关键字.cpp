#include<iostream>
using namespace std;
/*
      this指针是一个特殊的指针，它指向当前对象的地址
	  一个成员函数 内部访问 对象的数据成员或调用对象的其他成员函数时，可以使用this指针来引用当前对象

	  在静态成员函数中的使用：静态成员函数不属于任何特定的对象，因此不能在静态成员函数中使用this指针

*/
void PrintEntity(Entity& e);
class Entity
{
public:
	int x, y;
	/*
          存在相同名字的变量时 this表示当前对象
	*/
	Entity(int x, int y)
	{
		//Entity* const e = this 
		this->x = x;
		this->y = y;
	/*
	      或者把当前类传给外部函数  
	*/
		PrintEntity(*this);
	}
};
void PrintEntity(Entity& e)
{
	//print
}
int main()
{
	return 0;
}
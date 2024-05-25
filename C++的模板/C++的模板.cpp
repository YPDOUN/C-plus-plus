#include<iostream>
using namespace std;
/*
     模板：允许我定义一个可以根据我的用途进行编译的模板；允许我编写通用的代码，以便在不同的数据类型上工作，减少重复代码
	 当模板没有实际使用到，不会产生任何代码
*/

template <typename T>
void Print(T value)
{
	cout << value << endl;
}

template <typename T, int N>//可指定类型和大小
class Array
{
private:
	int array[N];
public:
	int GetSize() const { return N; }
};
int main()
{
	Print("Hello");
	Print(5);
	Print(5.5f);

	Array<int, 5> a1;
	cout << a1.GetSize() << endl;
	return 0;
}
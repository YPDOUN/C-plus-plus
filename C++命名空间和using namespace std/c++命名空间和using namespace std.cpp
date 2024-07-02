#include<iostream>
#include<string>
/*
       using namespace std;
	   std是C++标准库 使用标准库里的内容如string，cout，vector等都需声明其作用域std::
	   using namespace std 的作用是将整个 std 命名空间中的所有符号引入当前的作用域；
	   可理解为扩大了标准库的作用域，当在当前cpp文件里声明为全局时；所以不用加上std::以强调在哪个作用域
	   ！使用时最好声明在局部，并不要在头文件里声明

	   命名空间namespace
	   1.减少命名冲突 通过命名空间名访问代码中可能存在的相同名字的函数或者操作，例如通过std命名空间访问cout对象
	   2.提高代码可阅读性
	   3.封装和隐藏 隐藏其内部细节避免滥用和误用
	   同时也可以让namespace name = apple(命名空间) 通过a::print("HELLO") 在嵌套命名空间可以减少代码量
*/
namespace apple {

	void print(const std::string& text)
	{
		std::cout << text << std::endl;
	}

}
namespace orange {

	void print(const char* text)
	{
		std::string tem = text;
		std::reverse(tem.begin(), tem.end());
		std::cout << tem << std::endl;
	}
}
void test1()
{
	using namespace apple;
	using namespace orange;

	print("HELLO");//apple的print包含隐式转换，故优先调用orange里的
}
int main()
{
	test1();
	std::cin.get();
}
#include<iostream>
#include<vector>
using namespace std;
/*
    容器：一种数据结构，存储和管理一组对象；例如：动态数组(vector)
	vector：是 C++ 标准库中的一个动态数组容器，它提供了动态大小的数组功能，允许在运行时动态添加或删除元素
	创建方法：
	        std::vector<element> myVector
	打印数据方法：
	           1.迭代器：for (auto it = myVector.begin(); it != myVector.end(); ++it) 
			     使用这种方法当遇到erase元素时,如：it = other.m_Array.erase(it); 可能会导致it无法正确更新 导致出错
				 应使用while(it != myVector.end())   if() ...  else ++i; 才能保证有效更新
			   2.范围循环：for(element Myname:container) 例如：for(int myname: myvector) -> 适用于数组或者字符串打印
			   用引用更好，减少复制的次数，加上const防止元素被修改出错const element& myname
	添加元素：
	        myvector.push_back();
	访问元素：
	        []下标访问 或者.at()访问
	        1.myvector[0]
			2.myvector.at(0)
	清空元素:
	        myvector.clear();
	删除元素：
	        myvector.erase(myvector.begin() + 1)
	获取大小：
	        myvector.size();
*/
struct Vertex
{
	float x, y, z;
};

ostream& operator<<(ostream& ostream, const Vertex& vertex)
{
	cout << vertex.x << "," << vertex.y << "," << vertex.z << endl;
	return ostream;
}
int main()
{
	vector<Vertex>Vertexs;//Vertexs是vector容器，存储的元素类型是Vertex的	
	Vertexs.push_back({ 1,2,3 });
	Vertexs.push_back({ 4,5,6 });
	for (int i = 0; i < Vertexs.size(); i++)
		cout << Vertexs[i];
	for (const Vertex& v : Vertexs)
		cout << v;

	//Vertexs.clear();
	Vertexs.erase(Vertexs.begin() + 1);//范围循环
	for (Vertex v : Vertexs)
		cout << v;
	return 0;
}


/*
     上面的vector<Vertex>Vertexs可以声明为 vector<Vertex*>Vertexs为何不用？

	 1.Vertex是存储结构体的，存储的是为一整块连续的数据的 不是像指针那样的碎片 更有利于数据的读取和操作
	 2.如果vertex是存储字符串的，由于字符串的大小可能很大，动态数组扩充空间的时候是复制本身数据到另一个地方，这样速度十分慢，
	   这个时候用指针就比较快速
*/
/*
     push_back和emplace_back的区别：
	 push_back添加元素时会调用拷贝构造函数 生成该类的副本 然后再将副本放进容器里
	 其次当空间容量(capacity)不够时 会生成已有元素副本 将已有元素拷贝进新的内存中 这会生成一次拷贝 放入新的元素会再生成一次拷贝
	 emplace_back则是直接添加元素

	 当我有一个对象 想把对象复制进容器中 此时可以使用push_back
*/
#include<iostream>
using namespace std;
/*
    浅层拷贝 直接把类赋值给一个新类 例如下面的 String second = string; 默认拷贝构造函数就是浅层拷贝
	只是直接复制指针 所以新类的m_Buffer也指向同一块区域 会造成悬空指针


*/
class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size + 1);
		m_Buffer[m_Size] = 0;
	}
	~String()
	{
		delete[] m_Buffer;
	}
	friend ostream& operator<<(ostream& ostream, const String& string);
	//String(const String& other) = delete;///删除默认拷贝函数

	String(const String& other)
		:m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}
};

ostream& operator<<(ostream& ostream, const String& string)
{
	cout << string.m_Buffer;
	return ostream;
}

int main()
{
	String string = "cheron";
	String second = string;
	second[2] = 'a';

	cout << string << endl;
	cout << second << endl;
	return 0;
}
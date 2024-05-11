#include<iostream>
using namespace std;

class Entity
{
public:
	Entity()
	{
		cout << "created Entity!" << endl;
	}
	~Entity()
	{
		cout << "destroyed Entity!" << endl;
	}
};
class smartptr
{
private:
	Entity* m_ptr;
public:
	smartptr(Entity* e) : m_ptr(e) {};
	
	~smartptr() { delete m_ptr; }
};
int main()
{
	smartptr e(new Entity()); // smartptr e = new Entity();
	return 0;
}
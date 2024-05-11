#include<iostream>
#include<memory>
using namespace std;
/*
      unique_ptr 是一种 独占所有权 的智能指针，它确保在任何时候只有一个 unique_ptr 实例可以拥有指向特定对象的所有权。
	  当unique_ptr被销毁时，它所拥有的对象也会被自动销毁

	  shared_ptr 是一种共享所有权的智能指针，它允许多个 shared_ptr 实例共享对同一个对象的所有权。
	  通过引用计数，shared_ptr 能够跟踪有多少个指针共享同一对象，并在最后一个 shared_ptr 被销毁时释放对象的内存。

*/
class Entity
{
public:
	Entity() { cout << "created Entity!" << endl; }

	~Entity() { cout << "destoryed Entity!" << endl; }

	void Print() { cout << "Entity" << endl; }
};

int main()
{
	{
		unique_ptr<Entity>entity = make_unique<Entity>();
		entity->Print();

		//unique_ptr<Entity>e0 = entity;  只有一个 unique_ptr 可以拥有对其所指对象的所有权 不能分配多个对象
	}//出了作用域entity就会被自动销毁


	{
		shared_ptr<Entity>e0;
		{
			shared_ptr<Entity> ShareEntity = make_shared<Entity>();
			e0 = ShareEntity;
		}
		//e0还持有对Entity的引用 故出了这个作用域 还不会销毁Entity
	}
	//出了该作用域 Entity被销毁
	return 0;
}
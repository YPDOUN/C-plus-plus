#include<iostream>
using namespace std;

class Entity
{
public :
	float X, Y;
	
	void move(int x , int y)
	{
		X += x;
		Y += y;
	}
};

//继承
class Player : public Entity
{
public:
	const char* name;
	void Print()
	{
		cout << name << endl;;
	}
};


int main()
{
	Player player; //Player总是Entity的超集

	//player.move(1, 5);

	cout << sizeof(Entity) << endl;//8 --> two float

	cout << sizeof(Player) << endl;//16 --> two float + 1 pointer

	return 0;
}
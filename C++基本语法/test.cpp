#include<iostream>
using namespace std;

class Player
{
public:
	int X, Y;
	int Speed = 4;

	void Move(int x, int y)
	{
		X += x * Speed;
		Y += y * Speed;
	}

};
int main()
{
	Player player;
	/*
	由类类型构成的变量叫做对象  新的对象变量称为实例
	上述操作：实例化一个Player对象
	*/
	player.X = 3;
	player.Y = 3;

	player.Move(-1, 1);

	return 0;
}
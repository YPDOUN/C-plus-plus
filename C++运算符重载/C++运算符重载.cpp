#include<iostream>
using namespace std;
/*
    形式： operator(关键字) 运算符(+-*)

*/
struct Vector2
{
	float X, Y;
	Vector2(float x, float y) :X(x), Y(y) {};

	Vector2 Add(const Vector2& other)const
	{
		return Vector2(X + other.X, Y + other.Y);
	}
	Vector2 operator+(const Vector2& other)const
	{
		return Add(other);
	}

	Vector2 Multiple(const Vector2& other)const
	{
		return Vector2(X * other.X, Y * other.Y);
	}
	Vector2 operator*(const Vector2& other)const
	{
		return Multiple(other);
	}
};
//重载 << 操作符
ostream& operator<<(ostream& stream, const Vector2& other)
{
	cout << other.X << "," << other.Y;
	return stream;
}
int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(1.5f, 0.8f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Multiple(powerup));//包含了向量类(Vector2)的加和乘运算
	Vector2 result2 = position + speed * powerup;

	cout << result2 << endl;
	return 0;
}
#include <iostream>
using namespace std;

class Drib {
private:
    double x=1, y=1;


	inline bool isYOdnakove(const int& y1, const int& y2)
	{
		if (y1 == y2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
public:
	Drib() = default;
	Drib(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void input() {
		cout << "Input x: "; cin >> x;
		cout << "Input y: "; cin >> y;
	}
    void print() {
		cout << "" << x << "\n----\n" << "" << y << "\n\n\n";
    }
	void setX(const double& x) {
		this->x = x;
	}
	void setY(const double& y) {
		this->y = y;
	}
	double getX() {
		return x;
	}
	double getY() {
		return y;
	}
	Drib add(const Drib& other) {
		if (isYOdnakove(this->y, other.y))
		{
			int a = this->x + other.x;
			Drib res(a, this->y);
			return res;
		}
		int a = this->x * other.y + other.x * this->y;
		int b = this->y * other.y;
		Drib res(a, b);
		return res;
	}
	Drib sub(const Drib& other) {
		if (isYOdnakove(this->y, other.y))
		{
			int a = this->x - other.x;
			Drib res(a, this->y);
			return res;
		}
		int a = this->x * other.y - other.x * this->y;
		int b = this->y * other.y;
		Drib res(a, b);
		return res;
	}
	Drib mul(const Drib& other) {
		if (isYOdnakove(this->y, other.y))
		{
			int a = this->x * other.x;
			Drib res(a, this->y);
			return res;
		}
		int a = (this->x * other.y) * (other.x * this->y);
		int b = this->y * other.y;
		Drib res(a, b);
		return res;
	}
	Drib div(const Drib& other) {
		int temp_x = other.y;
		int temp_y = other.x;
		if (isYOdnakove(this->y, temp_y))
		{
			int a = this->x * temp_x;
			Drib res(a, this->y);
			return res;
		}
		int a = (this->x * temp_y) * (temp_x * this->y);
		int b = this->y * temp_y;
		Drib res(a, b);
		return res;
	}
};


int main()
{
	Drib drib;
	drib.input();
	drib.print();
	Drib drib2(2, 3);
	Drib res_sum = drib.add(drib2);
	cout << "added" << endl;
	res_sum.print();
	Drib res_sub = drib.sub(drib2);
	cout << "subtracted" << endl;
	res_sub.print();
	Drib res_mult = drib.mul(drib2);
	cout << "multiplied" << endl;
	res_mult.print();
	Drib res_div = drib.div(drib2);
	cout << "divided" << endl;
	res_div.print();

	drib.setX(5);
	drib.setY(25);
	cout << "set x to 5 and y to 25" << endl;
	drib.print();

	cout << "x = " << drib.getX() << endl;
	cout << "y = " << drib.getY() << endl;
}
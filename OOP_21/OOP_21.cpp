#include <iostream>
using namespace std;

class Drib {
private:
    double x=1, y=1;
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
	void addX(const double& x) {
		this->x += x;
	}
	void addY(const double& y) {
		this->y += y;
	}
	void subX(const double& x) {
		this->x -= x;
	}
	void subY(const double& y) {
		this->y -= y;
	}
	void mulX(const double& x) {
		this->x *= x;
	}
	void mulY(const double& y) {
		this->y *= y;
	}
	void divX(const double& x) {
		this->x /= x;
	}
	void divY(const double& y) {
		this->y /= y;
	}
};


int main()
{
	Drib drib;
	drib.input();
	drib.print();
	drib.addX(1);
	drib.addY(1);
	cout << "added 1 to x and y" << endl;
	drib.print();
	drib.subX(1);
	drib.subY(1);
	cout << "subtracted 1 from x and y" << endl;
	drib.print();
	drib.mulX(2);
	drib.mulY(2);
	cout << "multiplied x and y by 2" << endl;
	drib.print();
	drib.divX(2);
	drib.divY(2);
	cout << "divided x and y by 2" << endl;
	drib.print();

	drib.setX(5);
	drib.setY(25);
	cout << "set x to 5 and y to 25" << endl;
	drib.print();

	cout << "x = " << drib.getX() << endl;
	cout << "y = " << drib.getY() << endl;
}
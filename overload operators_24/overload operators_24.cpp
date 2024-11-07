#include <iostream>
using namespace std;


class Drib {
private:
	double x = 1, y = 1;


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


	Drib operator+(const Drib& other)
	{
		return add(other);
	}
	Drib operator-(const Drib& other)
	{
		return sub(other);
	}
	Drib operator*(const Drib& other)
	{
		return mul(other);
	}
	Drib operator/(const Drib& other)
	{
		return div(other);
	}
};

class Complex {
private:
	double real_val;
	double imaginary_val;

public:
	Complex() 
		: real_val(0), imaginary_val(0) {}
	Complex(double real, double imaginary) 
		: real_val(real), imaginary_val(imaginary) {}


	inline double getReal() const { 
		return real_val; 
	}
	inline double getImaginary() const { 
		return imaginary_val; 
	}


	inline void setReal(double r) { 
		real_val = r; 
	}
	inline void setImaginary(double i) { 
		imaginary_val = i; 
	}


	Complex operator+(const Complex& other) const {
		return Complex(real_val + other.real_val, imaginary_val + other.imaginary_val);
	}


	Complex operator-(const Complex& other) const {
		return Complex(real_val - other.real_val, imaginary_val - other.imaginary_val);
	}


	Complex operator*(const Complex& other) const {
		double newReal = real_val * other.real_val - imaginary_val * other.imaginary_val;
		double newImag = real_val * other.imaginary_val + imaginary_val * other.real_val;
		return Complex(newReal, newImag);
	}


	Complex operator/(const Complex& other) const {
		double denominator = other.real_val * other.real_val + other.imaginary_val * other.imaginary_val;
		if (denominator == 0) {
			cout << "Error! Division by zero." << endl;
			return Complex(0, 0);
		}

		double newReal = (real_val * other.real_val + imaginary_val * other.imaginary_val) / denominator;
		double newImaginary = (imaginary_val * other.real_val - real_val * other.imaginary_val) / denominator;
		return Complex(newReal, newImaginary);
	}

	void print() const {
		cout << real_val << (imaginary_val >= 0 ? " + " : " - ")
			<< (imaginary_val >= 0 ? imaginary_val : -imaginary_val) << "i";
		cout << "\n\n";
	}


	void input() {
		cout << "Enter real part: ";
		cin >> real_val;
		cout << "Enter imaginary part: ";
		cin >> imaginary_val;
	}

};


int main()
{
	Drib drib;
	drib.input();
	drib.print();
	Drib drib2(2, 3);
	Drib res_sum = drib + drib2;
	cout << "added" << endl;
	res_sum.print();
	Drib res_sub = drib - drib2;
	cout << "subtracted" << endl;
	res_sub.print();
	Drib res_mult = drib * drib2;
	cout << "multiplied" << endl;
	res_mult.print();
	Drib res_div = drib / drib2;
	cout << "divided" << endl;
	res_div.print();

    Complex num1;
    Complex num2;
    num1.input();
    num2.input();
    Complex sum = num1 + num2;
    cout << "Sum: ";
    sum.print();
	Complex sub = num1 - num2;
	cout << "Sub: ";
	sub.print();
	Complex mult = num1 * num2;
	cout << "Mult: ";
	mult.print();
	Complex div = num1 / num2;
	cout << "Div: ";
	div.print();
}
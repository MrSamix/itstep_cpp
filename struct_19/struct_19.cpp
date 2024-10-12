#include <iostream>
#include <string>
using namespace std;

struct Car {
    string color;
    string model;
    string number;
};

void fillCar(Car& car) {
    cout << "Enter the color of the car: ";
    cin >> car.color;
    cout << "Enter the model of the car: ";
    cin >> car.model;
    cout << "Enter the number of the car: ";
    cin >> car.number;
}

void printCar(const Car& car) {
    cout << "Color: " << car.color << endl;
    cout << "Model: " << car.model << endl;
    cout << "Number: " << car.number << endl;
}

void editCar(Car& car) {
    cout << "Enter the new color of the car: ";
    cin >> car.color;
    cout << "Enter the new model of the car: ";
    cin >> car.model;
    cout << "Enter the new number of the car: ";
    cin >> car.number;
}

void printAllCars(const Car* cars, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << "Car " << i + 1 << ":" << endl;
        printCar(cars[i]);
        cout << endl;
    }
}

void searchCarByNumber(const Car* cars, const int& size, const string& number) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (cars[i].number == number) {
            cout << "Car found at index " << i << ":" << endl;
            printCar(cars[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Car not found." << endl;
    }
}

int main() {
    // Task 1.1
    Car car;
	fillCar(car);
    // Task 1.2
	printCar(car);
	cout << endl;
    // Task 2
    const int SIZE = 10;
    Car* cars = new Car[SIZE]{
        {"Red", "Toyota", "YAKTAK"},
        {"Blue", "BMW", "HEH"},
        {"Green", "Audi", "UWU"},
        {"Yellow", "Mercedes", "HELLO"},
        {"Black", "Ford", "78900"},
        {"White", "Chevrolet", "20345"},
        {"Gray", "Nissan", "67890"},
        {"Orange", "Volkswagen", "01230"},
        {"Purple", "Honda", "45670"},
        {"Pink", "Hyundai", "89010"}
    };
    // Task 2.1
	int index;
	cout << "Enter the index of the car to edit: ";
	cin >> index;
    if (index >= 0 && index < SIZE)
    {
        editCar(cars[index]);
        cout << endl;
    }
    // Task 2.2
    cout << "Printing all cars:" << endl;
    printAllCars(cars, SIZE);
    cout << endl;
    // Task 2.3
    string searchNumber;
    cout << "Enter a car number to search: ";
    cin >> searchNumber;
    searchCarByNumber(cars, SIZE, searchNumber);
}

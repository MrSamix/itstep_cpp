#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Task 1
    int minutes;
    cout << "Enter the number of minutes that have passed since the beginning of the week: ";
    cin >> minutes;

    int totalSeconds = minutes * 60;
    int currentDay = totalSeconds / (24 * 60 * 60);
    int remainingSeconds = totalSeconds % (24 * 60 * 60);

    int currentHour = remainingSeconds / (60 * 60);
    remainingSeconds %= (60 * 60);

    int currentMinute = remainingSeconds / 60;
    int currentSecond = remainingSeconds % 60;

    int remainingDays = 7 - currentDay;
    int remainingHours = 24 - currentHour;
    int remainingMinutes = 60 - currentMinute;
    remainingSeconds = 60 - currentSecond;

    cout << "Current day: " << currentDay << endl;
    cout << "Current time: " << currentHour << ":" << currentMinute << ":" << currentSecond << endl;
    cout << "Remaining time until the end of the week: " << remainingDays << " days, " << remainingHours << " hours, " << remainingMinutes << " minutes, " << remainingSeconds << " seconds" << endl;

    // Task 2
    float length, width;
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    float area = length * width;
    float perimeter = 2 * (length + width);

    cout << "Area of the rectangle: " << area << endl;
    cout << "Perimeter of the rectangle: " << perimeter << endl;

    // Task 3
    float side1, side2, side3;
    cout << "Enter the length of side 1: ";
    cin >> side1;
    cout << "Enter the length of side 2: ";
    cin >> side2;
    cout << "Enter the length of side 3: ";
    cin >> side3;

    float s = (side1 + side2 + side3) / 2;
    float triangleArea = sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Для того, щоб порахувати квадратний корінь, потрібно підключити бібліотеку cmath
    float trianglePerimeter = side1 + side2 + side3;

    cout << "Area of the triangle: " << triangleArea << endl;
    cout << "Perimeter of the triangle: " << trianglePerimeter << endl;

    // Task 4
    float mass, quantity, unitPrice;
    cout << "Enter the mass of the product: ";
    cin >> mass;
    cout << "Enter the quantity of the product: ";
    cin >> quantity;
    cout << "Enter the unit price of the product: ";
    cin >> unitPrice;

    float totalMass = mass * quantity;
    float totalPrice = unitPrice * quantity;

    cout << "Total mass of the order: " << totalMass << endl;
    cout << "Total price of the order: " << totalPrice << endl;


    // Task 5
    float pricePerKg, quantity2;
    cout << "Enter the price per kilogram: ";
    cin >> pricePerKg;
    cout << "Enter the quantity in kilograms: ";
    cin >> quantity2;

    float totalWeight = quantity2;
    float totalPrice2 = pricePerKg * quantity2;

    if (totalWeight > 5)
    {
        totalPrice2 *= 0.9; // 10% знижка
    }

    cout << "Total price of the purchase: " << totalPrice2 << endl;


    // Task 6
    float distance, speed;
    cout << "Enter the distance between two cities: ";
    cin >> distance;
    cout << "Enter the speed of the car: ";
    cin >> speed;

    if (distance <= 0 || speed <= 0)
    {
        cout << "Invalid input!" << endl;
    }
    else
    {
        float travelTime = distance / speed;
        int remainingHours2 = 24 - (8 + (int)travelTime);
        int remainingMinutes2 = (60 - (int)((travelTime - (int)(travelTime)) * 60)) % 60;
        cout << "Travel time: " << (int)(travelTime) << " hours and " << (int)(travelTime * 60) % 60 << " minutes" << endl;
        cout << "Remaining time until the end of the day: " << remainingHours2 << " hours and " << remainingMinutes2 << " minutes" << endl;
    };



    // Task 7
    float bookPrice, bookcount, vat;
    cout << "Enter the price of one book: ";
    cin >> bookPrice;
    cout << "Enter the count of books: ";
    cin >> bookcount;
    cout << "Enter the VAT rate: ";
    cin >> vat;

    float subtotal = bookPrice * bookcount;
    float total = subtotal + (subtotal * vat / 100);

    cout << "Subtotal: " << subtotal << endl;
    cout << "Total including VAT: " << total << endl;

	// Task 8
    float waterVolume, waterPrice;
    cout << "Enter the water volume used in liters: ";
    cin >> waterVolume;
    cout << "Enter the price of one cubic meter of water: ";
    cin >> waterPrice;

    float waterVolumeInCubicMeters = waterVolume / 1000;
    float totalWaterCost = waterVolumeInCubicMeters * waterPrice;

    cout << "Total water cost for the month: " << totalWaterCost << endl;

	// Task 9
    int fileSize;
    float writeSpeed;
    
    cout << "Enter the number of bytes in the file: ";
    cin >> fileSize;
    cout << "Enter the write speed in megabytes per second: ";
    cin >> writeSpeed;
    
    float fileSizeInMB = fileSize / 1000000.0;
    float writeTime = fileSizeInMB / writeSpeed;
    
    cout << "The time to write the file to disk is: " << writeTime << " seconds" << endl;


	// Task 10
    float power, hoursPerDay;
    cout << "Enter the power of the electrical device in watts: ";
    cin >> power;
    cout << "Enter the number of hours the device operates per day: ";
    cin >> hoursPerDay;
    
    float kilowattHoursPerDay = (power * hoursPerDay) / 1000;
    float kilowattHoursPerMonth = kilowattHoursPerDay * 30;
    
    cout << "Kilowatt-hours consumed per day: " << kilowattHoursPerDay << endl;
    cout << "Kilowatt-hours consumed per month: " << kilowattHoursPerMonth << endl;
}
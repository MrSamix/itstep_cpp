#include <iostream>
using namespace std;

int main()
{
    // Task 1.1
    int second;
    cout << "Enter time in seconds: " << endl;
    cin >> second;
    int day = 86400;
    int result = day - second;
    int result_in_hours = result / 3600;
    int result_in_minutes = result / 60;
    cout << "Result in seconds = " << result << endl;
    cout << "Result in hours = " << result_in_hours << endl;
    cout << "Result in minutes = " << result_in_minutes << endl;

    // Task 1.2
    float PI = 3.14;
    float r;
    cout << "Enter radius: " << endl;
    cin >> r;
    float formula = PI * (r * r);
    cout << "D = " << formula << endl;

    // Task 2.1
    int number_1, number_2;
    cout << "Enter two numbers: " << endl;
    cin >> number_1 >> number_2;
    cout << number_1 << " + " << number_2 << " = " << number_1 + number_2 << endl;
    cout << number_1 << " - " << number_2 << " = " << number_1 - number_2 << endl;
    cout << "avg = " << (number_1 + number_2)/2 << endl;

    // Task 2.2
    int number_1_1, number_2_2, number_3_3;
    cout << "Enter three numbers: " << endl;
    cin >> number_1_1 >> number_2_2 >> number_3_3;
    cout << number_1_1 << " + " << number_2_2 << " + " << number_3_3 << " = " << number_1_1 + number_2_2 + number_3_3 << endl;
    cout << number_1_1 << " - " << number_2_2 << " - " << number_3_3 << " = " << number_1_1 - number_2_2 - number_3_3 << endl;
    cout << "avg = " << (number_1_1 + number_2 + number_3_3) / 3 << endl;

    // Task 2.3
    int price, count, discount;
    cout << "Enter: price, count, discount: " << endl;
	cin >> price >> count >> discount;
	float res = (float)(price * count) - discount / 100;
	cout << "Total price = " << res << endl;

    // Task 2.4
    int zarplata_bez_vidsotkiv = 100;
    int sum_of_ugody;
	cout << "Enter sum of ugody($): " << endl;
	cin >> sum_of_ugody;
	float zarplata_z_vidsotkamy = (float)zarplata_bez_vidsotkiv + (sum_of_ugody * 0.05);
	cout << "Zarplata z vidsotkamy = " << zarplata_z_vidsotkamy << "$" << endl;

	//Task 2.5
    double fileSizeGB;
    double internetSpeedBps;
    cout << "Enter the file size in gigabytes: ";
    cin >> fileSizeGB;
    cout << "Enter the internet speed in bits per second: ";
    cin >> internetSpeedBps;
    double fileSizeBits = fileSizeGB * 8 * 1024 * 1024 * 1024;
    double totalTimeSeconds = fileSizeBits / internetSpeedBps;
    int hours = totalTimeSeconds / 3600;
    int minutes = ((int)totalTimeSeconds % 3600) / 60;
    int seconds = (int)totalTimeSeconds % 60;
    cout << "The file will be downloaded in " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
}
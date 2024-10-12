#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	// Task 1
	ifstream file_1;
	file_1.open("1.txt");
	ifstream file_2;
	file_2.open("2.txt");

	if (!file_1.is_open() || !file_2.is_open())
	{
		cout << "Error opening files" << endl;
	}
	else
	{
		bool identifical = true;
		string line_file_1, line_file_2;
		while (getline(file_1, line_file_1) && getline(file_2, line_file_2) && identifical)
		{
			if (line_file_1 != line_file_2)
			{
				identifical = false;
				cout << "File 1: " << line_file_1 << endl;
				cout << "File 2: " << line_file_2 << endl;
			}	
		}
		if (identifical)
		{
			cout << "This files are identifical!" << endl;
		}
	}
	file_1.close();
	file_2.close();

	// Task 2
	string line;
	file_1.open("1.txt");
	ofstream file_3;
	file_3.open("3.txt");
	
	if (!file_1.is_open() || !file_3.is_open())
	{
		cout << "Error opening files" << endl;
	}
	else
	{
		int counter_symbol = 0, counter_lines = 0, counter_vowel_letter = 0, counter_consonant_letter = 0, counter_digit = 0;
		while (getline(file_1, line))
		{
			counter_symbol += line.length();
			counter_lines++;
			for (int i = 0; i < line.length(); i++)
			{
				if (isdigit(line[i]))
				{
					counter_digit++;
				}
				if (isalpha(line[i]))
				{
					if ((char)tolower(line[i]) == 'a' || (char)tolower(line[i]) == 'e' || (char)tolower(line[i]) == 'i' || (char)tolower(line[i]) == 'o' || (char)tolower(line[i]) == 'u' || (char)tolower(line[i]) == 'y')
					{
						counter_vowel_letter++;
					}
					else
					{
						counter_consonant_letter++;
					}
				}
				
			}
		}
		file_3 << "======================== STATS ==========================" << endl;
		file_3 << "Count of symbols: " << counter_symbol << endl;
		file_3 << "Count of lines: " << counter_lines << endl;
		file_3 << "Count of vowel letters: " << counter_vowel_letter << endl;
		file_3 << "Count of consonant letters: " << counter_consonant_letter << endl;
		file_3 << "Count of digits: " << counter_digit;
	}
	file_1.close();
	file_3.close();

	// Task 3
	ifstream file_4;
	file_4.open("4.txt");
	ofstream file_5;
	file_5.open("5.txt");

	if (!file_4.is_open() || !file_5.is_open())
	{
		cout << "Error opening files" << endl;
	}
	else
	{
		int choice;
		cout << "Enter the encryption key" << endl;
		cin >> choice;
		if (choice > 0 && choice < 26) // English language ONLY!
		{
			while (getline(file_4, line))
			{
				for (int i = 0; i < line.length(); i++)
				{
					if (isalpha(line[i]))
					{
						if (isupper(line[i]))
						{
							if (line[i] + choice > 90)
							{
								int temp = (line[i] + choice) - 90;
								line[i] = 64 + temp;
							}
							else
							{
								line[i] += choice;
							}
						}
						else
						{
							if (line[i] + choice > 122)
							{
								int temp = (line[i] + choice) - 122;
								line[i] = 96 + temp;
							}
							else
							{
								line[i] += choice;
							}
						}
					}
				}
				file_5 << line << endl;
			}
		}
	}
	file_4.close();
	file_5.close();
}
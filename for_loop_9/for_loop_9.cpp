#include <iostream>
#include <chrono> // для затримки
#include <thread> // для затримки
using namespace std;

int main()
{
    // Task 1.1
    char symbol = '*';
    int n = 10;
    int choice;
    int speed;
    cout << "Menu: \n[1] Print horizontally \n[2] Print vertically \n[0] Exit" << endl;
    cout << "\nEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter the speed ([1] Fast, [2] Normal, [3] Slow): ";
        cin >> speed;
        switch (speed)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << symbol;
				this_thread::sleep_for(chrono::milliseconds(100)); // затримка на 100 мілісекунд
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << symbol;
				this_thread::sleep_for(chrono::milliseconds(500)); // Затримка на 500 мілісекунд
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                cout << symbol;
				this_thread::sleep_for(chrono::seconds(1)); // Затримка на 1 секунду
            }
            break;
        default:
            cout << "Invalid speed!" << endl;
            break;
        }
        break;
    case 2:
        cout << "Enter the speed ([1] Fast, [2] Normal, [3] Slow): ";
        cin >> speed;
        switch (speed)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                cout << symbol << endl;
                this_thread::sleep_for(chrono::milliseconds(100)); // затримка на 100 мілісекунд
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                cout << symbol << endl;
                this_thread::sleep_for(chrono::milliseconds(500)); // Затримка на 500 мілісекунд
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                cout << symbol << endl;
                this_thread::sleep_for(chrono::seconds(1)); // Затримка на 1 секунду
            }
            break;
        default:
            cout << "Invalid speed!" << endl;
            break;
        }
        break;
    case 0:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

	cout << "\n\n" << endl;

    // Task 1.2
    srand(time(0)); // для рандома

    int userScore = 0;
    int computerScore = 0;

    cout << "Welcome to the Dice Game!" << endl;

    for (int round = 1; round <= 3; round++)
    {
        cout << "Round " << round << endl;

        int userDice1 = rand() % 6 + 1;
        int userDice2 = rand() % 6 + 1;
        int computerDice1 = rand() % 6 + 1;
        int computerDice2 = rand() % 6 + 1;

        cout << "You rolled:" << endl;
        switch (userDice1)
        {
        case 1:
            cout << "---------" << endl;
            cout << "|       |" << endl;
            cout << "|   *   |" << endl;
            cout << "|       |" << endl;
            cout << "---------" << endl;
            break;
        case 2:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|       |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 3:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|   *   |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 4:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|       |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 5:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|   *   |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 6:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        }

        switch (userDice2)
        {
        case 1:
            cout << "---------" << endl;
            cout << "|       |" << endl;
            cout << "|   *   |" << endl;
            cout << "|       |" << endl;
            cout << "---------" << endl;
            break;
        case 2:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|       |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 3:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|   *   |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 4:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|       |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 5:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|   *   |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 6:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        }

        cout << "Computer rolled:" << endl;
        switch (computerDice1)
        {
        case 1:
            cout << "---------" << endl;
            cout << "|       |" << endl;
            cout << "|   *   |" << endl;
            cout << "|       |" << endl;
            cout << "---------" << endl;
            break;
        case 2:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|       |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 3:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|   *   |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 4:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|       |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 5:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|   *   |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 6:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        }

        switch (computerDice2)
        {
        case 1:
            cout << "---------" << endl;
            cout << "|       |" << endl;
            cout << "|   *   |" << endl;
            cout << "|       |" << endl;
            cout << "---------" << endl;
            break;
        case 2:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|       |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 3:
            cout << "---------" << endl;
            cout << "| *     |" << endl;
            cout << "|   *   |" << endl;
            cout << "|     * |" << endl;
            cout << "---------" << endl;
            break;
        case 4:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|       |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 5:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "|   *   |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        case 6:
            cout << "---------" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "| *   * |" << endl;
            cout << "---------" << endl;
            break;
        }

        int userRoundScore = userDice1 + userDice2;
        int computerRoundScore = computerDice1 + computerDice2;

        cout << "Your round score: " << userRoundScore << endl;
        cout << "Computer round score: " << computerRoundScore << endl;

        userScore += userRoundScore;
        computerScore += computerRoundScore;

        cout << "Your total score: " << userScore << endl;
        cout << "Computer total score: " << computerScore << endl;

        cout << "------------------------" << endl;

		this_thread::sleep_for(chrono::seconds(2)); // Затримка на 2 секунди
    }

    cout << "Game Over!" << endl;
    cout << "Your final score: " << userScore << endl;
    cout << "Computer final score: " << computerScore << endl;

    if (userScore > computerScore)
    {
        cout << "Congratulations! You win!" << endl;
    }
    else if (userScore < computerScore)
    {
        cout << "Sorry, you lose. Better luck next time!" << endl;
    }
    else
    {
        cout << "It's a tie!" << endl;
    }

    cout << "\n\n" << endl;

    // Task 2.1
    int arr_of_int[10]{};
    for (int i = 0; i < 10; i++)
    {
		arr_of_int[i] = rand(); // заповнення масиву випадковими числами
    }
	int max = arr_of_int[0];
	int min = arr_of_int[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < arr_of_int[i])
        {
			max = arr_of_int[i];
        }
        if (min > arr_of_int[i])
        {
			min = arr_of_int[i];
        }
    }
	cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    
	cout << "\n\n" << endl;

	// Task 2.2
    int arr_of_cash[12]{};
	for (int i = 0; i < 12; i++)
	{
		cout << "Enter cash for month " << i + 1 << ": ";
		cin >> arr_of_cash[i];
	}
	int month_start, month_end;
	cout << "Enter the month start number: ";
    cin >> month_start;
	cout << "Enter the month end number: ";
	cin >> month_end;
	int max_ = arr_of_cash[month_start - 1];
	int min_ = arr_of_cash[month_start - 1];
    int month_max = 0;
	int month_min = 0;
    for (int i = month_start-1; i < month_end; i++)
    {
        if (max_ < arr_of_cash[i])
        {
            max_ = arr_of_cash[i];
			month_max = i + 1;
        }
		if (min_ >= arr_of_cash[i])
		{
			min_ = arr_of_cash[i];
			month_min = i + 1;
		}
    }
	cout << "Max: " << max_ << " in month " << month_max << endl;
	cout << "Min: " << min_ << " in month " << month_min << endl;


    cout << "\n\n" << endl;
    // Task 2.3
	int arr_of_integers[10]{-10,-2,2,4,55,66,11,0,-50,90};
	int sum_negative_num = 0;
	int mult_min_max = 1;
	int min__ = arr_of_integers[0];
	int max__ = arr_of_integers[0];
	int min_index = 0;
	int max_index = 0;
	int even_mult = 1;
	int sum_min_max = 0;
	int min_negative = -1;
	int max_negative = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr_of_integers[i] < 0)
        {
            sum_negative_num += arr_of_integers[i];
        }
        if (min__ >= arr_of_integers[i])
        {
			min__ = arr_of_integers[i];
			min_index = i;
        }
        if (max__ < arr_of_integers[i])
        {
            max__ = arr_of_integers[i];
			max_index = i;
        }
        if (arr_of_integers[i] % 2 == 0 && arr_of_integers[i] != 0)
        {
            even_mult *= arr_of_integers[i];
        }
        if (arr_of_integers[i] < 0 && min_negative == -1)
        {
			min_negative = i;
        }
    }
    for (int i = 9; i > 0; i--)
    {
        if (arr_of_integers[i] < 0)
        {
            max_negative = i;
            break;
        }
    }

    for (int i = min_index; i <= max_index; i++)
    {
		mult_min_max *= arr_of_integers[i];
    }

    for (int i = min_negative; i <= max_negative; i++)
    {
        sum_min_max += arr_of_integers[i];
    }

	cout << "Sum of negative numbers: " << sum_negative_num << endl;
	cout << "Multiplication of min and max: " << mult_min_max << endl;
	cout << "Even numbers multiplication: " << even_mult << endl;
	cout << "Sum of min and max: " << sum_min_max << endl;
}
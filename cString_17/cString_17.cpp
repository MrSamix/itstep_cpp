#include <iostream>
#include <string>
using namespace std;

// Task 1
int porivnynnya(char str_1[], char str_2[])
{
    const int size1 = strlen(str_1);
    const int size2 = strlen(str_2);
    if (size1 > size2)
    {
        return 1;
    }
    else if (size1 < size2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}


// Task 3
int countVowels(const char* str)
{
    int count = 0;
    const char vowels[] = "aeiouy";
    for (int i = 0; str[i] != '\0'; i++)
    {
        char lowercaseChar = tolower(str[i]);
        for (size_t j = 0; j < strlen(vowels); j++)
        {
            if (lowercaseChar == vowels[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}


// Task 4
void truncate(char* str, int maxLength)
{
    int length = strlen(str);
    if (length > maxLength)
    {
        if (maxLength > 3)
        {
            str[maxLength - 3] = '\0';
            strcat_s(str, maxLength+1, "...");
        }
        else
        {
            str[0] = '\0';
        }
    }
}

// Task 5
void ispalindrom(char* str)
{
    int length = strlen(str);
    cout << length << endl;
    for (int i = 0; i < length/2; i++)
    {
        if (tolower(str[i])==tolower(str[length-1-i]))
        {
            continue;
        }
        else
        {
            cout << "This word isn't palindrom!" << endl;
            return;
        }
    }
    cout << "This word is palindrom!" << endl;
    return;
}

// Task 6
void counter_words(char* str)
{
    int length = strlen(str);
    int counter_words = 0, counter_bukvs = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(str[i]))
        {
            counter_bukvs++;
        }
        else
        {
            if (counter_bukvs > 1)
            {
                counter_words++;
                counter_bukvs = 0;
            }
        }
    }
    cout << "Count of str: " << str << " = " << counter_words << endl;
}


// Task 7
void max_word(char* str)
{
    int length = strlen(str);
    int counter_words = 0, counter_bukvs = 0;
    //counter
    for (int i = 0; i < length; i++)
    {
        if (isalpha(str[i]))
        {
            counter_bukvs++;
        }
        else
        {
            if (counter_bukvs > 1)
            {
                counter_words++;
                counter_bukvs = 0;
            }
        }
    }
    char* arr = new char[counter_words];

    // write array
    int start_index = 0, end_index = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(str[i]))
        {
            if (i == 0)
            {
                start_index = 0;
            }
            else if (counter_bukvs == 0)
            {
                start_index = i;
            }
            counter_bukvs++;
        }
        else
        {
            end_index = i - 1;
            char* arr_word = new char[counter_bukvs];
            for (int i = 0; i < counter_bukvs; i++)
            {
                if (start_index <= end_index)
                {
                    arr_word[i] = arr[start_index++];
                }
            }
            arr_word[counter_bukvs] = '\0';

            for (int i = 0; i < counter_words; i++)
            {
                if (counter_bukvs > 1)
                {
                    arr[i] = arr_word;
                    counter_bukvs = 0;
                }
            }
        }
    }
    /*cout << "Count of str: " << str << " = " << counter_words << endl;*/
}

int main()
{
    // Task 1
    char string_1[] = "hello", string_2[] = "world";
    cout << "Result = " << porivnynnya(string_1, string_2) << endl;

    // Task 2
    char str[] = "my";
	str[0] = toupper(str[0]);
    cout << str << endl;


    // Task 3
    char str_3[] = "Hello";
    cout << "Count vowels in " << str_3 << " = " << countVowels(str_3) << endl;


    // Task 4
    char str_4[] = "Hello, world!";
    truncate(str_4, 8);
    cout << str_4 << endl;

	// Task 5
    char str_5[] = "WOw";
    ispalindrom(str_5);

    // Task 6
    char str_6[] = "Hello, world!";
    counter_words(str_6);
}
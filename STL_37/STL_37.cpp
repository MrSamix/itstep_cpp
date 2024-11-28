#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename ContType>
void print(const ContType& cont, const string& prompt = "")
{
    cout << prompt << ": \t";
    for (const auto& el : cont)
    {
        cout << el << "\t";
    } cout << endl;
}


void rPrint(const vector<int>& cont, const string& prompt = "")
{
    cout << prompt << ": \t";
    auto it = cont.rbegin();
    for (int i = 0; i < cont.size(); i++)
    {
        cout << *(it+i) << "\t";
    }cout << endl;
}


int main()
{
    // Task 1
    vector<int> v1;
    int sizev1 = 0;
    cout << "Count of element: "; cin >> sizev1;
    for (int i = 0; i < sizev1; i++)
    {
        int elem;
        cout << "Enter a element: "; cin >> elem;
        v1.push_back(elem);
    }
    print(v1, "Vector v1");

    vector<int> v2(10, 0);
    print(v2, "Vector v2");

    vector<int> v3;
    int sizev3 = 0;
    cout << "size vector v3: "; cin >> sizev3;
    for (int i = 0; i < sizev3; i++)
    {
        v3.push_back(rand() % 100 + 1);
    }
    print(v3, "Vector v3");

    vector<int> v4(v1.begin(), v1.end());
    print(v4, "Vector v4");

    vector<int> v5(v3.begin() + 1, v3.end() - 1);
    print(v5, "Vector v5");

    // Task 2
    cout << "\n\n";
    print(v3, "Vector v3");

    rPrint(v1, "Reversed v1");

    // Task 3
    v2.clear();
    for (int i = 1; i <= 10; i++)
    {
        v2.push_back(i);
    }
    print(v2, "Vector v2");

    for (int i = 0; i <= v2.size()/2; i++)
    {
        swap(v2.at(rand() % 10), v2.at(rand() % 10));
    }
    print(v2, "v2 random");

    v2.erase(v2.begin() + 1);
    v2.erase(v2.end() - 1);
    print(v2, "v2 random");

    // Task 4
    v4.clear();
    v4.push_back(12);
    v4.push_back(10);
    v4.push_back(35);
    print(v4, "Vector v4");

    for (int i = 0; i < v4.size(); i += 2)
    {
        v4.insert(v4.begin() + i + 1, v4.at(i));
    }
    print(v4, "Vector v4");

    // Task 5
    v5.clear();
    for (auto& num : v4)
    {
        if (num % 2 == 0)
        {
            v5.push_back(num);
        }
    }
    print(v5, "Vector v5");
    transform(v5.begin(), v5.end(), v5.begin(), [](int num) {return num / 2; });
    print(v5, "Vector v5");

    // Task 6
    int value = 5;

    auto it_find = find(v5.begin(), v5.end(), value);
    while (it_find != v5.end())
    {
        cout << "Number --> " << * it_find << "\t index --> " << it_find - v5.begin() << endl;
        it_find = find(it_find + 1, v5.end(), value);
    }
    cout << "Count of " << value << " --> " << count(v5.begin(), v5.end(), value) << endl;

    // Task 7
    print(v4, "Vector v4");
    print(v5, "Vector v5");
    v4.swap(v5);
    print(v4, "v4 after swap");
    print(v5, "v5 after swap");
}
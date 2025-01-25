#include <iostream>
#include <bitset>
using namespace std;
string decimalToIEEE754(float num)
{
    union
    {
        float input;
        int output;
    } data;
    data.input = num;
    bitset<32> bits(data.output);
    return bits.to_string();
}

int main()
{
    float num1, num2;
    int choice;

    while (true)
    {
        cout << "Choose an operation:\n";
        cout << "1. Addition\n";
        cout << "2. Multiplication\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2)
        {
            cout << "Enter the first number: ";
            cin >> num1;
            cout << "Enter the second number: ";
            cin >> num2;
        }

        switch (choice)
        {
        case 1:
        {
            float result = num1 + num2;
            cout << "Result (Decimal): " << result << endl;
            cout << "Result (IEEE 754): " << decimalToIEEE754(result) << endl;
            break;
        }
        case 2:
        {
            float result = num1 * num2;
            cout << "Result (Decimal): " << result << endl;
            cout << "Result (IEEE 754): " << decimalToIEEE754(result) << endl;
            break;
        }
        case 3:
            return 0;
        default:
            cout << "Error. Please try again.\n";
        }
    }
    return 0;
}

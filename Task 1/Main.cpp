#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int num1;
    int num2;
    num1 = rand() % 10 + 1;
    do
    {
        cout << "Enter a number to guess(1-10):";
        cin >> num2;

        if (num2 > num1)
        {
            cout << "Guess is too high\n";
        }
        else if (num2 < num1)
        {
            cout << "Guess is too low\n";
        }
        else
        {
            cout << "\nCongrats!You guessed correct number\n";
            break;
        }

    } while (num1 != num2);

    return 0;
}
// gcd uses Euclid's algorithm to calculate the greatest common divisor of two integers

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int getUserInput();    // prompts user for input, accepts positive and negative integers as input
int gcd(int x, int y); // calculates greatest common divisor of two integers

int main()
{
    int a, b;  // to store user input
    bool exit; // to exit program
    char ch;   // to store user input

    // program instructions
    cout << "  This program will accept two integers and calculate their greatest common divisor. " << endl
         << "    1. Enter the integers one at a time. The integers can be positive or negative." << endl
         << "    2. User input must contain only positive or negative integers with no whitespace." << endl
         << "    3. If the program returns 0, the greatest common divisor is undefined." << endl
         << endl;

    // run program
    exit = false;
    while (!exit)
    {
        //  prompt user to enter integer a
        cout << "Integer a " << endl;
        a = getUserInput();
        cout << "Integer a = " << a << endl
             << endl;

        // prompt user to enter integer b
        cout << "Integer b " << endl;
        b = getUserInput();
        cout << "Integer b = " << b << endl
             << endl;

        // calculate the greatest common divisor of a and b and print to screen
        cout << "The greatest common divisor of " << a << " and " << b << " is " << gcd(a, b) << endl;

        // prompt user to exit program
        cout << "Exit? type 'e' to exit, type anthing else to continue: ";
        cin >> ch;
        cout << endl;

        if (ch == 'e' || ch == 'E')
            exit = true;

        while (getchar() != '\n')
            ;
        cin.clear();
    }

    return 0;
}

// prompts user for input, accepts positve and negative integers as input
int getUserInput()
{
    bool validInput = false;
    string input;
    unsigned int value;

    // input validation
    while (!validInput)
    {
        cout << "Enter an integer: ";
        getline(cin, input);

        // special case for empty string
        if (input == "")
        {
            cout << "Input cannot be blank!" << endl;
            continue;
        }

        // special case for negative sign
        if (input[0] != '-' && !isdigit(input[0]))
        {
            continue;
        }

        // check if string is valid
        validInput = true;
        for (int i = 1; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                validInput = false;
                break;
            }
        }
    }

    // if number is too large for stoi(), then call getUserInput()
    try
    {
        return stoi(input);
    }
    catch (exception e)
    {
        cout << "Number is too large! " << endl;
        return getUserInput();
    }
}

// finds the greatest common divisor of two integers using Euclid's algorithm
// if the function returns 0, the gcd is undefined
int gcd(int x, int y)
{
    int r;    // remainder, r = y mod x
    int temp; // temporary

    // make x and y positive values
    y = abs(y);
    x = abs(x);

    // special case, check for 0
    if (y == 0 || x == 0)
    {
        if (x > 0)
            return x;

        return y;
    }

    // if y is less than x, swap x and y
    if (y < x)
    {
        temp = y;
        y = x;
        x = temp;
    }
    r = y % x;

    // finds the greatest common divisor
    while (r > 0)
    {
        y = x;
        x = r;
        r = y % x;
    }

    return x;
}
#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

int a, b = 0;

// Is string a num?
bool CanStoi(string& input)
{
    if (input.empty()) return false;

    int num;

    try
    {
        num = stoi(input);
    } catch (...) { return false; }

    return true;
}

// Enter correct number from keyboard
void EnterNumber(int& num, string message)
{
    string input;

    cout << message;
    getline(cin, input);

    while (!CanStoi(input))  
    {
        cout << message;
        getline(cin, input);
    }

    num = stoi(input);
}

// Function to set value of variable "a"
void EnterA()
{

}

// Function to set value of variable "b"
void EnterB()
{
    EnterNumber(b, "Enter value of b: ");
}

// Function to sum up variables "a" and "b"
void ExecutePlus()
{

}

// Function to minus variables "a" and "b"
void ExecuteMinus()
{

}

struct MenuItem
{
    string title;
    function<void()> func; 
};

int main()
{   
    map<int, MenuItem> Menu {
        {1, {"Enter A", EnterA}},
        {2, {"Enter B", EnterB}},
        {3, {"Execute \"+\"", ExecutePlus}},
        {4, {"Execute \"-\"", ExecuteMinus}}
    };

    int choice;

    for (;;)
    {
        for (auto item : Menu)
        {
            cout << item.first << ". " << item.second.title << endl;
        }

        cout << "0. Exit" << endl << endl;

        EnterNumber(choice, "Choice a menu option: ");

        if (choice == 0) break;

        cout << endl;

        if (Menu.find(choice) != Menu.end())
            Menu[choice].func();
    }

    return 0;
}
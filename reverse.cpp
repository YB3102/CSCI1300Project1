// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA: Meenakshi Sistla
// Project 1 - Problem #1: Question 1: reverse()
#include <iostream>
#include <string>
using namespace std;

/*
* This function accepts a string and then prints the characters of that string in a reverse order.
* Parameters: string number - the string passed into the function
* Return: void function
*/

void reverse (string number)
{
    int l = number.length();
    for (int i=l-1; i>=0; i--)//starting from the final position of the string
    {
        cout << number[i];//printing the characters from final position to 0th position
    }
    cout << endl;
}
int main() //main function to call the reverse() function.
{
    string entry;
    cout << "Enter a string" << endl;
    getline(cin,entry);
    reverse(entry);
    return 0;
}
// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA: Meenakshi Sistla
// Project 1 - Problem #2: Question 2: isConstant()
#include <iostream>
using namespace std;

/*
* This function accepts a character and returns a bool value depending whether the char is a consonant or a vowel.
* Parameters: char letter - the character passed into the function
* Return: a boolean value
*/

bool isConsonant(char letter)
{   
    bool check;//bool variable to store the boolean value
    if (letter==97 || letter==101 || letter==105 || letter==111 || letter==117 ||
        letter==65 || letter==69 || letter==73 || letter==79 || letter==85) //ascii values for lowercase and uppercase vowels
    {
        check=false;   
    }
    else if ((letter>=65 && letter<=90) || (letter>=97 && letter<=122)) //ascii values for upper case and lower case alphabets
    //only executes if the first if condition is false.                                                  
    {
        check=true;
    }
    else
    {
        check = false; //returning false for any other char value 
    }
    return check; //returning the bool variable
}
int main() //main function to call the function
{
    bool consonantCheck;
    char alphabet=' ';
    cout << "Enter a character: " << endl;
    cin >> alphabet;
    consonantCheck = isConsonant(alphabet); //calling the function using the entered character variable
    cout << consonantCheck;
    cout << endl;
    return 0;
}
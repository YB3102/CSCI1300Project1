// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA: Meenakshi Sistla
// Project 1 - Problem #3: Question 3: numConstant()
#include <iostream>
#include <string>
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
        letter==65 || letter==69 || letter==73 || letter==79 || letter==85)     //ascii values for lowercase and uppercase vowels
    {
        check=false;   
    }
    else if ((letter>=65 && letter<=90) || (letter>=97 && letter<=122))      //ascii values for upper case and lower case alphabets
    //only executes if first if statement is false
    {
        check=true;
    }
    else
    {
        check = false;   //returning false for any other char value 
    }
    return check; //returning the boolean variable
}

/*
* This function accepts a string and then returns an int value for the number of consonants in the string. It makes uses of the previous isConstant() function.
* Parameters: string sentence - the string passed into the function
* Return: int numConstant - the number of consonants in the string
*/

int numConsonant (string sentence)
{
    int size = sentence.length();
    int num_Consonant=0; //integer variable to store the number of consonants
    bool charCheck; //boolean to store value from the isConstant() function
    for(int i=0; i<size; i++) //checking from 0th to final position of the string.
    {   
        char stringLetter = sentence[i]; //extracting the character at i th position of the string
        charCheck = isConsonant(stringLetter); //checking using the isConstant() function

        if (charCheck==1) //only increasing the value of num_Constant by 1 if boolean has a true value (consonant)
        {
            num_Consonant = num_Consonant + 1;
        }
    }
    return num_Consonant;   //returning the integer variable
}
int main()
{
    string line;
    cout << "Enter a string consisting of a sentence: " << endl;
    getline(cin,line);
    int numOfConsonants = numConsonant(line);
    cout << numOfConsonants;
    cout << endl;
    return 0;

}
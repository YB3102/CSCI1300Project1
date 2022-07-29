// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA: Meenakshi Sistla
// Project 1 - Problem #8: Extra Credit Question 1
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime> //library for truly random generation
using namespace std;

/*
* This function accepts an integer value of no. of cards and then using random ascii values generates a string of random sequence of
cards according to the desired parameters.
* Parameters: int numOfCards - number of cards passed into the function as an integer value
* Return: a randomized string consisting of the number of cards passed into the function
*/

string generateSequence(int numOfCards)
{   
    int operateString = numOfCards*2; //length of the string that will be returned
    string generated_seq; //string to be returned
    for (int i=0; i<operateString; i=i+1) //for loop for each string position
    {   
        if(i%2==0)//if position is divisible by 2, then it is a suit position
        {
        int ascii = 0;
        char storeSuit;
        while (ascii!=83 && ascii!=67 && ascii!=68 && ascii !=72) //ascii values for S,C,D and H respectively
        {
        ascii = rand()%127 + 1; //generating random ascii values ranging from 1 to 127
        }
        storeSuit=ascii; //storing the ascii value if C,S,H or D in a char variable
        generated_seq = generated_seq + storeSuit; //adding the char to string
        }

        else if(i%2==1)//if remainder is 1 then it is a rank position
        {   
            int asciiRank=0;
            char storeRank;
            while (asciiRank!=65 && !(asciiRank>=50 && asciiRank<=57) && asciiRank!=84 && asciiRank!=74 && asciiRank!=81 && asciiRank!=75)
            // ascii values for A,2-9,T,J,Q and K respectively
            {   
                asciiRank = rand()%127 + 1; //generating random ascii values ranging from 1 to 127
            }
            storeRank=asciiRank; //storing the ascii value if it matches the criteria in a char variable
            generated_seq = generated_seq + storeRank; //ading the char to string
        }
    }

     return generated_seq; //returning the string
}

int main() //main function to call the generate sequence function
{   
    srand(time(NULL)); //srand to truly generate random numbers
    int choice=0;
    string cards;
    cout << "Enter the number of cards. Max of 10 cards." << endl;
    cin>>choice;
    if (choice<=10 && choice>0)
    {
        cards = generateSequence(choice);
        cout << cards << endl;
    }
    else
    {
        cout << "Invalid input." << endl;
    }
    
    return 0;
}
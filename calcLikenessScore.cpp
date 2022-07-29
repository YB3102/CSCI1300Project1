// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA: Meenakshi Sistla
// Project 1 - Problem #4: Question 4: calcLiknessScore()
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
* This function accepts two strings and then according to the parameters, compares the first string to the second string(golden sequence.)
Both strings must be of same length. The function then returns a likeness score as per the given criteria in the question.
* Parameters: string seq1, string seq2 - the strings passed into the function. seq2 is the golden sequence to which the first string is compared to.
* Return: double likeness_score : the double likness score obtained after comparing the string as per the given criteria.
*/

double calcLikenessScore(string seq1, string seq2)
{
    double l1 = seq1.length(); //length of first string
    double l2 = seq2.length(); //length of second string
    double suit=0; //score to store all matching suit positions
    double suitTotal=0;//variable to store the total score out of all the suit positions
    double rank=0;//variable to score the matching rank positions
    double check= l1/2.0; //total number of suit positions in the sequence
    double likeness_score; //total score to be returned

    if(l1==l2) //only running the function if lengths are equal.
    {
        for(int i=0; i<l1-1; i=i+2) //searching the string from 0th position to the (final-1)th position which contain suit positions
        {
            if(seq1[i]==seq2[i]) //comparing the respective suit positions of both the strings
            {
                suit = suit+1; //increasing by 1 point for each matching case
                    if(seq1[i+1]==seq2[i+1])//checking for adjacent rank position and only increasing by bonus 1 point if suit positions match
                    {
                        rank=rank+1;
                    }    
            }
            suitTotal = suit/check; //calculating the total Suit score in each loop iteration by dividing the obtained score by the total number of suit positions
        }                           //value of check remains constant
        likeness_score = suitTotal+rank;//calculating the total score after the loop has finished
    }
    else
    {
        likeness_score = -1; //if lengths are unequal then likeness score is -1
    }

    return likeness_score; //returning the likeness score.
}
int main() //main function to call the calcLikenessScore() function.
{   
    string userentry;
    string golden;
    cout << "enter the seq1" << endl;
    getline(cin,userentry);
    cout << "enter golden seq" << endl;
    getline(cin,golden);
    double valuetake = calcLikenessScore(userentry,golden);
    cout << setprecision(2) << valuetake << endl;
    return 0;
}
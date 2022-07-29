// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA: Meenakshi Sistla
// Project 1 - Problem #5: Question 5: bestLiknessScore()
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
    double l1 = seq1.length();//length of first string
    double l2 = seq2.length();//length of second string
    double suit=0;//score to store all matching suit positions
    double suitTotal=0;//variable to store the total score out of all the suit positions
    double rank=0;//variable to score the matching rank positions
    double check= l1/2.0;//total number of suit positions in the sequence
    double likeness_score;//total score to be returned

    if(l1==l2)//only running the function if lengths are equal.
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

/*
* This function accepts two strings and then according to the parameters, compares the first string to the second string(golden sequence.)
Both strings need not be of the same length. Using substrings of the first string, the best likeness score is returned after comparing each
substring to the golden sequence string.
* Parameters: string seq1, string seq2 - the strings passed into the function. seq2 is the golden sequence to which the substrings of the first string are compared to.
* Return: double best_likeness_score : the double best likness score obtained after comparing the string as per the given criteria.
*/

double bestLikenessScore(string seq1, string gold_seq)
{
    double l1 = seq1.length(); //length of the first string
    double l2 = gold_seq.length();//length of the second string
    double best_likeness_score=0;//variable to store the best likeness score into
    double value=0; //value to compare and store the best likeness score during function run
    if (l1>=l2) //string1 needs to equal or greater than string2
    {   
        for (int i=0; i<l1; i=i+2)//starting from 0th suit position and checking till final position
        {
            string s = seq1.substr(i,l2);//using substr(), creating a substr of the same length as golden sequence from the i th position
            value = calcLikenessScore(s,gold_seq);//calling the calcLikenessScore() function to calculate the likeness score for the substring and golden sequence
            if (best_likeness_score<value)
            {
                best_likeness_score=value; //storing value in best_likeness_score if value variable is greater than the previously stored value
            }
        }
        
    }
    if (l1<l2)
    {
        best_likeness_score = -1; //returning -1 if string1 is shorter in length than the golden sequence
    }
    return best_likeness_score; //returning the best likeness score
}
int main() //main function to call the bestLikenessScore() function
{   
    string userentry;
    string golden;
    cout << "enter the seq1" << endl;
    getline(cin,userentry);
    cout << "golden seq: " << endl;
    getline(cin,golden);
    double valuetake = bestLikenessScore(userentry,golden);
    cout << setprecision(2) << valuetake << endl;
    return 0;
}
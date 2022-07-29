// CSCI1300 Fall 2021
// Author: Yatharth Brahmbhatt
// Recitation: 117 – TA: Meenakshi Sistla
// Project 1 - Problem #9: Extra Credit Question 2
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
* This function accepts a string of cards then returns a shuffled sequence of those cards.
* Parameters: string orig_seq - a sequence of cards passed into the function
* Return: a shuffled string consisting of the cards passed into the function
*/

string cardsShuffle (string orig_seq)
{
    int shuffler = 0; //this int variable will be vital for generating random shuffles
    string shuffled_seq;
    int size = orig_seq.length(); //length of string passed into the function
    int cards = size/2;
    
    for(int i=0; i<size-1; i=i+2) //this loop runs for each cards
    {
        shuffler = rand()%size; //shuffling the cards randomly each time from a sample size of 0 to last position of string 
        while(shuffler%2!=0) //only shuffling cards along with suit and rank, so only accepting shuffler if it has a suit position
        {
            shuffler = rand()%size;//running loop until a suit position is obtained
        }
        char c = orig_seq[i]; //storing original position in a char variable
        orig_seq[i] = orig_seq[shuffler];//switching characters from position to shuffler position
        orig_seq[shuffler] = c;//storing original position character in the shuffler position
        
        char d = orig_seq[i+1]; //doing the same as above for the adjacent rank position
        orig_seq[i+1] = orig_seq[shuffler+1];
        orig_seq[shuffler+1] = d;
        
    }
    shuffled_seq = orig_seq; //storing the shuffled seq in the string variable to be passed
    return shuffled_seq; //returned the shuffle sequence
}
int main() //main function to call the function shuffle sequence
{
    srand(time(0)); //srand for truly random number generation
    string lets;
    string go;
    cout << "Enter a string to shuffle: " << endl;
    getline(cin,lets);

    go = cardsShuffle(lets);

    cout << go << endl;

    return 0;
}
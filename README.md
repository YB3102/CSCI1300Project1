# CSCI 1300 - Project 1

---

Project 1 - README
CSCI 1300 Fall 21
Project Name - Sequence of Cards

Authors: Yatharth Brahmbhatt (me)

This project consists of a main cpp file "sequenceofCards.cpp" which is the main program. The other cpp files are test cpp files to test the functions which were implemented in the aforementioned file. The names of the cpp files are reflective of their purpose as functions in the main cpp file. 
This project tested me on my understanding of functions and arrays. The various functions perform various tasks such as generating random sequences of cards, shuffling sequences, and calculating the best sequence. The program generates a predetermined "golden sequence" when called. Each player is also given a random sequence. The program then compares the players' sequenece to the golden sequence, and produces a likeness score based on the comparison between the two sequences. The player with the best likeness score of a sequence wins. 

The files and code have been compiled using the following command in wsl terminal:
g++ -std=c++17 CSCI1300Project1/sequenceOfCards.cpp
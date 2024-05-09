/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 1
 * Description: Processes a file containing formatted data for local 
   election
 * Input: elections1.txt and elections2.txt
 * Output: list of candidates, sorted list by votes, lowest scoring 
    candidate, highest scoring candidate, rounded pScore list */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>

using namespace std;

const int ARR_SIZE = 100;

// Declare array of structs for Candidate
struct Candidate {
  string first; // first name
  string last; // last name
  int votes; // votes or score
  double pScore; // pScore (percentage)
};

// Function prototypes
void readFile(string, Candidate[]);
void displayList(Candidate[]);
void sortByVotes(Candidate[]);
void displayCandidate(Candidate);
Candidate getWinner(Candidate[]);
Candidate getLast(Candidate[]);
void calculateScores(Candidate[]);
void roundScores(Candidate[]);

int main(int argc, char *argv[]) {
  Candidate candidates[ARR_SIZE]; // declare array

  // execute if arg count is greater than 1 (>./a.out)
  if (argc>1) { 
    readFile(argv[1], candidates); // reads file specified in argv[1]
  }

  //calculateScores(candidates); RETURNS SEG FAULT

  displayList(candidates);

  //sortByVotes(candidates); RETURNS SEG FAULT

  return 0;
}

/* function_identifier: reads input file, fills candidates[] array
 * parameters: string inFileName and candidates array
 * return value: none */

void readFile(string inFileName, Candidate candidates[]) {
  ifstream inFile;
  Candidate candidate; // define variable named candidate

  int valid = 0; // counter to check valid
  string electionLine; // to store line from txt file

  inFile.open(inFileName.c_str()); // open file

  if (!inFile) { // error for opening file
    cout << endl;
    cout << "Error - Can't open the file named " << inFileName;
    cout << endl << endl;

    return;
  }

  getline(inFile, electionLine); // read line from file to string

  while (inFile) { // while file is open...
    while (1) {
      // If the checks are not found, break out of loop
      if (electionLine.find("F=") == string::npos)
        break;
      if (electionLine.find(",L=") == string::npos)
	break;
      if (electionLine.find(",V=") == string::npos) {
	if (electionLine.find(", V=") == string::npos)
	  break;
      }

      // Returns first name part of string
      candidates[valid].first = electionLine.substr( 
        electionLine.find("F=")+2, 
        electionLine.find(",L=")-(electionLine.find("F=")+2) );
      
      // Returns last name and votes of string if no space found
      if (electionLine.find(",V") != string::npos) {
	
        // Returns last name of string
        candidates[valid].last = electionLine.substr( 
          electionLine.find(",L=")+3, 
          electionLine.find(",V=")-(electionLine.find(",L=")+3) );
        
        // Returns votes of string
        candidates[valid].votes = stoi( electionLine.substr( 
          electionLine.find(",V=")+3, 4 ) );
      }

      // Returns last name and votes of string if space found
      if (electionLine.find(", V") != string::npos) {
        
        // Returns last name of string
        candidates[valid].last = electionLine.substr( 
          electionLine.find(",L=")+3, 
          electionLine.find(", V=")-(electionLine.find(",L=")+3) );
        
        // Returns votes of string
        candidates[valid].votes = stoi( electionLine.substr( 
          electionLine.find(", V=")+4, 4 ) );
      }

      valid++; // increment valid count for next candidate
      
      break; // break out of loop
    }
    getline(inFile, electionLine); // read next line into string
  }
}

/* function_identifier: prints array of Candidate structs
 * parameters: candidates array
 * return value: none */

void displayList(Candidate candidates[]) {
  int recordTotal; // counter for candidates
  
  // Candidate list output message
  cout << "ALL CANDIDATES:" << endl;
  cout << setw(10) << "First";
  cout << setw(12) << "Last";
  cout << setw(12) << "Votes";
  cout << setw(12) << "% Score" << endl;
  cout << "----------  ----------  ----------  ----------" << endl;
  
  // For loop iterates through the entire array to count candidates
  for (int i = 0; i < ARR_SIZE; i++) {
    if (candidates[i].first != "")
      recordTotal++;
  }
  
  // Prints first name, last name, votes, and pScore for each candidate
  for (int j = 0; j < recordTotal; j++) {
    cout << setw(10) << candidates[j].first;
    cout << setw(12) << candidates[j].last;
    cout << setw(12) << candidates[j].votes;
    //cout << setw(12) << setprecision(2) << candidates[j].pScore;
    cout << endl;
  }
  
  cout << endl << endl;  
}

/* function_identifier: sorts candidates array by number of votes
 * parameters: candidates array
 * return value: none */

void sortByVotes(Candidate candidates[]) {
  int recordTotal; // counter for candidates
  
  // Output message for sorted candidates
  cout << "ALL CANDIDATES:" << endl;
  cout << setw(10) << "First";
  cout << setw(12) << "Last";
  cout << setw(12) << "Votes";
  cout << setw(12) << "% Score" << endl;
  cout << "----------  ----------  ----------  ----------" << endl;
  
  // For loop to count candidates
  for (int i = 0; i < ARR_SIZE; i++) {
    if (candidates[i].first != "")
      recordTotal++;
  }

  // Attempt to bubble sort
  for (int x = 0; x < recordTotal; x++) {
    for (int y = 0; y < recordTotal-x-1; y++) {
      if (candidates[y+1].votes > candidates[y].votes) {
	swap(candidates[y].votes, candidates[y+1].votes);
      }
    }
  }
  
  // Attempt to print out sorted list
  for (int j = 0; j < recordTotal; j++) {
    cout << setw(10) << candidates[j].first;
    cout << setw(12) << candidates[j].last;
    cout << setw(12) << candidates[j].votes;
    //cout << setw(12) << setprecision(2) << candidates[j].pScore;
    cout << endl;
  }
  
  cout << endl << endl;
  
}

/* function_identifier: prints complete info about candidate
 * parameters: cand variable
 * return value: none
 
 void displayCandidate(Candidate cand) {
 
 }
*/

/* function_identifier: returns candidate with highest score
 * parameters: candidates array
 * return value: ? 
 
 Candidate getWinner(Candidate candidates[]) {
 
 }
*/

/* function_identifier: returns candidate with lowest score
 * parameters: candidates array
 * return value: ? 
 
 Candidate getLast(Candidate candidates[]) {
 
 }
*/

/* function_identifier: calculates percentage score
 * parameters: candidates array
 * return value: none */
void calculateScores(Candidate candidates[]) {
  int recordTotal; // counter for candidates
  double sum = 0; // to calculate sum
  
  // for loop to count candidates
  for (int i = 0; i < ARR_SIZE; i++) {
    if (candidates[i].first != "")
      recordTotal++;
  }
  
  // (Attempt) For loop to find sum of votes
  for (int j = 0; j < recordTotal; j++) {
    sum += candidates[j].votes;
  }
  
  // (Attempt) For loop to calculate pScore
  for (int n = 0; n < recordTotal; n++) {
    candidates[n].pScore = (candidates[n].votes / sum)*.100;
  }
  
}

/* function_identifier: rounds or updates pScore
 * parameters: candidates array
 * return value: none 
 
 void roundScores(Candidate candidates[]) {
 
 }
*/

//  CS 202
//  Implementation file
//  Assignment #2 - Rock-Paper-Scissors-Lizard-Spock

/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 2
 * Description: C++ implementation file to 
  	Rock-Paper-Scissors-Lizard-Spock object. */

#include <iostream>
#include <string>
#include <cstdlib> // rand(), srand()
#include <ctime> // time()
#include "rpslsType.h" // header file

using namespace std;

// sets the constructor to initialize class variables to 0
rpslsType::rpslsType() {
  userWins = 0;
  userLosses = 0;
  gamesPlayed = 0;
}

/* function_identifier: prompt user for move selection
 * parameters: none
 * return value: userInput (integer) */
int rpslsType::getUserMove() {
  char userInput;
  bool invalid = true;
  
  do {
    cout << "------------------------------" << endl;
    cout << "Enter move" << endl;
    cout << "   1 - Rock" << endl;
    cout << "   2 - Paper" << endl;
    cout << "   3 - Scissors" << endl;
    cout << "   4 - Lizard" << endl;
    cout << "   5 - Spock       : ";
    
    cin >> userInput;

    switch (userInput) { 
    /* Break out of loop if menu options chosen */
    case '1': // rock
      invalid = false;      
      break;
      
    case '2': // paper
      invalid = false;
      break;
      
    case '3': // scissors
      invalid = false;
      break;
      
    case '4': // lizard
      invalid = false;
      break;
      
    case '5': // spock
      invalid = false;
      break;

    case ' ': // error for space (doesn't work)
      invalid = true;
      cout << "Error, invalid input." << endl;

      cin.clear();
      cin.ignore(100, '\n');
      break;

    default: // any other input error
      invalid = true;
      cout << endl << "Error, invalid input." << endl;

      cin.clear();
      cin.ignore(100, '\n');
      break;
      
    }
  } while (invalid); // loop if invalid
  return userInput; // return userInput
}

/* function_identifier: Use rand() to select computer move
 * parameters: none
 * return value: cpuInput (integer) */
int rpslsType::getComputerMove () {
  srand(time(0));
  int cpuInput = rand() % 5 + 1; // random integer 1-5
  
  return cpuInput; // return computer move
}

/* function_identifier: return games played, user wins, user losses
 * parameters: wins, losses, games (played)
 * return value: none */
void rpslsType::getScores (int& games, int& wins, int& losses) {
  games = gamesPlayed;
  wins = userWins;
  losses = userLosses;
}

/* function_identifier: display score statistics to the screen
 * parameters: none
 * return value: none */
void rpslsType::showScores () {
  cout << endl;
  cout << "------------------------------" << endl;
  cout << "Score Summary" << endl;
  cout << "  Games Played: " << gamesPlayed << endl;
  cout << "     User wins: " << userWins << endl;
  cout << "   User losses: " << userLosses << endl;
  cout << "     Game Ties: " << (gamesPlayed - (userWins + userLosses))
       << endl;
  cout << endl << endl;
}

/* function_identifier: reset class variables to 0
 * parameters: none
 * return value: none */
void rpslsType::resetScores () {
  userWins = 0;
  userLosses = 0;
  gamesPlayed = 0;
}

/* function_identifier: display score statistics to the screen
 * parameters: none
 * return value: true or false depending on response */
bool rpslsType::playAgain () {
  char userResponse; // user input response
  bool invalid = true; // for invalid response loop
  bool responseCheck; // return value true if 'y/Y'

  // Prompt user to play again
  cout << "Play again (Y/y/N/n): ";
  cin >> userResponse;

  // return true if 'y/Y'
  if (userResponse == 'y' || userResponse == 'Y') {
    responseCheck = true;
  } // return false if 'n/N'
  else if (userResponse == 'n' || userResponse == 'N') {
    responseCheck = false;
  } // loop if any other input
  else {
    while (invalid) {
      // error message
      cout << endl;
      cout << "Error, invalid response. Please re-enter." << endl;

      // Re-prompt
      cout << "Play again (Y/y/N/n): ";
      cin >> userResponse;

      if (userResponse == 'y' || userResponse == 'Y') {
        invalid = false;
        responseCheck = true;
      }
      else if (userResponse == 'n' || userResponse == 'N') {
        invalid = false;
        responseCheck = false;
      }

    }
  }
  return responseCheck;
}

/* function_identifier: play a single round of RPSLS
 * parameters: none
 * return value: none */
void rpslsType::playRound () {
  
  switch (getUserMove()) {
  case '1': // userMove is rock
    cout << endl << "  ";
    if (getComputerMove() == 1) { // computerMove is rock
      cout << "Tie! Please try again!" << endl << endl;
      gamesPlayed++;
    }
    else if (getComputerMove() == 2) { // computerMove is paper
      cout << "Paper covers rock. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 3) { // computerMove is scissors
      cout << "Rock crushes scissors. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 4) { // computerMove is lizard
      cout << "Rock crushes lizard. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 5) { // computerMove is Spock
      cout << "Spock vaporizes rock. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    
    break;
    
  case '2': // userMove is paper
    cout << endl << "  ";
    if (getComputerMove() == 1) { // computerMove is rock
      cout << "Paper covers rock. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 2) { // computerMove is paper
      cout << "Tie! Please try again!" << endl << endl;
      gamesPlayed++;
    }
    else if (getComputerMove() == 3) { // computerMove is scissors
      cout << "Scissors cut paper. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 4) { // computerMove is lizard
      cout << "Lizard eats paper. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 5) { // computerMove is Spock
      cout << "Paper disproves Spock. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    
    break;
    
  case '3': // userMove is scissors
    cout << endl << "  ";
    if (getComputerMove() == 1) { // computerMove is rock
      cout << "Rock crushes scissors. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 2) { // computerMove is paper
      cout << "Scissors cut paper. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 3) { // computerMove is scissors
      cout << "Tie! Please try again!" << endl << endl;
      gamesPlayed++;
    }
    else if (getComputerMove() == 4) { // computerMove is lizard
      cout << "Scissors decapitate lizard. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 5) { // computerMove is Spock
      cout << "Spock smashes scissors. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
			
    break;
    
  case '4': // userMove is lizard
    cout << endl << "  ";
    if (getComputerMove() == 1) { // computerMove is rock
      cout << "Rock crushes lizard. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 2) { // computerMove is paper
      cout << "Lizard eats paper. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 3) { // computerMove is scissors
      cout << "Scissors decapitate lizard. Sorry, you lose."
	   << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 4) { // computerMove is lizard
      cout << "Tie! Please try again!" << endl << endl;
      gamesPlayed++;
    }
    else if (getComputerMove() == 5) { // computerMove is Spock
      cout << "Lizard poisons Spock. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    
    break;
    
  case '5': // userMove is Spock
    cout << endl << "  ";
    if (getComputerMove() == 1) { // computerMove is rock
      cout << "Spock vaporizes rock. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 2) { // computerMove is paper
      cout << "Paper disproves Spock. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 3) { // computerMove is scissors
      cout << "Spock smashes scissors. You win!" << endl << endl;
      userWins++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 4) { // computerMove is lizard
      cout << "Lizard poisons Spock. Sorry, you lose." << endl << endl;
      userLosses++;
      gamesPlayed++;
    }
    else if (getComputerMove() == 5) { // computerMove is Spock
      cout << "Tie! Please try again!" << endl << endl;
      gamesPlayed++;
    }
    
    break;
  }
  
}


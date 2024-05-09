//  CS 202
//  Header file
//  Assignment #2 - Rock-Paper-Scissors-Lizard-Spock

/* Name: Kristy Nguyen, NSHE ID 5006243601, CS 202-1002, Assignment 2
 * Description: C++ header file to 
 Rock-Paper-Scissors-Lizard-Spock object. */

class rpslsType {
  public:
    rpslsType(); // constructor
  
    void playRound();
    void showScores();
    void resetScores();
    bool playAgain();
    void getScores(int &, int &, int &);

 private:
    int userWins;
    int userLosses;
    int gamesPlayed;

    void showRound();
    int getUserMove();
    int getComputerMove();
    
};

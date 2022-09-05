// pacuriel
// Simple program to play rock-paper-scissors in terminal
#include <iostream>
#include <random>

using namespace std;

// Player class
class Player {
public:
    Player(); // Player constructor
    void playGame(); // Function that plays game
    string oppThrow(); // Funtion to throw opponent object
    char decideGame(string opp_obj); // Decides individual game
    void gameOutput(char decision); // Displays output after individual games
    void finalStats(); // Displays a player's final stats
private:
    string name; // Stores player name
    string player_obj; // Stores object thrown
    string opp_obj_name, player_obj_name; // Stores object name
    string keep_playing; // Determines if player would like to continue playing
    int win_ct = 0, loss_ct = 0, tie_ct = 0; // Store win/loss/tie counts
};//Player class

// Player constructor
Player::Player() {
    cout << "Hello, new player. What is your name?" << endl;
    cin >> name;
    cout << "Good luck, " << name << ", and have fun!" << endl;
    cout << "*  *   *   *   *" << endl;
}

// Function to play rock, paper, scissors
void Player::playGame() {
    // do-while loop to play game
    do {
        // Displaying throw output
        cout << "What would you like to throw?" << endl;
        cout << "Enter 'r' for rock, 'p' for paper, or 's' for scissors: " << endl;
        cin >> player_obj; // Inputting object to throw
        string opp_obj = oppThrow(); // Getting opponent's object
        // Deciding game
        char game_result = decideGame(opp_obj); // Storing game result
        gameOutput(game_result); // Displaying game output
        // Play again?
        cout << "Would you like to play again? Enter 'y' or 'n': " << endl;
        cin >> keep_playing;
        cout << "*  *   *   *   *" << endl;
    } while (keep_playing == "y" || keep_playing == "Y");
    // Calling function to display final stats
    finalStats();
}

// Function to throw opponent's object
string Player::oppThrow() {
    default_random_engine generator;
    // Probability of a specifc object being thrown btwn 0,1

    srand(time(0));
    double epsilon = 0.001;
    double obj_prob = (double) ((rand() % 100) + epsilon)/100;
    string opp_obj; // Stores object thrown by opponent

    // if-else statements to decide opponent's object
    if (0 < obj_prob && obj_prob < 0.33) {
        opp_obj = "r"; // Opp throws rock
        opp_obj_name = "rock";
    }
    else if (0.33 < obj_prob && obj_prob < 0.67) {
        opp_obj = "p"; // Opp throws paper
        opp_obj_name = "paper";
    }
    else if (0.67 < obj_prob && obj_prob < 1) {
        opp_obj = "s"; // Opp throws scissors
        opp_obj_name = "scissors";
    }
    return opp_obj; // Returning opponent's object
}// oppThrow

// Function to decide game based on object thrown
char Player::decideGame(string opp_obj) {
    char result = 'T'; // Stores result of game
    // if-else-if statements to decide winner (CLEAN UP)
    if (player_obj == "r") { // Player threw rock
        player_obj_name = "rock";
        if (opp_obj == "p") { // Player loses
            loss_ct++;
            result = 'L';
        }
        else if (opp_obj == "s") { // Player wins
            win_ct++;
            result = 'W';
        }
        else if (opp_obj == "r") { // Player ties
            tie_ct++;
            result = 'T';
        }
    }
    else if (player_obj == "p") { // Player threw paper
        player_obj_name = "paper";
        if (opp_obj == "s") { // Player loses
            loss_ct++;
            result = 'L';
        }
        else if (opp_obj == "r") { // Player wins
            win_ct++;
            result = 'W';
        }
        else if (opp_obj == "p") { // Player ties
            tie_ct++;
            result = 'T';
        }
    }
    else if (player_obj == "s") { // Player threw scissors
        player_obj_name = "scissors";
        if (opp_obj == "r") { // Player loses
            loss_ct++;
            result = 'L';
        }
        else if (opp_obj == "p") { // Player wins
            win_ct++;
            result = 'W';
        }
        else if (opp_obj == "s") { // Player ties
            tie_ct++;
            result = 'T';
        }
    }
    return result;
}// decideGame

// Function to display game output
void Player::gameOutput(char decision) {
    cout << "Opponent threw: " << opp_obj_name << endl;
    // Displaying output based on game result and objects thrown
    if (decision == 'W') { // Player won
        if (player_obj_name == "rock") {
            player_obj_name = "Rock";
        }
        else if (player_obj_name == "paper") {
            player_obj_name = "Paper";
        }
        else if (player_obj_name == "scissors") {
            player_obj_name = "Scissors";
        }
        cout << player_obj_name << " beats " << opp_obj_name << ". You win!" << endl;
    }
    else if (decision == 'L') { // Player lost
        if (opp_obj_name == "rock") {
            opp_obj_name = "Rock";
        }
        else if (opp_obj_name == "paper") {
            opp_obj_name = "Paper";
        }
        else if (opp_obj_name == "scissors") {
            opp_obj_name = "Scissors";
        }
        cout << opp_obj_name << " beats " << player_obj_name << ". You lose!" << endl;
    }
    else if (decision == 'T') { // Player tied
        cout << "It's a tie!" << endl;
    }
}// gameOutput

// Function to display a player's final stats
void Player::finalStats() {
    cout << name << "'s final stats: " << endl;
    cout << "Wins: " << win_ct << "\nLosses: " << loss_ct <<
    "\nTies: " << tie_ct << endl;
    cout << "Thanks for playing, " << name << "!" << endl;
    cout << "*  *   *   *   *" << endl;
}// finalStats

int main() {

    // Creating player object
    Player player_1;

    // Calling play game function to simulate game
    player_1.playGame();

    return 0;
}

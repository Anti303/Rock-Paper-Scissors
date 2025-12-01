// Please be certain to run this code on https://www.onlinegdb.com/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// Colors
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// ASCII FRAMES for Animated Hand
string rockFrame =
"    _______\n"
" ---'   ____)\n"
"       (_____)\n"
"       (_____)\n"
"       (____)\n"
"---.__(___)\n";

string paperFrame =
"     _______\n"
" ---'   ____)____\n"
"           ______)\n"
"          _______)\n"
"         _______)\n"
"---.__________)\n";

string scissorsFrame =
"    _______\n"
" ---'   ____)____\n"
"           ______)\n"
"        __________)\n"
"       (____)\n"
"---.__(___)\n";

// HAND ANIMATION
void handAnimation() {
    string frames[] = { rockFrame, paperFrame, scissorsFrame };
    
    cout << CYAN << "Computer is choosing...\n" << RESET;

    for (int i = 0; i < 12; i++) {
        system("cls"); // Clear screen for animation
        cout << CYAN << "Computer is choosing...\n\n" << RESET;
        cout << BLUE << frames[i % 3] << RESET;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

// Show final static art
void showArt(string move) {
    cout << BLUE;
    if (move == "rock") cout << rockFrame;
    else if (move == "paper") cout << paperFrame;
    else cout << scissorsFrame;
    cout << RESET;
}

// Converts number to move
string getComputerMove(int move){
    if (move == 0) return "rock";
    if (move == 1) return "paper";
    return "scissors";
}

// Determine round outcome
int roundResult(string playerMove, string compMove) {
    if (playerMove == compMove) return 0;
    if (playerMove == "rock"     && compMove == "scissors") return 1;
    if (playerMove == "paper"    && compMove == "rock")     return 1;
    if (playerMove == "scissors" && compMove == "paper")    return 1;
    return -1;
}

int main() {
    srand(time(0));
    string playerMove;
    int score = 0;

    cout << MAGENTA << "====== ROCK PAPER SCISSORS GAME ======" << RESET << "\n";

    // Game Loop
    for (int round = 1; round <= 3; round++) {
        cout << CYAN << "\nROUND " << round << RESET << "\n";
        cout << "Make a move (rock / paper / scissors): ";

        // Player Input
        while (true) {
            cin >> playerMove;
            if (playerMove == "rock" || playerMove == "paper" || playerMove == "scissors")
                break;
            cout << RED << "\tInvalid input! Must be lowercase.\nTry again: " << RESET;
        }

        // Animated hand (NEW)
        handAnimation();

        string compMove = getComputerMove(rand() % 3);

        cout << GREEN << "\nYou chose:\n" << RESET;
        showArt(playerMove);

        cout << RED << "\nComputer chose:\n" << RESET;
        showArt(compMove);

        int result = roundResult(playerMove, compMove);
        score += result;

        if (result == 1)
            cout << GREEN << "➡ You won this round!\n" << RESET;
        else if (result == -1)
            cout << RED << "➡ You lost this round.\n" << RESET;
        else
            cout << YELLOW << "➡ This round is a tie.\n" << RESET;

        cout << CYAN << "Current Score: " << score << RESET << "\n";
    }

    cout << MAGENTA << "\n========== FINAL RESULT ==========\n" << RESET;

    if (score > 0)
        cout << GREEN << "🎉 YOU WIN THE MATCH! 🎉\n" << RESET;
    else if (score < 0)
        cout << RED << "💀 The computer wins...\n" << RESET;
    else
        cout << YELLOW << "🤝 It's a tie!\n" << RESET;

    cout << MAGENTA << "===================================\n" << RESET;

    system("pause");
    return 0;
}
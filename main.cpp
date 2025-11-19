#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string getComputerMove(int move){
    if (move == 0) {
        return "rock";
    }
    else if (move == 1) {
        return "paper";
    }
    return "scissors";
}

int roundResult(string playerMove, string compMove) {
    if (playerMove == compMove) {
        return 0;
    }
    if (playerMove == "rock" && compMove == "paper") {
        return -1;
    }
    if (playerMove == "rock" && compMove == "scissors") {
        return 1;
    }
    if (playerMove == "paper" && compMove == "rock") {
        return 1;
    }
    if (playerMove == "paper" && compMove == "scissors") {
        return -1;
    }
    if (playerMove == "scissors" && compMove == "rock") {
        return -1;
    }
    if (playerMove == "scissors" && compMove == "paper") {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    srand(time(0));
    string playerMove;
    int score = 0;
    cout << "\t\t\tIt's time to Play! Rock, Paper, Scissors\n";
    for (int i = 3; i > 0; i--) {
        cout << "Make a Move: ";
        while(1){
            cin >> playerMove;
            if (playerMove == "rock" || playerMove == "paper" || playerMove == "scissors"){
            break;
            }
            else{
            cout << "\t\tInvalid Input! Please make sure your input is all lowercase\n";
            cout << "Try Again: ";
            }
        }
        string compMove = getComputerMove(rand() % 3);
        cout << playerMove << "\n";
        cout << compMove << "\n";
        score += roundResult(playerMove, compMove);
        cout << "Score: " << score << "\n";
    }
    if (score == 0) {
        cout << "\t\t\tThe Match is Decided!\n";
        cout << "\t\t\t   We have a Tie!\n";
    }
    else if (score > 0) {
        cout << "\t\t\tThe Match is Decided!\n";
        cout << "\t\t\tYou Are The Winner!!!\n";
    }
    else {
        cout << "\t\t\tThe Match is Decided!\n";
        cout << "\t\t\t  The Computer Won!\n";
    }
    system("pause");
    return 0;
}
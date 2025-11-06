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

int main() {
    srand(time(0));
    string compMove = getComputerMove(rand() % 3);
    string compMove2 = getComputerMove(rand() % 3);
    cout << compMove << "\n" << compMove2;
}
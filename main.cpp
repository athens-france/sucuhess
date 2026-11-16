#include <iostream>
#include <string>
#include "chess.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::string board[8][8] = {
        "br", "bn", "bb", "bq", "bk", "bb", "bn", "br",
        "bp", "bp", "bp", "bp", "bp", "bp", "bp", "bp",
        "", "", "", "", "", "", "", "",
        "", "", "", "", "", "", "", "",
        "", "", "", "", "", "", "", "",
        "", "", "", "", "", "", "", "",
        "wp", "wp", "wp", "wp", "wp", "wp", "wp", "wp",
        "wr", "wn", "wb", "wq", "wk", "wb", "wn", "wr",
    };
    drawBoard(board);

    int turn = 0;
    bool active = true;
    char piece = 'n';
    std::string position = "c3";
    std::cout << std::endl;
    move(piece, position, board, turn);
    turn++;

    while (active) {
        if (turn == 0) {
            std::cout << "White's turn!\n" << std::endl;
        } else if (turn == 1) {
            std::cout << "Black's turn!\n" << std::endl;
        }
        drawBoard(board);
        std::cin >> piece >> position;
        std::cout << std::endl;
        move(piece, position, board, turn);
        if (turn == 0) {
            turn++;
        } else {
            turn--;
        }
    }



    std::cout << std::endl;
    int a = 0;
    std::cin >> a;
}
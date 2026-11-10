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
    char piece = 'n';
    std::string position = "c3";

    std::cout << std::endl;
    move(piece, position, board);
    drawBoard(board);

    std::cout << std::endl;
    int a = 0;
    std::cin >> a;
}
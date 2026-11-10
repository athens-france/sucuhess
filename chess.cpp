#include "chess.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>

// ROOK

Rook::Rook() {
    type = 'r';
}

std::vector<Square> Rook::getLegalMoves(const std::string (&arr)[8][8], Square from) const {
    std::vector<Square> moves;
    // ... fill moves ...
    return moves;
}

// KNIGHT

Knight::Knight() {
    type = 'n';
}

std::vector<Square> Knight::getLegalMoves(const std::string (&arr)[8][8], Square from) const {
    std::vector<Square> moves;
    // ... fill moves ...
    for(int r = 0; r < 8; r++) {
        for(int c = 0; c < 8; c++) {
            moves.push_back({r, c});
        }
    }
    return moves;
}

// BISHOP

Bishop::Bishop() {
    type = 'b';
}

std::vector<Square> Bishop::getLegalMoves(const std::string (&arr)[8][8], Square from) const {
    std::vector<Square> moves;
    // ... fill moves ...
    return moves;
}

// KING

King::King() {
    type = 'k';
}

std::vector<Square> King::getLegalMoves(const std::string (&arr)[8][8], Square from) const {
    std::vector<Square> moves;
    // ... fill moves ...
    return moves;
}

// QUEEN

Queen::Queen() {
    type = 'q';
}

std::vector<Square> Queen::getLegalMoves(const std::string (&arr)[8][8], Square from) const {
    std::vector<Square> moves;
    // ... fill moves ...
    return moves;
}

// PAWN

Pawn::Pawn() {
    type = 'p';
}

std::vector<Square> Pawn::getLegalMoves(const std::string (&arr)[8][8], Square from) const {
    std::vector<Square> moves;
    // ... fill moves ...
    return moves;
}

void drawBoard(std::string (&arr)[8][8]) {
    std::cout << "  +---+---+---+---+---+---+---+---+\n";
    for (int i = 0; i < 8; i++) {
        std::cout << 8 - i << " |";

        for (int j = 0; j < 8; j++) {

            std::string display = arr[i][j];

            if (display == "wr") display = "♖";
            else if (display == "wn") display = "♘";
            else if (display == "wb") display = "♗";
            else if (display == "wq") display = "♕";
            else if (display == "wk") display = "♔";
            else if (display == "wp") display = "♙";

            else if (display == "br") display = "♜";
            else if (display == "bn") display = "♞";
            else if (display == "bb") display = "♝";
            else if (display == "bq") display = "♛";
            else if (display == "bk") display = "♚";
            else if (display == "bp") display = "♟";

            if (display.empty()) display = " ";

            std::cout << " " << display << " |";
        }
        std::cout << "\n  +---+---+---+---+---+---+---+---+\n";
    }
}

bool move(char piece, std::string position, std::string(&arr)[8][8]) {

    // algebraic notation to arr index

    std::string pieceToMove = std::string("w") + piece;

    std::transform(position.begin(), position.end(), position.begin(), ::tolower);
    if (position.length() != 2) {
        std::cout << "invalid algebraic notation" << std::endl;
        return false;
    }

    char file_char = position[0]; char rank_char = position[1];
    int x = file_char - 'a';
    int y = '8' - rank_char;

    if (x < 0 || x > 7 || y < 0 || y > 7) {
        std::cout << "Invalid algebraic notation" << std::endl;
        return false;
    }

    Knight knight;
    Rook rook;
    Bishop bishop;
    King king;
    Queen queen;
    Pawn pawn;
    Piece* p = nullptr;
    if (piece == 'n') p = &knight;
    if (piece == 'r') p = &rook;
    if (piece == 'b') p = &bishop;
    if (piece == 'k') p = &king;
    if (piece == 'q') p = &queen;
    if (piece == 'p') p = &pawn;

    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[i][j] != pieceToMove) continue;

            std::vector<Square> moves = p->getLegalMoves(arr, {i, j});

            for (const Square& s : moves) {
                if (s.row == y && s.col == x) {
                    arr[i][j] = " ";
                    arr[y][x] = pieceToMove;
                    return true;
                }
            }
        }
    }
    std::cout << "illegal move!" << std::endl;
    return false;
}
#ifndef CHESS_H
#define CHESS_H
#include <string>
#include <vector>

struct Square { 
    int row, 
    col; 
};

void drawBoard(std::string (&arr)[8][8]);

class Piece {
    public:
        std::string color;
        std::string type;
        virtual ~Piece() {};
        virtual std::vector<Square> getLegalMoves(const std::string (&arr)[8][8], Square from) const = 0;
};

class Rook: public Piece {
    public:
        Rook();
        virtual std::vector<Square> getLegalMoves(const std::string (&arr)[8][8], Square from) const override;
};

class Knight: public Piece {
    public:
        Knight();
        virtual std::vector<Square> getLegalMoves(const std::string (&arr)[8][8], Square from) const override;
};

class Bishop: public Piece {
    public:
        Bishop();
        virtual std::vector<Square> getLegalMoves(const std::string (&arr)[8][8], Square from) const override;
};

class King: public Piece {
    public:
        King();
        virtual std::vector<Square> getLegalMoves(const std::string (&arr)[8][8], Square from) const override;
};

class Queen: public Piece {
    public:
        Queen();
        virtual std::vector<Square> getLegalMoves(const std::string (&arr)[8][8], Square from) const override;
};

class Pawn: public Piece {
    public:
        Pawn();
        virtual std::vector<Square> getLegalMoves(const std::string (&arr)[8][8], Square from) const override;
};

bool move(char piece, std::string position, std::string(&arr)[8][8]);


#endif
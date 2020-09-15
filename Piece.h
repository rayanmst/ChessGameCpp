#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "Position.h"
#include "Board.h"
using namespace std;

class Piece {
public:
    Piece(){};
    Piece(Board* board):_board(board),_pos(NULL){};
    virtual bool** possibleMoves();
    bool possibleMove(Position pos){
        return possibleMoves()[pos.getRow()][pos.getColumn()];
    }
    bool isThereAnyPossibleMove(){
        bool** mat = possibleMoves();
        int length = 8;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (mat[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    Board* _board;
protected:
    Position* _pos;

    Board* getBoard(){
        return _board;
    }
};



#endif // PIECE_H

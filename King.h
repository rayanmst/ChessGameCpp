#ifndef KING_H
#define KING_H
#include "Piece.h"
#include "ChessGame.h"
#include "Pawn.h"
#include "Color.h"

class King: public Piece{
public:
    King(Color color, QGraphicsItem* parent=0): Piece(color,parent){
        setImage();
    }

    void setImage(){
        if(this->_color == Color::BLACK){
            setPixmap(QPixmap(":/images/bKing"));
        } else
            setPixmap(QPixmap(":/images/wKing"));
    }

    void possibleMoves();
private:
    bool testCastling(Position* pos);
};

#endif // KING_H

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"

class Knight: public Piece{
public:
    Knight(Color color, QGraphicsItem* parent=0): Piece(color,parent){
        setImage();
    }
    void setImage(){
        if(_color == Color::BLACK){
            setPixmap(QPixmap(":/images/bKnight"));
        } else
            setPixmap(QPixmap(":/images/wKnight"));
    }
    void possibleMoves();
};

#endif // KNIGHT_H

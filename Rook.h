#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include "Color.h"

class Rook: public Piece {
public:
    Rook(Color color, QGraphicsItem* parent=0): Piece(color,parent){
        setImage();
    }

    void setImage(){
        if(this->_color == Color::BLACK){
            setPixmap(QPixmap(":/images/bRook"));
        } else
            setPixmap(QPixmap(":/images/wRook"));
    }

    void possibleMoves();
};

#endif // ROOK_H

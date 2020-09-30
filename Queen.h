#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include "Color.h"


class Queen: public Piece {
public:
    Queen(Color color, QGraphicsItem* parent=0): Piece(color,parent){
        setImage();
    }

    void setImage(){
        if(this->_color == Color::BLACK){
            setPixmap(QPixmap(":/images/bQueen"));
        } else
            setPixmap(QPixmap(":/images/wQueen"));
    }

    void possibleMoves();
};

#endif // QUEEN_H

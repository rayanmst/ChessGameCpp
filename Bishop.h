#ifndef BISHOP_H
#define BISHOP_H

#include "Color.h"
#include "Piece.h"
class Bishop: public Piece{
public:
    Bishop(Color color, QGraphicsItem* parent=0): Piece(color,parent){
        setImage();
    }
    void setImage(){
        if(_color == Color::BLACK){
            setPixmap(QPixmap(":/images/bBishop"));
        } else
            setPixmap(QPixmap(":/images/wBishop"));
    }
    void possibleMoves();

};


#endif // BISHOP_H

#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn: public Piece{
public:
    Pawn(Color color, QGraphicsItem* parent):Piece(color,parent){
        setImage();
    }

    void setImage(){
        if(_color == Color::BLACK){
            setPixmap(QPixmap(":/images/bPawn.png"));
        } else
            setPixmap(QPixmap(":/images/wPawn.png"));
    }

    void possibleMoves();

};

#endif // PAWN_H

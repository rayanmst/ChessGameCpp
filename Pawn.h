#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <QDebug>
#include "Color.h"

class Pawn: public Piece{
public:
    Pawn(Color color, QGraphicsItem *parent=0):Piece(color,parent){
        setImage();
    }

    void setImage(){
        if(_color == Color::BLACK){
            setPixmap(QPixmap(":/images/bPawn.png"));
        } else
            setPixmap(QPixmap(":/images/wPawn.png"));
    }

    void possibleMoves();

    bool isEnPassantVulnerable(Position* pos);

   // void promotion();

    bool enPassantVulnerable;
};

#endif // PAWN_H

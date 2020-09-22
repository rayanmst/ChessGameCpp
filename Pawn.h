#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include "Color.h"

class Pawn: public Piece{
public:
    Pawn(Color color, QGraphicsItem *parent=0):Piece(color,parent){
        setImage();
    }

    void setImage(){
        if(_color == Color::BLACK){
            setPixmap(QPixmap("C:\\Qt2\\ChessGameCpp\\Images\\bPawn.png"));
        } else
            setPixmap(QPixmap("C:\\Qt2\\ChessGameCpp\\Images\\wPawn.png"));
    }

    void possibleMoves();
private:

};

#endif // PAWN_H

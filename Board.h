#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsRectItem>
#include"Piece.h"

class Board{
public:
    Board(){
        setWhite();
        setBlack();
    }

    void drawBoard(int x, int y);
    void addPieces();
    void setWhite();
    void setBlack();
    void reset();

private:
    QList <Piece*> _wPieces;
    QList <Piece*> _bPieces;
};

#endif // BOARD_H

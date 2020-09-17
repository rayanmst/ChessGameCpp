#ifndef POSITION_H
#define POSITION_H
#include "Piece.h"
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QtWidgets/QGraphicsRectItem>

class Piece;
class Position: public QGraphicsRectItem{

public:

    Position(QGraphicsItem *parent=0);

    ~Position(){
        delete this;
    }

    void mousePressEvent(QGraphicsSceneMouseEvent* e);

    void setColor(QColor color){
        _brush.setColor(color);
        setBrush(color);
    }

    void placePiece(Piece* p);

    void resetColor(){
        setColor(_originalColor);
    }
    void setOriginalColor(QColor val){
        _originalColor = val;
        setColor(_originalColor);
    }

    void setOcupation(bool ocupation){
        _ocupation=ocupation;
    }

    bool isOcupied(){
        return _ocupation;
    }

    void isInCheck();

    Color getPieceColor(){
        if(isOcupied())
            return currentPiece->getColor();
        else
            return Color::NOCOLOR;
    }

    int row;
    int column;

    Piece* currentPiece;

private:
    QBrush _brush;
    bool _ocupation;
    QColor _color, _originalColor;
};

#endif // POSITION_H

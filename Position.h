#ifndef POSITION_H
#define POSITION_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QBrush>
#include "Piece.h"
#include "Color.h"

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

    void setOcupation(bool ocupation,Piece* p=0);

    bool isOcupied(){
        return _ocupation;
    }

    void isInCheck();

    Color getPieceColor(){
        if(isOcupied())
            return _pColor;
        else
            return Color::NOCOLOR;
    }

    void setPieceColor(Color color){
        _pColor = color;
    }

    int row;
    int column;

    Piece* currentPiece;

private:
    QBrush _brush;
    bool _ocupation;
    Color _pColor;
    QColor _color, _originalColor;
};

#endif // POSITION_H

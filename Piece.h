#ifndef PIECE_H
#define PIECE_H
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include "Position.h"
#include "Board.h"
#include "Color.h"
using namespace std;

class Position;
class Piece: public QGraphicsPixmapItem {
public:
    Piece(Color color, QGraphicsItem *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void setCurrentPosition(Position* pos);

    Position* getCurrentPosition(){
      return this->_pos;
    };

    Color getColor(){
        return this->_color;
    }

    void setColor(Color color){
        this->_color = color;
    }

    virtual void setImage()= 0;

    bool getAlive(){
        return this->_alive;
    }

    void setAlive(bool alive){
        this->_alive = alive;
    }

    QList <Position*> moveLocation();

    virtual bool** possibleMoves() = 0;

    bool possibleMove(Position pos){
        return possibleMoves()[pos.getRow()][pos.getColumn()];
    }
    bool setPosition(Position* pos);

private:
    Board* _board;
protected:
    Position* _pos;
    Color _color;
    bool _alive;
    QList <Position*> _location;

};



#endif // PIECE_H

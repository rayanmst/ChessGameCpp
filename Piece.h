#ifndef PIECE_H
#define PIECE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "Position.h"
#include "Color.h"

class Position;
class Piece: public QGraphicsPixmapItem {
public:
    Piece(Color color, QGraphicsItem *parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void setPosition(Position* pos){
        _pos = pos;
    }

    Position* getPosition(){
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

    QList <Position*> getLocation(){
        return _location;
    }

    virtual void possibleMoves() = 0;

    void decolor();

    bool positionSetting(Position* pos);

    void setLastMoved(int val){
        _lastMoved = val;
    }

    int getLastMoved(){
        return _lastMoved;
    }

    int moveCount;


protected:
    Position* _pos;
    Color _color;
    bool _alive;
    QList <Position*> _location;
    int _lastMoved;

};



#endif // PIECE_H

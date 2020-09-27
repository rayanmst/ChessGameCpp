#include "Button.h"

Button::Button(QString name, QGraphicsItem* parent): QGraphicsRectItem(parent){
    setRect(0,0,200,50);
    QBrush b;
    b.setStyle(Qt::SolidPattern);
    b.setColor(Qt::darkRed);
    setBrush(b);

    _txt = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - _txt->boundingRect().width()/2,
        yPos = rect().height()/2 - _txt->boundingRect().height()/2;
    _txt->setPos(xPos,yPos);
    _txt->setDefaultTextColor(Qt::white);

    setAcceptHoverEvents(true);

}

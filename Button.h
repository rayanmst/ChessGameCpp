#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>

class Button: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Button(QString name, QGraphicsItem* parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *e){
        if(e) emit clicked();
    }

    void hoverEnterEvent(QGraphicsSceneHoverEvent *e){
        if(e){
            QBrush b;
            b.setStyle(Qt::SolidPattern);
            b.setColor(Qt::red);
            setBrush(b);
        }
    }

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *e){
        if(e){
            QBrush b;
            b.setStyle(Qt::SolidPattern);
            b.setColor(Qt::darkRed);
            setBrush(b);
        }
    }

signals:
    void clicked();
private:
    QGraphicsTextItem* _txt;

};

#endif // BUTTON_H

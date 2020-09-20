#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Piece.h"
#include "Board.h"

class ChessGame: public QGraphicsView{
    Q_OBJECT
public:
    ChessGame(QWidget* parent=0);
    void drawGraveyard(int x, int y, QColor color);
    void drawBoard();
    void displayDead(Color color);
    void restInPeace(Piece* p);

    void addToScene(QGraphicsItem* item){
        _gScene->addItem(item);
    }
    void removeFromScene(QGraphicsItem* item){
        _gScene->removeItem(item);
    }

    Color getTurn(){
        return _turn;
    }
    void setTurn(Color color){
        _turn=color;
    }

    void changeTurn(){
        if(getTurn()== Color::BLACK)
            setTurn(Color::WHITE);
        else
            setTurn(Color::BLACK);
    }

    void showMenu();
    void gameOver();
    void removeAll();


    Piece *pieceToMove;
    Position *chessBoard[8][8];
    QGraphicsTextItem* check;
    QList <Piece*> alivePiece;

public slots:
    void start();
private:
    Color _turn;
    QGraphicsScene* _gScene;
    Board* _board;
    QList <Piece*> _wDead;
    QList <Piece*> _bDead;
    QList <QGraphicsItem*> _itens;
    QGraphicsRectItem* _gravekeeper;
    QGraphicsTextItem* _disp;
};

#endif // CHESSGAME_H

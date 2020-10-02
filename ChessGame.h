#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Piece.h"
#include "Board.h"

class ChessGame: public QGraphicsView{
    Q_OBJECT
public:

    Piece *pieceToMove;
    Position *chessBoard[8][8];
    QGraphicsTextItem* check;
    QList <Piece*> alivePiece;

    ChessGame(QWidget* parent=0);
    void drawGraveyard(int x, int y, QColor color);
    void drawChessBoard();
    void displayDead(Color color);
    void restInPeace(Piece* p);

    void addToScene(QGraphicsItem* item){
        _gScene->addItem(item);
    }
    void removeFromScene(QGraphicsItem* item){
        _gScene->removeItem(item);
    }

    QString getTurn(){
        return _turn;
    }

    Color getCTurn(){
        return _cTurn;
    }
    void setTurn(QString turn){
        _turn=turn;
        if(turn == "WHITE")
            _cTurn = Color::WHITE;
        else
            _cTurn = Color::BLACK;
    }

    void changeTurn(){
        if(getTurn()== "BLACK")
            setTurn("WHITE");
        else
            setTurn("BLACK");
        _disp->setPlainText("Turn: " + getTurn());
        _turnCount++;
    }
    void setWinner(Color c){
        if(c == Color::BLACK){
            _winner = "Black Won!";
        }
        else
            _winner = "White Won!";
    }

    void resetTurnCount(){
        _turnCount = 1;
    }

    int getTurnCount(){
        return _turnCount;
    }

    void addToSelect(QGraphicsItem* item){
        _select.append(item);
    }

    void removeToSelect(QGraphicsItem* item){
        _select.removeAll(item);
    }

    void moveBox(int x, int y){
        _rect->setPos(x,y);
    }

    void showInitMenu();
    void showEndMenu();
    void gameOver();
    void removeAll();

    void pawnPromotion(Piece* p);
    QList <Piece*> options;
    bool selIsOpen;
    Piece* selected;

public slots:
    void start();
    void restart();
    void closeSel();
private:
    bool _end;
    Color _cTurn;
    QString _turn;
    Board* _board;
    int _turnCount;
    QString _winner;
    Piece* _promoted;
    QList <Piece*> _wDead;
    QList <Piece*> _bDead;
    QGraphicsScene* _gScene;
    QGraphicsRectItem* _rect;
    QGraphicsTextItem* _disp;
    QList <QGraphicsItem*> _itens;
    QList <QGraphicsItem*> _select;
    QGraphicsRectItem* _gravekeeper;
};

#endif // CHESSGAME_H

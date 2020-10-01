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

    void showInitMenu();
    void showEndMenu();
    void gameOver();
    void removeAll();


public slots:
    void start();
    void restart();
private:
    QString _turn;
    QString _winner;
    int _turnCount;
    Color _cTurn;
    QGraphicsScene* _gScene;
    Board* _board;
    QList <Piece*> _wDead;
    QList <Piece*> _bDead;
    QList <QGraphicsItem*> _itens;
    QGraphicsRectItem* _gravekeeper;
    QGraphicsTextItem* _disp;
};

#endif // CHESSGAME_H

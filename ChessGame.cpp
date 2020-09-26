#include "ChessGame.h"
#include <QPixmap>
#include "King.h"


ChessGame::ChessGame(QWidget* parent):QGraphicsView(parent){
    //Create Scene
    _gScene = new QGraphicsScene();
    _gScene->setSceneRect(0,0,1400,850);

    //Build the view
    setFixedSize(1400,850);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(_gScene);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    pieceToMove = NULL;

    //Turn
    _disp = new QGraphicsTextItem();
    _disp->setPos(width()/2-100,10);
    _disp->setZValue(1);
    _disp->setDefaultTextColor(Qt::white);
    _disp->setFont(QFont("",18));
    _disp->setPlainText("Turn: WHITE");

    //Check
    check = new QGraphicsTextItem();
    check->setPos(width()/2-100,850);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
    check->setVisible(false);
    setTurn("WHITE");
    }

void ChessGame::drawGraveyard(int x, int y, QColor color){
    _gravekeeper = new QGraphicsRectItem(x,y,300,900);
    QBrush b;
    b.setStyle(Qt::SolidPattern);
    b.setColor(color);
    _gravekeeper->setBrush(b);
    addToScene(_gravekeeper);

}

void ChessGame::drawChessBoard(){
    _board = new Board();
    drawGraveyard(0,0,Qt::lightGray);
    drawGraveyard(1100,0,Qt::lightGray);
    _board->drawBoard(width()/2-400,50);

}

void ChessGame::displayDead(Color color){
    int delta = 50, j = 0, k = 0;
    if(color == Color::WHITE){
        for(int i = 0, n = _wDead.size();i<n;i++){
            if(j==4){
                k++; j=0;
            }
            _wDead[i]->setPos(40+delta*j,100+delta*2*k);
            j++;
        }
    } else{
        for(int i = 0, n = _bDead.size(); i<n;i++){
            if(j==4){
                k++; j=0;
            }
            _bDead[i]->setPos(1140+delta*j,100+delta*2*k);
            j++;
        }
    }
}

void ChessGame::restInPeace(Piece* p){
    if(p->getColor() == Color::BLACK){
        _bDead.append(p);
        King *k = dynamic_cast<King*>(p);
        if(k){
            check->setPlainText("Black Won!");
            gameOver();
        }
        displayDead(Color::BLACK);
    } else{
        _wDead.append(p);
        King *k = dynamic_cast<King*>(p);
        if(k){
            check->setPlainText("White Won!");
            gameOver();
        }
        displayDead(Color::WHITE);
    }
    alivePiece.removeAll(p);

}

void ChessGame::showInitMenu(){

}

void ChessGame::showEndMenu(){

}

void ChessGame::gameOver(){
    //removeAll();
    setTurn("WHITE");
    alivePiece.clear();
    _board->reset();
    showEndMenu();
}

void ChessGame::removeAll(){
    QList<QGraphicsItem*> iList = _gScene->items();
    for(int i =0,n=iList.size();i<n;i++){
        if(iList[i]!=check)
            removeFromScene(iList[i]);
    }
}

void ChessGame::start(){
    for(int i=0,n=_itens.size();i<n;i++){
        removeFromScene(_itens[i]);
    }
    addToScene(_disp);
    QGraphicsTextItem* wPiece = new QGraphicsTextItem();
    wPiece->setPos(70,10);
    wPiece->setZValue(1);
    wPiece->setDefaultTextColor(Qt::white);
    wPiece->setFont(QFont("",14));
    wPiece->setPlainText("White Piece");
    addToScene(wPiece);

    QGraphicsTextItem* bPiece = new QGraphicsTextItem();
    bPiece->setPos(1170,10);
    bPiece->setZValue(1);
    bPiece->setDefaultTextColor(Qt::black);
    bPiece->setFont(QFont("",14));
    bPiece->setPlainText("Black Piece");
    addToScene(bPiece);
    addToScene(check);
    _board->addPieces();


}

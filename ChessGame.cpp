#include "ChessGame.h"
#include <QPixmap>
#include "King.h"
#include "Button.h"

ChessGame::ChessGame(QWidget* parent):QGraphicsView(parent){
    //Create Scene
    _gScene = new QGraphicsScene();
    _gScene->setSceneRect(0,0,1366,768);

    //Build the view
    setFixedSize(1366,768);
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
    _disp->setPos(width()/2-100,5);
    _disp->setZValue(1);
    _disp->setDefaultTextColor(Qt::white);
    _disp->setFont(QFont("",18));
    _disp->setPlainText("Turn: WHITE");

    //Check
    check = new QGraphicsTextItem();
    check->setPos(width()/2-50,705);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("",18));
    check->setPlainText("CHECK!");
    check->setVisible(false);
    setTurn("WHITE");
    }

void ChessGame::drawGraveyard(int x, int y, QColor color){
    _gravekeeper = new QGraphicsRectItem(x,y,355,768);
    QBrush b;
    b.setStyle(Qt::SolidPattern);
    b.setColor(color);
    _gravekeeper->setBrush(b);
    addToScene(_gravekeeper);

}

void ChessGame::drawChessBoard(){
    _board = new Board();
    drawGraveyard(0,0,Qt::lightGray);
    drawGraveyard(1011,0,Qt::lightGray);
    _board->drawBoard(355,50);

}

void ChessGame::displayDead(Color color, bool end){
    int delta = 55, j = 0, k = 0;
    if(!end){
        if(color == Color::WHITE){
            for(int i = 0, n = _wDead.size();i<n;i++){
                if(j==4){
                    k++; j=0;
                }
                _wDead[i]->setPos(40+delta*j,100+delta*2*k);
                j++;
            }
        } else {
            for(int i = 0, n = _bDead.size(); i<n;i++){
                if(j==4){
                    k++; j=0;
                }
                _bDead[i]->setPos(1140+delta*j,100+delta*2*k);
                j++;
            }
        }
    } else {
        QList <Piece*> dead;
        if(color == Color::WHITE) dead = _wDead;
        else dead = _bDead;
        for(int i = 0, n = dead.size();i<n;i++){
            if(j==8){
                k++;j=0;
            }
            dead[i]->setPos(355+delta*j, 200+delta*2*k);
            j++;
        }
    }
}

void ChessGame::restInPeace(Piece* p){
    if(p->getColor() == Color::BLACK){
        _bDead.append(p);
        displayDead(Color::BLACK);
    } else{
        _wDead.append(p);
        displayDead(Color::WHITE);
    }
    checkMate();
    alivePiece.removeAll(p);
}

void ChessGame::checkMate(){
    for(int i=0,n=_bDead.size();i<n;i++){
       King *king = dynamic_cast<King*>(_bDead[i]);
       if(king){
            _winner = "White Won!";
            gameOver();
       }
    }

    for(int i=0,n=_wDead.size();i<n;i++){
       King *king = dynamic_cast<King*>(_bDead[i]);
       if(king){
            _winner = "Black Won!";
            gameOver();
       }
    }
}

void ChessGame::showInitMenu(){

}

void ChessGame::showEndMenu(){
    //Winner
    QGraphicsTextItem* winner = new QGraphicsTextItem(_winner);
    winner->setDefaultTextColor(Qt::white);
    QFont winnerFont("arial", 50);
    winner->setFont(winnerFont);
    int wxPos = width()/2 - winner->boundingRect().width()/2,
        wyPos = 100;
    winner->setPos(wxPos,wyPos);
    addToScene(winner);
    _itens.append(winner);
    winner->setVisible(true);

    //Reset button
    Button *rst = new Button("Reset");
    int rxPos = width()/2 - rst->boundingRect().width()/2,
        ryPos = 400;
    rst->setPos(rxPos,ryPos);
    connect(rst, SIGNAL(clicked()),this,SLOT(restart()));
    addToScene(rst);
    _itens.append(rst);

    //Quit Button
    Button* quit = new Button("Quit");
    int qxPos = width()/2 - quit->boundingRect().width()/2,
        qyPos = 500;
    quit->setPos(qxPos,qyPos);
    connect(quit, SIGNAL(clicked()),this,SLOT(close()));
    addToScene(quit);
    _itens.append(quit);
}

void ChessGame::gameOver(){
    removeAll();
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
    wPiece->setPos(125,10);
    wPiece->setZValue(1);
    wPiece->setDefaultTextColor(Qt::white);
    wPiece->setFont(QFont("",14));
    wPiece->setPlainText("White Piece");
    addToScene(wPiece);

    QGraphicsTextItem* bPiece = new QGraphicsTextItem();
    bPiece->setPos(1136,10);
    bPiece->setZValue(1);
    bPiece->setDefaultTextColor(Qt::black);
    bPiece->setFont(QFont("",14));
    bPiece->setPlainText("Black Piece");
    addToScene(bPiece);
    addToScene(check);
    _board->addPieces();

}

void ChessGame::restart(){

}

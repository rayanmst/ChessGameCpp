#include "ChessGame.h"
#include <QFont>
#include <QPixmap>
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Button.h"

ChessGame::ChessGame(QWidget* parent):QGraphicsView(parent){
    selIsOpen = false; selected = NULL; _end = false;

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
    resetTurnCount();
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

void ChessGame::displayDead(Color color){
    int delta = 70, j = 0, k = 0;
    if(color == Color::WHITE){
        for(int i = 0, n = _wDead.size();i<n;i++){
            if(j==4){
                k++; j=0;
            }
            _wDead[i]->setPos(30+delta*j,100+delta*2*k);
            j++;
        }
    } else {
        for(int i = 0, n = _bDead.size(); i<n;i++){
            if(j==4){
                k++; j=0;
            }
            _bDead[i]->setPos(1030+delta*j,100+delta*2*k);
            j++;
        }
    }

}

void ChessGame::restInPeace(Piece* p){
    if(p->getColor() == Color::BLACK){
        _bDead.append(p);
        King *king = dynamic_cast<King*>(p);
        if(king){
            _winner = "White Won!";
            gameOver();
        }
        displayDead(Color::BLACK);
    } else{
        _wDead.append(p);
        King *king = dynamic_cast<King*>(p);
        if(king){
            _winner = "Black Won!";
            gameOver();
        }
        displayDead(Color::WHITE);
    }
    alivePiece.removeAll(p);
}


void ChessGame::showInitMenu(){
    QGraphicsPixmapItem *p = new QGraphicsPixmapItem();
    p->setPixmap(QPixmap(":/images/lIcon.png"));
    p->setPos(420,150);
    addToScene(p); _itens.append(p);
    QGraphicsPixmapItem *p1 = new QGraphicsPixmapItem();
    p1->setPixmap(QPixmap(":/images/rIcon.png"));
    p1->setPos(830,150);
    addToScene(p1); _itens.append(p1);
    QGraphicsTextItem *chext = new QGraphicsTextItem("Chess C++");
    chext->setFont(QFont("arial", 50));
    int xPos = width()/2 - chext->boundingRect().width()/2;
    chext->setPos(xPos,150);
    addToScene(chext); _itens.append(chext);

    Button* pBtn = new Button("Play");
    int pxPos = width()/2 - pBtn->boundingRect().width()/2;
    pBtn->setPos(pxPos,300);
    connect(pBtn,SIGNAL(clicked()), this, SLOT(start()));
    addToScene(pBtn); _itens.append(pBtn);

    Button* qBtn = new Button("Quit");
    int qxPos = width()/2 - qBtn->boundingRect().width()/2;
    qBtn->setPos(qxPos,375);
    connect(qBtn,SIGNAL(clicked()), this, SLOT(close()));
    addToScene(qBtn); _itens.append(qBtn);

    drawChessBoard();
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
    _end = true;
    check->setVisible(false);
    _itens.clear();
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

void ChessGame::closeSel(){
    for(int i = 0, n = _select.size();i<n;i++){
        removeFromScene(_select[i]);
    }
    _select.clear();
    options.clear();
    Position* pos = _promoted->getPosition();
    removeFromScene(_promoted);
    alivePiece.removeAll(_promoted);
    pos->placePiece(selected);
    alivePiece.append(selected);
    addToScene(selected);
    selIsOpen = false;
}

void ChessGame::pawnPromotion(Piece* p){
    if(!_end){
        _promoted = p;
        selIsOpen = true;
        _rect = new QGraphicsRectItem(0,0,100,100);
        QGraphicsRectItem* selection = new QGraphicsRectItem(355,200,656,210);
        QGraphicsTextItem* selTxt = new QGraphicsTextItem("Select a piece");
        selTxt->setPos(width()/2 - selTxt->boundingRect().width(),205);
        selTxt->setZValue(4);
        selTxt->setDefaultTextColor(Qt::black);
        QFont selFont = QFont("",18);
        selFont.setWeight(QFont::Bold);
        selTxt->setFont(selFont);

        addToScene(selTxt);_select.append(selTxt);
        QBrush brush;

        Piece *pa;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::gray);
        selection->setBrush(brush);
        addToScene(selection); _select.append(selection);

        Color c = p->getColor();
        pa = new Queen(c);
        options.append(pa);
        _select.append(pa);
        selected = pa;
        pa = new Knight(c);
        options.append(pa);
        _select.append(pa);
        pa = new Rook(c);
        options.append(pa);
        _select.append(pa);
        pa = new Bishop(c);
        options.append(pa);
        _select.append(pa);

        for(int i = 0, n = options.size(); i<n;i++){
            options[i]->setPos(530+i*100 - p->pixmap().width()/2,250);
            addToScene(options[i]);
        }

        moveBox(selected->x(),selected->y());
        addToScene(_rect);
        _select.append(_rect);
        Button* done = new Button("Done");
        int dxPos = 686 - done->boundingRect().width()/2,
                dyPos = 350;
        done->setPos(dxPos,dyPos);
        connect(done, SIGNAL(clicked()),this,SLOT(closeSel()));
        addToScene(done);
        _select.append(done);
    }
}


#include "Position.h"
#include "ChessGame.h"
#include "King.h"

extern ChessGame *g;
Position::Position(QGraphicsItem* parent): QGraphicsRectItem(parent){
    setRect(0,0,82,82);
    _brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setOcupation(false);
    setPieceColor(Color::NOCOLOR);
    currentPiece = NULL;
}

void Position::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if(currentPiece == g->pieceToMove && currentPiece){
        currentPiece->mousePressEvent(e);
        return;
    }

    if(g->pieceToMove){
        //Verifica se é da mesma cor
        if(this->getPieceColor() == g->pieceToMove->getColor()){
            return;
        }

        //Remoção da peça comida
        QList <Position*> newLoc = g->pieceToMove->getLocation();

        //Verifica se a posição final está dentro das regras
        int check = 0;
        for(int i=0,n=newLoc.size();i<n;i++){
            if(newLoc[i]==this){
                check++;
            }
        }
        if(check==0) return;

        g->pieceToMove->decolor();
        g->pieceToMove->moveCount++;

        //Retirando a peça inimiga do local
        if(this->isOcupied()){
            this->currentPiece->setAlive(false);
            this->currentPiece->setPosition(NULL);
            g->restInPeace(this->currentPiece);
        }

        //Novos parâmetros da peça movida
        g->pieceToMove->getPosition()->setOcupation(false);
        g->pieceToMove->getPosition()->currentPiece = NULL;
        g->pieceToMove->getPosition()->resetColor();
        placePiece(g->pieceToMove);
        g->pieceToMove = NULL;
        g->changeTurn();
        isInCheck();
    }
    else if(this->isOcupied()){
        this->currentPiece->mousePressEvent(e);
    }
}

void Position::placePiece(Piece *p){
    p->setPos(x()+41 - p->pixmap().width()/2,y()+41 - p->pixmap().width()/2);
    p->setPosition(this);
    setOcupation(true,p);
    currentPiece = p;
}

void Position::isInCheck(){
    int c=0;
    QList <Piece*> pList = g->alivePiece;
    for(int i=0,n=pList.size();i<n;i++){
        King* k = dynamic_cast<King*>(pList[i]);
        if(k) continue;
        pList[i]->possibleMoves();
        pList[i]->decolor();
        QList <Position*> posList = pList[i]->getLocation();
        for(int j = 0,n=posList.size();j<n;j++){
            King* q = dynamic_cast<King*>(posList[j]->currentPiece);
            if(q){
                if(q->getColor()==pList[i]->getColor()) continue;
                posList[j]->setColor(Qt::blue);
                pList[i]->getPosition()->setColor(Qt::darkRed);
                //Exibindo a mensagem de Check
                if(!g->check->isVisible()){
                    g->check->setVisible(true);
                } else{
                    posList[j]->resetColor();
                    pList[i]->getPosition()->resetColor();
                    if(q->getColor() == Color::BLACK) g->setWinner(Color::WHITE);
                    else g->setWinner(Color::BLACK);
                    g->check->setVisible(false);
                    g->gameOver();
                }
                c++;
            }
        }

    }
    if(!c){
        g->check->setVisible(false);
        for(int i=0,n=pList.size();i<n;i++){
            pList[i]->getPosition()->resetColor();
        }
    }
}

void Position::setOcupation(bool ocupation,Piece* p){
    _ocupation=ocupation;
    if(ocupation){
        Color c = p->getColor();
        setPieceColor(c);
    } else
        setPieceColor(Color::NOCOLOR);
}

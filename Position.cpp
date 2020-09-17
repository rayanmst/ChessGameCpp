#include "Position.h"
#include "ChessGame.h"
#include "King.h"

extern ChessGame *game;
Position::Position(QGraphicsItem* parent): QGraphicsRectItem(parent){
    setRect(0,0,100,100);
    _brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setOcupation(false);
    currentPiece = NULL;
}

void Position::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if(currentPiece == game->pieceToMove && currentPiece){
        currentPiece->mousePressEvent(e);
        return;
    }

    if(game->pieceToMove){
        //Verifica se é da mesma cor
        if(this->getPieceColor() == game->pieceToMove->getColor()){
            return;
        }

        //Remoção da peça comida
        QList <Position*> newLoc = game->pieceToMove->moveLocation();

        //Verifica se a posição final está dentro das regras
        int check = 0;
        for(int i=0,n=newLoc.size();i<n;i++){
            if(newLoc[i]==this){
                check++;
            }
        }
        if(!check) return;

        game->pieceToMove->decolor();
        game->pieceToMove->_firstMove=false;

        //Retirando a peça inimiga do local
        if(this->isOcupied()){
            this->currentPiece->setAlive(false);
            this->currentPiece->setPosition(NULL);
            game->restInPeace(this->currentPiece);
        }

        //Novos parâmetros da peça movida
        game->pieceToMove->getPosition()->setOcupation(false);
        game->pieceToMove->getPosition()->_currentPiece = NULL;
        game->pieceToMove->getPosition()->resetColor();
        placePiece(game->pieceToMove);

        game->pieceToMove = NULL;
        game->changeTurn();
        isInCheck();
    }
    else if(this->isOcupied()){
        this->currentPiece->mousePressEvent(e);
    }
}

void Position::isInCheck(){
    int c=0;
    QList <Piece*> pList = game->alivePiece;
    for(int i=0,n=pList.size();i<n;i++){
        King* k = dynamic_cast<King*>(pList[i]);
        if(k) continue;
        pList[i]->possibleMoves();
        pList[i]->decolor();
        QList <Position*> posList = pList[i]->moveLocation();
        for(int j = 0,n=posList.size();j<n;j++){
            King* g = dynamic_cast<King*>(posList[j]->currentPiece);
            if(g){
                if(g->getColor()==pList[i]->getColor()) continue;
                posList[j]->setColor(Qt::blue);
                pList[i]->getPosition()->setColor(Qt::darkRed);
                //Exibino a mensagem de Check
                if(!game->check->isVisible){
                    game->check->setVisible(true);
                } else{
                    posList[j]->resetColor();
                    pList[i]->getPosition()->resetColor();
                    game->gameOver();
                }
                c++;
            }
        }

    }
    if(!c){
        game->check->setVisible(false);
        for(int i=0,n=pList.size();i<n;i++){
            pList[i]->getPosition()->resetColor();
        }
    }
}

#include "Piece.h"
#include "ChessGame.h"
#include "King.h"

extern ChessGame *g;
Piece::Piece(Color color, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    _color = color; _alive = true; moveCount=0;
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *e){
    //Removendo selecao da peca
    if(this == g->pieceToMove){
        g->pieceToMove->getPosition()->resetColor();
        g->pieceToMove->decolor();
        g->pieceToMove = NULL;
        return;
    }
    //Verifica se a peça ainda está viva ou se é do respectivo jogador
    if((!getAlive()) || ((g->getCTurn() != this->getColor()) && (!g->pieceToMove))){
        return;
    }

    //Selecionando a peca
    if(!g->pieceToMove){
        g->pieceToMove = this;
        g->pieceToMove->getPosition()->setColor(Qt::green);
        g->pieceToMove->possibleMoves();

      //Consuming enemy
    } else if(this->getColor() != g->pieceToMove->getColor()){
        this->getPosition()->mousePressEvent(e);
    }
}

void Piece::decolor(){
    for(int i=0,n=_location.size();i<n;i++){
        _location[i]->resetColor();
    }
}

bool Piece::positionSetting(Position *pos){
    if(pos->isOcupied()){
        King *k = dynamic_cast<King*>(_location.last()->currentPiece);
        if(k){
            pos->setColor(Qt::blue);
        } else
            pos->setColor(Qt::red);
        return true;
    } else
        _location.last()->setColor(Qt::darkRed);
    return false;

}

#include "Piece.h"
#include "ChessGame.h"
#include "King.h"

extern ChessGame *game;
Piece::Piece(Color color, QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    _color = color; _alive = true; _firstMove = true;
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent *e){
    //Removendo selecao da peca
    if(game->pieceToMove){
        game->pieceToMove = this;
        this->getPosition()->resetColor();
        game->pieceToMove = NULL;
        return;
    }
    //Verifica se a peça ainda está viva ou se é do respectivo jogador
    if((!getAlive()) || ((game->getTurn() != this->getColor()) && (!game->pieceToMove))){
        return;
    }

    //Selecionando a peca
    if(!game->pieceToMove){
        game->pieceToMove=this;
        this->getPosition()->setColor(Qt::green);
        this->possibleMoves();
    } else if(this->getColor() != game->pieceToMove->getColor()){
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
            pos->setColor(Qt::darkRed);
        return true;
    } else
        _location.last()->setColor(Qt::darkRed);
    return false;

}

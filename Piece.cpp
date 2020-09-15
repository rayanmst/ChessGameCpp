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

}

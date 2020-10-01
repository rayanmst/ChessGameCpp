#include "Pawn.h"
#include "ChessGame.h"
#include <QDebug>

extern ChessGame* g;
void Pawn::possibleMoves(){
    _location.clear();
    int pRow = this->getPosition()->row;
    int pCol = this->getPosition()->column;
    Color color = this->getColor();

    //White moves:
    if(color == Color::WHITE){
        //Foward
        if(pRow>0 && (!g->chessBoard[pRow-1][pCol]->isOcupied())){
            _location.append(g->chessBoard[pRow-1][pCol]);
            positionSetting(_location.last());
            //First move condition
            if(moveCount==0 && !g->chessBoard[pRow-2][pCol]->isOcupied()){
                _location.append(g->chessBoard[pRow-2][pCol]);
                positionSetting(_location.last());
            }
        }
        //Eat adversary pieces
        if(pRow>0 && pCol>0 && g->chessBoard[pRow-1][pCol-1]->getPieceColor()==Color::BLACK){
            _location.append(g->chessBoard[pRow-1][pCol-1]);
            positionSetting(_location.last());
        }
        if(pRow>0 && pCol<7 && g->chessBoard[pRow-1][pCol+1]->getPieceColor()==Color::BLACK){
            _location.append(g->chessBoard[pRow-1][pCol+1]);
            positionSetting(_location.last());
        }

    }
    //Black Moves
    else {
        //Foward
        if(pRow<7 && (!g->chessBoard[pRow+1][pCol]->isOcupied())){
            _location.append(g->chessBoard[pRow+1][pCol]);
            positionSetting(_location.last());
            //First move condition
            if(moveCount==0 && !g->chessBoard[pRow+2][pCol]->isOcupied()){
                _location.append(g->chessBoard[pRow+2][pCol]);
                positionSetting(_location.last());
            }
        }
        //Eat adversary pieces
        if(pRow<7 && pCol>0 && g->chessBoard[pRow+1][pCol-1]->getPieceColor()==Color::WHITE){
            _location.append(g->chessBoard[pRow+1][pCol-1]);
            positionSetting(_location.last());
        }
        if(pRow<7 && pCol<7 && g->chessBoard[pRow+1][pCol+1]->getPieceColor()==Color::WHITE){
            _location.append(g->chessBoard[pRow+1][pCol+1]);
            positionSetting(_location.last());
        }
    }

    //EnPassant
    //Left
    if(g->chessBoard[pRow][pCol-1]->isOcupied() && isEnPassantVulnerable(g->chessBoard[pRow][pCol-1])){
        _location.append(g->chessBoard[pRow][pCol-1]);
        _location.last()->setColor(Qt::yellow);
    }
    if(g->chessBoard[pRow][pCol+1]->isOcupied() && isEnPassantVulnerable(g->chessBoard[pRow][pCol+1])){
        _location.append(g->chessBoard[pRow][pCol+1]);
        _location.last()->setColor(Qt::yellow);
    }


}

bool Pawn::isEnPassantVulnerable(Position* pos){
    Pawn* pawn = dynamic_cast<Pawn*>(pos->currentPiece);
    if(pawn) {
        if(pawn->moveCount == 1 && (pawn->getLastMoved() == g->getTurnCount()-1)&& ((pos->row == 3 && pawn->getColor() == Color::BLACK) ||(pos->row == 4 && pawn->getColor() == Color::WHITE))){
            pawn->enPassantVulnerable = true;
        } else
            pawn->enPassantVulnerable = false;
        return pawn->enPassantVulnerable;
    }
    return false;
}
/*
void Pawn::promotion(){

}
*/

#include "Pawn.h"
#include "ChessGame.h"

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
        //En Passant TODO
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

        //En Passant TODO
    }




}

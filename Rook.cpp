#include "Rook.h"
#include "ChessGame.h"

extern ChessGame* g;
void Rook::possibleMoves(){
    _location.clear();
    int rRow = this->getPosition()->row,
        rCol = this->getPosition()->column;
    Color c = this->getColor();

    //Up
    for(int i = rRow-1, j = rCol; i>=0; i--){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }

    //Down
    for(int i = rRow+1, j = rCol; i<=7; i++){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }

    //Left
    for(int i = rRow, j = rCol-1; j>=0; j--){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }

    //Right
    for(int i = rRow, j = rCol+1; j<=7; j++){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }
}

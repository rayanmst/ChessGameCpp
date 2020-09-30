#include "Queen.h"
#include "ChessGame.h"

extern ChessGame *g;
void Queen::possibleMoves(){
    _location.clear();
    int qRow = this->getPosition()->row,
        qCol = this->getPosition()->column;
    Color c = this->getColor();

    //Up
    for(int i = qRow-1, j = qCol; i>=0; i--){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }

    //Down
    for(int i = qRow+1, j = qCol; i<=7; i++){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }

    //Left
    for(int i = qRow, j = qCol-1; j>=0; j--){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }

    //Right
    for(int i = qRow, j = qCol+1; j<=7; j++){
        if(g->chessBoard[i][j]->getPieceColor() == c) break;
        else{
            _location.append(g->chessBoard[i][j]);
            //Checking if the position is ocupied by any piece
            if(positionSetting(_location.last())) break;
        }
    }

    //Up Left
    for(int i = qRow-1, j = qCol-1; i>=0 && j>=0;i--,j--){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }

    //Up Right
    for(int i = qRow-1, j = qCol+1; i>=0 && j<=7;i--,j++){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }

    //Down Right
    for(int i = qRow+1, j = qCol+1; i<=7 && j<=7;i++,j++){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }

    //Down Left
    for(int i = qRow+1, j = qCol-1; j>=0 && i<=7;j--,i++){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }
}

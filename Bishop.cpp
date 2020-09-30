#include "Bishop.h"
#include "ChessGame.h"

extern ChessGame *g;

void Bishop::possibleMoves(){
    _location.clear();
    int bRow = this->getPosition()->row,
        bCol = this->getPosition()->column;

    //Up Left
    for(int i = bRow-1, j = bCol-1; i>=0 && j>=0;i--,j--){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }

    //Up Right
    for(int i = bRow-1, j = bCol+1; i>=0 && j<=7;i--,j++){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }

    //Down Right
    for(int i = bRow+1, j = bCol+1; i<=7 && j<=7;i++,j++){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }

    //Down Left
    for(int i = bRow+1, j = bCol-1; j>=0 && i<=7;j--,i++){
        if(g->chessBoard[i][j]->getPieceColor() == _color) break;
        else{
            _location.append(g->chessBoard[i][j]);
            if(positionSetting(_location.last())) break;
        }
    }
}

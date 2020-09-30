#include "Knight.h"
#include "ChessGame.h"

extern ChessGame* g;

void Knight::possibleMoves(){
    _location.clear();
    int i,j,
        hRow = this->getPosition()->row,
        hCol = this->getPosition()->column;
    Color c = this->getColor();


    //Up left
    i = hRow - 2; j = hCol - 1;
    if(i>=0 && j>=0 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }

    //Up right
    i = hRow - 2; j = hCol + 1;
    if(i>=0 && j<=7 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }
    //Left up
    i = hRow - 1; j = hCol - 2;
    if(i>=0 && j>=0 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }
    //Left down
    i = hRow + 1; j = hCol - 2;
    if(i<=7 && j>=0 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }

    //Down left
    i = hRow + 2; j = hCol - 1;
    if(i<=7 && j>=0 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }

    //Down right
    i = hRow + 2; j = hCol + 1;
    if(i<=7 && j<=7 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }

    //Right up
    i = hRow - 1; j = hCol + 2;
    if(i>=0 && j<=7 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }

    //Right down
    i = hRow + 1; j = hCol + 2;
    if(i<=7 && j<=7 && (g->chessBoard[i][j]->getPieceColor() != c)){
            _location.append(g->chessBoard[i][j]);
            if(_location.last()->isOcupied()) _location.last()->setColor(Qt::red);
            else _location.last()->setColor(Qt::darkRed);
    }

}

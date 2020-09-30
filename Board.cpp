#include "Board.h"
#include "Position.h"
#include "ChessGame.h"
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"

extern ChessGame* g;
void Board:: drawBoard(int x, int y){
    int DELTA = 82;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Position* p = new Position();
            g->chessBoard[i][j] = p;
            p->row=i; p->column=j;
            p->setPos(x+DELTA*j,y+DELTA*i);
            if((i+j)%2==0)
                p->setOriginalColor(Qt::lightGray);
            else
                p->setOriginalColor(Qt::darkGray);
            g->addToScene(p);
        }
    }
}

void Board::setBlack(){
    Piece* p;
    Color c = Color::BLACK;
    p = new Rook(c);
    _bPieces.append(p);
    p = new Knight(c);
    _bPieces.append(p);
    p = new Bishop(c);
    _bPieces.append(p);
    p = new Queen(c);
    _bPieces.append(p);
    p = new King(c);
    _bPieces.append(p);
    p = new Bishop(c);
    _bPieces.append(p);
    p = new Knight(c);
    _bPieces.append(p);
    p = new Rook(c);
    _bPieces.append(p);
    for(int i=0;i<8;i++){
        p = new Pawn(c);
        _bPieces.append(p);
    }
}

void Board::setWhite(){
    Piece* p;
    Color c = Color::WHITE;
    for(int i=0;i<8;i++){
        p = new Pawn(c);
        _wPieces.append(p);
    }
    p = new Rook(c);
    _wPieces.append(p);
    p = new Knight(c);
    _wPieces.append(p);
    p = new Bishop(c);
    _wPieces.append(p);
    p = new Queen(c);
    _wPieces.append(p);
    p = new King(c);
    _wPieces.append(p);
    p = new Bishop(c);
    _wPieces.append(p);
    p = new Knight(c);
    _wPieces.append(p);
    p = new Rook(c);
    _wPieces.append(p);

}
void Board::addPieces(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            Position* p = g->chessBoard[i][j];
            if(i<2){
                static int k;
                p->placePiece(_bPieces[k]);
                g->alivePiece.append(_bPieces[k]);
                g->addToScene(_bPieces[k]);
                k++;
            }
            if(i>5){
                static int h;
                p->placePiece(_wPieces[h]);
                g->alivePiece.append(_wPieces[h]);
                g->addToScene(_wPieces[h]);
                h++;
            }
        }
    }
}

void Board::reset(){
    int k = 0; int h = 0;
    for(int i = 0;i<8;i++){
        for(int j = 0; j<8; j++){
            Position* p = g->chessBoard[i][j];
            p->setOcupation(false);
            p->setPieceColor(Color::NOCOLOR);
            p->currentPiece = NULL;
            if(i < 2) {

                p->placePiece(_bPieces[k]);
                _bPieces[k]->setAlive(true);
                _bPieces[k]->moveCount = 0;
                g->alivePiece.append(_bPieces[k++]);

            }
            if(i > 5) {

                p->placePiece(_wPieces[h]);
                _wPieces[h]->setAlive(true);
                _wPieces[h]->moveCount = 0;
                g->alivePiece.append(_wPieces[h++]);

            }
        }
    }
}

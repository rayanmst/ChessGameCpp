#include "King.h"

extern ChessGame* g;
void King::possibleMoves(){
    _location.clear();
    Position* p = this->getPosition();
    int kRow = p->row; int kCol = p->column;
    Color color = this->getColor();

    //Above
    if(kRow>0 && !(g->chessBoard[kRow-1][kCol]->getPieceColor()== color)){
        _location.append(g->chessBoard[kRow-1][kCol]);
        g->chessBoard[kRow-1][kCol]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Below
    if(kRow<7 && !(g->chessBoard[kRow+1][kCol]->getPieceColor() == color)){
        _location.append(g->chessBoard[kRow+1][kCol]);
        g->chessBoard[kRow+1][kCol]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Left
    if(kCol>0 && !(g->chessBoard[kRow][kCol-1]->getPieceColor() == color)){
        _location.append(g->chessBoard[kRow][kCol-1]);
        g->chessBoard[kRow][kCol-1]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Right
    if(kCol<7 && !(g->chessBoard[kRow][kCol+1]->getPieceColor() == color)){
        _location.append(g->chessBoard[kRow][kCol+1]);
        g->chessBoard[kRow][kCol+1]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Up left
    if(kRow>0 && kCol>0 && !(g->chessBoard[kRow-1][kCol-1]->getPieceColor() == color)){
        _location.append(g->chessBoard[kRow-1][kCol-1]);
        g->chessBoard[kRow-1][kCol-1]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Up right
    if(kRow>0 && kCol<7 && !(g->chessBoard[kRow-1][kCol+1]->getPieceColor() == color)){
        _location.append(g->chessBoard[kRow-1][kCol+1]);
        g->chessBoard[kRow-1][kCol+1]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Down left
    if(kRow<7 && kCol>0 && !(g->chessBoard[kRow+1][kCol-1]->getPieceColor() == color)){
        _location.append(g->chessBoard[kRow+1][kCol-1]);
        g->chessBoard[kRow+1][kCol-1]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Down Right
    if(kRow<7 && kCol<7 && !(g->chessBoard[kRow+1][kCol+1]->getPieceColor() == color)){
        _location.append(g->chessBoard[kRow+1][kCol+1]);
        g->chessBoard[kRow+1][kCol+1]->setColor(Qt::darkRed);
        if(_location.last()->isOcupied()){
            _location.last()->setColor(Qt::red);
        }
    }

    //Unsafe positions
    QList <Piece*> pList = g->alivePiece;
    for(int i=0,n=pList.size();i<n;i++){
        if(pList[i]->getColor() != this->getColor()){
            QList <Position*> posList = pList[i]->getLocation();

            for(int j=0,m=posList.size();j<m;j++){
                Pawn* c = dynamic_cast<Pawn*>(pList[i]);
                if(c) continue;
                for(int k=0,o=_location.size();k<o;k++){
                    if(posList[j]==_location[k]){
                        _location[k]->setColor(Qt::blue);
                    }
                }
            }
        }
    }

}

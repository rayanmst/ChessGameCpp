#include "King.h"
#include "Rook.h"

extern ChessGame* g;
void King::possibleMoves(){
    _location.clear();
    int kRow = this->getPosition()->row; int kCol = this->getPosition()->column;
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

    //Castling SPM
    if(moveCount == 0 && !(g->check->isVisible())){
        //KingSide Rook
        if(testCastling(g->chessBoard[kRow][kCol+3])){
            bool test1 = g->chessBoard[kRow][kCol+1]->isOcupied(),
                 test2 = g->chessBoard[kRow][kCol+2]->isOcupied();
            if(!test1 && !test2){
                _location.append(g->chessBoard[kRow][kCol+2]);
                g->chessBoard[kRow][kCol+2]->setColor(Qt::yellow);
            }
        }

        //QueenSide Rook
        if(testCastling(g->chessBoard[kRow][kCol-4])){
            bool test1 = g->chessBoard[kRow][kCol-3]->isOcupied(),
                 test2 = g->chessBoard[kRow][kCol-2]->isOcupied(),
                 test3 = g->chessBoard[kRow][kCol-1]->isOcupied();
            if(!test1 && !test2 && !test3){
                _location.append(g->chessBoard[kRow][kCol-2]);
                g->chessBoard[kRow][kCol-2]->setColor(Qt::yellow);
            }
        }
    }
}
bool King::testCastling(Position* pos){
    if(!(pos->isOcupied())) return false;
    Rook *rook = dynamic_cast<Rook *>(pos->currentPiece);
    if(rook){
        if(rook->moveCount == 0 && rook->getColor() == getColor()) return true;
        return false;
    } else{
        return false;
    }
}

#include "ChessGame.h"
#include "Board.h"
#include <QApplication>

ChessGame* g;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    g = new ChessGame();
    g->drawChessBoard();
    g->start();
    g->show();

    return a.exec();
}

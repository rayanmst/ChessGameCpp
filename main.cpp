#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Position.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    bool mat[8][8] = {
        {false,false,false,false,false,false,false, false},
        {false,false,false,false,false,false,false, false},
        {false,false,false,false,false,false,false, false},
        {false,false,false,false,false,false,false, false},
        {false,false,false,false,false,false,false, false},
        {false,false,false,false,false,false,false, false},
        {false,false,false,false,false,false,false, false},
        {false,false,false,false,false,false,false, false}
    }, c=false;
    int length = 8;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (mat[i][j]) {
                c=true;
                break;
            }
        }
    }
    cout << c << endl;

return 0;
//return app.exec();
}

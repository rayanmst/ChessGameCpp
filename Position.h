#ifndef POSITION_H
#define POSITION_H
#include <string>
using namespace std;

class Position{
private:
    int _row;
    int _column;
public:
    Position();
    Position(int row, int column):_row(row), _column(column){};
    int getRow(){
        return _row;
    };

    void setRow(int row){
        _row=row;
    };

    int getColumn(){
        return _column;
    }

    void setValues(int row, int column){
        _row=row; _column = column;
    }

    std::string to_string() {
        return '[' + std::to_string(_row) + ',' + std::to_string(_column) + ']';
    }
};

#endif // POSITION_H

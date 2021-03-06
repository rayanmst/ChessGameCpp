QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bishop.cpp \
    Board.cpp \
    Button.cpp \
    ChessGame.cpp \
    King.cpp \
    Knight.cpp \
    Pawn.cpp \
    Piece.cpp \
    Position.cpp \
    Queen.cpp \
    Rook.cpp \
    main.cpp

HEADERS += \
    Bishop.h \
    Board.h \
    Button.h \
    ChessGame.h \
    Color.h \
    King.h \
    Knight.h \
    Pawn.h \
    Piece.h \
    Position.h \
    Queen.h \
    Rook.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

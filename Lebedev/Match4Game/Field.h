#pragma once

const int FIELD_WIDTH = 7;
const int FIELD_HEIGHT = 6;

enum Cell
{
    EMPTY,
    RED,
    YELLOW
};

class Field
{
    Cell cells[FIELD_WIDTH][FIELD_HEIGHT];
    bool isRedTurn;
    Cell winner;

    //void clear(State turn);
 public:
    Field(bool isRedFirst);
    void clear(bool isRedFirst);
    bool makeTurn(int column);
    bool isOver() const;
    bool isRedTurnNow() const;
    void print() const;
    void printResult() const;
    void checkWinner();

    //bool isWon(bool isRed) const;
    //Cell getCell(int i, int j) const;

    //Field(int h, int w, Cell turn = RED);

};

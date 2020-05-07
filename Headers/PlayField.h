//
// Created by Sam Petrov on 22.04.2020.
//
#ifndef TICTACTOE_PLAYFIELD_H
#define TICTACTOE_PLAYFIELD_H

#include <vector>

class PlayField{
public:
    enum csState {
        csEmpty,
        csCross,
        csNought
    };

    enum fnState {
        fsInvalid,
        fsNormal,
        fsCrossesWin,
        fsNoughtsWin,
        fsDraw
    };

    class CellPos{
    public:
        CellPos(int, int);
        operator int() const;
    private:
        int x, y;
    };

    PlayField();
    csState operator[](CellPos) const;
    void print() const;
    std::vector<CellPos> getEmptyCells() const;
    fnState checkFieldStatus() const;
    PlayField makeMove(CellPos) const;
private:
    static constexpr int HEIGHT_FIELD = 3;
    static constexpr int SIZE_FIELD = HEIGHT_FIELD * HEIGHT_FIELD;
    csState cellField[SIZE_FIELD];
    PlayField operator+(CellPos) const;
};
#endif //TICTACTOE_PLAYFIELD_H
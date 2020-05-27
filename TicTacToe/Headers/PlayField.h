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

    static constexpr int FIELD_HEIGHT = 3;
    static constexpr int FIELD_SIZE = FIELD_HEIGHT * FIELD_HEIGHT;

    class CellPos{
    public:
        CellPos(int, int);
        operator int() const;
    private:
        int x = 0;
        int y = 0;
    };

    PlayField();
    csState operator[](const CellPos) const;
    void print() const;
    int diffCrossAndNought() const;
    std::vector<CellPos> getEmptyCells() const;
    fnState checkFieldStatus() const;
    PlayField makeMove(CellPos) const;
private:
    csState cellField[FIELD_SIZE];
    PlayField operator+(CellPos) const;
};
#endif //TICTACTOE_PLAYFIELD_H
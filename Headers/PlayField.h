//
// Created by Sam Petrov on 22.04.2020.
//
#include <vector>

#ifndef TICTACTOE_PLAYFIELD_H
#define TICTACTOE_PLAYFIELD_H
class PlayField{
public:
    enum class csState;
    enum class fnState;
    static const int SIZE_FIELD = 9;
    class CellPos{
        private:
            int x, y;
        public:
            CellPos(int, int);
            int getIndex();
    };

    PlayField();
    csState operator[](CellPos);
    std::vector<CellPos> getEmptyCells() const;
    fnState checkFieldStatus() const;
    PlayField makeMove(CellPos) const;
private:
    csState previosState;
    csState cellField[SIZE_FIELD]{};
    PlayField operator+(CellPos);
};
#endif //TICTACTOE_PLAYFIELD_H
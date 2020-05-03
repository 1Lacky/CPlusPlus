//
// Created by Sam Petrov on 22.04.2020.
//
#include <vector>
#include <cassert>
#include "../Headers/PlayField.h"

enum class PlayField::csState{
        csEmpty,
        csCross,
        csNought
};
enum class PlayField::fnState{
        fsInvalid,
        fsNormal,
        fsCrossesWin,
        fsNoughtsWin,
        fsDraw
};

PlayField::PlayField() {
    previosState = csState::csCross;
    for(int i = 0; i < 9; ++i)
        cellField[i] = csState::csEmpty;
}

PlayField::CellPos::CellPos(int a, int b) {
    assert((a >= 0 && a <= 2) && (b >= 0 && b <= 2));
    x = a;
    y = b;
}

int PlayField::CellPos::getIndex() {
    return 3 * this->x + this->y;
}

PlayField::csState PlayField::operator[](PlayField::CellPos item){
    return cellField[item.getIndex()];
}

PlayField PlayField::operator+(PlayField::CellPos item){
    auto res = *this;
    res.cellField[item.getIndex()] = previosState;
    if(res.previosState == csState::csCross)
        res.previosState = csState::csNought;
    else
        res.previosState = csState::csCross;
    return res;
}

std::vector<PlayField::CellPos> PlayField::getEmptyCells() const {
    std::vector<CellPos> result;
    for (int i = 0; i < SIZE_FIELD ; ++i)
        if(cellField[i] == csState::csEmpty)
            result.emplace_back(i / 3, i % 3);
    return result;
}

PlayField PlayField::makeMove(PlayField::CellPos item) const {
    auto kek1 = cellField[item.getIndex()] == csState::csEmpty;
    auto kek2 = checkFieldStatus() == fnState::fsNormal;
    assert(kek1 && kek2);
    auto result = *this;
    return result + item;
}

PlayField::fnState PlayField::checkFieldStatus() const {
    auto countCross = 0;
    auto countNought = 0;
    auto win = csState::csEmpty;

    for(auto elem : cellField)
        if(elem == csState::csCross)
            countCross++;
        else if(elem == csState::csNought)
            countNought++;

    if(std::abs(countCross-countNought) > 1)
        return fnState::fsInvalid;

    for(int i = 0; i < 3; ++i)
        if(cellField[3 * i] != csState::csEmpty && cellField[3 * i] == cellField[3 * i + 1] && cellField[3 * i + 1] == cellField[3 * i + 2])
            win = cellField[3 * i];
    for(int i = 0; i < 3; ++i)
        if(cellField[i] != csState::csEmpty && cellField[i]== cellField[i + 3] && cellField[i + 3] == cellField[i + 6])
            win = cellField[i];

    if(cellField[0] != csState::csEmpty && cellField[0] == cellField[4] && cellField[4] == cellField[8])
        win = cellField[0];
    else if(cellField[2] != csState::csEmpty && cellField[2] == cellField[4] && cellField[4] == cellField[6])
        win = cellField[2];

    if(win == csState::csEmpty && countCross + countNought == SIZE_FIELD)
        return fnState::fsDraw;
    else if(win == csState::csCross)
        return fnState::fsCrossesWin;
    else if(win == csState::csNought)
        return fnState::fsNoughtsWin;
    else
        return fnState::fsNormal;
}


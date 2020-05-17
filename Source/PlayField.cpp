//
// Created by Sam Petrov on 22.04.2020.
//
#include <vector>
#include <cassert>
#include <iostream>
#include "PlayField.h"

PlayField::PlayField() {
    for(int i = 0; i < FIELD_HEIGHT; ++i)
        for(int j = 0; j < FIELD_HEIGHT; ++j)
            cellField[CellPos(i, j)] = csEmpty;
}

PlayField::CellPos::CellPos(int a, int b) {
    assert((0 <= a && a < FIELD_HEIGHT) && (0 <= b && b < FIELD_HEIGHT));
    x = a;
    y = b;
}

PlayField::CellPos::operator int() const {
    return FIELD_HEIGHT * x + y;
}

PlayField::csState PlayField::operator[](const PlayField::CellPos item) const {
    return cellField[item];
}

void PlayField::print() const {
    for(int i = 0; i < FIELD_HEIGHT; ++i) {
        for(int j = 0; j < FIELD_HEIGHT; ++j) {
            char symbol;
            if(cellField[CellPos(i, j)] == csCross)
                symbol = 'X';
            else if(cellField[CellPos(i, j)] == csNought)
                symbol = '0';
            else
                symbol = ' ';
            std::cout<<"|"<<symbol;
        }
        std::cout<<"|"<<std::endl;
    }
}

int PlayField::diffCrossAndNought() const {
    auto countCross = 0;
    auto countNought = 0;

    for(auto elem : cellField)
        if(elem == csCross)
            countCross++;
        else if(elem == csNought)
            countNought++;
    auto diff = countCross - countNought;
    assert(diff == 1 || diff == 0);
    return diff;
}

PlayField PlayField::operator+(PlayField::CellPos item) const {
    assert(cellField[item] == csEmpty && checkFieldStatus() == fsNormal);
    auto result = *this;
    auto diff = diffCrossAndNought();
    result.cellField[item] = (diff == 1) ? csNought : csCross;
    return result;
}

std::vector<PlayField::CellPos> PlayField::getEmptyCells() const {
    std::vector<CellPos> result;
    for(int i = 0; i < FIELD_HEIGHT; ++i)
        for(int j = 0; j < FIELD_HEIGHT; ++j)
            if(cellField[CellPos(i, j)] == csEmpty)
                result.emplace_back(i, j);
    return result;
}

PlayField PlayField::makeMove(PlayField::CellPos item) const {
    assert(cellField[item] == csEmpty && checkFieldStatus() == fsNormal);
    return  *this + item;
}

PlayField::fnState PlayField::checkFieldStatus() const {
    auto winCross = false;
    auto winNought = false;

    auto diff = diffCrossAndNought();
    if(0 > diff || diff > 1)
        return fsInvalid;

    for(int i = 0; i < FIELD_HEIGHT; ++i) {
        // Проверяем горизонталь
        bool horizontal = true;
        for(int j = 1; j < FIELD_HEIGHT; ++j)
            if (cellField[CellPos(i, j - 1)] != cellField[CellPos(i, j)]) {
                horizontal = false;
                break;
            }
        // Проверяем вертикаль
        bool vertical = true;
        for(int j = 1; j < FIELD_HEIGHT; ++j)
           if (cellField[CellPos(j - 1, i)] != cellField[CellPos(j, i)]) {
               vertical = false;
               break;
           }
        if((vertical && cellField[CellPos(0, i)] == csNought) || (horizontal && cellField[CellPos(i, 0)] == csNought))
            winNought = true;
        if((vertical && cellField[CellPos(0, i)] == csCross) || (horizontal && cellField[CellPos(i, 0)] == csCross))
            winCross = true;
    }
    // Главная диагональ
    int i = 1;
    int j = 1;
    bool mainDiagonal = true;
    while(i < FIELD_HEIGHT) {
        if (cellField[CellPos(i - 1, j - 1)] != cellField[CellPos(i, j)]){
            mainDiagonal = false;
            break;
        }
        i++;
        j++;
    }

    // Побочная диагональ
    i = 1;
    j = 1;
    bool sideDiagonal = true;
    while(i < FIELD_HEIGHT) {
        if (cellField[CellPos(i - 1, j + 1)] != cellField[CellPos(i, j)]){
            sideDiagonal = false;
            break;
        }
        i++;
        j--;
    }
    //  Проверка победившего по диагонали
    if((mainDiagonal && cellField[CellPos(0, 0)] == csNought) || (sideDiagonal && cellField[CellPos(0, FIELD_HEIGHT - 1)] == csNought))
        winNought = true;
    if((mainDiagonal && cellField[CellPos(0, 0)] == csCross) || (sideDiagonal && cellField[CellPos(0, FIELD_HEIGHT - 1)] == csCross))
        winCross = true;

    assert(!(winCross && winNought));

    if(winCross)
        return fsCrossesWin;
    else if(winNought)
        return fsNoughtsWin;
    else if(getEmptyCells().empty())
        return fsDraw;
    else
        return fsNormal;
}


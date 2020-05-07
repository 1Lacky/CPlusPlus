//
// Created by Sam Petrov on 22.04.2020.
//
#include <vector>
#include <cassert>
#include <iostream>
#include "PlayField.h"

PlayField::PlayField() {
    for(int i = 0; i < HEIGHT_FIELD; ++i)
        for(int j = 0; j < HEIGHT_FIELD; ++j)
            cellField[CellPos(i, j)] = csEmpty;
}

PlayField::CellPos::CellPos(int a, int b) {
    assert((0 <= a && a < HEIGHT_FIELD) && (0 <= b && b < HEIGHT_FIELD));
    x = a;
    y = b;
}

PlayField::CellPos::operator int() const {
    return HEIGHT_FIELD * x + y;
}

PlayField::csState PlayField::operator[](PlayField::CellPos item) const {
    return cellField[item];
}

void PlayField::print() const {
    for(int i = 0; i < HEIGHT_FIELD; ++i) {
        for(int j = 0; j < HEIGHT_FIELD; ++j) {
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

PlayField PlayField::operator+(PlayField::CellPos item)  const {
    auto countCross = 0;
    auto countNought = 0;

    for(auto elem : cellField)
        if(elem == csCross)
            countCross++;
        else if(elem == csNought)
            countNought++;

    auto result = *this;
    result.cellField[item] = (countCross - countNought == 1) ? csNought : csCross;
    return result;
}

std::vector<PlayField::CellPos> PlayField::getEmptyCells() const {
    std::vector<CellPos> result;
    for (int i = 0; i < SIZE_FIELD ; ++i)
        if(cellField[i] == csEmpty)
            result.emplace_back(i / HEIGHT_FIELD, i % HEIGHT_FIELD);
    return result;
}

PlayField PlayField::makeMove(PlayField::CellPos item) const {
    assert(cellField[item] == csEmpty && checkFieldStatus() == fsNormal);
    return  *this + item;
}

PlayField::fnState PlayField::checkFieldStatus() const {
    auto countCross = 0;
    auto countNought = 0;
    auto winCross = false;
    auto winNought = false;

    for(auto elem : cellField)
        if(elem == csCross)
            countCross++;
        else if(elem == csNought)
            countNought++;

    auto diff = countCross-countNought;
    if(0 > diff || diff > 1)
        return fsInvalid;

    // Проверяем горизонталь
    for(int i = 0; i < HEIGHT_FIELD; ++i) {
        bool horizontal = true;
        for(int j = 1; j < HEIGHT_FIELD; ++j) {
            auto flag = cellField[CellPos(i, j - 1)] == cellField[CellPos(i, j)];
            horizontal = (horizontal) ? flag : false;
        }
        if(horizontal && cellField[CellPos(i, 0)] == csNought)
            winNought = true;
        if(horizontal && cellField[CellPos(i, 0)] == csCross)
            winCross = true;
    }
    // Проверяем вертикаль
    for(int i = 0; i < HEIGHT_FIELD; ++i) {
        bool vertical = true;
        for(int j = 1; j < HEIGHT_FIELD; ++j) {
            auto flag = cellField[CellPos(j - 1, i)] == cellField[CellPos(j, i)] ;
            vertical = (vertical) ? flag : false;
        }
        if(vertical && cellField[CellPos(0, i)] == csNought)
            winNought = true;
        if(vertical && cellField[CellPos(0, i)] == csCross)
            winCross = true;
    }
    // Главная диагональ
    int i = 1;
    int j = 1;
    bool mainDiagonal = true;
    while(i < HEIGHT_FIELD){
        auto flag = cellField[CellPos(i - 1, j - 1)] == cellField[CellPos(i, j)];
        mainDiagonal = (mainDiagonal) ? flag : false;
        i++;
        j++;
    }
    // Побочная диагональ
    i = 1;
    j = 1;
    bool sideDiagonal = true;
    while(i < HEIGHT_FIELD){
        auto flag = cellField[CellPos(i - 1, j + 1)] == cellField[CellPos(i, j)];
        sideDiagonal = (sideDiagonal) ? flag : false;
        i++;
        j--;
    }
    //  Проверка победившего по диагонали
    int midPos = HEIGHT_FIELD / 2;
    if((mainDiagonal || sideDiagonal) && cellField[CellPos(midPos, midPos)] == csNought)
        winNought = true;
    if((mainDiagonal || sideDiagonal) && cellField[CellPos(midPos, midPos)] == csCross)
        winCross = true;

    assert(!(winCross && winNought));

    if(winCross)
        return fsCrossesWin;
    else if(winNought)
        return fsNoughtsWin;
    else if(countCross + countNought == SIZE_FIELD)
        return fsDraw;
    else
        return fsNormal;
}


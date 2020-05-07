#include <iostream>
#include "PlayField.h"
#include "TreeNode.h"

int countCrossesWinTotal = 0;
int countNoughtsWinTotal = 0;
int countDrawTotal = 0;

int countCrossesWin = 0;
int countNoughtsWin = 0;
int countDraw = 0;

void BuildSubTree(TreeNode node){
    auto f = node.value();
    switch (node.value().checkFieldStatus()){
        case f.fsInvalid:
            return;
        case f.fsCrossesWin:
            countCrossesWin++;
            return;
        case f.fsNoughtsWin:
            countNoughtsWin++;
            return;
        case f.fsDraw:
            countDraw++;
            return;
    }
    for(auto item : node.value().getEmptyCells()) {
        node.addChild(node.value().makeMove(item));
        BuildSubTree(node[node.childCount()-1]);
        if(node.getParent() == nullptr) {
            node[node.childCount()-1].value().print();
            std::cout << "X " << countCrossesWin << ", 0 " << countNoughtsWin << ", D " << countDraw << std::endl;
            countCrossesWinTotal += countCrossesWin;
            countNoughtsWinTotal += countNoughtsWin;
            countDrawTotal +=  countDraw;
            countCrossesWin = 0;
            countNoughtsWin = 0;
            countDraw = 0;
        }
    }
}

int main() {
    PlayField pf0;
    TreeNode node0(pf0);
    BuildSubTree(node0);
    std::cout <<"TOTAL "<< "X " << countCrossesWinTotal << ", 0 " << countNoughtsWinTotal << ", D " << countDrawTotal << std::endl;
    std::cout <<"OVERALL "<< countCrossesWinTotal + countNoughtsWinTotal + countDrawTotal << std::endl;
    return 0;
}

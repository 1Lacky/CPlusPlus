#include <iostream>
#include "Headers/PlayField.h"
#include "Headers/TreeNode.h"

int countCrossesWin = 0;
int countNoughtsWin = 0;
int countDraw = 0;

void BuildSubTree(TreeNode node){
    switch (int(node.value().checkFieldStatus())){
        case 0:
            return;
        case 2:
            countCrossesWin++;
            return;
        case 3:
            countNoughtsWin++;
            return;
        case 4:
            countDraw++;
            return;
    }
     for(auto item : node.value().getEmptyCells()) {
         node.addChild(node.value().makeMove(item));
         BuildSubTree(node[node.childCount()-1]);
     }
}

int main() {
    PlayField pf0;
    TreeNode node0(pf0);
    BuildSubTree(node0);
    std::cout << "X " << countCrossesWin << ", O " << countNoughtsWin << ", D " << countDraw << std::endl;
    return 0;
}

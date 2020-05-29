#include "XOPlayer.h"
#include <iostream>
#include <cassert>

void BuildSubTree(TreeNode &node) {
    if (node.value().checkFieldStatus() == PlayField::fsNormal)
        for (auto item : node.value().getEmptyCells()) {
            node.addChild(node.value().makeMove(item));
            BuildSubTree(node[node.childCount() - 1]);
        }
}

void WalkTree(TreeNode &node) {
    switch (node.value().checkFieldStatus()) {
        case PlayField::fsCrossesWin:
            node.addCrossesWin();
            break;
        case PlayField::fsNoughtsWin:
            node.addNoughtsWin();
            break;
        case PlayField::fsDraw:
            node.addDraw();
            break;
        case PlayField::fsNormal:
            for (int i = 0; i < node.childCount(); ++i) {
                WalkTree(node[i]);
                node += node[i];
            }
            break;
        case PlayField::fsInvalid:
            assert(false && "Play field Invalid");
            break;
    }
}


int main() {
    PlayField pf;
    TreeNode node0(pf);
    BuildSubTree(node0);
    WalkTree(node0);

    std::cout << "Select player (0 - Xs, 1 - Os)" << std::endl;
    int sel_player;
    std::cin >> sel_player;
    assert(sel_player == 0 || sel_player == 1);
    XOPlayer player(node0, (sel_player == 0 ? PlayField::csCross : PlayField::csNought));

    do {
        if (sel_player == 0) {
            int x, y;
            std::cout << "Your turn, write X Y" << std::endl;
            std::cin >> x >> y;
            player.makeMove(PlayField::CellPos(x, y));
            sel_player = 1;
        } else {
            std::cout << "The Bot turn" << std::endl;
            player.makeMove();
            sel_player = 0;
        }
        player.currentState().print();
    } while (player.fieldStatus() == PlayField::fsNormal);
    return 0;
}

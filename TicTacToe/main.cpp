#include <iostream>
#include <queue>
#include <string>
#include <cassert>
#include "TreeNode.h"

struct Counter {
    int crossesWin = 0;
    int noughtsWin = 0;
    int draw = 0;

    void operator+=(const Counter &elem) const {
        crossesWin += elem.crossesWin;
        noughtsWin += elem.noughtsWin;
        draw += elem.draw;
    }

     friend std::ostream& operator<<(std::ostream &out, Counter &c) {
         out << "X " << c.crossesWin << ", 0 " << c.noughtsWin << ", D " << c.draw << std::endl;
         return out;
    }

    int overall() const {
        return crossesWin + noughtsWin + draw;
    }
};

void BuildSubTree(TreeNode& node) {
    if(node.value().checkFieldStatus() == PlayField::fsNormal)
        for(auto item : node.value().getEmptyCells()) {
            node.addChild(node.value().makeMove(item));
            BuildSubTree(node[node.childCount()-1]);
        }
}

void WalkTree(const TreeNode& node) {
    Counter totalCount;
    for(int i = 0; i < node.childCount(); ++i) {
        Counter localCount;
        std::queue<TreeNode*> queue;
        queue.push(&node[i]);
        while(!queue.empty()) {
            auto& active = *queue.front();
            switch (active.value().checkFieldStatus()) {
                case PlayField::fsCrossesWin:
                    localCount.crossesWin++;
                    break;
                case PlayField::fsNoughtsWin:
                    localCount.noughtsWin++;
                    break;
                case PlayField::fsDraw:
                    localCount.draw++;
                    break;
                case PlayField::fsDraw:
                    for (int j = 0; j < active.childCount(); ++j)
                        queue.push(&active[j]);
                case PlayField::fsInvalid:
                    assert("Play field Invalid" && false);
                    break;
            }
            queue.pop();
        }
        node[i].value().print();
        std::cout << localCount;
        totalCount = totalCount + localCount;
    }
    std::cout <<"TOTAL " << totalCount;
    std::cout << "OVERALL " << totalCount.overall() << std::endl;
}

int main() {
    PlayField pf;
    TreeNode node0(pf);
    BuildSubTree(node0);
    WalkTree(node0);
    return 0;
}

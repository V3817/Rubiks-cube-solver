//
// Created by pspkm on 30-12-2024.
//

#include "CornerDBMaker.h"
using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName) {
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}
bool CornerDBMaker::bfsAndStore() {
    RubiksCubeBitboard cube;
    queue<RubiksCubeBitboard> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int cur_depth = 0;
    while (!q.empty()) {
        cur_depth++;
        if (cur_depth == 11) break;
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto node = q.front();
            q.pop();
            for (int j = 0;j < 18;j++) {
                auto cur_move = static_cast<RubiksCube::MOVE>(j);
                node.move(cur_move);
                if ((int)cornerDB.getNumMoves(node) > cur_depth) {
                    q.push(node);
                    cornerDB.setNumMoves(node, cur_depth);
                }
                node.invert(cur_move);
            }
        }
    }
    cornerDB.toFile(fileName);

    return true;
}

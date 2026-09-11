//
// Created by pspkm on 27-12-2024.
//
#include <bits/stdc++.h>
#include "../Models/RubiksCube.h"
template<typename T, typename H>
#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H

class IDDFSSolver {
    vector<RubiksCube::MOVE> moves;
    int max_depth;

    bool dfs(int depth) {
        if (depth == -1) return false;
        if (rubiksCube.isSolved())return true;
        for (int i = 0;i < 18;i++) {
            auto next_move = static_cast<RubiksCube::MOVE>(i);
            rubiksCube.move(next_move);
            moves.push_back(next_move);
            if (dfs(depth - 1)) return true;
            rubiksCube.invert(next_move);
            moves.pop_back();
        }
        return false;
    }
    public:
    T rubiksCube;
    IDDFSSolver(T _rubiksCube, int md) {
        rubiksCube = _rubiksCube, max_depth = md;
    }
    vector<RubiksCube::MOVE> solve() {
        for (int i = 0;i <= max_depth;i++) {
            if (dfs(i)) return moves;
            moves.clear();
        }
        return {};
    }
};
#endif //IDDFSSOLVER_H

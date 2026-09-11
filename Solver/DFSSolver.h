//
// Created by pspkm on 27-12-2024.
//
#include<bits/stdc++.h>
#include"../Models/RubiksCube.h"

#ifndef DFSSOLVER_H
#define DFSSOLVER_H

template<typename T, typename H>

class DFSSolver {
    int max_depth;
    vector<RubiksCube::MOVE> moves;


    bool dfs(int dep) {
        if (rubiksCube.isSolved())return true;
        if (dep > max_depth) return false;
        for (int i{0};i < 18;i++) {
            moves.push_back(static_cast<RubiksCube::MOVE>(i));
            rubiksCube.move(static_cast<RubiksCube::MOVE>(i));
            if (dfs(dep + 1))return true;
            moves.pop_back();
            rubiksCube.invert(static_cast<RubiksCube::MOVE>(i));
        }
        return false;
    }
    public:
    T rubiksCube;
    DFSSolver(T _rubiksCube, int max_dep):  max_depth(max_dep), rubiksCube(_rubiksCube) {}
    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }

};
#endif //DFSSOLVER_H

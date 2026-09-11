//
// Created by pspkm on 27-12-2024.
//
#include <bits/stdc++.h>
#include "../Models/RubiksCube.h"
#include "../PatternDatabases/CornerPatternDatabase.h"

#ifndef IDASTARSOLVER_H
#define IDASTARSOLVER_H
template<typename T, typename H>
class IDAstarSolver {
    CornerPatternDatabase cornerDB;
    vector<RubiksCube::MOVE> moves;
    unordered_map<T, RubiksCube::MOVE, H> move_done;
    unordered_map<T, bool, H> visited;

    struct Node {
        T cube;
        int depth;
        int estimate;
    };

    struct compare {
        bool operator()(pair<Node, int> &p1, pair<Node, int> &p2) {
            auto n1 = p1.first;
            auto n2 = p2.first;
            if (n1.depth + n1.estimate == n2.depth + n2.estimate) {
                return n1.estimate > n2.estimate;
            }
            else {
                return n1.depth + n1.estimate > n2.depth + n2.estimate;
            }
        }
    };
    void reset() {
        moves.clear();
        move_done.clear();
        visited.clear();
    }

    pair<T, int> IDAStar(int bound) {
        priority_queue<pair<Node, int>, vector<pair<Node, int>>, compare> pq;
        Node start{rubiksCube, 0, cornerDB.getNumMoves(rubiksCube)};
        int next_bound = 100;
        pq.push({start, 0});
        while (!pq.empty()) {
            auto p = pq.top();
            Node node = p.first;
            pq.pop();
            if (visited[node.cube]) continue;

            visited[node.cube] = true;
            move_done[node.cube] = static_cast<RubiksCube::MOVE>(p.second);

            if (node.cube.isSolved()) return {node.cube, bound};
            ++node.depth;
            for (int i{0};i < 18;i++) {
                auto cur_move = static_cast<RubiksCube::MOVE>(i);
                node.cube.move(cur_move);
                if (!visited[node.cube]) {
                    node.estimate = (int)cornerDB.getNumMoves(node.cube);
                    if (node.depth + node.estimate > bound) {
                        next_bound = min(next_bound, node.depth + node.estimate);
                    }
                    else {
                        pq.push({node, i});
                    }
                }
                node.cube.invert(cur_move);
            }

        }
        return {rubiksCube,next_bound};
    }
public:
    T rubiksCube;
    IDAstarSolver(T _rubiksCube, string filename):rubiksCube(_rubiksCube){
        cornerDB.fromFile(filename) ;
    }
    vector<RubiksCube::MOVE> solve() {
        int bound = 1;
        auto p = IDAStar(bound);
        while (p.second != bound) {
            reset();
            bound = p.second;
            p = IDAStar(bound);
        }
        T solved_cube = p.first;
        // assert(solved_cube.isSolved());
        T cur_cube = solved_cube;
        while (!(cur_cube == rubiksCube)) {
            auto cur_move = move_done[cur_cube];
            cur_cube.invert(cur_move);
            moves.push_back(cur_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }

};
#endif //IDASTARSOLVER_H

//
// Created by pspkm on 27-12-2024.
//
#include <bits/stdc++.h>
#include "../Models/RubiksCube.h"



#ifndef BFSSOLVER_H
#define BFSSOLVER_H
//    bfs() -> performs breadth-first-search and returns a solved Rubik's Cube
//    move_done[] -> Back-Pointer map as to how we reached that state
template<typename T, typename H>
class BFSSolver {
   vector<RubiksCube::MOVE> moves;
   unordered_map<T, bool, H> visited;
   unordered_map<T, RubiksCube::MOVE, H> move_done;


   T bfs() {
      queue<T> q;
      q.push(rubiksCube);
      visited[rubiksCube] = true;

      while (!q.empty()) {
         T node = q.front();
         q.pop();
         if (node.isSolved()) {
            return node;
         }
         for (int i{0};i < 18;i++) {
            auto cur_move = static_cast<RubiksCube::MOVE>(i);
            node.move(cur_move);
            if (visited[node] == false) {
               q.push(node);
               visited[node] = true;
               move_done[node] = cur_move;
            }
            node.invert(cur_move);
         }
      }
      return rubiksCube;
   }
public:
   T rubiksCube;
   BFSSolver(T _rubiksCube) {
      rubiksCube = _rubiksCube;
   }

   vector<RubiksCube::MOVE> solve() {
      T solvedCube = bfs();
      assert(solvedCube.isSolved());
      T cur_cube = solvedCube;
      while (!(cur_cube == rubiksCube)) {
         RubiksCube::MOVE cur_move = move_done[cur_cube];
         cur_cube.invert(cur_move);
         moves.push_back(cur_move);
      }
      rubiksCube = solvedCube;
      reverse(moves.begin(), moves.end());
      return moves;
   }
};



#endif //BFSSOLVER_H

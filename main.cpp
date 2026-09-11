#include <bits/stdc++.h>

// #include "Models/RubiksCube3dArray.cpp"
// #include "Models/RubiksCube1dArray.cpp"
// #include "Models/RubiksCubeBitboard.cpp"
#include "Solver/BFSSolver.h"
#include "Solver/DFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "Solver/IDDFSSolver.h"
// #include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {

//     RubiksCube3dArray object3DArray;
//     RubiksCube1dArray object1dArray;
//     RubiksCubeBitboard objectBitboard;
//
//     object3DArray.print();
//
//     if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
//
//     if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
//
//     if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
//
//     objectBitboard.u();
//     object3DArray.u();
//     object1dArray.u();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.l();
//     object3DArray.l();
//     object1dArray.l();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.f();
//     object3DArray.f();
//     object1dArray.f();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.r();
//     object3DArray.r();
//     object1dArray.r();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.b();
//     object3DArray.b();
//     object1dArray.b();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.d();
//     object3DArray.d();
//     object1dArray.d();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
//
//     if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
//
//     if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
//
//     objectBitboard.dPrime();
//     object3DArray.dPrime();
//     object1dArray.dPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.bPrime();
//     object3DArray.bPrime();
//     object1dArray.bPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.rPrime();
//     object3DArray.rPrime();
//     object1dArray.rPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.fPrime();
//     object3DArray.fPrime();
//     object1dArray.fPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.lPrime();
//     object3DArray.lPrime();
//     object1dArray.lPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     objectBitboard.uPrime();
//     object3DArray.uPrime();
//     object1dArray.uPrime();
//     objectBitboard.print();
//     object3DArray.print();
//     object1dArray.print();
//
//     if (object3DArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
// //
//     if (object1dArray.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";
//
//     if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
//     else cout << "NOT SOLVED\n\n";

    //Create 2 cube
    // RubiksCubeBitboard cube1, cube2;

    // RubiksCube3dArray cube1, cube2;

    // RubiksCube1dArray cube1, cube2;

    //Testing Assignment and Equality operator-----------------------------------//

    // if (cube1 == cube2) {
    //     cout<<"Cubes are equal"<<endl;
    // }
    // else {
    //     cout<<"Cubes are different"<<endl;
    // }
    // cube1.randomShuffleCube(1);
    // if (cube1 == cube2) {
    //     cout<<"Cubes are equal"<<endl;
    // }
    // else {
    //     cout<<"Cubes are different"<<endl;
    // }
    // cube1 = cube2;
    // if (cube1 == cube2) {
    //     cout<<"Cubes are equal"<<endl;
    // }
    // else {
    //     cout<<"Cubes are different"<<endl;
    // }
    //Unordered map of the cube------------------------------------------------//
    // unordered_map<RubiksCube3dArray, bool, Hash3d> mp1;

    // unordered_map<RubiksCube1dArray, bool, Hash1d> mp1;

    // unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
    //
    // mp1[cube1] = true;
    // cube2.randomShuffleCube(8);
    // if (mp1[cube1]) cout << "Cube1 is present\n";
    // else cout << "Cube1 is not present\n";
    //
    // if (mp1[cube2]) cout << "Cube2 is present\n";
    // else cout << "Cube2 is not present\n";


    //DFS Solver---------------------------------------------------------------//
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(8);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // DFSSolver<RubiksCubeBitboard, HashBitboard> dfsSolver(cube, 10);
    // vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // dfsSolver.rubiksCube.print();


    //BFS Solver---------------------------------------------------------------//
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
    // vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
    //
    // for(auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // bfsSolver.rubiksCube.print();

    //IDDFS Solver------------------------------------------------------------//
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 9);
    // vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
    //
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // iddfsSolver.rubiksCube.print();

    //IDAStar Solver-----------------------------------------------------------//
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    //
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube);
    // vector<RubiksCube::MOVE> solve_moves = idAstarSolver.solve();
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // idAstarSolver.rubiksCube.print();

    // CornerPatternDatabase Testing ---------------------------------------------------------------------------------

    // CornerPatternDatabase cornerDB;
    // RubiksCubeBitboard cube;
    // cube.print();
    //
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    // cornerDB.setNumMoves(cube, 5);
    //
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    // cube.randomShuffleCube(1);
    // cube.print();
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    // cornerDB.setNumMoves(cube, 6);
    //
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";


    // CornerDBMaker Testing --------------------------------------------------------------------------
    string fileName = "C:\\Users\\pspkm\\CLionProjects\\RubicksCubeSolver\\DataBase\\cornerDepth5V1.txt";

    //    Code to create Corner Database
    // CornerDBMaker dbMaker(fileName, 0x99);
    // cout<<dbMaker.bfsAndStore();

    // RubiksCubeBitboard cube;
    // cout<<cube.isSolved();
    // CornerPatternDatabase cd;
    // cd.fromFile(fileName);
    // cout<<(int)cd.getNumMoves(cube);
    // auto data = cd.inflate();
    // for (const auto& val : data) {
    //     cout << static_cast<int>(val) << " ";
    // }




    RubiksCubeBitboard cube;
    auto shuffleMoves = cube.randomShuffleCube(9);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n";

    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    idaStarSolver.rubiksCube.print();
    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n";

    return 0;

}


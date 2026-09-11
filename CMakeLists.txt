cmake_minimum_required(VERSION 3.30)
project(RubicksCubeSolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(RubicksCubeSolver main.cpp
        Models/RubiksCube.cpp
        Models/RubiksCube.h
        Models/RubiksCube1dArray.cpp
        Models/RubiksCube3dArray.cpp
        Models/RubiksCubeBitboard.cpp
        Solver/BFSSolver.h
        Solver/DFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h
        PatternDatabases/NibbleArray.cpp
        PatternDatabases/NibbleArray.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/math.cpp
        PatternDatabases/math.h
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/CornerDBMaker.h)

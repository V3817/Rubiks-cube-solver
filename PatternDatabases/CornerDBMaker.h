//
// Created by pspkm on 30-12-2024.
//

#ifndef CORNERDBMAKER_H
#define CORNERDBMAKER_H



#include "CornerPatternDatabase.h"
#include "../Models/RubiksCubeBitboard.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string _fileName);
    CornerDBMaker(string _fileName, uint8_t init_val);

    bool bfsAndStore();
};




#endif //CORNERDBMAKER_H

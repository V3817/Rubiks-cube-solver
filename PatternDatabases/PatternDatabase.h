//
// Created by pspkm on 28-12-2024.
//

#ifndef PATTERNDATABASE_H
#define PATTERNDATABASE_H
#include <bits/stdc++.h>
#include "../Models/RubiksCube.h"
#include "NibbleArray.h"

class PatternDatabase {
    NibbleArray database;
    size_t size;
    size_t numItems;
    PatternDatabase();
    public:

    PatternDatabase(size_t size);

    PatternDatabase(const size_t size, uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const RubiksCube &cube) const = 0;

    virtual bool setNumMoves(const RubiksCube &cube, const uint8_t numMoves);

    virtual bool setNumMoves(const uint32_t ind, const uint8_t numMoves);

    virtual uint8_t getNumMoves(const RubiksCube &cube) const;

    virtual uint8_t getNumMoves(const uint32_t ind) const;

    virtual size_t getSize() const;

    virtual size_t getNumItems() const;

    virtual bool isFull() const;

    virtual void toFile(const string &filePath) const;

    virtual bool fromFile(const string &filePath);

    virtual vector<uint8_t> inflate() const;

    virtual void reset();

};
#endif //PATTERNDATABASE_H

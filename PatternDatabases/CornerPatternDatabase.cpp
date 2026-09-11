//
// Created by pspkm on 30-12-2024.
//

#include "CornerPatternDatabase.h"

CornerPatternDatabase::CornerPatternDatabase():PatternDatabase(100179840) {

}
CornerPatternDatabase::CornerPatternDatabase(uint8_t init_val):PatternDatabase(100179840, init_val) {

}

uint32_t CornerPatternDatabase::getDatabaseIndex(const RubiksCube &cube) const {
    array<uint8_t, 8> cornerPerm{
        cube.getCornerIndex(0),
        cube.getCornerIndex(1),
        cube.getCornerIndex(2),
        cube.getCornerIndex(3),
        cube.getCornerIndex(4),
        cube.getCornerIndex(5),
        cube.getCornerIndex(6),
        cube.getCornerIndex(7)
    };
    uint32_t rank = this->permIndexer.rank(cornerPerm);

    array<uint8_t, 7> orientation{
    cube.getCornerOrientation(0),
    cube.getCornerOrientation(1),
    cube.getCornerOrientation(2),
    cube.getCornerOrientation(3),
    cube.getCornerOrientation(4),
    cube.getCornerOrientation(5),
    cube.getCornerOrientation(6),
    };

    uint32_t orientation_num = orientation[0] +
        orientation[1] * 3 +
            orientation[2]*9 +
                orientation[3]*27 +
                    orientation[4]*81 +
                        orientation[5]*243 +
                            orientation[6]*729;

    return rank * 2187 + orientation_num;
}


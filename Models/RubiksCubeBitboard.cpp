//
// Created by P S Pritish on 26-12-2024.
//

#include "RubiksCube.h"

class RubiksCubeBitboard :public RubiksCube {

    uint64_t solved_cube[6]{};
    uint64_t one_8 = (1 << 8) - 1, one_24 = (1 << 24) - 1;
    int arr[3][3] = {{0, 1, 2},
                    {7, 8, 3},
                    {6, 5, 4}};

    void rotateFace(int face) {
        auto side = bitboard[face];
        side = side >> 48;
        bitboard[face] = (bitboard[face] << 16) | (side);
    }
    //moving from side 2 to size 1;
    void rotateSide(int s1, int s11, int s12, int s13, int s2, int s21, int s22, int s23) {
        uint64_t clr1 = (bitboard[s2] & (one_8 << (8 * s21))) >> (8 * s21);
        uint64_t clr2 = (bitboard[s2] & (one_8 << (8 * s22))) >> (8 * s22);
        uint64_t clr3 = (bitboard[s2] & (one_8 << (8 * s23))) >> (8 * s23);

        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s11))) | (clr1 << (8 * s11));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s12))) | (clr2 << (8 * s12));
        bitboard[s1] = (bitboard[s1] & ~(one_8 << (8 * s13))) | (clr3 << (8 * s13));
    }

    public:
    unsigned long long bitboard[6]{};

    RubiksCubeBitboard() {
        for (int i = 0;i < 6;i++) {
            bitboard[i] = 0;
            uint64_t clr = 1 << i;
            for (int j = 0;j < 8;j++) {
                bitboard[i] |= clr << (8 * j);
            }
            solved_cube[i] = bitboard[i];
        }
    }
    COLOR getColor(FACE face, unsigned row, unsigned col)const override{
        int idx = arr[row][col];
        if (idx == 8)return  static_cast<COLOR>((int)face);

        uint64_t side = bitboard[(int)face];
        uint64_t color = (side & (one_8 << (8 * idx))) >> (8 * idx);
        int pos = -1;
        while (color) {
            pos++;
            color = color >> 1;
        }
        return static_cast<COLOR>(pos);

    }
    bool isSolved()const {
        for (int i = 0;i < 6;i++) {
            if (bitboard[i] != solved_cube[i]) {return false;}
        }
        return true;
    }
    RubiksCube& u() override
    {
        this->rotateFace(0);
        uint64_t temp = bitboard[2] & (one_24);
        bitboard[2] = (bitboard[2] & ~(one_24)) | (bitboard[3] & (one_24));
        bitboard[3] = (bitboard[3] & ~(one_24)) | (bitboard[4] & (one_24));
        bitboard[4] = (bitboard[4] & ~(one_24)) | (bitboard[1] & (one_24));
        bitboard[1] = (bitboard[1] & ~(one_24)) | temp;

        return *this;
    }
    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    };

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    };

    RubiksCube &l() override {
        this-> rotateFace(1);

        uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 7))) >> (8 * 7);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(2, 0, 7, 6, 0, 0, 7, 6);
        this->rotateSide(0, 0, 7, 6, 4, 4, 3, 2);
        this->rotateSide(4, 4, 3, 2, 5, 0, 7, 6);

        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 0))) | (clr1 << (8 * 0));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bitboard[5] = (bitboard[5] & ~(one_8 << (8 * 6))) | (clr3 << (8 * 6));

        return *this;
    }
    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();

        return *this;
    };

    RubiksCube &l2() override {
        this->l();
        this->l();

        return *this;
    };
    RubiksCube &f() override {
        this->rotateFace(2);

        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(0, 4, 5, 6, 1, 2, 3, 4);
        this->rotateSide(1, 2, 3, 4, 5, 0, 1, 2);
        this->rotateSide(5, 0, 1, 2, 3, 6, 7, 0);

        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();
        return *this;
    };

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    };

    RubiksCube &r() override {
        this->rotateFace(3);
        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 2))) >> (8 * 2);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 3))) >> (8 * 3);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 4))) >> (8 * 4);

        this->rotateSide(0, 2, 3, 4, 2, 2, 3, 4);
        this->rotateSide(2, 2, 3, 4, 5, 2, 3, 4);
        this->rotateSide(5, 2, 3, 4, 4, 7, 6, 0);

        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 7))) | (clr1 << (8 * 7));
        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 6))) | (clr2 << (8 * 6));
        bitboard[4] = (bitboard[4] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();

        return *this;
    };

    RubiksCube &r2() override {
        this->r();
        this->r();

        return *this;
    };

    RubiksCube &b() override {
        this->rotateFace(4);

        uint64_t clr1 = (bitboard[0] & (one_8 << (8 * 0))) >> (8 * 0);
        uint64_t clr2 = (bitboard[0] & (one_8 << (8 * 1))) >> (8 * 1);
        uint64_t clr3 = (bitboard[0] & (one_8 << (8 * 2))) >> (8 * 2);

        this->rotateSide(0, 0, 1, 2, 3, 2, 3, 4);
        this->rotateSide(3, 2, 3, 4, 5, 4, 5, 6);
        this->rotateSide(5, 4, 5, 6, 1, 6, 7, 0);

        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 6))) | (clr1 << (8 * 6));
        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 7))) | (clr2 << (8 * 7));
        bitboard[1] = (bitboard[1] & ~(one_8 << (8 * 0))) | (clr3 << (8 * 0));

        return *this;
    };

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    };

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    };

    RubiksCube &d() override {
        this->rotateFace(5);

        uint64_t clr1 = (bitboard[2] & (one_8 << (8 * 4))) >> (8 * 4);
        uint64_t clr2 = (bitboard[2] & (one_8 << (8 * 5))) >> (8 * 5);
        uint64_t clr3 = (bitboard[2] & (one_8 << (8 * 6))) >> (8 * 6);

        this->rotateSide(2, 4, 5, 6, 1, 4, 5, 6);
        this->rotateSide(1, 4, 5, 6, 4, 4, 5, 6);
        this->rotateSide(4, 4, 5, 6, 3, 4, 5, 6);

        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 4))) | (clr1 << (8 * 4));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 5))) | (clr2 << (8 * 5));
        bitboard[3] = (bitboard[3] & ~(one_8 << (8 * 6))) | (clr3 << (8 * 6));

        return *this;
    };

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    };

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    bool operator==(const RubiksCubeBitboard &r1) const {
        for (int i = 0; i < 6; i++) {
            if (bitboard[i] != r1.bitboard[i]) return false;
        }
        return true;
    }

    RubiksCubeBitboard &operator=(const RubiksCubeBitboard &r1) {
        for (int i = 0; i < 6; i++) {
            bitboard[i] = r1.bitboard[i];
        }
        return *this;
    }

};
struct HashBitboard {
    size_t operator()(const RubiksCubeBitboard &r1) const {
        uint64_t final_hash = r1.bitboard[0];
        for (int i = 1; i < 6; i++) final_hash ^= r1.bitboard[i];
        return (size_t) final_hash;
    }
};
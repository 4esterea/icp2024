/**
 * @file Position.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 28.04.2024
 * @brief Declaration of GameObject's position.
 */

#ifndef __POSITION_H__
#define __POSITION_H__

#include "../interfaces/IPosition.h"

class Position: public IPosition {
    public:
        Position(int x, int y, int angle);
        void SetPosition(IPosition * position);
        void SetPosition(int x, int y, int angle);
        void SetPosition(int x, int y);
};

#endif

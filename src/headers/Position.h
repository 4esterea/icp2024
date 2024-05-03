/**
 * @file Position.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 28.04.2024
 * @brief Declaration of GameObject's position.
 */

#ifndef __POSITION_H__
#define __POSITION_H__

#include "../interfaces/IPosition.h"

class Position: public IPosition {
    public:
        Position(double x, double y, double angle);
        void SetPosition(IPosition * position);
        void SetPosition(double x, double y, double angle);
        void SetPosition(double x, double y);
        double GetX();
        void SetX(double x);
        double GetY();
        void SetY(double y);
        double GetAngle();
        void SetAngle(double angle);
};

#endif

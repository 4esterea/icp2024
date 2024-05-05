    /**
 * @file IPosition.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Position doubleerface
 */

#ifndef __IPOSITION_H__
#define __IPOSITION_H__

class IPosition {
    public:
        double x;
        double y;
        double angle;

        virtual void SetPosition(IPosition * position) = 0;
        virtual void SetPosition(double x, double y, double angle) = 0;
        virtual void SetPosition(double x, double y) = 0;
        virtual ~IPosition() {};
};

#endif

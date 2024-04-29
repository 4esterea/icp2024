/**
 * @file IPosition.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Position interface
 */

#ifndef __IPOSITION_H__
#define __IPOSITION_H__

class IPosition {
    public:
        double x;
        double y;
        double angle;

        virtual ~IPosition() {};
};

#endif

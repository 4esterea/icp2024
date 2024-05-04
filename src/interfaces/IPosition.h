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
        int x;
        int y;
        int angle;

        virtual void SetPosition(IPosition * position) = 0;
        virtual void SetPosition(int x, int y, int angle) = 0;
        virtual void SetPosition(int x, int y) = 0;
        virtual ~IPosition() {};
};

#endif

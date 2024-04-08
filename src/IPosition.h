/**
 * @file IPosition.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Position interface
 */

#ifndef __IPOSITION_H__
#define __IPOSITION_H__

using namespace std;

class IPosition {
    public:
        float x;
        float y; 
        float angle;

        virtual ~IPosition() = 0;        
};

#endif
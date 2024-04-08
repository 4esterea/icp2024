/**
 * @file IPosition.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of Position interface
 */

using namespace std;

class IPosition {
    public:
        float x;
        float y; 
        float angle;

        virtual ~IPosition() = 0;        
};
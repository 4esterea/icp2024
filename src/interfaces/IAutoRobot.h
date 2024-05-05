/**
 * @file IAutoRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Auto Robot interface
 */

#ifndef __IAUTOROBOT_H__
#define __IAUTOROBOT_H__

#include <utility>

#include "IRobot.h"
#include "IRectangleCollider.h"

using namespace std;

class IAutoRobot : public IRobot {
    public:
    /**
    * @brief Gets the vision of the auto robot.
    *
    * @return A pointer to the rectangle collider representing the robot's vision.
    */
    IRectangleCollider * GetVision();

    /**
     * @brief Sets the vision of the auto robot.
     *
     * @param vision A pointer to the rectangle collider to set as the robot's vision.
     */
    void SetVision(IRectangleCollider * vision);

    /**
     * @brief Virtual destructor for the IAutoRobot interface.
     */
    virtual ~IAutoRobot();

    protected:
        IRectangleCollider * _vision; // <Right sigth collider, Left sight collider>
};

#endif

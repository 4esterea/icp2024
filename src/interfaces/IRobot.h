/**
 * @file IRobot.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of Robot interface
 */

#ifndef __IROBOT_H__
#define __IROBOT_H__

#include "IGameObject.h"

class IRobot : public IGameObject {
public:
    /**
    * @brief Updates the state of the robot.
    */
    virtual void Update() = 0;

    /**
     * @brief Gets the speed of the robot.
     *
     * @return The speed of the robot.
     */
    virtual double GetSpeed() = 0;

    /**
     * @brief Sets the speed of the robot.
     *
     * @param speed The speed to set the robot to.
     */
    virtual void SetSpeed(double speed) = 0;

    /**
     * @brief Gets the rotation angle of the robot.
     *
     * @return The rotation angle of the robot.
     */
    virtual double GetRotationAngle() = 0;

    /**
     * @brief Sets the rotation angle of the robot.
     *
     * @param rotationAngle The rotation angle to set the robot to.
     */
    virtual void SetRotationAngle(double rotationAngle) = 0;

    /**
     * @brief Virtual destructor for the IRobot interface.
     */
    virtual ~IRobot() {};

    protected:
        double _speed; // Constant through run
        double _rotationAngle; // Constant through run
};

#endif

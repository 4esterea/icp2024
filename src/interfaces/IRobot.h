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
#include "IQtCircleCollider.h"
#include "IQtCollider.h"

/**
 * @brief Base class for robots in the simulation.
 *
 * This class defines common properties and behaviors for all robots.
 */
class IRobot : public IGameObject {
public:
    /**
     * @brief Get the robot's vision collider.
     * @return Vision collider.
     */
    IQtCollider * GetVision() { return this->_vision; }

    /**
     * @brief Set the robot's vision collider.
     * @param New vision collider.
     */
    void SetVision(IQtCollider * vision) { this->_vision = vision; }

    /**
     * @brief Get the robot's collision behavior.
     * @return Direction of rotation on collision.
     */
    RotationDirection GetCollisionBehavior() { return this->_collisionBehavior; }

    /**
     * @brief Set the robot's collision behavior.
     * @param New direction of rotation on collision.
     */
    void SetCollisionBehavior(RotationDirection collisionBehavior) { this->_collisionBehavior = collisionBehavior; }

    /**
     * @brief Get the robot's body qt circle collider.
     * @return Pointer to the body collider.
     */
    IQtCircleCollider * GetCollider() { return dynamic_cast<IQtCircleCollider *>(this->_collider); };

    /**
     * @brief Get the robot's radius.
     * @return The radius of the robot.
     */
    double GetRadius() { return this->_radius; }

    /**
     * @brief Set the robot's radius.
     * @param radius The new radius for the robot.
     */
    void SetRadius(double radius) { this->_radius = radius; }

    /**
     * @brief Update the robot's state (pure virtual).
     */
    virtual void Update() = 0;

    /**
     * @brief Get the robot's speed (pure virtual).
     * @return The robot's speed.
     */
    virtual double GetSpeed() = 0;

    /**
     * @brief Set the robot's speed (pure virtual).
     * @param speed The new speed for the robot.
     */
    virtual void SetSpeed(double speed) = 0;

    /**
     * @brief Get the robot's rotation angle (pure virtual).
     * @return The rotation angle in radians.
     */
    virtual double GetRotationAngle() = 0;

    /**
     * @brief Set the robot's rotation angle (pure virtual).
     * @param rotationAngle The new rotation angle in radians.
     */
    virtual void SetRotationAngle(double rotationAngle) = 0;

    /**
     * @brief Virtual destructor for IRobot.
     */
    virtual ~IRobot() {};

protected:
    double _radius;
    double _speed; // Constant throughout run
    double _rotationAngle; // Constant throughout run
    IQtCollider* _vision; // <Right sight collider, Left sight collider>
    RotationDirection _collisionBehavior;
};

#endif

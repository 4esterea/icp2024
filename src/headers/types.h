/**
 * @file types.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of types used in program.
 */

#ifndef __TYPES_H__
#define __TYPES_H__

#define MAX_MAP_GAMEOBJECTS 100

/**
 * @brief Type of object 
 */
enum ObjectType {
    eot_null = 0,
    eot_obstacle = 1
};

/**
 * @brief Direction of speed 
 */
enum SpeedDirection {
    esd_none = 0,
    esd_forward = 1
};

/**
 * @brief Direction of rotation 
 */
enum RotationDirection {
    erd_right = -1,
    erd_none = 0,
    erd_left = 1
};

#endif

/**
 * @file types.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author Zhdanovich Iaroslav (xzhdan00)
 * @date 08.04.2024
 * @brief Definition of types used in program.
 */

#ifndef __TYPES_H__
#define __TYPES_H__

#define PI 3.14159265
#define MAX_MAP_GAMEOBJECTS 100
#define FRAME_TIMEGAP_MS 30

/**
 * @brief Type of object
 */
enum ObjectType {
    eot_gameobject = 0,
    eot_obstacle = 1,
    eot_auto_robot = 2,
    eot_controlled_robot = 3
};

/**
 * @brief Type of collider
 */
enum ColliderType {
    ect_collider = 0,
    ect_circle_collider = 1,
    ect_rectangle_collider = 2,
    ect_square_collider = 3
};

/**
 * @brief Direction of speed 
 */
enum SpeedDirection: int {
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

/**
 * @brief Line orientation
 */
enum PointsOrientation {
    epo_collinear = 0,
    epo_clockwise = 1,
    epo_counter_clockwise = 2
};

#endif

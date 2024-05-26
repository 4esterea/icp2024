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

#define SIMRULE_MAX_MAP_GOBJECTS 100
#define SIMRULE_FRAME_TIMEGAP_MS 10
#define SIMRULE_ROBOT_DEFAULT_SPEED 200
#define SIMRULE_ROBOT_DEFAULT_ANGLE 180
#define SIMRULE_ROTATE_IF_STUCK false
#define SIMRULE_ROTATE_TIMES_SLOWER 3
#define SIMRULE_RC_STOP_ON_VISION true

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
    ect_square_collider = 3,
    ect_qt_qrect_collider = 4,
    ect_qt_qcirc_collider = 5
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
    erd_right = 1,
    erd_none = 0,
    erd_left = -1
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

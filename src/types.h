/**
 * @file types.h
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 08.04.2024
 * @brief Definition of types used in program
 */

/**
 * @brief Type of object 
 */
typedef enum ObjectType {
    null = 0 
};

/**
 * @brief Direction of speed 
 */
typedef enum SpeedDirection {
    none = 0,
    forward = 1
};

/**
 * @brief Direction of rotation 
 */
typedef enum RotationDirection {
    right = -1,
    none = 0,
    left = 1
};
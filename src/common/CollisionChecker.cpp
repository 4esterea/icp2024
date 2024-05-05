/**
 * @file CollisionChecker.cpp
 * @author Sniehovskyi Nikita (xsnieh00)
 * @author TODO
 * @date 04.05.2024
 * @brief Implementation of Collision Checker.
 */

#include "../headers/CollisionChecker.h"

#include <QDebug>
bool CollisionChecker::CheckCollision(ICollider * c1, ICollider * c2) {
    // 2 Circle Colliders
    if (c1->GetColliderType() == ect_circle_collider && c2->GetColliderType() == ect_circle_collider) {
        ICircleCollider * cc1 = dynamic_cast<ICircleCollider *>(c1);
        ICircleCollider * cc2 = dynamic_cast<ICircleCollider *>(c2);
        return CollisionChecker::CheckCollisionCircleCircle(cc1, cc2);
    }

    // Rectangle + Circle Colliders
    if (c1->GetColliderType() == ect_circle_collider && c2->GetColliderType() == ect_rectangle_collider) {
        IRectangleCollider * rc1 = dynamic_cast<IRectangleCollider *>(c2);
        ICircleCollider * cc2 = dynamic_cast<ICircleCollider *>(c1);
        return CollisionChecker::CheckCollisionRectangleCircle(rc1, cc2);
    } else if (c1->GetColliderType() == ect_rectangle_collider && c2->GetColliderType() == ect_circle_collider) {
        IRectangleCollider * rc1 = dynamic_cast<IRectangleCollider *>(c1);
        ICircleCollider * cc2 = dynamic_cast<ICircleCollider *>(c2);
        return CollisionChecker::CheckCollisionRectangleCircle(rc1, cc2);
    }

    // 2 Rectangle Colliders
    if (c1->GetColliderType() == ect_circle_collider && c2->GetColliderType() == ect_circle_collider) {
        ICircleCollider * cc1 = dynamic_cast<ICircleCollider *>(c1);
        ICircleCollider * cc2 = dynamic_cast<ICircleCollider *>(c2);
        return CollisionChecker::CheckCollisionCircleCircle(cc1, cc2);
    }
    return false;
}

bool CollisionChecker::CheckCollisionCircleCircle(ICircleCollider * cc1, ICircleCollider * cc2) {
    return sqrt(pow(abs(cc1->GetPosition()->x - cc2->GetPosition()->x), 2) + pow(abs(cc1->GetPosition()->y - cc2->GetPosition()->y), 2)) < (cc1->GetRadius() + cc2->GetRadius());
}

bool CollisionChecker::CheckCollisionRectangleRectangle(IRectangleCollider * cr1, IRectangleCollider * cr2) {
    return false;
}

bool CollisionChecker::CheckCollisionRectangleCircle(IRectangleCollider * cr1, ICircleCollider * cc2) {
    bool result = false;
    double r = cc2->GetRadius();
    double w = cr1->GetWidth();
    double h = cr1->GetHeight();
    double cx;
    double cy;
    // Move circle as if rectangle was in 0,0
    Position * pc2 = new Position(cc2->GetPosition()->x - cr1->GetPosition()->x, cc2->GetPosition()->y - cr1->GetPosition()->y, 0);
    // Rotate circle center
    Position * pc2c = new Position(
        pc2->x * cos((360 - cr1->GetPosition()->angle) * PI / 180) - pc2->y * sin((360 - cr1->GetPosition()->angle) * PI / 180),
        pc2->x * sin((360 - cr1->GetPosition()->angle) * PI / 180) + pc2->y * cos((360 - cr1->GetPosition()->angle) * PI / 180),
        cr1->GetPosition()->angle
    );

    // Get closest X to circle on rectangle
    if (pc2c->x + r > -1 * w / 2 && pc2c->x - r < w / 2) {
        cx = pc2c->x;
        cx = cx > w / 2 ? w / 2 : cx;
        cx = cx < -1 * w / 2 ? -1 * w / 2 : cx;
    } else {
        delete pc2;
        delete pc2c;
        return false;
    }
    // Get closest Y to circle on rectangle
    if (pc2c->y + r > -1 * h / 2 && pc2c->y - r < h / 2) {
        cy = pc2c->y;
        cy = cy > h / 2 ? h / 2 : cy;
        cy = cy < -1 * h / 2 ? -1 * h / 2 : cy;
    } else {
        delete pc2;
        delete pc2c;
        return false;
    }

    result = pow(pc2c->x - cx, 2) + pow(pc2c->y - cy, 2) < pow(r, 2);
    delete pc2;
    delete pc2c;
    return result;
}

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
    if (c1->GetColliderType() == ect_rectangle_collider && c2->GetColliderType() == ect_rectangle_collider) {
        IRectangleCollider * rc1 = dynamic_cast<IRectangleCollider *>(c1);
        IRectangleCollider * rc2 = dynamic_cast<IRectangleCollider *>(c2);
        return CollisionChecker::CheckCollisionRectangleRectangle(rc1, rc2);
    }
    return false;
}

bool CollisionChecker::CheckCollisionCircleCircle(ICircleCollider * cc1, ICircleCollider * cc2) {
    return sqrt(pow(abs(cc1->GetPosition()->x - cc2->GetPosition()->x), 2) + pow(abs(cc1->GetPosition()->y - cc2->GetPosition()->y), 2)) < (cc1->GetRadius() + cc2->GetRadius());
}

bool CollisionChecker::CheckCollisionRectangleRectangle(IRectangleCollider * cr1, IRectangleCollider * cr2) {
    double r1p[4][2];
    double r2p[4][2];
    Position * p1 = dynamic_cast<Position *>(cr1->GetPosition());
    Position * p2 = dynamic_cast<Position *>(cr2->GetPosition());
    double w1 = cr1->GetWidth();
    double w2 = cr2->GetWidth();
    double h1 = cr1->GetHeight();
    double h2 = cr2->GetHeight();
    p1->y *= -1;
    p2->y *= -1;
    // Corner points of first rectangle
    r1p[0][0] = p1->x + w1/2 * cos((360 - p1->angle) * PI / 180) + h1/2 * sin((360 - p1->angle) * PI / 180);
    r1p[1][0] = p1->x + w1/2 * cos((360 - p1->angle) * PI / 180) - h1/2 * sin((360 - p1->angle) * PI / 180);
    r1p[2][0] = p1->x - w1/2 * cos((360 - p1->angle) * PI / 180) - h1/2 * sin((360 - p1->angle) * PI / 180);
    r1p[3][0] = p1->x - w1/2 * cos((360 - p1->angle) * PI / 180) + h1/2 * sin((360 - p1->angle) * PI / 180);
    r1p[0][1] = p1->y + w1/2 * sin((360 - p1->angle) * PI / 180) + h1/2 * cos((360 - p1->angle) * PI / 180);
    r1p[1][1] = p1->y + w1/2 * sin((360 - p1->angle) * PI / 180) - h1/2 * cos((360 - p1->angle) * PI / 180);
    r1p[2][1] = p1->y - w1/2 * sin((360 - p1->angle) * PI / 180) - h1/2 * cos((360 - p1->angle) * PI / 180);
    r1p[3][1] = p1->y - w1/2 * sin((360 - p1->angle) * PI / 180) + h1/2 * cos((360 - p1->angle) * PI / 180);

    // Corner points of second rectangle
    r2p[0][0] = p2->x + w2/2 * cos((360 - p2->angle) * PI / 180) + h2/2 * sin((360 - p2->angle) * PI / 180);
    r2p[1][0] = p2->x + w2/2 * cos((360 - p2->angle) * PI / 180) - h2/2 * sin((360 - p2->angle) * PI / 180);
    r2p[2][0] = p2->x - w2/2 * cos((360 - p2->angle) * PI / 180) - h2/2 * sin((360 - p2->angle) * PI / 180);
    r2p[3][0] = p2->x - w2/2 * cos((360 - p2->angle) * PI / 180) + h2/2 * sin((360 - p2->angle) * PI / 180);
    r2p[0][1] = p2->y + w2/2 * sin((360 - p2->angle) * PI / 180) + h2/2 * cos((360 - p2->angle) * PI / 180);
    r2p[1][1] = p2->y + w2/2 * sin((360 - p2->angle) * PI / 180) - h2/2 * cos((360 - p2->angle) * PI / 180);
    r2p[2][1] = p2->y - w2/2 * sin((360 - p2->angle) * PI / 180) - h2/2 * cos((360 - p2->angle) * PI / 180);
    r2p[3][1] = p2->y - w2/2 * sin((360 - p2->angle) * PI / 180) + h2/2 * cos((360 - p2->angle) * PI / 180);

    for (int i = 0; i < 4; i++) {
        std::pair<double, double> l1p1;
        std::pair<double, double> l1p2;
        l1p1.first = r1p[i][0];
        l1p1.second = r1p[i][1] * -1;
        l1p2.first = r1p[(i+1)%4][0];
        l1p2.second = r1p[(i+1)%4][1] * -1;
        for (int j = 0; j < 4; j++) {
            std::pair<double, double> l2p1;
            std::pair<double, double> l2p2;
            l2p1.first = r2p[j][0];
            l2p1.second = r2p[j][1] * -1;
            l2p2.first = r2p[(j+1)%4][0];
            l2p2.second = r2p[(j+1)%4][1] * -1;
            if (CollisionChecker::IsLinesIntersect(l1p1,l1p2,l2p1,l2p2)) {
                qDebug() << "TRUE";
                return true;
            }
        }
    }

    qDebug() << "FALSE";
    return false;
}
bool CollisionChecker::IsLinesIntersect(std::pair<double, double> l1p1, std::pair<double, double> l1p2, std::pair<double, double> l2p1, std::pair<double, double> l2p2) {
    int o1 = CollisionChecker::PointsOrientation(l1p1, l1p2, l2p1);
    int o2 = CollisionChecker::PointsOrientation(l1p1, l1p2, l2p2);
    int o3 = CollisionChecker::PointsOrientation(l2p1, l2p2, l1p1);
    int o4 = CollisionChecker::PointsOrientation(l2p1, l2p2, l1p2);

    if (o1 != o2 && o3 != o4) {
        return true;
    }
    if (o1 == epo_collinear && CollisionChecker::IsPointOnLine(l1p1, l1p2, l2p1)) {
        return true;
    }
    if (o2 == epo_collinear && CollisionChecker::IsPointOnLine(l1p1, l1p2, l2p2)) {
        return true;
    }
    if (o3 == epo_collinear && CollisionChecker::IsPointOnLine(l2p1, l2p2, l1p1)) {
        return true;
    }
    if (o4 == epo_collinear && CollisionChecker::IsPointOnLine(l2p1, l2p2, l1p2)) {
        return true;
    }
    return false;
}

PointsOrientation CollisionChecker::PointsOrientation(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3) {
    double result = (p3.first - p2.first) * (p2.second - p1.second) - (p3.second - p2.second) * (p2.first - p1.first);
    if (result < 0.005 && result > -0.005) {
        return epo_collinear;
    }
    return result > 0 ? epo_clockwise : epo_counter_clockwise; // clock or counterclock wise
}

bool CollisionChecker::IsPointOnLine(std::pair<double, double> lp1, std::pair<double, double> lp2, std::pair<double, double> p) {
    if (p.first <= std::max(lp1.first, lp2.first) && p.first >= std::min(lp1.first, lp2.first) && p.second <= std::max(lp1.second, lp2.second) && p.second >= std::min(lp1.second, lp2.second)) {
        return true;
    }
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

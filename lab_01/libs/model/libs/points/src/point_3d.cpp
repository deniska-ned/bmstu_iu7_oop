#include "point_3d.hpp"

#include <cmath>

ERR_POINT_3D point_3D_fscan(point_3D &point, FILE *f)
{
    if (nullptr == f)
    {
        return ERR_POINT_3D_FILE_NULL;
    }

    point_3D point_tmp = {};

    if (3 != fscanf(f, "%lf %lf %lf",
                    &point_tmp.x, &point_tmp.y, &point_tmp.z))
    {
        return ERR_POINT_3D_INCOR_FILE;
    }
    else
    {
        point = point_tmp;
        return ERR_POINT_3D_OKAY;
    }
}

void point_3d_move(struct point_3D & point,
                   const point_3D_diff & point_deltas)
{
    point.x += point_deltas.x;
    point.y += point_deltas.y;
    point.z += point_deltas.z;
}

void point_3d_scale_by_0(struct point_3D &point,
                         const point_3D_diff & point_k)
{
    point.x = point_k.x * point.x;
    point.y = point_k.y * point.y;
    point.z = point_k.z * point.z;
}

void point_3d_scale(struct point_3D &point, const struct point_3D & center,
                    const point_3D_diff & point_k)
{
    point.x = point_k.x * point.x + center.x * (1 - point_k.x);
    point.y = point_k.y * point.y + center.y * (1 - point_k.y);
    point.z = point_k.z * point.z + center.z * (1 - point_k.z);
}

void point_3d_rotate_by_0_x(struct point_3D & point,
                            const double angle)
{
    double y = point.y;
    double z = point.z;

    point.y = y * cos(angle) + z * sin(angle);
    point.z = - y * sin(angle) + z * cos(angle);
}

void point_3d_rotate_by_0_y(struct point_3D & point,
                            const double angle)
{
    double x = point.x;
    double z = point.z;

    point.x = x * cos(angle) + z * sin(angle);
    point.z = -x * sin(angle) + z * cos(angle);
}

void point_3d_rotate_by_0_z(struct point_3D & point,
                            const double angle)
{
    double x = point.x;
    double y = point.y;

    point.x = x * cos(angle) - y * sin(angle);
    point.y = x * sin(angle) + y * cos(angle);
}

void point_3d_rotate_by_0(struct point_3D & point,
                          const struct point_3D_diff angles)
{
    point_3d_rotate_by_0_x(point, angles.x);
    point_3d_rotate_by_0_y(point, angles.y);
    point_3d_rotate_by_0_z(point, angles.z);
}

void point_3d_rotate(struct point_3D & point, const struct point_3D & center,
                     const struct point_3D_diff angles)
{
    double x, y, z;

    // X rotation
    y = point.y;
    z = point.z;

    point.y = center.y
              + (y - center.y) * cos(angles.x)
              + (z - center.z) * sin(angles.x);
    point.z = center.z
              - (y - center.y) * sin(angles.x)
              + (z - center.z) * cos(angles.x);

    // Y rotation
    x = point.x;
    z = point.z;

    point.x = center.x
              + (x - center.x) * cos(angles.y)
              + (z - center.z) * sin(angles.y);
    point.z = center.z
              - (x - center.x) * sin(angles.y)
              + (z - center.z) * cos(angles.y);

    // Z rotation
    x = point.x;
    y = point.y;

    point.x = center.x
              + (x - center.x) * cos(angles.z)
              - (y - center.y) * sin(angles.z);
    point.y = center.y
              + (x - center.x) * sin(angles.z)
              + (y - center.y) * cos(angles.z);
}

struct point_3D point_3d_get_0()
{
    return { .x = 0.0, .y = 0.0, .z = 0.0};
}

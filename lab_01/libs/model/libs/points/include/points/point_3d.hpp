#ifndef LAB_01_POINT_HPP
#define LAB_01_POINT_HPP

#include <stdio.h>

struct point_3D
{
    double x;
    double y;
    double z;
};

struct point_3D_diff
{
    double x;
    double y;
    double z;
};

enum ERR_POINT_3D
{
    ERR_POINT_3D_OKAY,
    ERR_POINT_3D_INCOR_FILE,
    ERR_POINT_3D_FILE_NULL
};

ERR_POINT_3D point_3D_fscan(point_3D &point, FILE *f);

void point_3d_move(struct point_3D & point,
                   const point_3D_diff & point_deltas);

void point_3d_scale_by_0(struct point_3D &point,
                         const point_3D_diff & point_k);
void point_3d_scale(struct point_3D &point, const struct point_3D & center,
                    const point_3D_diff & point_k);

void point_3d_rotate_by_0(struct point_3D & point,
                     const struct point_3D_diff angles);
void point_3d_rotate(struct point_3D & point, const struct point_3D & center,
                     const struct point_3D_diff angles);

struct point_3D point_3d_get_0();

#endif //LAB_01_POINT_HPP

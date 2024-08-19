#include "s21_3dviewer.h"

int s21_centering(viewer *buf) {
    int centerX, centerY, centerZ, min, max;
    min = buf->v->MinMaxX[0];
    max = buf->v->MinMaxX[1];
    centerX = min + (max - min)/2;
    buf->v->MinMaxX[0] -= centerX;
    buf->v->MinMaxX[1] -= centerX;
    min = buf->v->MinMaxY[0];
    max = buf->v->MinMaxY[1];
    centerY = min + (max - min)/2;
    buf->v->MinMaxY[0] -= centerY;
    buf->v->MinMaxY[1] -= centerY;
    min = buf->v->MinMaxZ[0];
    max = buf->v->MinMaxZ[1];
    centerZ = min + (max - min)/2;
    buf->v->MinMaxZ[0] -= centerZ;
    buf->v->MinMaxZ[1] -= centerZ;
    for(int i = 0; i < buf->v->amount_coord; i++){
        buf->v->coord[i].x -= centerX; 
        buf->v->coord[i].y -= centerY;
        buf->v->coord[i].z -= centerZ;
    }
    return 0;
}

double find_max(double x, double y, double z) {
    double max_num = x;
    if(max_num < y){
        max_num = y;
    }
    if(max_num < z){
        max_num = z;
    }
    return max_num;
}

void scale_coord(viewer *head, double scale) {
    for(int i = 0; i < head->v->amount_coord; i++){
        head->v->coord[i].x *= scale; 
        head->v->coord[i].y *= scale;
        head->v->coord[i].z *= scale;
    }
}

int s21_down_to_window(viewer *buf, int value) {
    int x, y, z;
    x = buf->v->MinMaxX[1] - buf->v->MinMaxX[0];
    y = buf->v->MinMaxY[1] - buf->v->MinMaxY[0];
    z = buf->v->MinMaxZ[1] - buf->v->MinMaxZ[0];
    double clmax = find_max(x, y, z);
    double scale = (value - (value*(-1)))/clmax;
   scale_coord(buf, scale);
    return 0;
}

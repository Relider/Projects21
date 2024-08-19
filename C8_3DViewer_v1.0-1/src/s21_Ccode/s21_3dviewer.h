#ifndef S21_3DVIEWER_H
#define S21_3DVIEWER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct vertex *v;
    struct polygon *p;
    int amount_polygon;
} viewer;

struct vertex{
    int amount_coord;
    struct points *coord;
    int MinMaxX[2];
    int MinMaxY[2];
    int MinMaxZ[2];
};

struct points{
    double x;
    double y;
    double z;
};

struct polygon{
    int *p;
    int amount_p;
};

void initial_struct(viewer *head);
void push_coord(viewer *head, double x, double y, double z);
void free_struct(viewer *head);

int s21_centering(viewer *buf);
int s21_down_to_window(viewer *buf, int value);



#endif  // S21_3DVIEWER_H

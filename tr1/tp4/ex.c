#include <stdio.h>
#include <math.h>

#define N 5

typedef struct
{
    double x;
    double y;
} Point;

int main()
{
    Point points[N];
    Point ref_point = {1, 2};
    printf("Entrez les coordonnées de %d points (x y) :\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("Point %d : ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    printf("\nLes points entrés sont :\n");
    for (int i = 0; i < N; i++)
    {
        printf("Point %d : (%.1lf, %.1lf)\n", i + 1, points[i].x, points[i].y);
    }

    int index_max = 0;
    double max_distance = sqrt((points[0].x - ref_point.x) * (points[0].x - ref_point.x) + (points[0].y - ref_point.y) * (points[0].y - ref_point.y));

    for (int i = 1; i < N; i++)
    {
        double dist = sqrt((points[i].x - ref_point.x) * (points[i].x - ref_point.x) + (points[i].y - ref_point.y) * (points[i].y - ref_point.y));
        if (dist > max_distance)
        {
            max_distance = dist;
            index_max = i;
        }
    }

    printf("\nLe point le plus éloigné de (1, 2) est : (%.1lf, %.1lf)\n", points[index_max].x, points[index_max].y);

    return 0;
}
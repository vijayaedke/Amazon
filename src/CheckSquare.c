//
// Created by Viee on 12/30/2018.
//
/*
 * How to check if given four points form a square
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct point {
    int x,y;
};

double distance(struct point p1,struct point p2){
    return sqrt( (p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y) );
}

double slope(struct point p1,struct point p2){
    // printf("%d\t%d\t%d\t%d\n",p2.x,p2.y,p1.x,p1.y);
    return (p2.y-p1.y) / (p2.x-p1.x);
}

char* isSquare(struct point p1,struct point p2,struct point p3,struct point p4){
    //to check if the given point are square check the following:
    //1) Check the diatance between two diagonals are equal or not. d = sqrt(sqrt( (x2 - x1)*(x2 - x1.) + (y2 - y1)*(y2 - y1))
    //2) The diagonals of the square are always perpendicular . Find the slope of two diagonals and compare it.
    //the slope of 2 diagonals are always negative reciprocals of each other. m = (y2-y1) / (x2-x1)

    //calculate the diatance between two diagonals
    double d1 = distance(p1,p3);
    double d2 = distance(p2,p4);
    // printf("%lf\t%lf\n",d1,d2);

    //calculate the slope of two diagonals
    double m1 = slope(p1,p3);
    double m2 = slope(p2,p4);
    // printf("%lf\t%lf\n",m1,m2);

    //check if the distances are equal & has negative reciprocals
    if(d1==d2 && m1==(m2*m1*m1*-1))
        return "yes";
    else
        return "no";
}//isSquare

int main(){
    //provide structure with co-ordinates
    struct point p1 = { 20, 10 }, p3 = { 10, 20 },
            p2 = { 20, 20 }, p4 = { 11, 90 };
    printf("%s\n",isSquare(p1,p2,p3,p4));
    return 0;
}


//sample input
/*
 input 1
 struct point p1 = { 20, 10 }, p3 = { 10, 20 },
        p2 = { 20, 20 }, p4 = { 10, 10 };
 output  : yes

 input 2
 struct point p1= { -1,5 }, p2 = { -1,1 },
      p3 = { 3,1 }, p4 = { 3,5 };
 output   : yes

 input 3
 struct point p1 = { 20, 10 }, p3 = { 10, 20 },
            p2 = { 20, 20 }, p4 = { 11, 90 };
 output : no
 *
 */


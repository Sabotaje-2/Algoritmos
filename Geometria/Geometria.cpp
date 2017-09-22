#include <bits/stdc++.h>

using namespace std;

typedef long long type;

struct Point
{
    type x,y;
    Point(){ x = y = 0.0; }
    Point(type _x, type _y) : x(_x), y(_y){}

    Point operator+ (Point p)
    {
        return Point(p.x + x, p.y + y);
    }

    Point operator- (Point p)
    {
        return Point(x - p.x, y - p.y);
    }

    type operator* (Point p)
    {
        return p.x * x + p.y * y;
    }

    Point operator* (type t)
    {
        return Point(x*t, y*t);
    }

    type operator~ ()
    {
        return x * x + y * y;
    }

    type operator% (Point p)
    {
        return x * p.y - y * p.x;
    }

};

/**
    Remove two if when is a line.
**/
Point projection(Point p1, Point p2, Point o)
{
    Point a = (p2 - p1);
    Point b = (o - p1);
    double t =( (a * b) / (a * a) );
    //[BEGIN_OPCIONAL]
    if( t < 0.0 ) return p1;
    if( t > 1.0 ) return p2;
    //[END_OPCIONAL]
    return p1 + a * t;
}

Point reflection(Point p1, Point p2, Point o)
{
    Point proj = projection(p1, p2, o);
    return o + (proj - o) * 2.0;
}

bool ccw(Point p1, Point p2, Point o)
{
    return ( (p2-p1)%(o-p1) ) < 0;
}

/**
    Return 1 when are orthogonal
    Return 2 when are parallel
    Else Return 0
**/
int areParallel(Point p1, Point p2, Point p3, Point p4)
{
    Point vec = (p2 - p1);
    Point vec1 = (p4 - p3);
    if(vec * vec1 == 0) return 1;
    if( vec.x * vec1.y == vec1.x * vec.y ) return 2;
    return 0;
}

bool areIntersectSegment(Point a, Point b, Point p, Point q)
{
    Point v1=(b-a);
    Point v2=(q-p);
    double t,t1;
    if( v1 % v2 != 0 )
    {
        t = (double)(( p - a ) % v2) / (double)(v1 % v2);
        t1 = (double)(( a - p ) % v1) / (double)(v2 % v1);
        if( t >= 0.0 && t <= 1.0 && t1 >= 0.0 && t1 <= 1.0) return true;
        else return false;
    }
    else
    {
        // Segment cotypeinear
        if( v1 % v2 == 0 && (p - a) % v1 == 0 )
        {
            t = (double)((p - a)*v1) /  (double)(v1*v1);
            t1 = (double)((p+v2-a)*v1) / (double)(v1*v1);
            //If are in opposite direction
            if( v1 * v2 < 0 )
            {
                if( t1 <= 1.0 && 0.0 <= t ) return true;
            }
            else
            {
                if( t <= 1.0 && 0.0 <= t1 ) return true;
            }
        }
    }
    return false;
}

/**
    Assume that the segments are not collinear
    Return the point of intersection.
**/
Point areIntersectSegment(Point a, Point b, Point p, Point q)
{
    Point v1=(b-a);
    Point v2=(q-p);
    double t;
    t = (double)(( p - a ) % v2) / (double)(v1 % v2);
    return a + v1*t;
}

double distancePointToSegment(Point a, Point b, Point p)
{
    return ~(projection(a,b,p)-p);
}

double distanceSegmentToSegment(Point a, Point b, Point p, Point q)
{
    double minimo = numeric_limits<type>::max();
    if( !areIntersectSegment(a,b,p,q) )
    {
        minimo = min( minimo, distancePointToSegment(a,b,p) );
        minimo = min( minimo, distancePointToSegment(a,b,q) );
        minimo = min( minimo, distancePointToSegment(p,q,a) );
        minimo = min( minimo, distancePointToSegment(p,q,b) );
        return  minimo;
    }
    return 0.0;
}

double areaPolygon(int n)
{
    double acum = 0.0;
    for(int i = 1 ; i < n+1 ; i++)
        acum += polygon[i-1]%polygon[i];
    return acum / 2.0;
}

bool isConvex(int n)
{
    if(n+1 <= 3) return false;
    bool isLeft = ccw(polygon[0], polygon[1], polygon[2]);
    for(int i = 1 ; i < n; i++)
        if(ccw(polygon[i-1],polygon[i],polygon[i+1]) != isLeft)
            return false;
    return true;
}

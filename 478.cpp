#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

class Shape
{
public:
    virtual bool in_area(double,double) = 0;
};


class Rectangle : public Shape
{
private:
    double x1,y1,x2,y2;
public:
    Rectangle(double,double,double,double);
    bool in_area(double,double);
};
Rectangle::Rectangle(double X1, double Y1, double X2, double Y2)
{
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
}
bool Rectangle::in_area(double x, double y)
{
    if (x > x1 && x < x2 && y < y1 && y > y2)
    {
        return true;
    }
    else
    {
        return false;
    }
}


class Circle : public Shape
{
private:
    double x,y,r;
public:
    Circle(double,double,double);
    bool in_area(double,double);
};
Circle::Circle(double X, double Y, double R)
{
    x = X;
    y = Y;
    r = R;
}
bool Circle::in_area(double xp, double yp)
{
    double distance = (xp - x) * (xp - x) + (yp - y) * (yp - y);
    if (distance < r * r)
    {
        return true;
    }
    else
    {
        return false;
    }
}


class Triangle : public Shape
{
private:
    double x1,y1,x2,y2,x3,y3;
public:
    Triangle(double,double,double,double,double,double);
    bool in_area(double,double);
};
Triangle::Triangle(double X1, double Y1, double X2, double Y2, double X3, double Y3)
{
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
    x3 = X3;
    y3 = Y3;

}
bool Triangle::in_area(double x, double y)
{
    double triangleArea = fabs((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3));
    double newTriangleArea = fabs((x - x1) * (y - y3) - (y - y1) * (x - x3))
                            + fabs((x - x1) * (y - y2) - (y - y1) * (x - x2))
                            + fabs((x - x2) *(y - y3) - (y - y2) * (x - x3));
    if (newTriangleArea - triangleArea < 0.00001)
    {
        if (fabs((x - x1) * (y - y3) - (y - y1) * (x - x3)) == 0
            || fabs((x - x1) * (y - y2) - (y - y1) * (x - x2)) == 0
            || fabs((x - x2) *(y - y3) - (y - y2) * (x - x3)) == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    int n = 0;
    bool inArea;
    double x1c, y1c, x2c, y2c;
    double xs, ys, rs;
    double x1t, y1t, x2t, y2t, x3t, y3t;
    double x, y;
    char shp;
    vector<Shape*> v;
    while(true)
    {
        cin >> shp;
        if (shp == '*')
        {
            break;
        }
        else if (shp == 'r')
        {
            cin >> x1c >> y1c >> x2c >> y2c;
            Shape* s = new Rectangle(x1c, y1c, x2c, y2c);
            v.push_back(s);

        }
        else if (shp == 'c')
        {
            cin >> xs >> ys >> rs;
            Shape* s = new Circle(xs, ys, rs);
            v.push_back(s);
        }
        else if (shp == 't')
        {
            cin >> x1t >> y1t >> x2t >> y2t >> x3t >> y3t;
            Shape* s = new Triangle(x1t, y1t, x2t, y2t, x3t, y3t);
            v.push_back(s);
        }
    }

    while(true)
    {
        int counter = 0;
        ++n;
        cin >> x >> y;
        if (x == 9999.9 && y == 9999.9)
        {
            break;
        }
        else
        {
            for (unsigned int i = 0; i < v.size( ); i++)
            {
                inArea = v[i]->in_area(x, y);
                if (inArea)
                {
                    cout << "Point " << n << " is contained in figure " << i + 1 << endl;
                }
                else
                {
                    counter++;
                    if (counter == v.size())
                    {
                        cout << "Point " << n << " is not contained in any figure" << endl;
                    }
                    continue;
                }
            }
        }
    }
}

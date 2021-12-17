#include <iostream>
using namespace std;

class PlaneObject {
    protected:
        float centerX, centerY, radius;
    public:
        PlaneObject(float x, float y, float r) : centerX(x), centerY(y), radius(r) {}
        virtual void move(float, float) = 0;
        virtual void rotate(int) = 0;
        virtual void scale(float) = 0;
        virtual void show() = 0;
};

class Circle : public PlaneObject {
    public:
        
        Circle(float centerX, float centerY, float radius) : PlaneObject(centerX, centerY, radius) {}

        void move(float, float);
        void scale(float);
        void rotate(int);
        void show();
};

class Square : public PlaneObject {
    private: 
        float mass[4][2];
    public:
        Square(float centerX, float centerY, float radius) : PlaneObject(centerX, centerY, radius) {}

        void coordinates(float);
        void move(float, float);
        void rotate(int);
        void scale(float);
        void show();
};

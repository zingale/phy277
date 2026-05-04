#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {

    double width;
    double height;

public:

    Rectangle(double _width, double _height)
      : width(_width), height(_height)
    {}

    Rectangle(double _length)
      : width(_length), height(_length)
    {}

    double perimeter() {
        return 2 * width + 2 * height;
    }

    double area() {
        return width * height;
    }

    bool is_square() {
        return width == height;
    }
};

#endif

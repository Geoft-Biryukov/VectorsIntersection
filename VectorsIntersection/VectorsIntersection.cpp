// VectorsIntersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Segment3D.h"

int main()
{
    std::cout << "Hello World!\n";

    try {
        // Создаём два пересекающихся отрезка
        Segment3D seg1(Vector3D(0, 0, 0), Vector3D(10, 0, 0));
        Segment3D seg2(Vector3D(5, -5, 0), Vector3D(5, 5, 0));

        Vector3D point = Segment3D::Intersect(seg1, seg2);
        std::cout << "Interseption point: ("
            << point.X << ", "
            << point.Y << ", "
            << point.Z << ")" << std::endl;

        // Пример с непересекающимися отрезками
        Segment3D seg3(Vector3D(0, 0, 0), Vector3D(1, 0, 0));
        Segment3D seg4(Vector3D(2, 0, 0), Vector3D(3, 0, 0));

        Vector3D point2 = Segment3D::Intersect(seg3, seg4);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

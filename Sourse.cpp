#include <iostream>
#include "VectorN.h"
using namespace std;

int main()
{
    int size = 3;
    double values1[] = { 1.0, 2.0, 3.0 };
    double values2[] = { 4.0, 5.0, 6.0 };

    VectorN vector1(size, values1);
    VectorN vector2(size, values2);

    // Показує вектори
    cout << "Vector 1: " << vector1 << endl;
    cout << "Vector 2: " << vector2 << endl << endl;

    // ADD and DELETE
    VectorN sum = vector1 + vector2;
    VectorN difference = vector1 - vector2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl << endl;

    // SCALIAR
    double scalarProduct = vector1.Scaliar(vector2);
    cout << "Scalar product: " << scalarProduct << endl << endl;

    // ++ --
    cout << "Now vector is: " << vector1 << endl;
    ++vector1;
    cout << "Prefix: " << vector1 << endl;
    vector1++;
    cout << "Postfix: " << vector1 << endl << endl;

    cout << "Now vector is: " << vector1 << endl;
    --vector1;
    cout << "Prefix: " << vector1 << endl;
    vector1--;
    cout << "Postfix: " << vector1 << endl << endl;

    // =============
    VectorN aVector = vector1;
    cout << "aVector = vector1: " << aVector << endl << endl;

    // << >> << >> << >>
    VectorN inputVector;
    cout << "Enter vector values: ";
    cin >> inputVector;
    cout << "Input vector: " << inputVector << endl << endl;

    // ToString
    string strVector = static_cast<string>(inputVector);
    cout << "String: " << strVector << endl;

}

// VectorN.cpp
#include "VectorN.h"
#include <iostream>
#include <stdexcept>
using namespace std;

VectorN::VectorN() {
    N = 1;
    a = new double[N];
}

VectorN::VectorN(int val, double* m) {
    N = val;
    a = new double[N];
    for (int i = 0; i < N; ++i)
        a[i] = m[i];
}

VectorN::VectorN(const VectorN& other) {
    N = other.N;
    a = new double[N];
    for (int i = 0; i < N; ++i)
        a[i] = other.a[i];
}

VectorN::~VectorN() {
    delete[] a;
}


// SET ================================================================
void VectorN::SetN(int value) {
    N = value;
}
void VectorN::SetA(double* value) {
    delete[] a;
    a = new double[N];
    for (int i = 0; i < N; ++i)
        a[i] = value[i];
}


// ADD AND DELETE
VectorN VectorN::operator+(const VectorN& other) const {
    if (N != other.N)
        throw invalid_argument("Vectors must have the same dimensions for addition");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] + other.a[i];
    VectorN result(N, resultValues);
    delete[] resultValues;
    return result;
}

VectorN VectorN::operator-(const VectorN& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for subtraction");
    double* resultValues = new double[N];
    for (int i = 0; i < N; ++i)
        resultValues[i] = a[i] - other.a[i];
    VectorN result(N, resultValues);
    delete[] resultValues;
    return result;
}


// SCALIAR 
double VectorN::Scaliar(const VectorN& other) const {
    if (N != other.N)
        throw std::invalid_argument("Vectors must have the same dimensions for dot product");
    double result = 0;
    for (int i = 0; i < N; ++i)
        result += a[i] * other.a[i];
    return result;
}



// OPERATION
VectorN& VectorN::operator=(const VectorN& other) {
    if (this != &other) {
        delete[] a;
        N = other.N;
        a = new double[N];
        for (int i = 0; i < N; ++i)
            a[i] = other.a[i];
    }
    return *this;
}

VectorN& VectorN::operator++() {
    for (int i = 0; i < N; ++i)
        ++a[i];
    return *this;
}

VectorN VectorN::operator++(int) {
    VectorN temp(*this);
    ++(*this);
    return temp;
}

VectorN& VectorN::operator--() {
    for (int i = 0; i < N; ++i)
        --a[i];
    return *this;
}

VectorN VectorN::operator--(int) {
    VectorN temp(*this);
    --(*this);
    return temp;
}

ostream& operator<<(ostream& os, const VectorN& obj) {
    os << "VectorN values: ";
    for (int i = 0; i < obj.N; ++i) {
        os << obj.a[i] << " ";
    }
    return os;
}

istream& operator>>(istream& is, VectorN& obj) {
    delete[] obj.a;
    cout << "Enter vector size: ";
    is >> obj.N;
    obj.a = new double[obj.N];
    cout << "Enter vector values: ";
    for (int i = 0; i < obj.N; ++i)
        is >> obj.a[i];
    return is;
}

VectorN::operator std::string() const {
    string result = "VectorN values: ";
    for (int i = 0; i < N; ++i) {
        result += to_string(a[i]) + " ";
    }
    return result;
}

#pragma once
#include <string>
#include <sstream>
using namespace std;

class VectorN {
    int N;
    double* a;

public:
    VectorN();
    VectorN(int, double*);
    VectorN(const VectorN& other);
    ~VectorN();

    void SetN(int value);
    void SetA(double* value);
    int GetN() const { return N; }
    double* GetA() const { return a; }

    VectorN operator+(const VectorN& other) const;
    VectorN operator-(const VectorN& other) const;
    double Scaliar(const VectorN& other) const;

    VectorN& operator=(const VectorN& other);

    VectorN& operator++(); 
    VectorN operator++(int); 
    VectorN& operator--(); 
    VectorN operator--(int); 

    friend ostream& operator<<(ostream& os, const VectorN& obj);
    friend istream& operator>>(istream& is, VectorN& obj);
    operator string() const;
};


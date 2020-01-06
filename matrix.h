#pragma once

#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

using std::vector;
using std::tuple;

class Matrix {
public:
  Matrix(unsigned, unsigned, double); // shady af
    Matrix(const char *);
    Matrix(const Matrix &);
    ~Matrix();

    // Matrix Operations
    Matrix operator+(Matrix &);
    Matrix operator-(Matrix &);
    Matrix operator*(Matrix &);
    Matrix transpose();

    // Scalar Operations
    Matrix operator+(double);
    Matrix operator-(double);
    Matrix operator*(double);
    Matrix operator/(double);

    // Asthetics
    double& operator()(const unsigned &, const unsigned &);
    void print() const;
    unsigned getRows() const;
    unsigned getCols() const;

    // Power iteration
    tuple<Matrix, double, int> powerIter(unsigned, double);

    // Deflation
    Matrix deflation(Matrix &, double&);

private:
    unsigned m_rowSize;
    unsigned m_colSize;
    vector<vector<double> > m_matrix;
};

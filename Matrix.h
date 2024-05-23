#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

//row_operation
const std::vector< std::vector <double>> swapping(std::vector< std::vector <double>> m, int a, int b);
const std::vector< std::vector <double>> resca1ing(std::vector< std::vector <double>> m, int a, double k);
const std::vector< std::vector <double>> row_combination(std::vector< std::vector <double>> m,int a, int b, double k);//a+=bk

const std::vector< std::vector <double>> identity(int n);

const std::vector< std::vector <double>> operator *(const std::vector< std::vector <double>> a, const std::vector< std::vector <double>> b);
const std::vector< std::vector <double>> transpose(const std::vector< std::vector <double>> a);
const double determinant(const std::vector< std::vector <double>> a);
const std::vector< std::vector <double>> inverse(std::vector< std::vector <double>> a);

#endif

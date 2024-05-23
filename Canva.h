#pragma once
#ifndef CANVA_H
#define CANVA_H
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "Matrix.h"

class Canva {
protected:
	int width, height;
	std::vector< std::vector <char>> image;
public:
	Canva(int w, int h);
	void clear();
	void display();
	void draw_line(std::vector<double> a, std::vector<double> b);
    void draw_dot(std::vector<double> a,char c);
};
std::vector<double> parallel_projection(std::vector<double> a); //3d to 2d
std::vector<double> perspective_projection(std::vector<double> a); //3d to 2d
std::vector<std::vector<double>> read_dot(std::string path);
std::vector<std::vector<double>> read_line(std::string path);

#endif

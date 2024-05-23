#include "Canva.h"

Canva::Canva(int w, int h) {
	width = w;
	height = h;
	std::vector<std::vector<char>> temp(height, std::vector<char>(width, ' '));
	image = temp;
};
void Canva::clear() {
	std::vector<std::vector<char>> temp(height, std::vector<char>(width, ' '));
	image = temp;
}
void Canva::display() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << image[height - i - 1][j] << " ";
		}
		std::cout << std::endl;
	}
}
void Canva::draw_dot(std::vector<double> a,char c){
	if(a[0]>=0 && a[0]<height && a[1]>=0 && a[1]<width){
		image[a[0]][a[1]]=c;
	}
}
void Canva::draw_line(std::vector<double> a, std::vector<double> b) {
	//y=mx+c
	std::vector<double> v = { -a[0] + b[0],-a[1] + b[1] };
	if(v[0]==0 &&v[1]==0){
		return;
	}
	char ch = '-';
	/*if (v[0] == 0) { ch = '-'; }
	else if (v[1]/v[0] < 0.4 && v[1] / v[0] >= -0.4) { ch = '|'; }
	else if (v[1] / v[0] < 2.4 && v[1] / v[0] >= 0.4) { ch = '/'; }
	else if (-v[1] / v[0] < 2.4 && -v[1] / v[0] >= 0.4) { ch = 92; }*/
	if (v[0] != 0) {
		v[0] /= sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
	}
	v[1] /= sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
	while (1) {
		draw_dot(a,ch);
		a[0] += v[0];
		a[1] += v[1];
		if ((v[0] < 0 && a[0] < b[0]) || (v[0] > 0 && a[0] > b[0]) || (v[1] < 0 && a[1] < b[1]) || (v[1] > 0 && a[1] > b[1])) {
			break;
		}
		if(a[0]<0 || a[0]>width || a[1]<0|| a[1]>height){
			break;
		}
	}
}
std::vector<double> parallel_projection(std::vector<double> a){
    std::vector<double> result;
    result.push_back(a[2]);
    result.push_back(a[0]);
    return result;
}
std::vector<double> perspective_projection(std::vector<double> a, int fovy){
    std::vector<double> result;
    result.push_back(a[2]);
    result.push_back(a[0]);
    return result;
}
std::vector< std::vector<double>> read_dot(std::string path){
	std::vector< std::vector<double>> result;
	std::vector<double> temp;

	std::fstream myFile;
	myFile.open(path, std::ios::in);
	while(!myFile.eof()){
		double a;
		myFile>>a;
		temp.push_back(a);
	}
	myFile.close();
	std::vector<double> storage;
	for(int i=0;i<temp.size();i++){
		storage.push_back(temp[i]);
		if(storage.size()==3){
			result.push_back(storage);
			storage.resize(0);
		}
	}
	return result;
}
std::vector<std::vector<double>> read_line(std::string path){
	std::vector<std::vector<double>> result;
	std::vector<double> temp;

	std::fstream myFile;
	myFile.open(path, std::ios::in);
	while(!myFile.eof()){
		double a;
		myFile>>a;
		temp.push_back(a);
	}
	myFile.close();
	std::vector<double> storage;
	for(int i=0;i<temp.size();i++){
		storage.push_back(temp[i]);
		if(storage.size()==2){
			result.push_back(storage);
			storage.resize(0);
		}
	}
	return result;
}

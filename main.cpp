#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include "Canva.h"
#include "Matrix.h"

#define PI 3.14159265

using namespace std;
void draw_3D_model(vector<vector<double>> dots, vector<vector<double>> lines,int frame_width, int frame_height){
	Canva canva(frame_width, frame_height);
	for(int i=0;i<lines.size();i++){
		vector<double> temp_a=parallel_projection(dots[lines[i][0]]);
		vector<double> temp_b=parallel_projection(dots[lines[i][1]]);
		canva.draw_line(temp_a,temp_b);
	}
	for(int i=0;i<dots.size();i++){
		vector<double> temp=parallel_projection(dots[i]);
		canva.draw_dot(temp,'@');
	}
	canva.display();
}
int main()
{
	vector<vector<double>> dots=read_dot("./Model/dot.txt");
	vector<vector<double>> lines=read_line("./Model/line.txt");
	vector<double> spin_center={15,15,15};
	double Theta_x=5*PI/180,Theta_y=5*PI/180,Theta_z=0*PI/180;
	vector<vector<double>> 	spin_x={{1,0,0},{0,cos(Theta_x),sin(Theta_y)},{0,-sin(Theta_x),cos(Theta_x)}},
							spin_y={{cos(Theta_y),0,-sin(Theta_y)},{0,1,0},{sin(Theta_y),0,cos(Theta_y)}},
							spin_z={{cos(Theta_z),sin(Theta_z),0},{-sin(Theta_z),cos(Theta_z),0},{0,0,1}};
	draw_3D_model(dots, lines, 40, 30);
	vector<vector<double>> temp={{},{},{}};
	while(1){
		string str;
		getline(cin, str);
		if(str!=""){
			break;
		}
		for(int i=0;i<dots.size();i++){
			for(int j=0;j<dots[i].size();j++){
				temp[j].push_back(dots[i][j]-spin_center[j]);
			}
		}
		temp=spin_x*spin_y*spin_z*temp;
		for(int i=0;i<dots.size();i++){
			for(int j=0;j<dots[i].size();j++){
				dots[i][j]=spin_center[j]+temp[j][i];
			}
		}
		for(int i=0;i<40*2;i++){
			cout<<"-";
		}
		cout<<endl;
		draw_3D_model(dots, lines, 40, 30);
	}
}

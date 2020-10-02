#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<cmath>
#include <bits/stdc++.h>
using namespace std;


void dda_algorithm(){
	double x0,y0 ,x1, y1,color;
	
	for (int i=1; i<=100; i++){
		//cout<<i<<endl;
		x0 = rand() % 1280;
		y0 = rand() % 720;
		
		x1 = rand() % 1200;
		y1 = rand() % 700;
		
		color = rand() % 15 + 1;
		
		double dy, dx, x, y;
		dy = abs(y0-y1);
		dx = abs(x0-x1);
		
		x= x0;
		y= y0;
		putpixel(round(x), round(y), color);
		
		for (int j=1; j<max(dy,dx); j++){
			if (dy > dx){
				
				if (x0 < x1){
					x+=(dx/dy);	
				} else {
					x-=(dx/dy);	
				}
				
				if (y0 < y1){
					y++;	
				} else{
					y--;
				}
				
			} else{
				
				if (x0 < x1){
					x++;	
				} else {
					x--;	
				}
				
				if (y0 < y1){
					y+=dy/dx;	
				} else{
					y-=dy/dx;
				}
				
			}
			
			putpixel(round(x), round(y), color);
			delay(1);
		}
			
	}
}

void bresenham_algorithm(){
	double x0,y0 ,x1, y1,color;
	
	for (int i=1; i<=100; i++){
		//cout<<i<<endl;
		x0 = rand() % 1280;
		y0 = rand() % 720;
		
		x1 = rand() % 1200;
		y1 = rand() % 700;
		
		color = rand() % 15 + 1;
		
		double dy, dx, x, y;
		dy = abs(y0-y1);
		dx = abs(x0-x1);
		int p = 2*dy-dx;
		
		x= x0;
		y= y0;
		putpixel(x, y, color);
		
		for (int j=1; j<max(dy,dx); j++){
			if (p>=0){
				p+=2*(dy-dx);
				if (x0 < x1){
					x++;	
				} else {
					x--;	
				}
				
				if (y0 < y1){
					y++;	
				} else{
					y--;
				}
				
			} else{
				p+=2*dy;
				if (x0 < x1){
					x++;	
				} else {
					x--;	
				}
			}
			
			putpixel(x,y,color);
			delay(1);
		}
			
	}
}

int main(){
	initwindow(1280,720);
	srand (time(NULL));
	
	dda_algorithm();
	bresenham_algorithm();
}


#include <iostream>
#include <string>
#include <fstream>

#ifndef PRINTER_H_
#define PRINTER_H_

using namespace std;

enum class shapes { cir , rect , tri };

void print_shape(const char * filename , enum shapes main_shape , const string color , const string color2);
void print_first_line(const char * filename , double width , double hight , enum shapes main_shape);
void print_last_line (const char * filename);
void print_rectangle(const char * filename , double rx , double ry , double width , double hight , const string color);
void print_circle(const char * filename , double cx , double cy , double radius , const string color);
void print_triangle(const char * filename , double point1_x , double point1_y , double point2_x , double point2_y ,
					double point3_x , double point3_y , const string color);
int print_small_shape(const char * filename,enum shapes main_shape, double width , double hight ,
					  double *size ,const string color) ;
int print_rect_in_rect(const char *filename,double width,double hight,double s_width,double s_hight,const string color);
int print_cir_in_rect(const char *filename,double width,double hight,double radius,const string color);
int print_tri_in_rect(const char *filename,double width,double hight,double length,const string color);
int print_rect_in_cir(const char *filename , double radius,double width,double hight,const string color);
int print_tri_in_cir(const char *filename , double radius,double length,const string color);
int print_cir_in_cir(const char *filename , double radius,double s_radius,const string color);
int print_rect_in_tri(const char *filename ,double length,double width,double hight,const string color);
int print_cir_in_tri(const char *filename ,double length,double radius ,const string color);
int print_tri_in_tri(const char *filename ,double length,double s_length ,const string color);
int emplimainting(const char * filename);
bool check_input_validity(enum shapes main_shape , double width , double hight);
double sqrt_root(double num);
double equation_circle(double x , double radius);


#endif /*PRINTER_H_*/
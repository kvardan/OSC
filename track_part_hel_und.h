#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraph2D.h"
#include "TAxis.h"
#include "TMath.h"
#include "TVector3.h"
#include <vector>

using namespace std;
void prepare_arrays(int, int, int);
void read_field(string);
void read_field_first_half(string, double);
void read_field_last_half(string, double);
vector<double> get_bfield(double, double, double);
void runge_kutta_prop(double, double, double, double, double, double, double, double, double, double);
double FPx(double, double, double, double, double, double, double);
double FPy(double, double, double, double, double, double, double);
double FPz(double, double, double, double, double, double, double);
void make_plots();
void prepare_for_plots();
int get_i_from_z(double);
void calc_integrals(double, double, double, double);

TCanvas *cc;
int div_nx;
int div_ny;

double ***x_arr;
double ***y_arr;
double ***z_arr;

double ***bx_arr;
double ***by_arr;
double ***bz_arr;
double ***b_abs;

double ***bx_rot_arr;
double ***by_rot_arr;
double ***bz_rot_arr;

const int n_gr_max=350000;

double x_gr[n_gr_max];
double y_gr[n_gr_max];
double z_gr[n_gr_max];

double I_1st_horiz_gr[n_gr_max];
double I_1st_vert_gr[n_gr_max];
double I_2nd_horiz_gr[n_gr_max];
double I_2nd_vert_gr[n_gr_max];

double bx_gr[n_gr_max];
double by_gr[n_gr_max];
double bz_gr[n_gr_max];

double px_gr[n_gr_max];
double py_gr[n_gr_max];
double pz_gr[n_gr_max];

int n_gr;
double rotation_angle, z_offset, k_scale;
double z_field_start;
int i_und;
int nx;
int ny;
int nz;

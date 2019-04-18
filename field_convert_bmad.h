#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "TMath.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TVector3.h"
#include "TRandom3.h"
#include "TMinuit.h"
#include "TLine.h"
#include "TMath.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TAxis.h"
#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "Math/GSLSimAnMinimizer.h"
#include "Math/GSLNLSMinimizer.h"
#include "Math/GSLMinimizer.h"

using namespace std;
double pi=TMath::Pi();

TVector3 func_family_form(double, double, double, Double_t *);  //defines cartesian map functions (4 families, 3 forms) for different terms
TVector3 func_family_form_minimizer(double, double, double, const double *);
void fit_with_minimizer();
void fit_with_Levemberg_minimizer();
void convert_bmad(string);
void fit_GSLNLSMinimizer();
void fcn_family_form(Int_t &, Double_t *, Double_t &, Double_t *, Int_t);  //A function to calculate chi^2, needed by Minuit
double fcn_family_form_minimizer(const double *);  //A function to calculate chi^2, needed by Minuit
void read_field_data(string);       // To read the field data
void fit_parameters();              // will fit the field and save the parameters in "best_fit_parameters.txt", while you can
                                    // also see the current values of the fit parameters in "fit_parameters.txt" (if status_monitor=true)
void draw_control_plots(int, int);  // This function will prepare and save plots (B_(x,y,z) vs z) on current step of the fit
                                    // the arguments are (ix, iy): x and y grid division numbers. This funcion will be called
                                    //only if the status_monitor=true




// must be in agreement with the input file
// remember also to check if the fit parameter ranges (A_max, x0, y0, phi_max) are ok.
string input_f_name="hundulator_66730_450_xyz.table";
double scale_f=1.e-4; //gaus->Tesla
double field_error_x=1e-3;  //field Bx error
double field_error_y=1e-3;  //field By error
double field_error_z=1e-3;  //field Bz error
const int nx=21;  //grid nx
const int ny=21;  //grid ny
const int nz=2301;  //grid nz
double x0_start=-1.;
double y0_start=-1.;
double z0_start=-100.;
double x0_step_size=0.1;
double y0_step_size=0.1;
double z0_step_size=0.2;

/*
const int nx=7;  //grid nx
const int ny=7;  //grid ny
const int nz=2301;  //grid nz
double x0_start=-0.3;
double y0_start=-0.3;
double z0_start=-100.;
double x0_step_size=0.1;
double y0_step_size=0.1;
double z0_step_size=0.2;
*/
double kz=2*pi/21.8/2./2.;
//double kz=2*pi/32.5;
const int n_terms=4;  //number of terms for cartesian map functions


/*
// must be in agreement with the input file
// remember also to check if the fit parameter ranges (A_max, x0, y0, phi_max) are ok.
string input_f_name="field_data.dat";
double scale_f=1.;
double field_error_x=1e-3;
double field_error_y=1e-3;
double field_error_z=1e-3;
const int nx=4;
const int ny=4;
const int nz=650;
double x0_start=0;
double y0_start=0;
double z0_start=0;
double x0_step_size=0.01;
double y0_step_size=0.01;
double z0_step_size=0.002;
double kz=2*pi/0.325;
const int n_terms=1;  //number of terms for cartesian map functions
*/

bool debug_mode=false;
bool status_monitor=true;
//fit parameters allowed ranges
double A_max=0.2;
double x0_max=0.001;
double y0_max=0.001;
double phi_max=pi;


double kz_terms[n_terms];
int n_total=0;
int n_pars[n_terms][4][3];
bool use_family_form[n_terms][4][3];
double x_bmad[nx][ny][nz];
double y_bmad[nx][ny][nz];
double z_bmad[nx][ny][nz];
double bx_bmad[nx][ny][nz];
double by_bmad[nx][ny][nz];
double bz_bmad[nx][ny][nz];
double chi2_fit=0;
const int n_max_pars=60*n_terms;
double fit_par_res[n_max_pars];
double fit_par_tmp[n_max_pars];
double fit_par_res_Err[n_max_pars];
string par_names[n_max_pars];

int n_fit=0, itry=0;

TCanvas *cc;

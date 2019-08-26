// track a particle through undulator field

#include "track_part_hel_und.h"

using namespace std;


void track_part_hel_und()
{
  pi=acos(-1.);
  nx=101; //field map divisions in x direction, needed for definitions of arrays
  ny=101; //field map divisions in y direction, needed for definitions of arrays
  nz=4001; //field map divisions in z direction, needed for definitions of arrays
  x_field_start=-5.;    // the lower edge of the field map. The field can start at any place after this edge (x_field>x_field_start)
  y_field_start=-5.;    // the lower edge of the field map. The field can start at any place after this edge (y_field>y_field_start)
  z_field_start=-200.;  // the lower edge of the field map. The field can start at any place after this edge (z_field>z_field_start)
  dx_field=0.1;         // field map step size in mm-s
  dy_field=0.1;         // field map step size in mm-s
  dz_field=0.2;         // field map step size in mm-s
  field_disp_z=0.;      // displacement of the field to be read next
  field_rot_angle=0.;   // rotation of the field to be read next
  double  x_max=5.,   y_max=5.,   z_min=z_field_start, z_max=580;  // maximum allowed coordinates
  double  x_init=0.0, y_init=0.,  z_init=-100;  // starting coordinates
  double  px_init=0., py_init=0., pz_init=1.;  // momentum is in GeV units
//  double pi=acos(-1.);

  prepare_arrays(nx, ny, nz);  // this will prepare arrays with dimensions nx, ny and nz in agreement with the field map
  prepare_for_plots();
//  k_scale=0.847;
//  k_scale=221./228.;
  n_period=4;
  l_period=28;
  k_scale=1.;

  i_und=850771772;
  int op3_cur=330;
  pz_init=1;
//  i_und=-1;

  if (i_und==-1)
  {
    read_field("SRW_field.dat");
  }

  if (i_und==8203)
  {
//    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
//    y_init=-0.0453053;
//    y_init=0.15;
//    px_init=0.03e-3;
//    py_init=-0.06e-3;
//    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
//    rotation_angle=19.4*TMath::Pi()/32.;
//    k_scale=1500./1328.;
  }

//  x_init=-0.025;
//  y_init=-0.015;

//  i_und=8300;
//  int op3_cur=339;


  if (i_und==6)
  {
    read_field("/nfs/acc/user/vk348/opera/v7_1_osc_geom_steel_cor_field_0.5_end_current_/hundulator_07_908_xyz.table");
    // We need to give some initial parameters to get the electron trajectory (and the radiated light) as expected
//    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
//    y_init=-0.0453053;
//    px_init=-pz_init*(-0.4354+0.0089301680)/130.;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=19.4*TMath::Pi()/32.;
//    k_scale=1500./1328.;
  }


  if (i_und==8207)
  {
//    k_scale=339/401.;
//    px_init=0.0276e-3;
//    py_init=-0.0276;
    x_init=-0.0276;
    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
    k_scale=-0.11;
    i_und=107;
    op3_cur=795;
    field_disp_z=-15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=0.055;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+25;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=0.088;
    i_und=107;
    field_rot_angle=0.;
    op3_cur=795;
    field_disp_z=14.*l_period+15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85501)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.452;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.42;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.20;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.155;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==8556)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.487;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.435;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.095;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.005;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==8540)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.627;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.59;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.11;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.14;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85331)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
/*
    x_init=-0.05;
    y_init=0.306;
    px_init=0.508e-3;
    py_init=-3.066e-3;
    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
*/

    k_scale=15.574;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-15.952;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=2.60;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=2.70;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85321)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
    x_init=-0.05;
    y_init=0.306;
    px_init=0.508e-3;
    py_init=-3.066e-3;
    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
  }
  else if (i_und==8535)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=15.65;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-15.792;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=2.67;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=2.50;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85361)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.479;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.482;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.06;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.10;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85381 || i_und==85382)
  {
    k_scale=1500./1493.68;
    double k_scale_tmp=k_scale;
//    x_init=-0.0276;
//    y_init=-0.0363;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
    k_scale=14.494*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.507*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.085*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.18*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==853841)
  {
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
    k_scale=14.494*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.507*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.085*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.18*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85386)
  {
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
    k_scale=14.634*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.507*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.085*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=0.02*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==853861)
  {
    k_scale=1500./1484.65;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
    k_scale=14.204*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.247*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.05*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.109*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85391)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500/1493.75;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.636;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.473;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.043;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.055;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*l_period+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und>=10)
  {
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }


//  loop over rotation angles to find the most suitable picture
//  for (rotation_angle=0; rotation_angle<=2.*TMath::Pi(); rotation_angle+=TMath::Pi()/32.)
  {
    x_init_tmp=x_init;
    y_init_tmp=y_init;
    runge_kutta_prop(x_init, y_init, z_init, px_init, py_init, pz_init, x_max, y_max, z_min, z_max);
    make_plots();
  }
  cout<<"magnet No:"<<i_und<<endl;
  cout<<"px_final="<<px_gr[n_gr-3]<<" n="<<n_gr-3<<endl;
  cout<<"py_final="<<py_gr[n_gr-3]<<" n="<<n_gr-3<<endl;

//  cc->Print("results_RK.pdf]");
}


void prepare_for_plots()
{
  cc = new TCanvas("cc", "cc", 100, 0, 1600, 900);
  div_nx=3;
  div_ny=3;
  cc->Divide(div_nx,div_ny);
//  cc->Print("results_RK.pdf[");
}


void runge_kutta_prop(double x0, double y0, double z0, double px0, double py0, double pz0, double x_max, double y_max, double z_min, double z_max)
{
  cout<<" --> Starting Runge-Kutta track propogator"<<endl;
  double cl = 2.99792458E+10;  // CGS system
  double ee = 4.80320451E-10;  // CGS system
  double dt;   // step size for Runge-Kutta propagator. Will be calculated later, by dz
  double charge1 = -1.*ee;
  n_gr=0;

  double x_new=x0;
  double y_new=y0;
  double z_new=z0;

  double Px_new=px0*(1.6021773E-3)/cl;  // convertion from GeV to erg
  double Py_new=py0*(1.6021773E-3)/cl;  // convertion from GeV to erg
  double Pz_new=pz0*(1.6021773E-3)/cl;  // convertion from GeV to erg
  double P_new = sqrt((px0)*(px0) + (py0)*(py0) + (pz0)*(pz0))*(1.6021773E-3)/cl;
  double En = P_new*cl; // electron mass is neglected

  while ( (z_new<=z_max) && (z_new>=z_min) && (fabs(x_new)<x_max) && (fabs(y_new)<y_max) )
  {
//    cout<<z_new<<"     "<<P_new<<endl;
    double dz=0.002; // the dz step size (in cm) for the Runge-Kutta propogator
    dt=fabs(P_new/Pz_new)*dz/cl;
    vector<double> b = get_bfield(x_new, y_new, z_new);
//    if ( z_new > l_period*2.5 ) b = get_bfield(x_new, y_new, l_period*2.5 - (z_new - l_period*2.5) );
    TVector3 B_rot(b[0], b[1], b[2]);
//    if ( z_new > l_period*2.5 ) B_rot[1]=-1.*B_rot[1];
//    if ( z_new > l_period*2.5 ) B_rot[2]=-1.*B_rot[2];
    if (0)
    if (i_und==66730)
    if (fabs(z_new+10.)<1e-6)
    {
      double py_kick=-3.671e-3;
      double px_kick=-0.8558e-03;
//      double pz_changed=sqrt(1-py_kick*py_kick-px_kick*px_kick);
      Px_new+=px_kick*(1.6021773E-3)/cl;
      Py_new+=py_kick*(1.6021773E-3)/cl;
//      Pz_new=pz_changed*(1.6021773E-3)/cl;
      Pz_new=sqrt(P_new*P_new-Px_new*Px_new-Py_new*Py_new);
    }

    if (0)
    if (i_und==66730)
    if (fabs(z_new-270.)<1e-5)
    {
      double py_kick=3.671e-3;
      double px_kick=-0.8558e-03;
//      double pz_changed=sqrt(1-py_kick*py_kick-px_kick*px_kick);
      Px_new+=px_kick*(1.6021773E-3)/cl;
      Py_new+=py_kick*(1.6021773E-3)/cl;
      Pz_new=sqrt(P_new*P_new-Px_new*Px_new-Py_new*Py_new);
    }

    B_rot.RotateZ(rotation_angle);

    double Bx=B_rot[0];
    double By=B_rot[1];
    double Bz=B_rot[2];

    // in case of infinitely long undulator we don't want to interpolate the field between two neighbour positions at the end (between B=0 and B=0.15 Tesla)
    if ( ( (z_new>130.) || (z_new<0.0) ) && (i_und==2) )
    {
      Bx=0.;
      By=0.;
      Bz=0.;
    }

    if ( ( (z_new>140.) || (z_new<-10.) ) && (i_und==4) )
    {
      Bx=0.;
      By=0.;
      Bz=0.;
    }

    x_new+=cl*(Px_new/P_new)*dt;
    y_new+=cl*(Py_new/P_new)*dt;
    z_new+=cl*(Pz_new/P_new)*dt;
//    cout<<n_gr<<setw(15)<<x_new<<setw(15)<<y_new<<setw(15)<<z_new<<endl;
    Px_new+=FPx(charge1, cl, En, Bz, By, Py_new, Pz_new)*dt;
    Py_new+=FPy(charge1, cl, En, Bz, Bx, Px_new, Pz_new)*dt;
    Pz_new+=FPz(charge1, cl, En, Bx, By, Px_new, Py_new)*dt;
    x_gr[n_gr]=x_new*10.;
    y_gr[n_gr]=y_new*10.;
    z_gr[n_gr]=z_new*10.;
    bx_gr[n_gr]=Bx/1000.;
    by_gr[n_gr]=By/1000.;
    bz_gr[n_gr]=Bz/1000.;
    px_gr[n_gr]=Px_new/((1.6021773E-6)/cl);
    py_gr[n_gr]=Py_new/((1.6021773E-6)/cl);
    pz_gr[n_gr]=Pz_new/((1.6021773E-6)/cl);
    pt_gr[n_gr]=sqrt(px_gr[n_gr]*px_gr[n_gr]+py_gr[n_gr]*py_gr[n_gr]);
    n_gr++;
  }
}


void prepare_arrays(int nx, int ny, int nz)
{
  // this function will prepare the arrays with large sizes
  // make sure that the computer you are useing has enogh memory

  x_arr  =new double **[nx];
  y_arr  =new double **[nx];
  z_arr  =new double **[nx];
  bx_arr  =new double **[nx];
  by_arr  =new double **[nx];
  bz_arr  =new double **[nx];
  for(int i=0;i<nx;i++)
  {
    x_arr[i]   =new double *[ny];
    y_arr[i]   =new double *[ny];
    z_arr[i]   =new double *[ny];
    bx_arr[i]   =new double *[ny];
    by_arr[i]   =new double *[ny];
    bz_arr[i]   =new double *[ny];
    for (int j=0;j<ny;j++)
    {
      x_arr[i][j]   =new double [nz];
      y_arr[i][j]   =new double [nz];
      z_arr[i][j]   =new double [nz];
      bx_arr[i][j]   =new double [nz];
      by_arr[i][j]   =new double [nz];
      bz_arr[i][j]   =new double [nz];
      for (int k=0;k<nz;k++)
      {
         x_arr[i][j][k] = 0.0;
         y_arr[i][j][k] = 0.0;
         z_arr[i][j][k] = 0.0;
        bx_arr[i][j][k] = 0.0;
        by_arr[i][j][k] = 0.0;
        bz_arr[i][j][k] = 0.0;
      }
    }
  }
  cout<<" --> The arrays are ready to use"<<endl;
}


void read_field(string filename)
{
  //this function will reat the field map
  string line;
  ifstream myfile(filename.c_str(),ios::in);
  if (myfile.is_open())
  {
    clog<<" --> Loading B-field. File:"<<filename<<"   field scale:"<<k_scale<<endl;
    while (! myfile.eof() )
    {
      getline(myfile,line);
      if (line.size() > 90)
      {
        double x, y, z;
        double bx, by, bz;
        istringstream vars(line);
        vars>>x>>y>>z>>bx>>by>>bz;
        if (z+field_disp_z>=z_field_start)
          z=z+field_disp_z;
        int ix=int((x-x_field_start)/dx_field+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y-y_field_start)/dy_field+0.000000000001);
        int iz=int((z-z_field_start)/dz_field+0.000000000001);
        if ((x==0) && (y==0) && (z==0))
        if (1==2)
          cout<<setw(15)<<ix<<setw(15)<<iy<<setw(15)<<iz<<setw(15)<<x<<setw(15)<<y<<setw(15)<<z<<setw(15)<<bx<<setw(15)<<by<<setw(15)<<bz<<endl;

        x_arr[ix][iy][iz]=x;
        y_arr[ix][iy][iz]=y;
        z_arr[ix][iy][iz]=z;
/*
        if (z<0)
        {
          bx_arr[ix][iy][iz]=0.3*k_scale*bx;
          by_arr[ix][iy][iz]=0.3*k_scale*by;
          bz_arr[ix][iy][iz]=0.3*k_scale*bz;
        }
        else if (z<l_period*0.5)
        {
          double k_factor_new=0.3+0.7*z/(l_period*0.5);
          bx_arr[ix][iy][iz]=k_factor_new*k_scale*bx;
          by_arr[ix][iy][iz]=k_factor_new*k_scale*by;
          bz_arr[ix][iy][iz]=k_factor_new*k_scale*bz;
        }
        else if (z>5*l_period)
        {
          bx_arr[ix][iy][iz]=0.3*k_scale*bx;
          by_arr[ix][iy][iz]=0.3*k_scale*by;
          bz_arr[ix][iy][iz]=0.3*k_scale*bz;
        }
        else if (z>5*l_period-l_period*0.5)
        {
          double k_factor_new=0.3+0.7*(5*l_period-z)/(l_period*0.5);
          bx_arr[ix][iy][iz]=k_factor_new*k_scale*bx;
          by_arr[ix][iy][iz]=k_factor_new*k_scale*by;
          bz_arr[ix][iy][iz]=k_factor_new*k_scale*bz;
        }
        else

        {
*/
          TVector3 B_rot(k_scale*bx, k_scale*by, k_scale*bz);
          B_rot.RotateZ(field_rot_angle);

          bx_arr[ix][iy][iz]+=B_rot[0];
          by_arr[ix][iy][iz]+=B_rot[1];
          bz_arr[ix][iy][iz]+=B_rot[2];
//      }
      }
    }
    clog<<" --> The field is ready to use"<<endl;
  }
}



void read_field_first_half(string filename, double z_max)
{
  //this function will reat the field map
  string line;
  ifstream myfile(filename.c_str(),ios::in);
  if (myfile.is_open())
  {
    clog<<" --> Loading B-field"<<endl;
    while (! myfile.eof() )
    {
      getline(myfile,line);
      if (line.size() > 90)
      {
        double x, y, z;
        double bx, by, bz;
        istringstream vars(line);
        vars>>x>>y>>z>>bx>>by>>bz;
        int ix=int((x-x_field_start)/dx_field+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y-y_field_start)/dy_field+0.000000000001);
        int iz=int((z-z_field_start)/dz_field+0.000000000001);
        if ((x==0) && (y==0) && (z==0))
        if (1==2)
          cout<<setw(15)<<ix<<setw(15)<<iy<<setw(15)<<iz<<setw(15)<<x<<setw(15)<<y<<setw(15)<<z<<setw(15)<<bx<<setw(15)<<by<<setw(15)<<bz<<endl;
        if (z <= z_max)
        {
          x_arr[ix][iy][iz]=x;
          y_arr[ix][iy][iz]=y;
          z_arr[ix][iy][iz]=z;
          bx_arr[ix][iy][iz]=bx;
          by_arr[ix][iy][iz]=by;
          bz_arr[ix][iy][iz]=bz;
        }
      }
    }
    clog<<" --> The first half of the field is ready to use"<<endl;
  }
}


void read_field_last_half(string filename, double z_min)
{
  //this function will reat the field map
  string line;
  ifstream myfile(filename.c_str(),ios::in);
  if (myfile.is_open())
  {
    clog<<" --> Loading B-field"<<endl;
    while (! myfile.eof() )
    {
      getline(myfile,line);
      if (line.size() > 90)
      {
        double x, y, z;
        double bx, by, bz;
        istringstream vars(line);
        vars>>x>>y>>z>>bx>>by>>bz;
        z+=z_offset;
        int ix=int((x-x_field_start)/dx_field+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y-y_field_start)/dy_field+0.000000000001);
        int iz=int((z-z_field_start)/dz_field+0.000000000001);
        if ((x==0) && (y==0) && (z==0))
        if (1==2)
          cout<<setw(15)<<ix<<setw(15)<<iy<<setw(15)<<iz<<setw(15)<<x<<setw(15)<<y<<setw(15)<<z<<setw(15)<<bx<<setw(15)<<by<<setw(15)<<bz<<endl;
        if (z >= z_min)
        {
          TVector3 B_rot(bx, by, bz);
          B_rot.RotateZ(rotation_angle);

          x_arr[ix][iy][iz]=x;
          y_arr[ix][iy][iz]=y;
          z_arr[ix][iy][iz]=z;
          bx_arr[ix][iy][iz]=B_rot[0];
          by_arr[ix][iy][iz]=B_rot[1];
          bz_arr[ix][iy][iz]=B_rot[2];
        }
      }
    }
    clog<<" --> The last half of the field is ready to use"<<endl;
  }
}


vector<double> get_bfield(double x_loc, double y_loc, double z_loc)
{
  // linear interpolation between the "net" of the field
  vector<double> b;
  int ix=int((x_loc-x_field_start)/dx_field+0.000000000001);  //+0.1 is needed for the proper conversion double->int
  int iy=int((y_loc-y_field_start)/dy_field+0.000000000001);
  int iz=int((z_loc-z_field_start)/dz_field+0.000000000001);

  if(1)
  {
    double x1=x_arr[ix  ][iy  ][iz];
    double x2=x_arr[ix+1][iy  ][iz];
    double y1=y_arr[ix  ][iy  ][iz];
    double y2=y_arr[ix  ][iy+1][iz];
    double z1=z_arr[ix  ][iy  ][iz];
    double z2=z_arr[ix  ][iy  ][iz+1];

    double Bx_y1z1 = bx_arr[ix][iy][iz]   + ((bx_arr[ix+1][iy][iz]   - bx_arr[ix][iy][iz]  )/(x2-x1))*(x_loc - x1);
    double Bx_y2z1 = bx_arr[ix][iy+1][iz] + ((bx_arr[ix+1][iy+1][iz] - bx_arr[ix][iy+1][iz])/(x2-x1))*(x_loc - x1);
    double Bx_z1   = Bx_y1z1 + (y_loc-y1)*(Bx_y2z1-Bx_y1z1)/(y2-y1);
    double Bx_y1z2 = bx_arr[ix][iy][iz+1]   + ((bx_arr[ix+1][iy][iz+1]-bx_arr[ix][iy][iz+1])/(x2-x1))*(x_loc - x1);
    double Bx_y2z2 = bx_arr[ix][iy+1][iz+1] + ((bx_arr[ix+1][iy+1][iz+1]-bx_arr[ix][iy+1][iz+1])/(x2-x1))*(x_loc - x1);
    double Bx_z2   = Bx_y1z2 + (y_loc-y1)*(Bx_y2z2-Bx_y1z2)/(y2-y1);

    double Bx_z = Bx_z1 + (z_loc - z1)*(Bx_z2-Bx_z1)/(z2-z1);



    double By_y1z1 = by_arr[ix][iy][iz] + ((by_arr[ix+1][iy][iz]-by_arr[ix][iy][iz])/(x2-x1))*(x_loc - x1);
    double By_y2z1 = by_arr[ix][iy+1][iz] + ((by_arr[ix+1][iy+1][iz]-by_arr[ix][iy+1][iz])/(x2-x1))*(x_loc - x1);
    double By_z1   = By_y1z1 + (y_loc-y1)*(By_y2z1-By_y1z1)/(y2-y1);

    double By_y1z2 = by_arr[ix][iy][iz+1] + ((by_arr[ix+1][iy][iz+1]-by_arr[ix][iy][iz+1])/(x2-x1))*(x_loc - x1);
    double By_y2z2 = by_arr[ix][iy+1][iz+1] + ((by_arr[ix+1][iy+1][iz+1]-by_arr[ix][iy+1][iz+1])/(x2-x1))*(x_loc - x1);
    double By_z2   = By_y1z2 + (y_loc-y1)*(By_y2z2-By_y1z2)/(y2-y1);

    double By_z = By_z1 + (z_loc - z1)*(By_z2-By_z1)/(z2-z1);



    double Bz_y1z1 = bz_arr[ix][iy][iz] + ((bz_arr[ix+1][iy][iz]-bz_arr[ix][iy][iz])/(x2-x1))*(x_loc - x1);
    double Bz_y2z1 = bz_arr[ix][iy+1][iz] + ((bz_arr[ix+1][iy+1][iz]-bz_arr[ix][iy+1][iz])/(x2-x1))*(x_loc - x1);
    double Bz_z1   = Bz_y1z1 + (y_loc-y1)*(Bz_y2z1-Bz_y1z1)/(y2-y1);

    double Bz_y1z2 = bz_arr[ix][iy][iz+1] + ((bz_arr[ix+1][iy][iz+1]-bz_arr[ix][iy][iz+1])/(x2-x1))*(x_loc - x1);
    double Bz_y2z2 = bz_arr[ix][iy+1][iz+1] + ((bz_arr[ix+1][iy+1][iz+1]-bz_arr[ix][iy+1][iz+1])/(x2-x1))*(x_loc - x1);
    double Bz_z2   = Bz_y1z2 + (y_loc-y1)*(Bz_y2z2-Bz_y1z2)/(y2-y1);

    double Bz_z = Bz_z1 + (z_loc - z1)*(Bz_z2-Bz_z1)/(z2-z1);


    b.push_back(Bx_z);
    b.push_back(By_z);
    b.push_back(Bz_z);
  }
  return b;
}

// below are functions used by Runge-Kutta. In principal could be used only one of these

double FPx(double charge, double c, double E, double Bz, double By, double Py, double Pz)
{
  return (c*charge/E)*(Py*Bz-Pz*By);
}

double FPy(double charge, double c, double E, double Bz, double Bx, double Px, double Pz)
{
  return (c*charge/E)*(Pz*Bx-Px*Bz);
}

double FPz(double charge, double c, double E, double Bx, double By, double Px, double Py)
{
  return (c*charge/E)*(Px*By-Py*Bx);
}

void make_plots()
{
  cout<<" --> Making plots"<<endl;
  TGraph *gr_xy = new TGraph(n_gr, x_gr, y_gr);

  TGraph *gr_x = new TGraph(n_gr, z_gr, x_gr);
  TGraph *gr_y = new TGraph(n_gr, z_gr, y_gr);
  TGraph *gr_z = new TGraph(n_gr, z_gr, z_gr);
  TGraph *gr_bx = new TGraph(n_gr, z_gr, bx_gr);
  TGraph *gr_by = new TGraph(n_gr, z_gr, by_gr);
  TGraph *gr_bz = new TGraph(n_gr, z_gr, bz_gr);
  TGraph *gr_px = new TGraph(n_gr, z_gr, px_gr);
  TGraph *gr_py = new TGraph(n_gr, z_gr, py_gr);
  TGraph *gr_pz = new TGraph(n_gr, z_gr, pz_gr);
  TGraph *gr_pt = new TGraph(n_gr, z_gr, pt_gr);
//  gr_xy->SetMarkerStyle(1);
  gr_y->SetMarkerStyle(7);
  gr_x->SetMarkerStyle(7);
  gr_z->SetMarkerStyle(7);
  gr_by->SetMarkerStyle(7);
  gr_bx->SetMarkerStyle(7);
  gr_bz->SetMarkerStyle(7);
  gr_py->SetMarkerStyle(7);
  gr_px->SetMarkerStyle(7);
  gr_pz->SetMarkerStyle(7);
  gr_pt->SetMarkerStyle(7);
  double d_phi=TMath::Pi()/32.;
/*
  gr_x->SetTitle(Form("x vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_y->SetTitle(Form("y vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_z->SetTitle(Form("z vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_bx->SetTitle(Form("bx vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_by->SetTitle(Form("by vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_bz->SetTitle(Form("bz vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_px->SetTitle(Form("px vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_py->SetTitle(Form("py vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
  gr_pz->SetTitle(Form("pz vs z (rotation angle is %.1f/32#upoint#pi)", rotation_angle/d_phi));
*/
  if (fabs(rotation_angle)>1.e-9)
  {
    gr_xy->SetTitle(Form("y vs x (rotation angle is %.2f rad)", rotation_angle));
    gr_x->SetTitle(Form("x vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_y->SetTitle(Form("y vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_z->SetTitle(Form("z vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_bx->SetTitle(Form("bx vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_by->SetTitle(Form("by vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_bz->SetTitle(Form("bz vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_px->SetTitle(Form("px vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_py->SetTitle(Form("py vs z (rotation angle is %.2f rad)", rotation_angle));
    gr_pz->SetTitle(Form("pz vs z (rotation angle is %.2f rad)", rotation_angle));
  }
  else
  {
    gr_xy->SetTitle(Form("y vs x"));
    gr_x->SetTitle(Form("x vs z"));
    gr_y->SetTitle(Form("y vs z"));
    gr_z->SetTitle(Form("z vs z"));
    gr_bx->SetTitle(Form("bx vs z"));
    gr_by->SetTitle(Form("by vs z"));
    gr_bz->SetTitle(Form("bz vs z"));
    gr_px->SetTitle(Form("px vs z"));
    gr_py->SetTitle(Form("py vs z"));
    gr_pz->SetTitle(Form("pz vs z"));
    gr_pt->SetTitle(Form("pt vs z"));
  }


  gr_xy->GetXaxis()->SetTitle("x [mm]");
  gr_x->GetXaxis()->SetTitle("z [mm]");
  gr_y->GetXaxis()->SetTitle("z [mm]");
  gr_z->GetXaxis()->SetTitle("z [mm]");
  gr_bx->GetXaxis()->SetTitle("z [mm]");
  gr_by->GetXaxis()->SetTitle("z [mm]");
  gr_bz->GetXaxis()->SetTitle("z [mm]");
  gr_px->GetXaxis()->SetTitle("z [mm]");
  gr_py->GetXaxis()->SetTitle("z [mm]");
  gr_pz->GetXaxis()->SetTitle("z [mm]");
  gr_pt->GetXaxis()->SetTitle("z [mm]");

  gr_xy->GetYaxis()->SetTitle("y [mm]");
  gr_x->GetYaxis()->SetTitle("x [mm]");
  gr_y->GetYaxis()->SetTitle("y [mm]");
  gr_z->GetYaxis()->SetTitle("z [mm]");
  gr_bx->GetYaxis()->SetTitle("Bx [kGaus]");
  gr_by->GetYaxis()->SetTitle("By [kGaus]");
  gr_bz->GetYaxis()->SetTitle("Bz [kGaus]");
  gr_px->GetYaxis()->SetTitle("px [MeV]");
  gr_py->GetYaxis()->SetTitle("py [MeV]");
  gr_pz->GetYaxis()->SetTitle("pz [MeV]");
  gr_pt->GetYaxis()->SetTitle("pt [MeV]");

  gr_xy->GetXaxis()->SetTitleSize(0.05);
  gr_x->GetXaxis()->SetTitleSize(0.05);
  gr_y->GetXaxis()->SetTitleSize(0.05);
  gr_z->GetXaxis()->SetTitleSize(0.05);
  gr_bx->GetXaxis()->SetTitleSize(0.05);
  gr_by->GetXaxis()->SetTitleSize(0.05);
  gr_bz->GetXaxis()->SetTitleSize(0.05);
  gr_px->GetXaxis()->SetTitleSize(0.05);
  gr_py->GetXaxis()->SetTitleSize(0.05);
  gr_pz->GetXaxis()->SetTitleSize(0.05);
  gr_pt->GetXaxis()->SetTitleSize(0.05);

  gr_xy->GetXaxis()->SetLabelSize(0.05);
  gr_x->GetXaxis()->SetLabelSize(0.05);
  gr_y->GetXaxis()->SetLabelSize(0.05);
  gr_z->GetXaxis()->SetLabelSize(0.05);
  gr_bx->GetXaxis()->SetLabelSize(0.05);
  gr_by->GetXaxis()->SetLabelSize(0.05);
  gr_bz->GetXaxis()->SetLabelSize(0.05);
  gr_px->GetXaxis()->SetLabelSize(0.05);
  gr_py->GetXaxis()->SetLabelSize(0.05);
  gr_pz->GetXaxis()->SetLabelSize(0.05);
  gr_pt->GetXaxis()->SetLabelSize(0.05);

  gr_xy->GetXaxis()->SetTitleOffset(0.97);
  gr_x->GetXaxis()->SetTitleOffset(0.97);
  gr_y->GetXaxis()->SetTitleOffset(0.97);
  gr_z->GetXaxis()->SetTitleOffset(0.97);
  gr_bx->GetXaxis()->SetTitleOffset(0.97);
  gr_by->GetXaxis()->SetTitleOffset(0.97);
  gr_bz->GetXaxis()->SetTitleOffset(0.97);
  gr_px->GetXaxis()->SetTitleOffset(0.97);
  gr_py->GetXaxis()->SetTitleOffset(0.97);
  gr_pz->GetXaxis()->SetTitleOffset(0.97);
  gr_pt->GetXaxis()->SetTitleOffset(0.97);

  gr_xy->GetYaxis()->SetTitleSize(0.05);
  gr_x->GetYaxis()->SetTitleSize(0.05);
  gr_y->GetYaxis()->SetTitleSize(0.05);
  gr_z->GetYaxis()->SetTitleSize(0.05);
  gr_bx->GetYaxis()->SetTitleSize(0.05);
  gr_by->GetYaxis()->SetTitleSize(0.05);
  gr_bz->GetYaxis()->SetTitleSize(0.05);
  gr_px->GetYaxis()->SetTitleSize(0.05);
  gr_py->GetYaxis()->SetTitleSize(0.05);
  gr_pz->GetYaxis()->SetTitleSize(0.05);
  gr_pt->GetYaxis()->SetTitleSize(0.05);

  gr_xy->GetYaxis()->SetTitleOffset(0.998);
  gr_x->GetYaxis()->SetTitleOffset(0.998);
  gr_y->GetYaxis()->SetTitleOffset(0.998);
  gr_z->GetYaxis()->SetTitleOffset(0.998);
  gr_bx->GetYaxis()->SetTitleOffset(0.998);
  gr_by->GetYaxis()->SetTitleOffset(0.998);
  gr_bz->GetYaxis()->SetTitleOffset(0.998);
  gr_px->GetYaxis()->SetTitleOffset(0.998);
  gr_py->GetYaxis()->SetTitleOffset(0.998);
  gr_pz->GetYaxis()->SetTitleOffset(0.998);
  gr_pt->GetYaxis()->SetTitleOffset(0.998);

  gr_xy->GetYaxis()->SetLabelSize(0.05);
  gr_x->GetYaxis()->SetLabelSize(0.05);
  gr_y->GetYaxis()->SetLabelSize(0.05);
  gr_z->GetYaxis()->SetLabelSize(0.05);
  gr_bx->GetYaxis()->SetLabelSize(0.05);
  gr_by->GetYaxis()->SetLabelSize(0.05);
  gr_bz->GetYaxis()->SetLabelSize(0.05);
  gr_px->GetYaxis()->SetLabelSize(0.05);
  gr_py->GetYaxis()->SetLabelSize(0.05);
  gr_pz->GetYaxis()->SetLabelSize(0.05);
  gr_pt->GetYaxis()->SetLabelSize(0.05);


//  cout<<"600  "<< get_i_from_z(600.)<<endl;
//  cout<<"925  "<< get_i_from_z(925.)<<endl;


  int i1_start_tmp=get_i_from_z(-400+1.e-7);
  int i2_start_tmp=get_i_from_z(4900+1.e-7);
  cout<<"index1="<<i1_start_tmp<<endl;
  cout<<"z(-0.4m)="<<z_gr[i1_start_tmp]<<" mm"<<endl;
  cout<<"x(-0.4m)="<<x_gr[i1_start_tmp]<<" mm,            x(-0.4m)-y(-100cm)="<<x_gr[i1_start_tmp]-10*x_init_tmp<<" mm"<<endl;
  cout<<"y(-0.4m)="<<y_gr[i1_start_tmp]<<" mm,            y(-0.4m)-y(-100cm)="<<y_gr[i1_start_tmp]-10*y_init_tmp<<" mm"<<endl;
  cout<<"px(-0.4m)="<<px_gr[i1_start_tmp]<<" MeV"<<endl;
  cout<<"py(-0.4m)="<<py_gr[i1_start_tmp]<<" MeV"<<endl;

  cout<<"index2="<<i2_start_tmp<<endl;
  cout<<"z(4.9m)="<<z_gr[i2_start_tmp]<<" mm"<<endl;
  cout<<"x(4.9m)="<<x_gr[i2_start_tmp]<<" mm,            x(4.9m)-y(-100cm)="<<x_gr[i2_start_tmp]-10*x_init_tmp<<" mm"<<endl;
  cout<<"y(4.9m)="<<y_gr[i2_start_tmp]<<" mm,            y(4.9m)-y(-100cm)="<<y_gr[i2_start_tmp]-10*y_init_tmp<<" mm"<<endl;
  cout<<"px(4.9m)="<<px_gr[i2_start_tmp]<<" MeV"<<endl;
  cout<<"py(4.9m)="<<py_gr[i2_start_tmp]<<" MeV"<<endl;


  int i1_tmp=get_i_from_z((n_period/2-0.5)*10.*l_period+1.e-7);
  int i2_tmp=get_i_from_z((n_period/2+0.5)*10.*l_period+1.e-7);
  if (n_period>10)
  {
    i1_tmp=get_i_from_z(3*10.*l_period+1.e-7);
    i2_tmp=get_i_from_z((n_period-3)*10.*l_period+1.e-7);
  }
  int j1_tmp=get_i_from_z((n_period/2-1)*10.*l_period+1.e-7);
  int j2_tmp=get_i_from_z((n_period/2)*10.*l_period+1.e-7);
  j1_tmp=i1_tmp;
  j2_tmp=i2_tmp;
 double k=1./10.*l_period;


  TF1 * func1 = new TF1("func1", "[0]*sin([1]*x-[2])+[3]", 1200., 1725.);
  func1->SetParLimits(0, 0.051, 10);
  func1->SetParLimits(1, 0.98*2.*pi*k, 1.02*2.*pi*k);
  func1->SetParLimits(2, -1.*pi, pi);
  func1->SetParLimits(3, 0.0, 0.5);

  func1->SetParName(0, "Amp");
  func1->SetParName(1, "k");
  func1->SetParName(2, "#Delta#phi");
  func1->SetParName(3, "offset");

  double dx=0;
  double dy=0;
  double dzx=0;
  double dzy=0;
  double sum_x=0;
  double sum_y=0;
  if (i1_tmp != -1)
  if (i2_tmp != -1)
  {
    dx=x_gr[j2_tmp]-x_gr[j1_tmp];
    cout<<" x="<<x_gr[j1_tmp]<<"     "<<x_gr[j2_tmp]<<endl;
    cout<<" y="<<y_gr[i1_tmp]<<"     "<<y_gr[i2_tmp]<<endl;
    cout<<" z="<<z_gr[i1_tmp]<<"     "<<z_gr[i2_tmp]<<endl;
    int nsum=0;
    for (int ii=i1_tmp; ii<i2_tmp; ii++)
    {
      sum_x+=x_gr[ii];
      sum_y+=y_gr[ii];
      nsum++;
    }
    sum_x/=double(nsum);
    sum_y/=double(nsum);
    dy=y_gr[i2_tmp]-y_gr[i1_tmp];
    dzx=z_gr[j2_tmp]-z_gr[j1_tmp];
    dzy=z_gr[i2_tmp]-z_gr[i1_tmp];
  }
  cout<<"mean_x="<<sum_x<<"    mean_y="<<sum_y<<endl;


  cc->cd(1);
  gr_x->Draw("AP");
//  gr_x->Fit(func1, "R");
  if (dzx!=0)
  {
    TLatex *text1_angle = new TLatex(0., sum_x-0.2, Form("x' = %.6f mrad", dx/dzx*1000.) );
    text1_angle->SetTextAlign(12);
    text1_angle->SetTextColor(4);
    text1_angle->SetTextSize(0.07);
    text1_angle->Draw();
    ofstream outfile;
    outfile.open("res.txt", ios::out | ios::app );
    outfile<<i_und<<"    x'="<<dx/dzx*1000.<<"    y'="<<dy/dzy*1000.<<endl;
    outfile.close();
    cout<<"radiation angle x'="<<dx/dzx*1000.<<" mrad,   y'="<<dy/dzy*1000.<<endl;
/*
    TLatex *text1_offset = new TLatex(0., sum_x, Form("x_{cent} = %.8f mm", sum_x) );
    text1_offset->SetTextAlign(12);
    text1_offset->SetTextColor(4);
    text1_offset->SetTextSize(0.06);
    text1_offset->Draw();
*/
/*
    TLine *line1 = new TLine(571.8945,0.4843582,2149.384,0.4798904);
    line1->SetLineColor(2);
    line1->SetLineWidth(2);
    line1->Draw();
*/
  }

  cc->cd(1+div_nx);
  gr_y->Draw("AP");
//  gr_y->Fit(func1, "R");
  if (dzx!=0)
  {
//    TLatex *text2_angle = new TLatex(900., y_gr[i2_tmp], Form("y' = %.3f mrad", dy/dz*1000.) );
    TLatex *text2_angle = new TLatex(0., sum_y+0.2, Form("y' = %.6f mrad", dy/dzy*1000.) );
    text2_angle->SetTextAlign(12);
    text2_angle->SetTextColor(4);
    text2_angle->SetTextSize(0.07);
    text2_angle->Draw();

/*
    TLatex *text2_offset = new TLatex(0., sum_y, Form("y_{cent} = %.8f mm", sum_y) );
    text2_offset->SetTextAlign(12);
    text2_offset->SetTextColor(4);
    text2_offset->SetTextSize(0.06);
    text2_offset->Draw();
*/
/*
    TLine *line2 = new TLine(308.9796,0.2290919,2226.712,0.2465697);
    line2->SetLineColor(2);
    line2->SetLineWidth(2);
    line2->Draw();
*/
  }

  cc->cd(1+2*div_nx);
  gr_z->Draw("AP");

  cc->cd(2);
  gr_bx->Draw("AP");

  cc->cd(2+div_nx);
  gr_by->Draw("AP");

  cc->cd(2+2*div_nx);
  gr_bz->Draw("AP");

  cc->cd(3);
  gr_px->Draw("AP");
  TLatex *text1 = new TLatex(n_period*10.*l_period, 1.0, Form("p_{x} = %.6f MeV", px_gr[n_gr-3] ) );
  text1->Draw();

  cc->cd(3+div_nx);
  gr_py->Draw("AP");
  TLatex *text2 = new TLatex(n_period*10.*l_period, 1.0, Form("p_{y} = %.6f MeV", py_gr[n_gr-3] ) );
  text2->Draw();

  cc->cd(3+2*div_nx);
  gr_pz->Draw("AP");
//  gr_pt->Draw("AP");

//  cc->Print("results_RK.pdf");
//  cc->SaveAs(Form("tmp_%.1f.gif", rotation_angle/d_phi));


  TGraph2D *gr_zxy = new TGraph2D(n_gr, z_gr, x_gr, y_gr);
  gr_zxy->SetMarkerStyle(20);
  cc->cd(1+2*div_nx);
  gr_zxy->Draw("*P");
  gr_xy->SetMarkerStyle(7);
  gr_xy->Draw("AP");
/*
  TGraph2D *gr_zpxy = new TGraph2D(n_gr, z_gr, px_gr, py_gr);
  gr_zpxy->SetMarkerStyle(20);
  cc->cd(3+2*div_nx);
  gr_zpxy->Draw("*P");
*/
  cc->SaveAs(Form("gif/tracks/%d_autosave.gif", i_und));
}

int get_i_from_z(double zz_tmp)
{
  for (int i=0; i<n_gr; i++)
  {
    if (fabs(z_gr[i]-zz_tmp)<1.e-4 ) return i;
//    cout<<i<<"    "<<zz_tmp<<"     "<<z_gr[i]<<"     "<<fabs(z_gr[i]-zz_tmp)<<endl;
  }
  return -1;
}

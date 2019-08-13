#include "track_part_hel_und.h"

using namespace std;

void gen_field(int, int, int);

void field_convert_SRW()
{
  pi=acos(-1.);
  n_period=14;
  nx=101; //field map divisions in x direction
  ny=101; //field map divisions in y direction
  nz=10001; //field map divisions in z direction
  x_field_start=-5.;    // the lower edge of the field map. The field can start at any place after this edge (x_field>x_field_start)
  y_field_start=-5.;    // the lower edge of the field map. The field can start at any place after this edge (y_field>y_field_start)
  z_field_start=-200.;  // the lower edge of the field map. The field can start at any place after this edge (z_field>z_field_start)
  dx_field=0.1;         // field map step size in mm-s
  dy_field=0.1;         // field map step size in mm-s
  dz_field=0.2;         // field map step size in mm-s
  field_disp_z=0.;      // displacement of the field to be read next
  field_rot_angle=0.;   // rotation of the field to be read next

  prepare_arrays(nx, ny, nz);  // this will prepare arrays with dimensions nx, ny and nz in agreement with the field map
  k_scale=1.;
  i_und=853861;
  int op3_cur=228;
  if (i_und==85501)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1482.61;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=k_scale_tmp*14.452;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.42*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.20*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.155*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==8556)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1482.92;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.487*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.435*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.095*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.005*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==8540)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1497.36;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.627*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.59*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.11*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.14*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85331)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1499.65;
    double k_scale_tmp=k_scale;

    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
/*
    x_init=-0.05;
    y_init=0.306;
    px_init=0.508e-3;
    py_init=-3.066e-3;
    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
*/

    k_scale=15.524*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-15.907*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=2.62*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=2.70*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85321)
  {
/*
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
    x_init=-0.05;
    y_init=0.306;
    px_init=0.508e-3;
    py_init=-3.066e-3;
    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
*/
  }
  else if (i_und==8535)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1497.77;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=15.65*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-15.792*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=2.67*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=2.50*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85361)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1493.06;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.479*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.482*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.06*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.10*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85381)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1493.59;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
/*
    k_scale=14.539;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.32;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=0.01;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=0.025;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
*/

    k_scale=14.629*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.222*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=0.18*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=0.19*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
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
    field_disp_z=14.*32.5+5;
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
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }
  else if (i_und==85382)
  {
//    k_scale=339/401.;
//    x_init=-0.0276;
//    y_init=-0.0363;
    k_scale=1500./1493.68;
    double k_scale_tmp=k_scale;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=14.494*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-14.515*k_scale_tmp;
    i_und=107;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));


    k_scale=-0.085*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=15;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));

    k_scale=-0.172*k_scale_tmp;
    i_und=107;
    field_rot_angle=pi/2.;
    op3_cur=795;
    field_disp_z=14.*32.5+5;
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
    field_disp_z=14.*32.5+5;
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
    field_disp_z=14.*32.5+5;
    read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }

  gen_field(nx, ny, nz);  // this will prepare arrays with dimensions nx, ny and nz in agreement with the field map
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

void gen_field(int nx, int ny, int nz)
{
  // this function will prepare the arrays with large sizes
  // make sure that the computer you are useing has enogh memory
  ofstream outt("SRW_field.dat");
  for(int i=0;i<nx;i++)
  {
    for (int j=0;j<ny;j++)
    {
      for (int k=0;k<nz;k++)
      {
        if ( (fabs(bx_arr[i][j][k])+fabs(by_arr[i][j][k])+fabs(bz_arr[i][j][k]))>1.e-10 )
        if ( fabs(x_arr[i][j][k])<=0.55 )
        if ( fabs(y_arr[i][j][k])<=0.55 )
        if ( z_arr[i][j][k]>=-100. )
        if ( z_arr[i][j][k]<=(32.5*n_period+100) )
          outt<<fixed<<setprecision(7)<<setw(16)<<x_arr[i][j][k]<<setw(16)<<y_arr[i][j][k]<<setw(16)<<z_arr[i][j][k]<<setprecision(14)<<setw(25)<<bx_arr[i][j][k]<<setw(25)<<by_arr[i][j][k]<<setw(25)<<bz_arr[i][j][k]<<endl;
//          outt<<fixed<<setprecision(14)<<setw(25)<<bx_arr[i][j][k]<<setw(25)<<by_arr[i][j][k]<<setw(25)<<bz_arr[i][j][k]<<endl;
      }
    }
  }
  outt.close();
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
        TVector3 B_rot(k_scale*bx, k_scale*by, k_scale*bz);
        B_rot.RotateZ(field_rot_angle);

        bx_arr[ix][iy][iz]+=B_rot[0];
        by_arr[ix][iy][iz]+=B_rot[1];
        bz_arr[ix][iy][iz]+=B_rot[2];
      }
    }
    clog<<" --> The field is ready to use"<<endl;
  }
}


/*
void read_field(string filename)
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
        int ix=int((x+5.0)/0.1+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y+5.0)/0.1+0.000000000001);
        int iz=int((z-z_field_start)/0.2+0.000000000001);
        if ((x==0) && (y==0) && (z==0))
        if (1==2)
          cout<<setw(15)<<ix<<setw(15)<<iy<<setw(15)<<iz<<setw(15)<<x<<setw(15)<<y<<setw(15)<<z<<setw(15)<<bx<<setw(15)<<by<<setw(15)<<bz<<endl;
        x_arr[ix][iy][iz]=x;
        y_arr[ix][iy][iz]=y;
        z_arr[ix][iy][iz]=z;
        bx_arr[ix][iy][iz]=k_scale*bx;
        by_arr[ix][iy][iz]=k_scale*by;
        bz_arr[ix][iy][iz]=k_scale*bz;
      }
    }
    clog<<" --> The field is ready to use"<<endl;
  }
}
*/






int get_i_from_z(double zz_tmp)
{
  for (int i=0; i<n_gr; i++)
  {
    if (fabs(z_gr[i]-zz_tmp)<1.e-4 ) return i;
//    cout<<i<<"    "<<zz_tmp<<"     "<<z_gr[i]<<"     "<<fabs(z_gr[i]-zz_tmp)<<endl;
  }
  return -1;
}

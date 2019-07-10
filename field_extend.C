#include "field_extend.h"

using namespace std;
double pi=acos(-1.);

void gen_extended_field(int, int, int);
double n_new_turns;  // how many turns to be added
double period_l;     // period length
double start_point;  // where we start adding new turns
double dz_step;

void field_extend()
{
  n_new_turns=9;
  period_l=32.5;
  start_point=32.5*3;
  dz_step=0.1;

  nx=11; //field map divisions in x direction
  ny=11; //field map divisions in y direction
  nz=10001; //field map divisions in z direction
  nz1=3701+32.5*n_new_turns/dz_step; //field map divisions in z direction


  x_field_start=-0.5;
  y_field_start=-0.5;
  z_field_start=-100.;
  i_und=85331;


  prepare_arrays(nx, ny, nz);  // this will prepare arrays with dimensions nx, ny and nz in agreement with the field map
  k_scale=1.;
  read_field(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_228_xyz.table", i_und));
//  read_field("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_8540_228_xyz.table");
  gen_extended_field(nx, ny, nz1);  // this will prepare arrays with dimensions nx, ny and nz in agreement with the field map
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

   x_arr1  =new double **[nx];
   y_arr1  =new double **[nx];
   z_arr1  =new double **[nx];
  bx_arr1  =new double **[nx];
  by_arr1  =new double **[nx];
  bz_arr1  =new double **[nx];
  for(int i=0;i<nx;i++)
  {
     x_arr1[i]   =new double *[ny];
     y_arr1[i]   =new double *[ny];
     z_arr1[i]   =new double *[ny];
    bx_arr1[i]   =new double *[ny];
    by_arr1[i]   =new double *[ny];
    bz_arr1[i]   =new double *[ny];
    for (int j=0;j<ny;j++)
    {
       x_arr1[i][j]   =new double [nz];
       y_arr1[i][j]   =new double [nz];
       z_arr1[i][j]   =new double [nz];
      bx_arr1[i][j]   =new double [nz];
      by_arr1[i][j]   =new double [nz];
      bz_arr1[i][j]   =new double [nz];
      for (int k=0;k<nz;k++)
      {
         x_arr1[i][j][k] = 0.0;
         y_arr1[i][j][k] = 0.0;
         z_arr1[i][j][k] = 0.0;
        bx_arr1[i][j][k] = 0.0;
        by_arr1[i][j][k] = 0.0;
        bz_arr1[i][j][k] = 0.0;
      }
    }
  }


  cout<<" --> The arrays are ready to use"<<endl;
}

void gen_extended_field(int nx, int ny, int nzx)
{
  // this function will prepare the arrays with large sizes
  // make sure that the computer you are useing has enogh memory
  ofstream outt(Form("hundulator_%d_228_xyz_gen.table", i_und));
//  cout<<"nz="<<nz<<endl;
//  nz=nz+int(n_new_turns*period_l/dz_step);
  cout<<"nz="<<nz<<endl;
  for(int i=0;i<nx;i++)
  {
    for (int j=0;j<ny;j++)
    {
      for (int k=0;k<nzx;k+=2)
      {
//        if ( (fabs(bx_arr1[i][j][k])+fabs(by_arr1[i][j][k])+fabs(bz_arr1[i][j][k]))>1.e-10)
//        if ( z_arr1[i][j][k]>=-100.)
//        if ( z_arr1[i][j][k]<=360)
//          outt<<i<<setw(5)<<j<<setw(5)<<k<<fixed<<setprecision(7)<<setw(16)<<x_arr1[i][j][k]<<setw(16)<<y_arr1[i][j][k]<<setw(16)<<z_arr1[i][j][k]<<setprecision(14)<<setw(25)<<bx_arr1[i][j][k]<<setw(25)<<by_arr1[i][j][k]<<setw(25)<<bz_arr1[i][j][k]<<endl;
          outt<<fixed<<setprecision(7)<<setw(16)<<x_arr1[i][j][k]<<setw(16)<<y_arr1[i][j][k]<<setw(16)<<z_arr1[i][j][k]<<setprecision(14)<<setw(25)<<bx_arr1[i][j][k]<<setw(25)<<by_arr1[i][j][k]<<setw(25)<<bz_arr1[i][j][k]<<endl;
      }
    }
  }
  cout<<"generated"<<endl;
  outt.close();
}


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
        int ix=int((x-x_field_start)/0.1+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y-y_field_start)/0.1+0.000000000001);
        int iz=int((z-z_field_start)/dz_step+0.000000000001);
        if ((x==0) && (y==0) && (z==0))
        if (1==2)
          cout<<setw(15)<<ix<<setw(15)<<iy<<setw(15)<<iz<<setw(15)<<x<<setw(15)<<y<<setw(15)<<z<<setw(15)<<bx<<setw(15)<<by<<setw(15)<<bz<<endl;
        x_arr[ix][iy][iz]=x;
        y_arr[ix][iy][iz]=y;
        z_arr[ix][iy][iz]=z;
        bx_arr[ix][iy][iz]=k_scale*bx;
        by_arr[ix][iy][iz]=k_scale*by;
        bz_arr[ix][iy][iz]=k_scale*bz;


        if ( (z >= start_point-period_l) && (z<=start_point) )
        {
          double i_tmp=1;
          while (i_tmp < n_new_turns+0.5)
          {
            int iz1=iz+int((i_tmp*period_l)/dz_step+0.000000000001);
            double z1=z+i_tmp*period_l;
//            if (int(i_tmp+0.1)%2==1) z1-=0.1;
            x_arr1[ix][iy][iz1]=x;
            y_arr1[ix][iy][iz1]=y;
            z_arr1[ix][iy][iz1]=z1;
//            cout<<setw(15)<<ix<<setw(15)<<iy<<setw(15)<<iz1<<setw(15)<<x<<setw(15)<<y<<setw(15)<<z<<setw(15)<<z1<<setw(15)<<bx<<setw(15)<<by<<setw(15)<<bz<<endl;
            bx_arr1[ix][iy][iz1]=k_scale*bx;
            by_arr1[ix][iy][iz1]=k_scale*by;
            bz_arr1[ix][iy][iz1]=k_scale*bz;
            i_tmp+=1.;
          }
        }

        if (z > start_point)
        {
          int iz1=iz+int((n_new_turns*period_l)/dz_step+0.000000000001);
          z=z+n_new_turns*period_l;
          x_arr1[ix][iy][iz1]=x;
          y_arr1[ix][iy][iz1]=y;
          z_arr1[ix][iy][iz1]=z;
          bx_arr1[ix][iy][iz1]=k_scale*bx;
          by_arr1[ix][iy][iz1]=k_scale*by;
          bz_arr1[ix][iy][iz1]=k_scale*bz;
        }
        else
        {
          x_arr1[ix][iy][iz]=x;
          y_arr1[ix][iy][iz]=y;
          z_arr1[ix][iy][iz]=z;
          bx_arr1[ix][iy][iz]=k_scale*bx;
          by_arr1[ix][iy][iz]=k_scale*by;
          bz_arr1[ix][iy][iz]=k_scale*bz;
        }
      }
    }
    clog<<" --> The field is ready to use"<<endl;
  }
}



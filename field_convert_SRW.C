#include "track_part_hel_und.h"

using namespace std;
double pi=acos(-1.);

void gen_field(int, int, int);

void field_convert_SRW()
{
  nx=101; //field map divisions in x direction
  ny=101; //field map divisions in y direction
  nz=4001; //field map divisions in z direction
  z_field_start=-200.;

  prepare_arrays(nx, ny, nz);  // this will prepare arrays with dimensions nx, ny and nz in agreement with the field map
  k_scale=1.;
  i_und=5520;
  if (i_und==5520)
  {
    read_field("../v9_4_many_xare/hundulator_66730_450_xyz.table");
//    read_field("field_extended.dat");
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
  for (int k=0;k<nz;k++)
  {
    for (int j=0;j<ny;j++)
    {
      for(int i=0;i<nx;i++)
      {
        if ( (fabs(bx_arr[i][j][k])+fabs(by_arr[i][j][k])+fabs(bz_arr[i][j][k]))>1.e-10)
//        if ( x_arr[i][j][k]==0.)
//        if ( y_arr[i][j][k]==0.)
        if ( z_arr[i][j][k]>=-100.)
        if ( z_arr[i][j][k]<=(260+100))
//          outt<<fixed<<setprecision(7)<<setw(16)<<x_arr[i][j][k]<<setw(16)<<y_arr[i][j][k]<<setw(16)<<z_arr[i][j][k]<<setprecision(14)<<setw(25)<<bx_arr[i][j][k]<<setw(25)<<by_arr[i][j][k]<<setw(25)<<bz_arr[i][j][k]<<endl;
          outt<<fixed<<setprecision(14)<<setw(25)<<bx_arr[i][j][k]<<setw(25)<<by_arr[i][j][k]<<setw(25)<<bz_arr[i][j][k]<<endl;
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




vector<double> get_bfield(double x_loc, double y_loc, double z_loc)
{
  // linear interpolation between the "net" of the field
  vector<double> b;
  int ix=int((x_loc+5.0)/0.1+0.000000000001);  //+0.1 is needed for the proper conversion double->int
  int iy=int((y_loc+5.0)/0.1+0.000000000001);
  int iz=int((z_loc-z_field_start)/0.2+0.000000000001);

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

int get_i_from_z(double zz_tmp)
{
  for (int i=0; i<n_gr; i++)
  {
    if (fabs(z_gr[i]-zz_tmp)<1.e-4 ) return i;
//    cout<<i<<"    "<<zz_tmp<<"     "<<z_gr[i]<<"     "<<fabs(z_gr[i]-zz_tmp)<<endl;
  }
  return -1;
}

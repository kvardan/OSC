#include "track_part_hel_und.h"

using namespace std;
double pi=acos(-1.);

void track_part_hel_und()
{
  nx=101; //field map divisions in x direction
  ny=101; //field map divisions in y direction
  nz=4001; //field map divisions in z direction
  z_field_start=-200.;
  double  x_max=5.,   y_max=5.,   z_min=z_field_start, z_max=360;  // maximum allowed coordinates
  double  x_init=0.0, y_init=0.,  z_init=-100;  // starting coordinates
  double  px_init=0., py_init=0., pz_init=1.;  // momentum is in GeV units
//  double pi=acos(-1.);

  prepare_arrays(nx, ny, nz);  // this will prepare arrays with dimensions nx, ny and nz in agreement with the field map
  prepare_for_plots();
  k_scale=1.0;

  i_und=82002;
  int op3_cur=248;


  if (i_und==6)
  {
    read_field("../v7_1_osc_geom_steel_cor_field_0.5_end_current_/hundulator_07_908_xyz.table");
    // We need to give some initial parameters to get the electron trajectory (and the radiated light) as expected
//    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
//    y_init=-0.0453053;
//    px_init=-pz_init*(-0.4354+0.0089301680)/130.;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=19.4*TMath::Pi()/32.;
  }

  if (i_und==7)
  {
    read_field("hundulator_07_v0_908_xyz.table");
    // We need to give some initial parameters to get the electron trajectory (and the radiated light) as expected
//    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
//    y_init=-0.0453053;
//    px_init=-pz_init*(-0.4354+0.0089301680)/130.;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=19.4*TMath::Pi()/32.;
  }

  if (i_und==777)
  {
    read_field("../v9_1_many/hundulator_07_908_xyz.table");
    z_init=200.;
    pz_init=-1.;
  }

  if (i_und==70)
  {
    read_field("hundulator_07_v0_908_xyz.table");
    // We need to give some initial parameters to get the electron trajectory (and the radiated light) as expected
    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
//    y_init=-0.0453053;
    px_init=-pz_init*(-0.4354+0.0089301680)/130.;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=19.4*TMath::Pi()/32.;
  }

  if (i_und==71)
  {
    read_field("hundulator_07_v0_908_xyz.table");
    z_init=-10;
    // We need to give some initial parameters to get the electron trajectory (and the radiated light) as expected
//    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
//    y_init=-0.0453053;
    px_init=-pz_init*(-0.4354+0.0089301680)/130.;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=16.7*TMath::Pi()/32.;
  }

  if (i_und==2)
  {
    read_field("ideal.table");
//    x_init=(0.-z_init)*0.3022/130.;
//    y_init=0.0119676;
//    px_init=-pz_init*0.3022/130.;
//    pz_init=sqrt(1-px_init*px_init);
    z_init=200.;
    pz_init=-1.;
    rotation_angle=0;
  }

  if (i_und==3)
  {
    read_field("hundulator_07_v1_908_xyz.table");
    // We need to give some initial parameters to get the electron trajectory (and the radiated light) as expected
////    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
////    y_init=0.0274449;
//    px_init=-0.00455109*0.09;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=32.*TMath::Pi()/32.;
  }



  if (i_und==8)
  {
    read_field("../v9_1_many/hundulator_08_908_xyz.table");
////    x_init=-1.*z_init*(-0.4354+0.0089301680)/130.-0.01+0.0257018;
////    y_init=0.0274449;
//    px_init=-0.00455109*0.09;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=32.*TMath::Pi()/32.;
  }


  if (i_und==5)
  {
    rotation_angle=0.;
    read_field_first_half("hundulator_07_v1_908_xyz.table", 65);
    rotation_angle=TMath::Pi();
    z_offset=32.5/2.;
    read_field_last_half ("hundulator_07_v1_908_xyz.table", 65);
    rotation_angle=0;
    px_init=-0.000451843+0.000186195-0.000111264;
    pz_init=sqrt(1-px_init*px_init);
//    z_init=200.;
//    pz_init=-1.;
  }
/*
  if (i_und==6)
  {
    rotation_angle=0.;
    read_field_first_half("hundulator_07_v0_908_xyz.table", 97.5);
//    rotation_angle=pi;
    z_offset=0.;
    read_field_last_half ("hundulator_08_908_xyz.table", 97.5);
//    read_field("hundulator_08_908_xyz.table");
    z_init=300.;
    px_init=3.83/1300.;
    pz_init=-1.*sqrt(1-px_init*px_init);
    rotation_angle=13.5*pi/32.;
  }
*/
  if (i_und==75)
  {
//    read_field("hundulator_08_908_xyz.table");


    rotation_angle=0.;
    read_field_first_half("hundulator_07_v0_908_xyz.table", 97.5);
    rotation_angle=pi;
    z_offset=0.;
    read_field_last_half ("hundulator_09_908_xyz.table", 97.5);
//    read_field("hundulator_08_908_xyz.table");
    z_init=300.;
    px_init=-7.5/1300.;
    pz_init=-1.*sqrt(1-px_init*px_init);
    rotation_angle=14.5*pi/32.;
  }

  if (i_und==101)
  {
    read_field("hundulator_10_908_xyz.table");
//    z_init=300.;
    px_init=-0.000788535;
    pz_init=sqrt(1-px_init*px_init);
//    pz_init=1.;
    rotation_angle=-0.5*pi/32.;
  }

  if (i_und==11)
  {
    read_field("hundulator_11_908_xyz.table");
  }

  if (i_und==111)
  {
    read_field("hundulator_11_908_xyz.table");
    px_init=-0.000783145;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=-0.01*pi;
  }

  if (i_und==112)
  {
//    read_field("hundulator_11_908_xyz.table");
    read_field_first_half("hundulator_11_908_xyz.table", 65);
    rotation_angle=pi;
    z_offset=32.5*0.5;
    read_field_last_half ("hundulator_11_908_xyz.table", 65);
    px_init=-0.000783145;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=-0.01*pi;
  }

  if (i_und==10)
  {
    read_field("hundulator_10_908_xyz.table");
    z_init=300.;
    pz_init=-1;
    rotation_angle=0.33*pi;
  }

  if (i_und==12)
  {
    read_field("hundulator_12_908_xyz.table");
  }

  if (i_und==121)
  {
    read_field("hundulator_12_908_xyz.table");
    px_init=-0.00269907;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=-0.173*pi;
  }

  if (i_und==14)
  {
    read_field("hundulator_14_908_xyz.table");
    rotation_angle=0.41*pi;
  }

  if (i_und==141)
  {
    read_field("hundulator_14_908_xyz.table");
//    read_field_first_half("hundulator_14_908_xyz.table", 65);
//    rotation_angle=pi;
//    z_offset=32.5*0.5;
//    read_field_last_half ("hundulator_14_908_xyz.table", 65);
    px_init=0.000475;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=0.41*pi;
  }


  if (i_und==15)
  {
    read_field("hundulator_15_908_xyz.table");
    rotation_angle=-0.115*pi;
  }

  if (i_und==151)
  {
    read_field("hundulator_15_908_xyz.table");
    rotation_angle=-0.115*pi;
    px_init=-0.000931091;
    pz_init=sqrt(1-px_init*px_init);
  }

  if (i_und==16)
  {
    read_field("hundulator_16_908_xyz.table");
    rotation_angle=0.08*pi;
  }

  if (i_und==161)
  {
    read_field("hundulator_16_908_xyz.table");
    rotation_angle=0.08*pi;
    px_init=-0.000905887;
    pz_init=sqrt(1-px_init*px_init);
  }

  if (i_und==17)
  {
    read_field("hundulator_17_908_xyz.table");
    rotation_angle=0.4*pi;
  }

  if (i_und==171)
  {
    read_field("hundulator_17_908_xyz.table");
    px_init=0.00154422;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=0.4*pi;
  }

  if (i_und==18)
  {
    read_field("hundulator_18_908_xyz.table");
    rotation_angle=0.37*pi;
  }

  if (i_und==181)
  {
    read_field("hundulator_18_908_xyz.table");
    px_init=0.00100977;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=0.357*pi;
  }

  if (i_und==191)
  {
    read_field("hundulator_19_908_xyz.table");
    x_init=-0.01;
    y_init=0.01;
    px_init=-0.000313533;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=-0.25*pi;
  }

  if (i_und==192)
  {
    read_field_first_half("hundulator_19_908_xyz.table", 65);
//    rotation_angle=pi;
    z_offset=32.5;
    read_field_last_half ("hundulator_19_908_xyz.table", 65);
    z_offset=2.*32.5;
    read_field_last_half ("hundulator_19_908_xyz.table", 65);
    z_offset=3.*32.5;
    read_field_last_half ("hundulator_19_908_xyz.table", 65);
    z_offset=4.*32.5;
    read_field_last_half ("hundulator_19_908_xyz.table", 97.5);
    px_init=0.000475;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=0.41*pi;
  }

  if (i_und==20)
  {
    read_field("hundulator_20_908_xyz.table");
//    px_init=0.00100977;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=0.357*pi;
  }

  if (i_und==201)
  {
    read_field("hundulator_20_908_xyz.table");
    px_init=-0.000373345;
    pz_init=sqrt(1-px_init*px_init);
    rotation_angle=-0.11*pi;
  }

  if (i_und==21)
  {
    read_field("hundulator_20_908_xyz.table");
    rotation_angle=-0.11*pi;
//    px_init=0.00100977;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=0.357*pi;
  }

  if (i_und==211)
  {
    read_field("hundulator_20_908_xyz.table");
    rotation_angle=-0.11*pi;
    px_init=-0.000382881;
    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=0.357*pi;
  }


  if (i_und==22)
  {
    read_field("../v9_1_many/hundulator_22_908_xyz.table");
    rotation_angle=-0.11*pi;
//    px_init=0.00100977;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=0.357*pi;
  }

  if (i_und==23)
  {
    read_field("../v9_1_many/hundulator_23_908_xyz.table");
    rotation_angle=-0.17*pi;
//    px_init=0.00100977;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=0.357*pi;
  }

  if (i_und==24)
  {
    read_field("../v9_1_many/hundulator_24_908_xyz.table");
    rotation_angle=-0.38*pi;
//    px_init=0.00100977;
//    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=0.357*pi;
  }


  if (i_und==25)
  {
    read_field("../v9_1_many/hundulator_25_908_xyz.table");
    rotation_angle=0.08*pi;
    px_init=0.001107;
    pz_init=sqrt(1-px_init*px_init);
//    rotation_angle=0.357*pi;
  }


  if (i_und==26)
  {
    read_field("../v9_1_many/hundulator_26_908_xyz.table");
  }

  if (i_und==27)
  {
    read_field("../v9_1_many/hundulator_27_908_xyz.table");
  }

  if (i_und==271)
  {
    read_field("../v9_1_many/hundulator_27_908_xyz.table");
    rotation_angle=-0.17*pi;
    x_init=-0.05;
    px_init=0.000410812;
    pz_init=sqrt(1-px_init*px_init);
  }

  if (i_und==28)
  {
    read_field("../v9_1_many/hundulator_28_908_xyz.table");
  }


  if (i_und==29)
  {
    read_field("../v9_1_many/hundulator_29_908_xyz.table");
//    rotation_angle=0.33*pi;
  }

  if (i_und==291)
  {
    read_field("../v9_1_many/hundulator_29_908_xyz.table");
    rotation_angle=0.33*pi;
//    x_init=-0.05;
//    y_init=-0.03;
    px_init=-8.9244e-05;
    pz_init=sqrt(1-px_init*px_init);
  }

  if (i_und==292)
  {
    read_field("../v9_1_many/hundulator_29_908_xyz.table");
    rotation_angle=0.33*pi;
    z_init=300;
    pz_init=-1.;
//    x_init=-0.05;
//    px_init=-6.49927e-05;
//    pz_init=sqrt(1-px_init*px_init);
  }

  if (i_und==30)
  {
    read_field("../v9_1_many/hundulator_30_908_xyz.table");
//    rotation_angle=0.24*pi;
//    z_init=300;
//    pz_init=-1.;
  }

  if (i_und==31)
  {
    read_field("../v9_1_many/hundulator_31_908_xyz.table");
//    rotation_angle=0.55*pi;
  }

  if (i_und==32)
  {
    read_field("../v9_1_many/hundulator_32_908_xyz.table");
//    rotation_angle=-0.15*pi;
  }

  if (i_und==33)
  {
    read_field("../v9_1_many/hundulator_33_908_xyz.table");
//    rotation_angle=-0.15*pi;
  }

  if (i_und==321)
  {
    read_field("../v9_1_many/hundulator_32_908_xyz.table");
    rotation_angle=-0.15*pi;
    px_init=-0.000241373;
    pz_init=sqrt(1-px_init*px_init);
  }
  if (i_und==50)
  {
    read_field("../v9_2_many/hundulator_50_908_xyz.table");
  }

  if (i_und==51)
  {
    read_field("../v9_2_many/hundulator_51_908_xyz.table");
  }

  if (i_und==52)
  {
    read_field("../v9_2_many/hundulator_52_908_xyz.table");
  }

  if (i_und==53)
  {
    read_field("../v9_2_many/hundulator_53_908_xyz.table");
  }


  if (i_und==54)
  {
    read_field("../v9_2_many/hundulator_54_908_xyz.table");
    rotation_angle=0.4*pi;
    //-0.00117003
  }

  if (i_und==55)
  {
    read_field("../v9_2_many/hundulator_55_908_xyz.table");
    rotation_angle=0.15*pi;
//    -0.0014
  }

  if (i_und==56)
  {
    read_field("../v9_2_many/hundulator_56_908_xyz.table");
//    rotation_angle=0.15*pi;
//    -0.0014
  }

  if (i_und==57)
  {
    read_field("../v9_2_many/hundulator_57_908_xyz.table");
    rotation_angle=0.23*pi;
    //-0.00136087
  }

  if (i_und==58)
  {
    read_field("../v9_2_many/hundulator_58_908_xyz.table");
    rotation_angle=-0.33*pi;
    //  -> -0.000407831
  }

  if (i_und==59)
  {
    read_field("../v9_2_many/hundulator_59_908_xyz.table");
    rotation_angle=-0.05*pi;
    //  -> -0.00027
  }

  if (i_und==60)
  {
    read_field("../v9_2_many/hundulator_60_908_xyz.table");
    rotation_angle=-0.4*pi;
    //  -> -0.000711613
  }


  if (i_und==61)
  {
    read_field("../v9_2_many/hundulator_61_908_xyz.table");
    rotation_angle=0.67*pi;
    //  -> 0.000586623
  }

  if (i_und==62)
  {
    read_field("../v9_2_many/hundulator_62_908_xyz.table");
    rotation_angle=-0.21*pi;
    //  -> -0.000344843
  }

  if (i_und==64)
  {
    read_field("../v9_2_many/hundulator_64_908_xyz.table");
    rotation_angle=0.3*pi;
    //  -> -0.000209938
  }

  if (i_und==65)
  {
    read_field("../v9_2_many/hundulator_65_908_xyz.table");
    rotation_angle=0.3*pi;
    //  -> -0.000209938
  }


  if (i_und==3356)
  {
    read_field("../v9_3_many/hundulator_56_908_xyz.table");
//    rotation_angle=0.15*pi;
//    -0.0014
  }

  if (i_und==7529)
  {
    read_field("../75mm_pipe/hundulator_29_772_xyz.table");
    rotation_angle=-0.07*pi;
//    -0.0014
  }


  if (i_und==37)
  {
    read_field("../v9_1_many/hundulator_37_908_xyz.table");
//    rotation_angle=0.33*pi;
//    x_init=-0.05;
//    y_init=-0.03;
//    px_init=-8.9244e-05;
//    pz_init=sqrt(1-px_init*px_init);
  }

//  if (i_und==37)
//  {
//    read_field("../v9_1_many/hundulator_37_908_xyz.table");
////    rotation_angle=-0.07*pi;
////    -0.0014
//  }

  if (i_und==38)
  {
    read_field("../v9_1_many/hundulator_38_908_xyz.table");
  }

  if (i_und==39)
  {
    read_field("../v9_1_many/hundulator_39_908_xyz.table");
  }


  if (i_und==40)
  {
    read_field("../v9_1_many/hundulator_40_908_xyz.table");
  }

  if (i_und==41)
  {
    read_field("../v9_1_many/hundulator_41_908_xyz.table");
  }

  if (i_und==42)
  {
    read_field("../v9_1_many/hundulator_42_908_xyz.table");
//    rotation_angle=-0.25*pi;
  }

  if (i_und==421)
  {
    x_init=-0.025;
    y_init=-0.01;
    read_field("../v9_1_many/hundulator_42_908_xyz.table");
  }

  if (i_und==43)
  {
    read_field("../v9_1_many/hundulator_43_908_xyz.table");
  }

  if (i_und==44)
  {
    read_field("../v9_1_many/hundulator_44_908_xyz.table");
  }

  if (i_und==45)
  {
    read_field("../v9_1_many/hundulator_45_908_xyz.table");
  }

  if (i_und==46)
  {
    read_field("../v9_1_many/hundulator_46_908_xyz.table");
  }

  if (i_und==47)
  {
    read_field("../v9_1_many/hundulator_47_908_xyz.table");
//    x_init=-0.03; y_init=-0.01,  z_init=-100;  // starting coordinates

  }

  if (i_und==48)
  {
    read_field("../v9_1_many/hundulator_48_908_xyz.table");
  }

  if (i_und==5501)
  {
    read_field("../v9_4_many_xare/hundulator_01_908_xyz.table");
  }

  if (i_und==5502)
  {
    read_field("../v9_4_many_xare/hundulator_02_908_xyz.table");
  }

  if (i_und==5503)
  {
    read_field("../v9_4_many_xare/hundulator_03_908_xyz.table");
    z_init=-60, z_max=4.5*32.5+60;  // maximum allowed coordinates
  }

  if (i_und==5504)
  {
    read_field("../v9_4_many_xare/hundulator_04_908_xyz.table");
/*
    x_init=-0.04;
    y_init=0.15;
    px_init=-0.0011;
    py_init=-0.001363;
    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
*/
  }

  if (i_und==5505)
  {
    read_field("../v9_4_many_xare/hundulator_05_908_xyz.table");
  }

  if (i_und==5506)
  {
    read_field("../v9_4_many_xare/hundulator_06_908_xyz.table");
  }

  if (i_und==5507)
  {
    read_field("../v9_4_many_xare/hundulator_07_908_xyz.table");
  }

  if (i_und==5508)
  {
    read_field("../v9_4_many_xare/hundulator_08_908_xyz.table");
  }

  if (i_und==5509)
  {
    read_field("../v9_4_many_xare/hundulator_09_908_xyz.table");
  }

  if (i_und==5510)
  {
    read_field("../v9_4_many_xare/hundulator_10_908_xyz.table");
  }

  if (i_und==5511)
  {
    k_scale=1500./1328.;
    read_field("../v9_4_many_xare/hundulator_11_1000_xyz.table");
  }

  if (i_und==5512)
  {
    read_field("../v9_4_many_xare/hundulator_12_1130_xyz.table");
//    z_init=-60, z_max=4.5*32.5+60;  // maximum allowed coordinates
  }

  if (i_und==5514)
  {
    read_field("../v9_4_many_xare/hundulator_14_1130_xyz.table");
  }

  if (i_und==5515)
  {
    read_field("../v9_4_many_xare/hundulator_15_908_xyz.table");
  }

  if (i_und==5518)
  {
    read_field("../v9_4_many_xare/hundulator_18_1130_xyz.table");
  }

  if (i_und==5520)
  {
//    read_field("SRW_field.dat");
    read_field("../v9_4_many_xare/hundulator_20_908_xyz.table");
    z_init=-120, z_max=(2.*(0.3*0.313+0.3*0.77)+7.3)*32.5+120;  // maximum allowed coordinates

    px_init=5.6786000e-06;
    py_init=-9.1676300e-06;
    x_init=-0.03779;
    y_init=-0.009681;

/*
    x_init=-0.035912;
    y_init=-0.0095881210;
    px_init=-2.684e-06;
    py_init=-9.1451700e-06;
*/
    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
  }

  if (i_und==5522)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_22_1130_xyz.table");
  }

  if (i_und==5523)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_23_1130_xyz.table");
  }


  if (i_und==5524)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_24_1130_xyz.table");
  }

  if (i_und==5525)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_25_1130_xyz.table");
  }

  if (i_und==5526)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_26_1130_xyz.table");
  }

  if (i_und==5527)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_27_1130_xyz.table");
  }

  if (i_und==5528)
  {
//    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_28_1130_xyz.table");
  }

  if (i_und==5529)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_29_1130_xyz.table");
  }

  if (i_und==5530)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_30_1130_xyz.table");
  }

  if (i_und==5532)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_32_1130_xyz.table");
  }

  if (i_und==5534)
  {
    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_34_1130_xyz.table");
  }

  if (i_und==5536)
  {
//    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_36_1130_xyz.table");
  }

  if (i_und==5537)
  {
//    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_37_1130_xyz.table");
  }

  if (i_und==5541)
  {
//    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_41_908_xyz.table");
  }

  if (i_und==5543)
  {
//    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_43_908_xyz.table");
  }

  if (i_und==5544)
  {
//    k_scale=0.66;
    read_field("../v9_4_many_xare/hundulator_44_908_xyz.table");
  }

  if (i_und==5571)
  {
    k_scale=0.45;
    read_field("../v9_4_many_xare/hundulator_71_908_xyz.table");
  }

  if (i_und==5573)
  {
//    k_scale=0.45;
    read_field("../v9_4_many_xare/hundulator_73_414_xyz.table");
  }

  if (i_und==55100)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_100_414_xyz.table");
  }

  if (i_und==55101)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_101_414_xyz.table");
  }

  if (i_und==55102)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_102_414_xyz.table");
  }

  if (i_und==55103)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_103_414_xyz.table");
  }

  if (i_und==55104)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_104_414_xyz.table");
  }

  if (i_und==55200)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_200_414_xyz.table");
  }

  if (i_und==55201)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_201_414_xyz.table");
  }

  if (i_und==55202)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_202_414_xyz.table");
  }

  if (i_und==55203)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_203_414_xyz.table");
  }

  if (i_und==55204)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_204_414_xyz.table");
  }

  if (i_und==55300)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_300_414_xyz.table");
  }

  if (i_und==55301)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_301_414_xyz.table");
  }

  if (i_und==55302)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_302_414_xyz.table");
  }

  if (i_und==55303)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_303_414_xyz.table");
  }

  if (i_und==55304)
  {
    k_scale=0.95;
    read_field("../v9_4_many_xare/hundulator_304_414_xyz.table");
  }

  if (i_und==55600)
  {
    read_field("../v9_4_many_xare/hundulator_600_414_xyz.table");
  }
  if (i_und==55601)    read_field("../v9_4_many_xare/hundulator_601_393_xyz.table");
  if (i_und==55602)    read_field("../v9_4_many_xare/hundulator_602_393_xyz.table");
  if (i_und==55603)    read_field("../v9_4_many_xare/hundulator_603_393_xyz.table");
  if (i_und==55604)    read_field("../v9_4_many_xare/hundulator_604_393_xyz.table");
  if (i_und==55605)    read_field("../v9_4_many_xare/hundulator_605_393_xyz.table");
  if (i_und==55700)    read_field("../v9_4_many_xare/hundulator_700_393_xyz.table");
  if (i_und==55701)    read_field("../v9_4_many_xare/hundulator_701_393_xyz.table");
  if (i_und==55702)    read_field("../v9_4_many_xare/hundulator_702_393_xyz.table");
  if (i_und==55703)    read_field("../v9_4_many_xare/hundulator_703_393_xyz.table");
  if (i_und==55704)    read_field("../v9_4_many_xare/hundulator_704_393_xyz.table");
  if (i_und==55800)    read_field("../v9_4_many_xare/hundulator_800_393_xyz.table");
  if (i_und==55801)    read_field("../v9_4_many_xare/hundulator_801_393_xyz.table");
  if (i_und==55803)    read_field("../v9_4_many_xare/hundulator_803_393_xyz.table");
  if (i_und==55804)    read_field("../v9_4_many_xare/hundulator_804_393_xyz.table");
  if (i_und==55900)    read_field("../v9_4_many_xare/hundulator_900_393_xyz.table");
  if (i_und==55901)    read_field("../v9_4_many_xare/hundulator_901_393_xyz.table");
  if (i_und==55902)    read_field("../v9_4_many_xare/hundulator_902_393_xyz.table");
  if (i_und==55903)    read_field("../v9_4_many_xare/hundulator_903_393_xyz.table");
  if (i_und==55904)    read_field("../v9_4_many_xare/hundulator_904_393_xyz.table");
  if (i_und==55905)    read_field("../v9_4_many_xare/hundulator_905_393_xyz.table");
  if (i_und==55906)    read_field("../v9_4_many_xare/hundulator_906_393_xyz.table");
  if (i_und==55907)    read_field("../v9_4_many_xare/hundulator_907_393_xyz.table");
  if (i_und==55908)    read_field("../v9_4_many_xare/hundulator_908_393_xyz.table");
  if (i_und==55915)    read_field("../v9_4_many_xare/hundulator_915_393_xyz.table");
  if (i_und==55910)    read_field("../v9_4_many_xare/hundulator_910_393_xyz.table");
  if (i_und==66000)    read_field("../v9_4_many_xare/hundulator_66000_450_xyz.table");
  if (i_und==66001)    read_field("../v9_4_many_xare/hundulator_66001_450_xyz.table");
  if (i_und==66002)    read_field("../v9_4_many_xare/hundulator_66002_450_xyz.table");
  if (i_und==66003)    read_field("../v9_4_many_xare/hundulator_66003_450_xyz.table");
  if (i_und==66004)    read_field("../v9_4_many_xare/hundulator_66004_450_xyz.table");
  if (i_und==66005)    read_field("../v9_4_many_xare/hundulator_66005_450_xyz.table");
  if (i_und==66006)    read_field("../v9_4_many_xare/hundulator_66006_450_xyz.table");
  if (i_und==66007)    read_field("../v9_4_many_xare/hundulator_66007_450_xyz.table");

  if (i_und==66010)    read_field("../v9_4_many_xare/hundulator_66010_450_xyz.table");
  if (i_und==66011)    read_field("../v9_4_many_xare/hundulator_66011_450_xyz.table");
  if (i_und==66012)    read_field("../v9_4_many_xare/hundulator_66012_450_xyz.table");
  if (i_und==66013)    read_field("../v9_4_many_xare/hundulator_66013_450_xyz.table");
  if (i_und==66014)    read_field("../v9_4_many_xare/hundulator_66014_450_xyz.table");
  if (i_und==66015)    read_field("../v9_4_many_xare/hundulator_66015_450_xyz.table");
  if (i_und==66016)    read_field("../v9_4_many_xare/hundulator_66016_450_xyz.table");
  if (i_und==66017)    read_field("../v9_4_many_xare/hundulator_66017_450_xyz.table");



  if (i_und>=7000)
  {
    read_field(Form("../v9_4_many_xare/hundulator_%d_%d_xyz.table", i_und, op3_cur));
  }

  if (i_und>=66737)
  if (i_und<=66738)
  {
    read_field(Form("../v9_4_many_xare/hundulator_%d_463_xyz.table", i_und));
//    k_scale=0.97;
  }

  if (i_und>=66777)
  if (i_und<=66778)
  {
    read_field(Form("../v9_4_many_xare/hundulator_%d_589_xyz.table", i_und));
//    k_scale=0.97;
  }

  if (i_und==66779)
//  if (i_und<=66778)
  {
    read_field(Form("../v9_4_many_xare/hundulator_%d_535_xyz.table", i_und));
//    k_scale=0.97;
  }

//  if (i_und==66730)
//  {
//    py_init=-3.671e-3;
//    px_init=-0.8558e-03;
//    pz_init=sqrt(1-px_init*px_init-py_init*py_init);
//  }

//  loop over rotation angles to find the most suitable picture
//  for (rotation_angle=0; rotation_angle<=2.*TMath::Pi(); rotation_angle+=TMath::Pi()/32.)
  {
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
//    if ( z_new > 32.5*2.5 ) b = get_bfield(x_new, y_new, 32.5*2.5 - (z_new - 32.5*2.5) );
    TVector3 B_rot(b[0], b[1], b[2]);
//    if ( z_new > 32.5*2.5 ) B_rot[1]=-1.*B_rot[1];
//    if ( z_new > 32.5*2.5 ) B_rot[2]=-1.*B_rot[2];
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
        int ix=int((x+5.0)/0.1+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y+5.0)/0.1+0.000000000001);
        int iz=int((z-z_field_start)/0.2+0.000000000001);
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
        else if (z<32.5*0.5)
        {
          double k_factor_new=0.3+0.7*z/(32.5*0.5);
          bx_arr[ix][iy][iz]=k_factor_new*k_scale*bx;
          by_arr[ix][iy][iz]=k_factor_new*k_scale*by;
          bz_arr[ix][iy][iz]=k_factor_new*k_scale*bz;
        }
        else if (z>5*32.5)
        {
          bx_arr[ix][iy][iz]=0.3*k_scale*bx;
          by_arr[ix][iy][iz]=0.3*k_scale*by;
          bz_arr[ix][iy][iz]=0.3*k_scale*bz;
        }
        else if (z>5*32.5-32.5*0.5)
        {
          double k_factor_new=0.3+0.7*(5*32.5-z)/(32.5*0.5);
          bx_arr[ix][iy][iz]=k_factor_new*k_scale*bx;
          by_arr[ix][iy][iz]=k_factor_new*k_scale*by;
          bz_arr[ix][iy][iz]=k_factor_new*k_scale*bz;
        }
        else

        {
*/
          bx_arr[ix][iy][iz]=k_scale*bx;
          by_arr[ix][iy][iz]=k_scale*by;
          bz_arr[ix][iy][iz]=k_scale*bz;
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
        int ix=int((x+5.0)/0.1+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y+5.0)/0.1+0.000000000001);
        int iz=int((z-z_field_start)/0.2+0.000000000001);
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
        int ix=int((x+5.0)/0.1+0.000000000001);  //+0.0001 is needed for the proper conversion double->int
        int iy=int((y+5.0)/0.1+0.000000000001);
        int iz=int((z-z_field_start)/0.2+0.000000000001);
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


//  cout<<"600  "<< get_i_from_z(600.)<<endl;
//  cout<<"925  "<< get_i_from_z(925.)<<endl;
  int i1_tmp=get_i_from_z(650.-325.-100.);
  int i2_tmp=get_i_from_z(975.-325.-100.);
  double k=1./325.;


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
  double dz=0;
  double sum_x=0;
  double sum_y=0;
  if (i1_tmp != -1)
  if (i2_tmp != -1)
  {
    dx=x_gr[i2_tmp]-x_gr[i1_tmp];
    cout<<" x="<<x_gr[i1_tmp]<<"     "<<x_gr[i2_tmp]<<endl;
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
    dz=z_gr[i2_tmp]-z_gr[i1_tmp];
  }


  cc->cd(1);
  gr_x->Draw("AP");
//  gr_x->Fit(func1, "R");
  if (dz!=0)
  {
    TLatex *text1_angle = new TLatex(0., sum_x+0.2, Form("x' = %.6f mrad", dx/dz*1000.) );
    text1_angle->SetTextAlign(12);
    text1_angle->SetTextColor(4);
    text1_angle->SetTextSize(0.06);
    text1_angle->Draw();
    ofstream outfile;
    outfile.open("res.txt", ios::out | ios::app );
    outfile<<i_und<<"    x'="<<dx/dz*1000.<<"    y'="<<dy/dz*1000.<<endl;
    outfile.close();
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
  if (dz!=0)
  {
//    TLatex *text2_angle = new TLatex(900., y_gr[i2_tmp], Form("y' = %.3f mrad", dy/dz*1000.) );
    TLatex *text2_angle = new TLatex(0., 0., Form("y' = %.6f mrad", dy/dz*1000.) );
    text2_angle->SetTextAlign(12);
    text2_angle->SetTextColor(4);
    text2_angle->SetTextSize(0.06);
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
  TLatex *text1 = new TLatex(2000., 2.0, Form("p_{x} = %.6f MeV", px_gr[n_gr-3] ) );
  text1->Draw();

  cc->cd(3+div_nx);
  gr_py->Draw("AP");
  TLatex *text2 = new TLatex(2000., 2.0, Form("p_{y} = %.6f MeV", py_gr[n_gr-3] ) );
  text2->Draw();

  cc->cd(3+2*div_nx);
  gr_pz->Draw("AP");

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
  cc->SaveAs(Form("%d_autosave.gif", i_und));
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

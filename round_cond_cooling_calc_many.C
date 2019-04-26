
void cooling_calc(double , double, double );
void plot_all();
int get_n_central();
vector<int> get_n_first(TH2D *);

bool plot_individual=true;
double cool_pres, tot_power, cden_final, cur_single,lcond_total, steel_mass, voltage_drop, tot_resist;
double nx_old[20], field_old[20], ny_old[12];
double inch = 2.54;
double dcond = 0.25*inch;                           //conductor diameter
double dhole = 0.12*inch;                           //conductor hole diameter

double insul_y=0.03;
double insul_x=0.021357;

double cond_height_single = dcond+insul_y;
double cond_width_single = dcond+insul_x;
double pi=TMath::Pi();
double RC0=4.5;
double pitch=32.5;
double alpha_dn=atan(2*pi*RC0/pitch);
double frac_w_real=sin(alpha_dn);
int n_per_width=11;
int n_per_height=8;
int ny_central=3;

int i_set=3;
int sett[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
string name[10]={"1to4_0.152", "1to4_0.12", "5to16_0.215", "5to16_0.183", "3to8_0.277", "3to8_0.245", "1to2_0.402", "1to2_0.37", "3to8_0.18", "1to2_0.24"};
double dcond_set[10] = {1./4., 1./4., 5./16., 5./16., 3./8., 3./8., 1./2., 1./2., 3./8., 1./2.};
double dhole_set[10] = {0.152,  0.12,  0.215,  0.183, 0.277, 0.245, 0.402,  0.37,  0.18,  0.24};
int n_per_width_set[10]={  10,    10,      9,      9,     7,    7,      6,     6,     7,     6};
double n_width_start_set[10]={  5,    5,     4,     4,     4,    4,      3,    3,     4,     3};
double n_height_start_set[10]={ 7,    7,     6,     6,     5,    5,      4,    4,     5,     4};

//double dcond_new=5./16.*inch;
//double dhole_new=0.215*inch;
double dcond_new=dcond_set[i_set]*inch;
double dhole_new=dhole_set[i_set]*inch;
double nx_new[20], field_new[20], ny_new[20];
int n_per_width_new=n_per_width_set[i_set];
int n_per_height_new=10;
double cond_height_single_new = dcond_new+insul_y;
double cond_width_single_new = dcond_new+insul_x;
bool larger_cond=false;
int  larger_N=0;
double larger_diam=dcond_set[i_set+2]*inch;
double larger_hole=dhole_set[i_set+2]*inch;
double delta_dcond=dhole_set[i_set+2]-dhole_set[i_set];

void round_cond_cooling_calc_many()
{
  cout<<dcond_set[2]<<endl;


/*
  cout<<frac_w_real<<endl;
  cout<<5.*frac_w_real<<endl;
  cout<<cond_width_single*5./frac_w_real<<endl;
  cout<<cond_height_single*10.<<endl;
*/


  for (int i=0; i<n_per_width; i++)    nx_old[i]=5. + double(i);
  for (int i=0; i<n_per_height; i++)   ny_old[i]=7. + double(i);

  for (int i=0; i<n_per_width_new; i++)    nx_new[i]=n_width_start_set[i_set] + double(i);
  for (int i=0; i<n_per_height_new; i++)   ny_new[i]=n_height_start_set[i_set] + double(i);

/*
  ny_old[0]=7;
  ny_old[1]=8;
  ny_old[2]=9;
  ny_old[3]=10;
  ny_old[4]=11;
  ny_old[5]=12;
  ny_old[6]=13;
  ny_old[7]=14;


  nx_old[0]=5.0;
  nx_old[1]=6.0;
  nx_old[2]=7.0;
  nx_old[3]=8.0;
  nx_old[4]=9.0;
  nx_old[5]=10.0;
  nx_old[6]=11.0;
  nx_old[7]=12.0;
  nx_old[8]=13.0;
  nx_old[9]=14.0;
  nx_old[10]=15.0;
*/
  field_old[0]=1.020;
  field_old[1]=1.204;
  field_old[2]=1.377;
  field_old[3]=1.537;
  field_old[4]=1.682;
  field_old[5]=1.811;
  field_old[6]=1.920;
  field_old[7]=2.008;
  field_old[8]=2.072;
  field_old[9]=2.107;
  field_old[10]=2.073;

  TCanvas *c_fld_cur = new TCanvas("c_fld_cur", "c_fld_cur");
  c_fld_cur->cd();
  TGraph * gr_wid_field = new TGraph(11, nx_old, field_old);
  gr_wid_field->SetTitle("Field vs current");
  gr_wid_field->SetMarkerStyle(20);
  gr_wid_field->Draw("AP");
  c_fld_cur->Update();
  TF1 *pol_fit = new TF1("pol_fit", "pol6");
  gr_wid_field->Fit("pol_fit");
  double par_0 = pol_fit->GetParameter(0);
  double par_1 = pol_fit->GetParameter(1);
  double par_2 = pol_fit->GetParameter(2);
  double par_3 = pol_fit->GetParameter(3);
  double par_4 = pol_fit->GetParameter(4);
  double par_5 = pol_fit->GetParameter(5);
  double par_6 = pol_fit->GetParameter(6);

  cout<<"par0="<<par_0<<endl;
  cout<<"par1="<<par_1<<endl;
  cout<<"par2="<<par_2<<endl;
  cout<<"par3="<<par_3<<endl;
  cout<<"par4="<<par_4<<endl;
  cout<<"par5="<<par_5<<endl;
  cout<<"par6="<<par_6<<endl;




  for (int i=0; i<n_per_width_new; i++)
  {
    double x_new=nx_new[i]*cond_width_single_new/cond_width_single;
    double x_new_op=x_new/frac_w_real;
    field_new[i]=par_0+par_1*x_new+par_2*pow(x_new,2)+par_3*pow(x_new,3)+par_4*pow(x_new,4)+par_5*pow(x_new,5)+par_6*pow(x_new,6);
//    field_new[i]*=cond_height_single_new/cond_height_single;
    cout<<i<<"       x_new="<<x_new<<"       x_new_real="<<x_new*frac_w_real<<"          field="<<field_new[i]<<endl;
  }
  for (int i=0; i<20; i++)
  {
    cout<<"i="<<i<<"      nx_new[i]="<<nx_new[i]<<"      ny_new[i]="<<ny_new[i]<<endl;
  }

  double height_central_old=ny_old[ny_central]*cond_height_single;
  cout<<"new central = "<<get_n_central()<<"      ny_cen[]="<<ny_old[ny_central]<<"      ny_cen_new[]="<<ny_new[get_n_central()]<<endl;

  ny_central=get_n_central();
  dcond=dcond_new;
  dhole=dhole_new;
  n_per_width=n_per_width_new;
  n_per_height=n_per_height_new;
  cond_height_single=cond_height_single_new;
  cond_width_single=cond_width_single_new;

  cout<<"dcond[\"]="<<dcond/inch<<endl;
  cout<<"dhole[\"]="<<dhole/inch<<endl;
  cout<<"n_per_width="<<n_per_width_new<<endl;
  cout<<"n_per_height="<<n_per_height_new<<endl;
  cout<<"cond_height_single="<<cond_height_single_new<<endl;
  cout<<"cond_width_single="<<cond_width_single_new<<endl;


  double height_central_new=ny_new[ny_central]*cond_height_single_new;
  for (int i=0; i<n_per_width; i++)
  {
    nx_old[i]=nx_new[i];
    field_old[i]=field_new[i]*height_central_new/height_central_old;
  }
  for (int i=0; i<n_per_height; i++)
  {
    ny_old[i]=ny_new[i];
    cout<<"i="<<i<<"      nx_old[i]="<<nx_old[i]<<"      ny_old[i]="<<ny_old[i]<<"      field_old[i]="<<field_old[i]<<endl;
  }

//  cout<<"please press enter to continue"<<endl;
//  cin.ignore();
//  cin.get();

//  cout<<"sleeping"<<endl;
//  int aaa=system("sleep 20s");


/*
  double x=7;
  cout<<"fn="<<par_0+par_1*x+par_2*x*x+par_3*x*x*x+par_4*x*x*x*x+par_5*x*x*x*x*x+par_6*x*x*x*x*x*x<<endl;
  x=8;
  cout<<"fn="<<par_0+par_1*x+par_2*x*x+par_3*x*x*x+par_4*x*x*x*x+par_5*x*x*x*x*x+par_6*x*x*x*x*x*x<<endl;
  x=9;
  cout<<"fn="<<par_0+par_1*x+par_2*x*x+par_3*x*x*x+par_4*x*x*x*x+par_5*x*x*x*x*x+par_6*x*x*x*x*x*x<<endl;
  x=10;
  cout<<"fn="<<par_0+par_1*x+par_2*x*x+par_3*x*x*x+par_4*x*x*x*x+par_5*x*x*x*x*x+par_6*x*x*x*x*x*x<<endl;
  x=11;
  cout<<"fn="<<par_0+par_1*x+par_2*x*x+par_3*x*x*x+par_4*x*x*x*x+par_5*x*x*x*x*x+par_6*x*x*x*x*x*x<<endl;
  x=12;
  cout<<"fn="<<par_0+par_1*x+par_2*x*x+par_3*x*x*x+par_4*x*x*x*x+par_5*x*x*x*x*x+par_6*x*x*x*x*x*x<<endl;
*/


  //+1. scale the field down for radial dimension (central row, ny_central)
  //+2. get new field[]... from fit parameters
  //-3. correct nx_old[], ny_old[]
  //-4. test for 2*width, 2*height
  plot_all();
}

void plot_all()
{
  TH2D * hh_pres = new TH2D ("Water pressure vs conductor geometry", "Water pressure vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_pow  = new TH2D ("Total power vs conductor geometry",   "Total power vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_cden = new TH2D ("Current density vs conductor geometry", "Current density vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_cur  = new TH2D ("Current for single wire", "Current for single wire", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_lcond  = new TH2D ("lcond", "Cond total length vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_steel  = new TH2D ("steel", "Steel weight vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_voltage= new TH2D ("volts", "Total voltage vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_resist = new TH2D ("resist", "Total resistance vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);
  TH2D * hh_NI     = new TH2D ("NI", "N #times I vs conductor geometry", 15, 0.5, 15.5, 14, 0.5, 14.5);

  hh_pres->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_pres->GetYaxis()->SetTitle("Nr of conductors per height (radial)");

  hh_pow->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_pow->GetYaxis()->SetTitle("Nr of conductors per height (radial)");

  hh_cden->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_cden->GetYaxis()->SetTitle("Nr of conductors per height (radial)");

  hh_cur->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_cur->GetYaxis()->SetTitle("Nr of conductors per height (radial)");

  hh_lcond->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_lcond->GetYaxis()->SetTitle("Nr of conductors per height (radial)");

  hh_steel->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_steel->GetYaxis()->SetTitle("Nr of conductors per height (radial)");

  hh_voltage->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_voltage->GetYaxis()->SetTitle("Nr of conductors per height (radial)");

  hh_NI->GetXaxis()->SetTitle("Nr of conductors per width");
  hh_NI->GetYaxis()->SetTitle("Nr of conductors per height (radial)");


  double pow_gr[20];
  double pres_gr[20];
  int i=0;
  int j=3;

//  for (j =0; j<n_per_height; j++)
//  for (i =0; i<n_per_width; i++)
  for (j =6; j<7; j++)
  for (i =2; i<3; i++)
  {
    lcond_total=0;
    voltage_drop=0;
    tot_resist=0;
    steel_mass=(pitch-(cond_width_single/frac_w_real)*nx_old[i]*2.)/pitch*pi*((RC0+cond_height_single*ny_old[j])*(RC0+cond_height_single*ny_old[j])-RC0*RC0)*pitch*14.*7.850;
    cout<<i<<"       "<<j<<"    inside loop    nx="<<nx_old[i]<<"    ny="<<ny_old[j]<<"        ny_old[ny_central]="<<ny_old[ny_central]<<"     scaled field="<<field_old[i]*ny_old[j]/ny_old[ny_central]<<endl;
    cool_pres=0;
    cooling_calc(nx_old[i], ny_old[j], field_old[i]*ny_old[j]/ny_old[ny_central]);
    cout<<"pres="<<cool_pres<<endl;
    pow_gr[i]=tot_power/1000.;
    pres_gr[i]=cool_pres;
    hh_pow    ->Fill(nx_old[i], ny_old[j], double(int(pow_gr[i]*10))/10.);
    hh_pres   ->Fill(nx_old[i], ny_old[j], double(int(pres_gr[i]*100))/100.);
    hh_cden   ->Fill(nx_old[i], ny_old[j], double(int(cden_final*1))/1.);
    hh_cur    ->Fill(nx_old[i], ny_old[j], double(int(cur_single*1))/1.);
    hh_lcond  ->Fill(nx_old[i], ny_old[j], double(int(0.0328084*lcond_total*0.1))/0.1);  //cm to ft
    hh_steel  ->Fill(nx_old[i], ny_old[j], double(int(steel_mass/1000.*1))/1.);
    hh_voltage->Fill(nx_old[i], ny_old[j], double(int(voltage_drop*1))/1.);
    hh_resist ->Fill(nx_old[i], ny_old[j], double(int(tot_resist*100))/100.);
    hh_NI     ->Fill(nx_old[i], ny_old[j], double(int(nx_old[i]*ny_old[j]*cur_single*1))/1.);
  }


/*
//  for (j =0; j<8; j++)
  for (i =0; i<11; i++)
  {
    cooling_calc(nx_old[i], ny_old[j], field_old[i]*ny_old[j]/10.);
    pow_gr[i]=tot_power/1000.;
    pres_gr[i]=cool_pres;
    hh_pow->Fill(nx_old[i], ny_old[j], pow_gr[i]);
    hh_pres->Fill(nx_old[i], ny_old[j], pres_gr[i]);
    hh_cden->Fill(nx_old[i], ny_old[j], cden_final);
  }

  i=5;
  for (j=0; j<6; j++)
  if (j!=3)
  {
    cooling_calc(nx_old[i], ny_old[j], field_old[i]*ny_old[j]/10.);
    pow_gr[i]=tot_power/1000.;
    pres_gr[i]=cool_pres;
    hh_pow->Fill(nx_old[i], ny_old[j], pow_gr[i]);
    hh_pres->Fill(nx_old[i], ny_old[j], pres_gr[i]);
    hh_cden->Fill(nx_old[i], ny_old[j], cden_final);
  }
*/
/*
  vector<int> range=get_n_first(hh_cur);
  cout<<range[0]<<"     "<<range[1]<<"     "<<range[2]<<"     "<<range[3]<<endl;
  hh_cur->GetXaxis()->SetRange(range[0], range[1]);
  hh_pres->GetXaxis()->SetRange(range[0], range[1]);
  hh_pow->GetXaxis()->SetRange(range[0], range[1]);
  hh_cden->GetXaxis()->SetRange(range[0], range[1]);
  hh_cur->GetXaxis()->SetRange(range[0], range[1]);
  hh_lcond->GetXaxis()->SetRange(range[0], range[1]);
  hh_steel->GetXaxis()->SetRange(range[0], range[1]);
  hh_voltage->GetXaxis()->SetRange(range[0], range[1]);
  hh_resist->GetXaxis()->SetRange(range[0], range[1]);

  hh_cur ->GetYaxis()->SetRange(range[2], range[3]);
  hh_pres->GetYaxis()->SetRange(range[2], range[3]);
  hh_pow ->GetYaxis()->SetRange(range[2], range[3]);
  hh_cden->GetYaxis()->SetRange(range[2], range[3]);
  hh_cur ->GetYaxis()->SetRange(range[2], range[3]);
  hh_lcond->GetYaxis()->SetRange(range[2], range[3]);
  hh_steel->GetYaxis()->SetRange(range[2], range[3]);
  hh_voltage->GetYaxis()->SetRange(range[2], range[3]);
  hh_resist->GetYaxis()->SetRange(range[2], range[3]);
//  hh_resist->SetTextSize(0.05);
*/
  TGraph * gr_pow = new TGraph(n_per_width, nx_old, pow_gr);
  TGraph * gr_pres = new TGraph(n_per_width, nx_old, pres_gr);
  gr_pow->SetMinimum(0);
  gr_pow->SetMaximum(20);
//tmp  gr_pres->SetMinimum(0);

/*
  TCanvas *c_pow = new TCanvas("power", "power", 0, 0, 1000, 700);
  c_pow->cd();
  c_pow->SetGridx();
  c_pow->SetGridy();
  gr_pow->Draw("AP*");
  c_pow->SaveAs(Form("autosave_test_pow_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));


  TCanvas *c_pres = new TCanvas("pres", "pres", 1000, 0, 1400, 900);
  c_pres->cd();
  c_pres->SetGridx();
  c_pres->SetGridy();
  gr_pres->Draw("AP*");
  c_pres->SaveAs(Form("autosave_set_%d_%s_test_pres.gif", sett[i_set], name[i_set].c_str()));
*/
  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  hh_voltage->SetMinimum(0);
  hh_voltage->SetMaximum(150);
  hh_cur->SetMinimum(0);
  hh_cur->SetMaximum(300);
  hh_pow->SetMinimum(0);
  hh_pow->SetMaximum(20);
  hh_pres->SetMinimum(0);
  hh_pres->SetMaximum(5);
  TCanvas *c_pow1 = new TCanvas("power1", "power1", 0, 800, 1290, 850);
  c_pow1->cd();
  c_pow1->SetGridx();
  c_pow1->SetGridy();
  hh_pow->Draw("colztext");
  c_pow1->SaveAs(Form("autosave_power_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_pow1->SaveAs(Form("gif/W/autosave_set_%d_%s_power.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_pres1 = new TCanvas("pres1", "pres1", 1000, 800, 1290, 850);
  c_pres1->cd();
  c_pres1->SetGridx();
  c_pres1->SetGridy();
  hh_pres->Draw("colztext");
  c_pres1->SaveAs(Form("autosave_pressure_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_pres1->SaveAs(Form("gif/P/autosave_set_%d_%s_pressure.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_cden1 = new TCanvas("cden1", "cden1", 500, 400, 1290, 850);
  c_cden1->cd();
  c_cden1->SetGridx();
  c_cden1->SetGridy();
  hh_cden->Draw("colztext");
  c_cden1->SaveAs(Form("autosave_cur_density_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_cden1->SaveAs(Form("gif/I_den/autosave_set_%d_%s_current_density.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_cur = new TCanvas("cur_sing", "cur_sing", 700, 400, 1290, 850);
  c_cur->cd();
  c_cur->SetGridx();
  c_cur->SetGridy();
  hh_cur->Draw("colztext");
  c_cur->SaveAs(Form("autosave_cur_single_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_cur->SaveAs(Form("gif/I_single/autosave_set_%d_%s_current_single.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_lcond = new TCanvas("lcond_sing", "lcond_sing", 100, 200, 1900, 1400);
  c_lcond->cd();
  c_lcond->SetGridx();
  c_lcond->SetGridy();
  hh_lcond->Draw("colztext");
  c_lcond->SaveAs(Form("autosave_lcond_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_lcond->SaveAs(Form("gif/L/autosave_set_%d_%s_lcond.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_steel = new TCanvas("steel", "steel", 700, 400, 1290, 850);
  c_steel->cd();
  c_steel->SetGridx();
  c_steel->SetGridy();
  hh_steel->Draw("colztext");
  c_steel->SaveAs(Form("autosave_steel_weight_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_steel->SaveAs(Form("gif/M_S/autosave_set_%d_%s_steel_weight.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_volts = new TCanvas("volts", "volts", 700, 400, 1290, 850);
  c_volts->cd();
  c_volts->SetGridx();
  c_volts->SetGridy();
  hh_voltage->Draw("colztext");
  c_volts->SaveAs(Form("autosave_voltage_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_volts->SaveAs(Form("gif/V/autosave_set_%d_%s_voltage_total.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_resist = new TCanvas("resist", "resist", 700, 400, 1290, 850);
  c_resist->cd();
  c_resist->SetGridx();
  c_resist->SetGridy();
  hh_resist->Draw("colztext");
  c_resist->SaveAs(Form("autosave_resistance_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_resist->SaveAs(Form("gif/R/autosave_set_%d_%s_resistance_total.gif", sett[i_set], name[i_set].c_str()));

  TCanvas *c_NI = new TCanvas("NI", "NI", 700, 400, 1290, 850);
  c_NI->cd();
  c_NI->SetGridx();
  c_NI->SetGridy();
  hh_NI->Draw("colztext");
  c_NI->SaveAs(Form("autosave_NI_set_%d_%s.gif", sett[i_set], name[i_set].c_str()));
  c_NI->SaveAs(Form("gif/NI/autosave_set_%d_%s_NI_total.gif", sett[i_set], name[i_set].c_str()));
}

void cooling_calc(double nx1, double ny1, double field1)
{
  double pres[100]={0};
  double n_layer[100]={0};
  double voltage_per_wire[100]={0};
  double resist_per_wire[100]={0};
  double lcond_per_wire[100]={0};

  int n_l=0;
  int n_model=8200;                                  //will be written in output file for the information
  ofstream cool_res;
  cool_res.open("results_cooling.txt", ios::out | ios::app );
// Always remember!!!
// b=5 in opera, means real width=3.28
  double nx = nx1;                                      //Number of turns in width
  double ny = ny1;                                      //Number of turns in height
  double n_period=14.;                                 //number of undulator periods
  double tot_width=nx*cond_width_single;               //total width of helix conductor
  double tot_height=ny*cond_height_single;             //total height of helix conductor
//  tot_width=nx*dcond;                                  //total width of helix conductor
//  tot_height=ny*dcond;                                 //total height of helix conductor
  double field=field1;





  double portion = 1.5/field;                           //field scale
//  portion = 1.;                                       //field scale
  double op3_cur_den=300;
  double current=op3_cur_den*tot_width*tot_height*portion;  //total current per helix
  double deltat = 35;

  double ahole = pi*(dhole*dhole)/4.;                 // conductor corner radius
  double acond = pi*(dcond*dcond)/4.-ahole;           // conductor area

  double total_power=0;
  double total_volts=0;
  double currdens = current/(nx*ny*acond);            // current density
  double pscurr = current/(nx*ny);                    // Power supply current

//  cout<<"model No:"<<n_model<<endl;
//  cout<<"       nx="<<nx<<",  ny="<<ny<<",  cur_dens="<<op3_cur_den*portion<<" A/cm2,    pow. sup current = "<<pscurr<<" Amps,   diam_cond="<<dcond<<" cm,    diam_hole="<<dhole<<" cm"<<endl;
  cool_res<<"nx="<<nx<<",  ny="<<ny<<",  cur_dens="<<op3_cur_den*portion<<" A/cm2,    pow. sup current = "<<pscurr<<" Amps,   diam_cond="<<dcond<<" cm,    diam_hole="<<dhole<<" cm"<<endl;
//  cout<<"Width = "<<tot_width<<"     (opera width = "<<tot_width/3.28*5<<")"<<endl;
//  cout<<"height = "<<tot_height<<endl;
  cool_res<<"Width = "<<tot_width<<"     (opera width = "<<tot_width/3.28*5<<")"<<endl;
  cool_res<<"Height = "<<tot_height<<" cm"<<endl;
  cool_res<<"deltat = "<<deltat<<" deg"<<endl;
  cool_res<<"N_layer   L_turn (cm)    l_cond(cm)     power(Wt)      Voltage(V)     reynolds       dP(Pascal)"<<endl;
  cden_final=op3_cur_den*portion;



  int int_ny=int(ny+0.1);
  for (int i_layer=0; i_layer < int_ny; i_layer++)
  {
    if (i_layer==0)
    {
      dcond = dcond_new;
      dhole = dhole_new;
      ahole = pi*(dhole*dhole)/4.;                 // conductor corner radius
      acond = pi*(dcond*dcond)/4.-ahole;           // conductor area
    }
    double rad = 4.5+0.5*cond_height_single+double(i_layer)*cond_height_single;
    if ((int_ny-i_layer)<=larger_N)
    {
      dcond = larger_diam;
      dhole = larger_hole;
      ahole = pi*(dhole*dhole)/4.;                 // conductor corner radius
      acond = pi*(dcond*dcond)/4.-ahole;           // conductor area
      rad+=(larger_N+1-(int_ny-i_layer))*delta_dcond-0.5*delta_dcond;
    }
//    cout<<i_layer<<"    "<<rad<<"    "<<dcond/inch<<"    "<<larger_diam<<endl;
    double lrad = 2.*pi*rad*n_period;
    double length = 32.5*n_period;
    double lturn = sqrt(length*length+lrad*lrad);       // Average length of one turn of each helix
    lturn+=4.5+2.*7.+pi*rad;                            // end regions
    double lcond = 2*nx*lturn+100;                        // We obtain the total coil length, multiplying by the number of turns. 2 helices
                                                        // +100 cm is for connecting to power supply
    lcond_total+=2.*nx*lturn+100;



    //We obtain the coil resistance multiplying by the copper resistivity.  
    //We can then obtain the power per coil and the voltage per magnet.
    //resCoil=1.7e-8*lcond/acond.   1.7e-8 ohm meter.

    double rescoil = 1.7e-6*lcond/acond;                // resistence of nx turns, one helix
    double powcoil = rescoil*pscurr*pscurr;             // power per each helix
    double psvolts = pscurr*rescoil;                    // Power drop for each turn
    double single_cur = pscurr;
    cur_single = single_cur;
    double lcirc = 0.01*lcond;                          // Length per water circuit in meters
    total_power+=powcoil;
    total_volts+=psvolts;
//    cout<<"                          0:    pscur="<<pscurr<<"     res="<<rescoil<<"     dhole="<<dhole<<"     dCOND="<<dcond<<"     A_COND="<<acond<<"     res="<<rescoil<<endl;
//    cout<<"                          1: "<<total_power<<"    "<<total_volts<<endl;
//    cout<<"                          2: "<<2.*powcoil<<"    "<<2.*psvolts<<endl;

//    cout<<"inner radius = "<<rad<<",    lturn="<<lturn<<endl;
//    cout<<"cur den = "<<op3_cur_den*portion<<endl;
//    cout<<"nx="<<nx<<"     ny="<<ny<<endl;
//    cout<<"current density = "<<op3_cur_den<<" Amps/cm2" <<"        real (inside conductor) current density = "<<currdens<<" Amps/cm2" <<endl;
//    cout<<"power "<<2.*powcoil <<endl;
//    cout<<psvolts<<" volts" <<endl;
//    cout<<single_cur<<" Amps" <<endl;


    //We set a maximum increment of temperature.  
    //With it and the the specific heat of water, we calculate the required mass flow.
    //deltaT=20
    //cp=4185 Joules/(kg degree-K).   Power/cp=kg/s. Then divide by water density (1000 kg/m^3) to get volume flow rate.
    //mprima=powcoil/(cp*deltaT)  !mass flow per coil in kg/s

    double cp = 4185;
    double massflow = powcoil/(deltat*cp);

    //We then obtain the volumetric flow and the water velocity.

    double wdensity = 1000;
    //# Flow in m**3/s
    double volflow = massflow/wdensity;
    // Convert from m^3/s to gpm
    double volflowgpm = volflow/6e-5;

    // velocity in m/s
    double velocity = volflow/(ahole/1e4);

    //Next is the Reynolds number.
    //kinematicViscosity=1e-6
    //reynolds=velocity*dcond/kinematicViscosity

    double kinvis = 1e-6;
    double reynolds = velocity*(dhole/100.)/kinvis;

    //We can now calculate the pressure drop using the turbulent and laminar flows.  
    //The choice of the proper one depends on the Reynolds number. 
    //It is laminar below 2500 and turbulent above 4000.  
    //In the transition regime we can use a linear combination of both.
    //This is the roughness of the cooling duct (used only for turbulent pressure drop)
    //roughness=0.05e-3
    //We use the Haaland equation for the turbulent friction coefficient.
    //aux=-1.8*log10(6.9/reynolds+(roughness/dcond/3.7)**1.11)
    //friction=1/aux**2
    //deltaPTurb=friction*lcond/dcond*density*velocity**2/2

    double rough = 0.00005;
    double aux = -1.8*log10(6.9/reynolds+pow((rough/(dhole/100)/3.7),1.11));
    double friction = pow(aux, -2);
    double delpturb = friction*lcirc/(dhole/100)*wdensity*velocity*velocity/2.;

    //The laminar equation is more simple, as the friction coefficient is 64/Reynolds
    //deltaPLam=64/reynolds*lcond/dcond*density*velocity**2/2

    double delplam = 64./reynolds*lcirc/(dhole/100.)*wdensity*velocity*velocity/2.;
//    cout<<reynolds<<endl;
    double delp;
    if (reynolds >= 4000)
    {
      delp = delpturb;
//      cout<<"1. delp="<<delp<<endl;
    }
    else if (reynolds <= 2500)
    {
      delp = delplam;
//      cout<<"2. delp="<<delp<<endl;
    }
    else
    {
      delp = delpturb*(reynolds-2500.)+delplam*(4000.-reynolds);
      delp = delp/(4000.-2500.);
//      cout<<"3. delp="<<delp<<endl;
    }
    cool_res<<setw(5)<<i_layer+1<<setw(12)<<lturn<<setw(15)<<lcond<<setw(15)<<2.*powcoil<<setw(15)<<2.*psvolts<<setw(15)<<reynolds<<setw(15)<<delp<<endl;
    cout<<setw(5)<<i_layer+1<<setw(5)<<nx<<setw(5)<<ny<<setw(10)<<tot_width<<setw(10)<<tot_height<<setw(10)<<pscurr<<setw(10)<<current<<setw(12)<<lturn<<setw(15)<<lcond<<setw(15)<<2.*powcoil<<setw(15)<<2.*psvolts<<setw(15)<<reynolds<<setw(15)<<delp<<endl;
    //The pressure drop must be less than the available in the facility (310 kPa, i.e. 3.1 bar, in our case).
    //If it is not so, we have to increment deltaT, until it is so.
    //---------------------------------------------------------------------------------------
    //
//    cout<<endl<<endl;
    n_layer[i_layer]=double(i_layer)+1;
    n_l++;
    pres[i_layer]=delp/1.e5;
    if (pres[i_layer]>cool_pres)
      cool_pres=pres[i_layer];
    voltage_per_wire[i_layer] = psvolts;
    resist_per_wire[i_layer] = rescoil;
    lcond_per_wire[i_layer] = lcond/100.;
    voltage_drop += psvolts;
    tot_resist += rescoil;
  }
  cout<<"total power = "<<total_power<<"   total volts = "<<total_volts<<endl;
  cool_res<<"total power = "<<total_power<<"   total volts = "<<total_volts<<endl;
  cool_res<<endl<<endl;
  cool_res.close();
  tot_power = total_power;
  if(plot_individual)
  {
    TGraph * gr = new TGraph( n_l, n_layer, pres);
    TGraph * gr_res_wire = new TGraph( n_l, n_layer, resist_per_wire);
    TGraph * gr_volt_wire = new TGraph( n_l, n_layer, voltage_per_wire);
    TGraph * gr_lcond_wire = new TGraph( n_l, n_layer, lcond_per_wire);

    gr->SetTitle("Water cooling pressure vs layer number (1st is at beam pipe)");
    gr->GetXaxis()->SetTitle("Layer number");
    gr->GetYaxis()->SetTitle("Required pressure [bar]");
    gr->SetMarkerStyle(22);

    gr_lcond_wire->SetTitle("Conductor (single) length vs layer number (1st is at beam pipe)");
    gr_lcond_wire->GetXaxis()->SetTitle("Layer number");
    gr_lcond_wire->GetYaxis()->SetTitle("Single conductor length [m]");
    gr_lcond_wire->SetMarkerStyle(22);

    gr_res_wire->SetTitle("Conductor (single) resistance vs layer number (1st is at beam pipe)");
    gr_res_wire->GetXaxis()->SetTitle("Layer number");
    gr_res_wire->GetYaxis()->SetTitle("Single conductor resistance [Ohm]");
    gr_res_wire->SetMarkerStyle(22);

    gr_volt_wire->SetTitle("Conductor (single) voltage drop vs layer number (1st is at beam pipe)");
    gr_volt_wire->GetXaxis()->SetTitle("Layer number");
    gr_volt_wire->GetYaxis()->SetTitle("Conductor voltage drop[V]");
    gr_volt_wire->SetMarkerStyle(22);


    TCanvas *cc3 = new TCanvas("h_pressure", "h_pressure", 0, 0, 1290, 850);
    cc3->cd();
    cc3->SetGridy();
    cc3->SetGridx();
    gr->Draw("AP");


    TCanvas *c_res_wire = new TCanvas("c_res_wire", "c_res_wire", 0, 0, 1290, 850);
    c_res_wire->cd();
    c_res_wire->SetGridy();
    c_res_wire->SetGridx();
    gr_res_wire->Draw("AP");

    TCanvas *c_volt_wire = new TCanvas("c_volt_wire", "c_volt_wire", 0, 0, 1290, 850);
    c_volt_wire->cd();
    c_volt_wire->SetGridy();
    c_volt_wire->SetGridx();
    gr_volt_wire->Draw("AP");

    TCanvas *c_lcond_wire = new TCanvas("c_lcond_wire", "c_lcond_wire", 0, 0, 1290, 850);
    c_lcond_wire->cd();
    c_lcond_wire->SetGridy();
    c_lcond_wire->SetGridx();
    gr_lcond_wire->Draw("AP");
  }

  // End of cooling calculation
  //------------------------------------
}

int get_n_central()
{
  double i_central=-1;
  double diff=100000;
  for (int i=0; i<n_per_height_new; i++)
  {
    double y_central = ny_old[ny_central]*cond_height_single;
    double y_tmp = ny_new[i]*cond_height_single_new;
    if (diff > fabs(y_tmp-y_central))
    {
      diff = fabs(y_tmp-y_central);
      i_central=i;
    }
  }
  return i_central;
}

vector<int> get_n_first(TH2D *hhh)
{
  vector<int> range;

  for (int i=1; i<=15; i++)
  {
    TH1D *hx = hhh->ProjectionY("proj",i, i);
    cout<<"bin1:"<<i<<"    "<<hx->Integral()<<endl;
    if (hx->Integral()>0.0005)
    {
      range.push_back(i);
      break;
    }
  }

  for (int i=range[0]; i<=15; i++)
  {
    TH1D *hx = hhh->ProjectionY("proj",i, i);
    cout<<"bin2:"<<i<<"    "<<hx->Integral()<<endl;
    if (hx->Integral()<0.0005)
    {
      range.push_back(i-1);
      break;
    }
    if (i==15) range.push_back(i);
  }

  for (int i=1; i<=14; i++)
  {
    TH1D *hx = hhh->ProjectionX("proj",i, i);
    cout<<"bin3:"<<i<<"    "<<hx->Integral()<<endl;
    if (hx->Integral()>0.0005)
    {
      range.push_back(i);
      break;
    }
  }

  for (int i=range[2]; i<=14; i++)
  {
    TH1D *hx = hhh->ProjectionX("proj",i, i);
    cout<<"bin4:"<<i<<"    "<<hx->Integral()<<endl;
    if (hx->Integral()<0.0005)
    {
      range.push_back(i-1);
      break;
    }
    if (i==14) range.push_back(i);
  }

  return range;

}

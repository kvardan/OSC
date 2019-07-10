
void fcn_minuit(Int_t &, Double_t *, Double_t &, Double_t *, Int_t);  //A function to calculate chi^2, needed by Minuit
double func_sin(double, Double_t *);
double func_cos(double, Double_t *);
void do_Minuit();

void read_field_data(string);
void read_field_data_steel(string);
void read_field_data_finite(string);
void draw_plots();
TGraph * gr_x;
TGraph * gr_y;
TGraph * gr_z;
TGraph * gr_abs;

TGraph * gr_steel_x;
TGraph * gr_steel_y;
TGraph * gr_steel_z;
TGraph * gr_steel_abs;

TGraph * gr_finite_x;
TGraph * gr_finite_y;
TGraph * gr_finite_z;
TGraph * gr_finite_abs;
//double scale=10675.710891858/10863.6794850346;
//double scale=1500./1483.;
//double scale=1500./1497.45;
double scale=1.;
double pi=TMath::Pi();

int n;
int n_und=85331;
int current=228;
double n_period=14;
double fit_range_min=2*1.5*16.25;
double fit_range_max=2*3.5*16.25;
bool Bx_fit_is_good=0;
bool use_minuit_fit=1;
bool tight_cuts=1;
bool loose_cuts=0;

//minuit stuff
double bx_minuit[50000], by_minuit[50000], z_minuit[50000];
int nz;
double chi2_fit;
double A_max=3000;
double kz_max=1;
double phi_max=pi;
int n_try=700;
double fit_par_res[100], fit_par_res_Err[100];

void field_fit_single()
{
  if (n_period==14)
  {
    fit_range_min=2*2*16.25;
    fit_range_max=2*12*16.25;
  }
/*
  read_field_data("../v0_ideal/ideal.table");
  read_field_data_finite("../v9_many/hundulator_07_m1_908_xyz.table");
  read_field_data_steel("../v7_osc_geom_steel_cor_field/hundulator_07_908_xyz.table");
*/
  n=1;
  read_field_data(  Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_%d_xyz.table", n_und, current));
//  read_field_data(  "field_extended.dat");

  if (use_minuit_fit) do_Minuit();
  draw_plots();
}


void draw_plots()
{
//  hbz_2D->Draw("colz");
//  hbz_1D->Draw("colz");
//  hbx_1D->Draw("colz");
  gr_x->SetMarkerStyle(7);
  gr_y->SetMarkerStyle(7);
  gr_z->SetMarkerStyle(7);
  gr_abs->SetMarkerStyle(7);

  gr_x->SetLineWidth(4);
  gr_y->SetLineWidth(4);
  gr_z->SetLineWidth(4);
  gr_abs->SetLineWidth(4);


  if (n==3)
  {
    gr_steel_x->SetLineWidth(2);
    gr_steel_y->SetLineWidth(2);
    gr_steel_z->SetLineWidth(2);
    gr_steel_abs->SetLineWidth(2);
  }

  if (n>=2)
  {
    gr_finite_x->SetLineWidth(2);
    gr_finite_y->SetLineWidth(2);
    gr_finite_z->SetLineWidth(2);
    gr_finite_abs->SetLineWidth(2);
  }


  if (n==3)
  {
    gr_steel_x->SetLineColor(2);
    gr_steel_y->SetLineColor(2);
    gr_steel_z->SetLineColor(2);
    gr_steel_abs->SetLineColor(2);
  }

  if (n==2)
  {
    gr_finite_x->SetLineColor(4);
    gr_finite_y->SetLineColor(4);
    gr_finite_z->SetLineColor(4);
    gr_finite_abs->SetLineColor(4);
  }


  gr_x->SetMarkerSize(1.5);
  gr_y->SetMarkerSize(1.5);
  gr_z->SetMarkerSize(1.5);
  gr_abs->SetMarkerSize(1.5);

  if (n==3)
  {
    gr_steel_x->SetMarkerStyle(7);
    gr_steel_y->SetMarkerStyle(7);
    gr_steel_z->SetMarkerStyle(7);
    gr_steel_abs->SetMarkerStyle(7);
  }

  if (n>=2)
  {
    gr_finite_x->SetMarkerStyle(7);
    gr_finite_y->SetMarkerStyle(7);
    gr_finite_z->SetMarkerStyle(7);
    gr_finite_abs->SetMarkerStyle(7);
  }

  if (n==3)
  {
    gr_steel_x->SetMarkerColor(2);
    gr_steel_y->SetMarkerColor(2);
    gr_steel_z->SetMarkerColor(2);
    gr_steel_abs->SetMarkerColor(2);
  }

  if (n>=2)
  {
    gr_finite_x->SetMarkerColor(4);
    gr_finite_y->SetMarkerColor(4);
    gr_finite_z->SetMarkerColor(4);
    gr_finite_abs->SetMarkerColor(4);
  }

  gr_abs->SetTitle("#sqrt{B_{x}^{2}+B_{y}^{2}} vs. z");
  gr_x->SetTitle("B_{x} vs. z");
  gr_y->SetTitle("B_{y} vs. z");
  gr_z->SetTitle("B_{z} vs. z");

  gr_abs->SetTitle("B_{xy} [Gauss]");
  gr_x->GetYaxis()->SetTitle("B_{x} [Gauss]");
  gr_y->GetYaxis()->SetTitle("B_{y} [Gauss]");
  gr_z->GetYaxis()->SetTitle("B_{z} [Gauss]");

  gr_abs->GetXaxis()->SetTitle("z [cm]");
  gr_x->GetXaxis()->SetTitle("z [cm]");
  gr_y->GetXaxis()->SetTitle("z [cm]");
  gr_z->GetXaxis()->SetTitle("z [cm]");

  gr_abs->GetXaxis()->SetTitleSize(0.05);
  gr_x->GetXaxis()->SetTitleSize(0.05);
  gr_y->GetXaxis()->SetTitleSize(0.05);
  gr_z->GetXaxis()->SetTitleSize(0.05);

  gr_abs->GetYaxis()->SetTitleSize(0.05);
  gr_x->GetYaxis()->SetTitleSize(0.05);
  gr_y->GetYaxis()->SetTitleSize(0.05);
  gr_z->GetYaxis()->SetTitleSize(0.05);

  gr_abs->GetYaxis()->SetTitleOffset(0.75);
  gr_x->GetYaxis()->SetTitleOffset(0.85);
  gr_y->GetYaxis()->SetTitleOffset(0.85);
  gr_z->GetYaxis()->SetTitleOffset(0.75);


  if (n_und!=94)
  {
    gr_x->SetMinimum(-2500.);
    gr_x->SetMaximum(2500.);
    gr_y->SetMinimum(-2500.);
    gr_y->SetMaximum(2500.);
    gr_z->SetMinimum(-10.);
    gr_z->SetMaximum(10.);
  }
  if (n_und==93)
  if (n_und!=94)
  {
    gr_z->SetMinimum(-300.);
    gr_z->SetMaximum(300.);
  }
  if (n_und!=94)
  {
    gr_abs->SetMaximum(2000.);
//    gr_abs->SetMaximum(1520.);
//    gr_abs->SetMinimum(1480.);
  }

//  fit_range_min=2*2*16.25;
//  fit_range_max=12*2*16.25;
//  fit_range_min=1.4*16.25;
//  fit_range_max=2.6*16.25;
//  fit_range_min=1.75*2*16.25;
//  fit_range_max=3.25*2*16.25;


  TCanvas *c = new TCanvas("cc","cc",100, 0, 1600, 900);
  c->Divide(2,2);

  c->cd(4);
  TF1 * funcz1 = new TF1("funcz1", "[0]", fit_range_min, fit_range_max);
  funcz1->SetParLimits(0, -5, 2500);
  gr_abs->Fit(funcz1, "R");
  gr_abs->Draw("AP");
  if (n==3)
    gr_steel_abs->Draw("PSame");
  if (n>=2)
    gr_finite_abs->Draw("PSame");
  TLine *l4_1 = new TLine(0., 0, 0, 2000);
  TLine *l4_2 = new TLine(n_period*32.5, 0, n_period*32.5, 2000);
  l4_1->SetLineStyle(2);
  l4_2->SetLineStyle(2);
  l4_1->SetLineWidth(2);
  l4_2->SetLineWidth(2);
  l4_1->Draw();
  l4_2->Draw();

  c->cd(1);
  gStyle->SetOptFit(1);
  double k=1./32.5;

  TF1 * funcx1 = new TF1("funcx1", "[0]*cos([1]*x-[2])", fit_range_min, fit_range_max);
  funcx1->SetParLimits(0, 0.999*funcz1->GetParameter(0), 1.001*funcz1->GetParameter(0));
  funcx1->SetParLimits(1, 0.999*2.*pi*k, 1.0011*2.*pi*k);
  funcx1->SetParLimits(2, -3.1416, 3.1416);
  if(use_minuit_fit)
  {
    if (tight_cuts)
    {
      funcx1->SetParLimits(0, 0.999999*fit_par_res[0], 1.000001*fit_par_res[0]);
      funcx1->SetParLimits(1, 0.999999*fit_par_res[1], 1.000001*fit_par_res[1]);
      if (fit_par_res[2]>0)
        funcx1->SetParLimits(2, 0.999999*fit_par_res[2], 1.000001*fit_par_res[2]);
      if (fit_par_res[2]<0)
        funcx1->SetParLimits(2, 1.000001*fit_par_res[2], 0.999999*fit_par_res[2]);
    }
    if (loose_cuts)
    {
      funcx1->SetParLimits(0, 0.9*fit_par_res[0], 1.1*fit_par_res[0]);
      funcx1->SetParLimits(1, 0.9*fit_par_res[1], 1.1*fit_par_res[1]);
      if (fit_par_res[2]>0)
        funcx1->SetParLimits(2, 0.9*fit_par_res[2], 1.1*fit_par_res[2]);
      if (fit_par_res[2]<0)
        funcx1->SetParLimits(2, 1.1*fit_par_res[2], 0.9*fit_par_res[2]);
    }
  }


  TF1 * funcy1 = new TF1("funcy1", "[0]*sin([1]*x-[2])", fit_range_min, fit_range_max);
  funcy1->SetParLimits(0, 0.9*funcz1->GetParameter(0), 1.1*funcz1->GetParameter(0));
  funcy1->SetParLimits(1, 0.99999*2.*pi*k, 1.000011*2.*pi*k);
  funcy1->SetParLimits(2, -3.1416, 3.1416);
//  funcy1->SetParLimits(2, -3.9, -2.3);

  funcx1->SetNpx(5000);
  funcy1->SetNpx(5000);


  funcx1->SetParName(0, "Amplitude");
  funcx1->SetParName(1, "k");
  funcx1->SetParName(2, "#Delta#phi");
  funcy1->SetParName(0, "Amplitude");
  funcy1->SetParName(1, "k");
  funcy1->SetParName(2, "#Delta#phi");


  TF1 * funcx2 = new TF1("funcx2", "[0]*cos([1]*x-[2])", 40, 7000);
  funcx2->SetParLimits(0, 1000, 10000);
  funcx2->SetParLimits(1, 0.999*2.*pi*k, 1.001051*2.*pi*k);
  funcx2->SetParLimits(2, -3.1416, 3.1416);

  TF1 * funcy2 = new TF1("funcy2", "[0]*sin([1]*x-[2])", 40, 7000);
  funcy2->SetParLimits(0, 1000, 10000);
  funcy2->SetParLimits(1, 0.999*2.*pi*k, 1.001051*2.*pi*k);
  funcy2->SetParLimits(2, -3.1416, 3.1416);

  funcx2->SetParName(0, "Amplitude");
  funcx2->SetParName(1, "k");
  funcx2->SetParName(2, "#Delta#phi");
  funcy2->SetParName(0, "Amplitude");
  funcy2->SetParName(1, "k");
  funcy2->SetParName(2, "#Delta#phi");

  ofstream outfile;
  outfile.open("amplitude.txt", ios::out | ios::app );

  gr_x->Draw("AL");
  if (n_und!=94)
    gr_x->Fit(funcx1, "R");
  outfile<<n_und<<"     Ax="<<funcx1->GetParameter(0)<<endl;

  if (Bx_fit_is_good)
  {
    if (tight_cuts)
    {
      funcy1->SetParLimits(0, 0.9999*funcx1->GetParameter(0), 1.0001*funcx1->GetParameter(0));
      funcy1->SetParLimits(1, 0.9999*funcx1->GetParameter(1), 1.0001*funcx1->GetParameter(1));
      if (funcx1->GetParameter(2)>0)
        funcy1->SetParLimits(2, 0.9999*funcx1->GetParameter(2), 1.0001*funcx1->GetParameter(2));
      if (funcx1->GetParameter(2)<0)
        funcy1->SetParLimits(2, 1.0001*funcx1->GetParameter(2), 0.9999*funcx1->GetParameter(2));
    }
    if (loose_cuts)
    {
      funcy1->SetParLimits(0, 0.9*funcx1->GetParameter(0), 1.1*funcx1->GetParameter(0));
      funcy1->SetParLimits(1, 0.9*funcx1->GetParameter(1), 1.1*funcx1->GetParameter(1));
      if (funcx1->GetParameter(2)>0)
        funcy1->SetParLimits(2, 0.9*funcx1->GetParameter(2), 1.1*funcx1->GetParameter(2));
      if (funcx1->GetParameter(2)<0)
        funcy1->SetParLimits(2, 1.1*funcx1->GetParameter(2), 0.9*funcx1->GetParameter(2));
    }
    cout<<"par1="<<funcx1->GetParameter(0)<<endl;
    cout<<"par2="<<funcx1->GetParameter(1)<<endl;
    cout<<"par3="<<funcx1->GetParameter(2)<<endl;
  }
  if(use_minuit_fit)
  {
    if (tight_cuts)
    {
      funcy1->SetParLimits(0, 0.999999*fit_par_res[0], 1.000001*fit_par_res[0]);
      funcy1->SetParLimits(1, 0.999999*fit_par_res[1], 1.000001*fit_par_res[1]);
      if (fit_par_res[2]>0)
        funcy1->SetParLimits(2, 0.999999*fit_par_res[2], 1.000001*fit_par_res[2]);
      if (fit_par_res[2]<0)
        funcy1->SetParLimits(2, 1.000001*fit_par_res[2], 0.999999*fit_par_res[2]);
    }
    if (loose_cuts)
    {
      funcy1->SetParLimits(0, 0.9*fit_par_res[0], 1.1*fit_par_res[0]);
      funcy1->SetParLimits(1, 0.9*fit_par_res[1], 1.1*fit_par_res[1]);
      if (fit_par_res[2]>0)
        funcy1->SetParLimits(2, 0.9*fit_par_res[2], 1.1*fit_par_res[2]);
      if (fit_par_res[2]<0)
        funcy1->SetParLimits(2, 1.1*fit_par_res[2], 0.9*fit_par_res[2]);
    }
  }

  if (n==3)
  if (n>=2)
    gr_finite_x->Draw("LSame");
  TLegend *leg = new TLegend(0.6, 0.8, 0.99, 0.99);
  leg->AddEntry(gr_x, "Smaller peropd lengths at the ends", "l");
  if (n>=2)
    leg->AddEntry(gr_finite_x, "Increased radius at the ends", "l");
  if (n==3)
    leg->AddEntry(gr_steel_x, "Iron (inner) cone at the ends", "l");
  if (n>=2)
    leg->Draw();

  if (n>=2)
  if (n_und!=94)
    gr_finite_x->Fit(funcx2, "R");



  TLine *l1_1 = new TLine(0., -2300, 0, 2300);
  TLine *l1_2 = new TLine(n_period*32.5, -2300, n_period*32.5, 2300);
  l1_1->SetLineStyle(2);
  l1_2->SetLineStyle(2);
  l1_1->SetLineWidth(2);
  l1_2->SetLineWidth(2);
  l1_1->Draw();
  l1_2->Draw();

  c->cd(2);

  gr_y->Draw("AL");
  if (n_und!=94)
    gr_y->Fit(funcy1, "R");
  outfile<<n_und<<"     Ay="<<funcy1->GetParameter(0)<<endl;
  if (n==3)
    gr_steel_y->Draw("LSame");
  if (n>=2)
    gr_finite_y->Draw("LSame");
  if (n>=2)
  if (n_und!=94)
    gr_finite_y->Fit(funcy2, "R");

  TLine *l2_1 = new TLine(0., -2300, 0, 2300);
  TLine *l2_2 = new TLine(n_period*32.5, -2300, n_period*32.5, 2300);
  l2_1->SetLineStyle(2);
  l2_2->SetLineStyle(2);
  l2_1->SetLineWidth(2);
  l2_2->SetLineWidth(2);
  l2_1->Draw();
  l2_2->Draw();
//  leg->Draw();

  c->cd(3);
  gr_z->Draw("AL");
  if (n==3)
    gr_steel_z->Draw("LSame");
  if (n>=2)
    gr_finite_z->Draw("LSame");
  TLine *l3_1 = new TLine(0., -10, 0, 10);
  if (n_und==93)
    l3_1 = new TLine(0., -300, 0, 300);
  gr_z->Fit(funcz1, "R");

  TLine *l3_2 = new TLine(n_period*32.5, -10, n_period*32.5, 10);

  if (n_und==93)
    l3_2 = new TLine(n_period*32.5, -300, n_period*32.5, 300);
  l3_1->SetLineStyle(2);
  l3_2->SetLineStyle(2);
  l3_1->SetLineWidth(2);
  l3_2->SetLineWidth(2);
  l3_1->Draw();
  l3_2->Draw();
//  leg->Draw();

//  leg->Draw();
  gr_x->GetXaxis()->SetRangeUser(-50, n_period*32.5+50);
  gr_y->GetXaxis()->SetRangeUser(-50, n_period*32.5+50);
  gr_z->GetXaxis()->SetRangeUser(-50, n_period*32.5+50);
  gr_abs->GetXaxis()->SetRangeUser(-50, n_period*32.5+50);
  c->cd(4);
//  gr_abs->GetXaxis()->SetRangeUser(-50, n_period*32.5+50);

  c->SaveAs(Form("gif/field/field_%d.gif", n_und));
}

void read_field_data(string fname)
{
  TH1D *hbz_1D = new TH1D("HBz 1d", "HBz 1d", 80, -16, 16);
  TH1D *hbx_1D = new TH1D("HBx 1d", "HBx 1d", 16000, -16, 16);
//  TH1D *hby_1D = new TH1D("HBy 1d", "HBy 1d", 16000, -16, 16);
  TH2D *hbz_2D = new TH2D("HBz 2d", "HBz 2d", 40, -8, 8, 40, -8, 8);
  double x_arr[50000];
  double y_arr[50000];
  double z_arr[50000];
  double bx_arr[50000];
  double by_arr[50000];
  double bx_err[50000];
  double by_err[50000];
  double bz_arr[50000];
  double b_abs[50000];

  string line;
  int nn=0;
  ifstream file_fort(fname.c_str(), ios::in);
  if ( file_fort.is_open() )
  {
    while ( ! file_fort.eof() )
    {
      getline(file_fort,line);
      if(line.size()>50)
      {
//        cout<<line<<endl;
        istringstream vars(line);
        {
          double x, y, z, bx, by, bz;
          vars >> x >> y >>z >> bx >> by >> bz;
          z=z-1.5;
          if (z==0)
          {
//            if (fabs(x) < 1.0) cout<<line<<endl;
            double x0=-8.;
            double x_bin=0.4;
            double y0=-8.;
            double y_bin=0.4;
            int ix=int((x-x0)/x_bin)+1;
            int iy=int((y-y0)/y_bin)+1;

//            hbz_2D->SetBinContent(ix, iy, bz);
            hbz_2D->Fill(x+0.002, y+0.002, bz);
          }
          if ((x==y) && (z==0) && (fabs(x)<5./sqrt(2.)))
            hbz_1D->Fill(sqrt(2)*x, bz);

          if ( (x==0) && (y==0) )
          {
            x_arr[nn]=x;
            y_arr[nn]=y;
//            z_arr[nn]=z-32.4/4.;
            z_arr[nn]=z;
            bx_arr[nn]=scale*bx;
            by_arr[nn]=scale*by;
            bx_err[nn]=1.;
            by_err[nn]=1.;
            bz_arr[nn]=scale*bz;
            bx_minuit[nn]=bx_arr[nn];
            by_minuit[nn]=by_arr[nn];
            z_minuit[nn]=z_arr[nn];
            b_abs[nn]=scale*sqrt(bx*bx+by*by);
            nn++;
            nz=nn;
//            cout<<line<<endl;
            hbx_1D->Fill(z, bx);
          }
          if ( (y==0) && (z==0) )
          {
//            cout<<line<<endl;
          }
        }
      }
    }
  }
  cout<<nn<<endl;
  gr_x = new TGraph (nn, z_arr, bx_arr);
  gr_y = new TGraph (nn, z_arr, by_arr);
  gr_z = new TGraph (nn, z_arr, bz_arr);
  gr_abs = new TGraph (nn, z_arr, b_abs);
}

void read_field_data_steel(string fname)
{
  double x_arr[50000];
  double y_arr[50000];
  double z_arr[50000];
  double bx_arr[50000];
  double by_arr[50000];
  double bz_arr[50000];
  double b_abs[50000];

  string line;
  int nn=0;
//  ifstream file_fort("../v7_osc_geom_steel/hundulator_01_1101_xyz.table", ios::in);
  ifstream file_fort(fname.c_str(), ios::in);
  if ( file_fort.is_open() )
  {
    while ( ! file_fort.eof() )
    {
      getline(file_fort,line);
      if(line.size()>50)
      {
//        cout<<line<<endl;
        istringstream vars(line);
        {
          double x, y, z, bx, by, bz;
          vars >> x >> y >>z >> bx >> by >> bz;
          if (z==0)
          {
//            if (fabs(x) < 1.0) cout<<line<<endl;
            double x0=-8.;
            double x_bin=0.4;
            double y0=-8.;
            double y_bin=0.4;
            int ix=int((x-x0)/x_bin)+1;
            int iy=int((y-y0)/y_bin)+1;
          }
          if ( (x==0.) && (y==0.) )
          {
            x_arr[nn]=x;
            y_arr[nn]=y;
            z_arr[nn]=z;
            bx_arr[nn]=bx;
            by_arr[nn]=by;
            bz_arr[nn]=bz;
            b_abs[nn]=sqrt(bx*bx+by*by);
            nn++;
//            cout<<line<<endl;
          }
        }
      }
    }
  }
  cout<<nn<<endl;
  gr_steel_x = new TGraph (nn, z_arr, bx_arr);
  gr_steel_y = new TGraph (nn, z_arr, by_arr);
  gr_steel_z = new TGraph (nn, z_arr, bz_arr);
  gr_steel_abs = new TGraph (nn, z_arr, b_abs);
}

void read_field_data_finite(string fname)
{
  double x_arr[50000];
  double y_arr[50000];
  double z_arr[50000];
  double bx_arr[50000];
  double by_arr[50000];
  double bz_arr[50000];
  double b_abs[50000];

  string line;
  int nn=0;
//  ifstream file_fort("../v7_osc_geom_steel/hundulator_01_1101_xyz.table", ios::in);
  ifstream file_fort(fname.c_str(), ios::in);
  if ( file_fort.is_open() )
  {
    while ( ! file_fort.eof() )
    {
      getline(file_fort,line);
      if(line.size()>50)
      {
//        cout<<line<<endl;
        istringstream vars(line);
        {
          double x, y, z, bx, by, bz;
          vars >> x >> y >>z >> bx >> by >> bz;
          if (z==0)
          {
//            if (fabs(x) < 1.0) cout<<line<<endl;
            double x0=-8.;
            double x_bin=0.4;
            double y0=-8.;
            double y_bin=0.4;
            int ix=int((x-x0)/x_bin)+1;
            int iy=int((y-y0)/y_bin)+1;
          }
          if ( (x==0.) && (y==0.) )
          {
            x_arr[nn]=x;
            y_arr[nn]=y;
            z_arr[nn]=z;
            bx_arr[nn]=bx;
            by_arr[nn]=by;
            bz_arr[nn]=bz;
            b_abs[nn]=sqrt(bx*bx+by*by);
            nn++;
//            cout<<line<<endl;
          }
        }
      }
    }
  }
  cout<<nn<<endl;
  gr_finite_x = new TGraph (nn, z_arr, bx_arr);
  gr_finite_y = new TGraph (nn, z_arr, by_arr);
  gr_finite_z = new TGraph (nn, z_arr, bz_arr);
  gr_finite_abs = new TGraph (nn, z_arr, b_abs);
}

void fcn_minuit(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  //this function is needed by minuit
  //it will fit the data points using function func_new()
//calculate chisquare
  Double_t chisq = 0;
  Double_t chi2_0 = 0;
  Double_t delta2 = 0;

  for (int i_z=0; i_z<nz; i_z++)
  if ( (fit_range_min<z_minuit[i_z]) && (z_minuit[i_z]<fit_range_max) )
  {
    double bx_func = func_cos(z_minuit[i_z], par);
    double by_func = func_sin(z_minuit[i_z], par);
//    cout<<z_minuit[i_z]<<
    delta2  = (bx_func-bx_minuit[i_z])*(bx_func-bx_minuit[i_z]);
    delta2 += (by_func-by_minuit[i_z])*(by_func-by_minuit[i_z]);
    chisq += delta2;
  }
  f = chisq;
  chi2_fit=f;
}


double func_sin(double z, Double_t *par)
{
  double bfield_fn=par[0]*sin(par[1]*z-par[2]);
  return bfield_fn;
}

double func_cos(double z, Double_t *par)
{
  double bfield_fn=par[0]*cos(par[1]*z-par[2]);
  return bfield_fn;
}

void do_Minuit()
{
    const int n_max_pars=3;
    clog<<"fitting data..."<<endl;
    TMinuit *gMinuit_fit_pars = new TMinuit(n_max_pars);  //initialize TMinuit with a maximum of 60
    gMinuit_fit_pars->SetPrintLevel(-1);
    TRandom3 * rnd_2 = new TRandom3(0);
    gMinuit_fit_pars->SetFCN(fcn_minuit);

    Double_t arglist[10];
    Int_t ierflg = 0;

    arglist[0] = 1;
    gMinuit_fit_pars->mnexcm("SET ERR", arglist ,1, ierflg);

//  Set starting values and step sizes for parameters

    Double_t vstart[n_max_pars];
    Double_t step[n_max_pars];

    double fit_pars[n_max_pars];
    for (int i=0; i<n_max_pars; i++)
    {
      step[i]=0.00001;
      fit_pars[i]=0.;
    }

    if(1)
    {
      fit_pars[0] = 1500.0;
      fit_pars[1] = 0.1933;
      fit_pars[2] = -1.874;
      int npar_tmp=0;
      Int_t & npar_tmp1=npar_tmp;
      double f_tmp=0;
      Double_t &f_tmp1=f_tmp;
      fcn_minuit(npar_tmp1, 0, f_tmp1,fit_pars, 0);
      cout<<"chi2 relative to 0 is "<<chi2_fit<<";"<<endl;
    }


    int itry=0;
    double chi2_min_best=1.e+30;
    while (itry<n_try)
    {
      itry++;
      vstart[0] = A_max*rnd_2->Rndm(); //from 0 to A_max
      vstart[1] = kz_max*rnd_2->Rndm(); //from 0 to kz_max
      vstart[2] = (2.*rnd_2->Rndm()-1)*phi_max; //from -phi_max to phi_max
      gMinuit_fit_pars->mnparm(0, "par_0_A1_", vstart[0],  step[0],  1.e-5*A_max, A_max,  ierflg);
      gMinuit_fit_pars->mnparm(1, "par_1_kz",  vstart[1],  step[1],  0.000,       kz_max, ierflg);
      gMinuit_fit_pars->mnparm(2, "par_2_phi", vstart[2],  step[2], -1*phi_max,   phi_max, ierflg);

      arglist[0] = 1000000;
      arglist[1] = 0.0001;

      gMinuit_fit_pars->mnexcm("MIGRAD", arglist ,2,ierflg);
//      cout<<"chi2 after fit is "<<chi2_fit<<";"<<endl;


//      clog<<itry<<"     chi2="<<chi2_fit<<endl;
      if (chi2_min_best>chi2_fit)
      {
        chi2_min_best = chi2_fit;
        clog<<endl<<"try:"<<itry<<" better fit parameters are found   with chi2="<<chi2_fit<<endl;
        clog<<"\033[1;34m If you are not satisfied with the current results, let the code continue working (to avoid local minimums) \033[0m "<<endl;

        for (int i=0; i<n_max_pars; i++)
        {
          gMinuit_fit_pars->GetParameter(i, fit_par_res[i], fit_par_res_Err[i]);
          cout<<"par:"<<i<<setw(20)<<fit_par_res[i]<<setw(20)<<"    error: "<<fit_par_res_Err[i]<<endl;
        }
      }
    }
    delete gMinuit_fit_pars;
    delete rnd_2;

}


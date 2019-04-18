
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
double scale=1.;

int n;
int n_und=8728;
int current=300;
void field_fit_single()
{
/*
  read_field_data("../v0_ideal/ideal.table");
  read_field_data_finite("../v9_many/hundulator_07_m1_908_xyz.table");
  read_field_data_steel("../v7_osc_geom_steel_cor_field/hundulator_07_908_xyz.table");
*/
  n=1;
  read_field_data(  Form("../v9_4_many_xare/hundulator_%d_%d_xyz.table", n_und, current));
//  read_field_data(       "../v9_4_many_xare/hundulator_73_414_xyz.table");
  if (n>=2)
    read_field_data_finite("../v9_4_many_xare/hundulator_24_1130_xyz.table");
//  read_field_data_steel( "../v9_4_many_xare/hundulator_05_908_xyz.table");

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


  if (n_und!=94)
  {
    gr_x->SetMinimum(-0.3*10000.);
    gr_x->SetMaximum(0.3*10000.);
    gr_y->SetMinimum(-0.3*10000.);
    gr_y->SetMaximum(0.3*10000.);
    gr_z->SetMinimum(-0.001*10000.);
    gr_z->SetMaximum(0.001*10000.);
  }
  if (n_und==93)
  if (n_und!=94)
  {
    gr_z->SetMinimum(-300.);
    gr_z->SetMaximum(300.);
  }
  if (n_und!=94)
    gr_abs->SetMaximum(0.3*10000.);

  TCanvas *c = new TCanvas("cc","cc",100, 0, 1600, 900);
  c->Divide(2,2);

  c->cd(1);
  gStyle->SetOptFit(1);
  double pi=TMath::Pi();
  double k=1./32.5;

  TF1 * funcx1 = new TF1("funcx1", "[0]*cos([1]*x-[2])", 40, 122.5-32.5);
  funcx1->SetParLimits(0, 650, 2500);
  funcx1->SetParLimits(1, 0.999*2.*pi*k, 1.00011*2.*pi*k);
  funcx1->SetParLimits(2, -3.1416, 3.1416);


  TF1 * funcy1 = new TF1("funcy1", "[0]*sin([1]*x-[2])", 40, 122.5-32.5);
  funcy1->SetParLimits(0, 650, 2500);
  funcy1->SetParLimits(1, 0.999*2.*pi*k, 1.00011*2.*pi*k);
  funcy1->SetParLimits(2, -3.1416, 3.1416);
//  funcy1->SetParLimits(2, -3.9, -2.3);


  funcx1->SetParName(0, "Amplitude");
  funcx1->SetParName(1, "k");
  funcx1->SetParName(2, "#Delta#phi");
  funcy1->SetParName(0, "Amplitude");
  funcy1->SetParName(1, "k");
  funcy1->SetParName(2, "#Delta#phi");


  TF1 * funcx2 = new TF1("funcx2", "[0]*cos([1]*x-[2])", 40, 7000);
  funcx2->SetParLimits(0, 1000, 10000);
  funcx2->SetParLimits(1, 0.9905*2.*pi*k, 1.01051*2.*pi*k);
  funcx2->SetParLimits(2, -3.1416, 3.1416);

  TF1 * funcy2 = new TF1("funcy2", "[0]*sin([1]*x-[2])", 40, 7000);
  funcy2->SetParLimits(0, 1000, 10000);
  funcy2->SetParLimits(1, 0.9905*2.*pi*k, 1.01051*2.*pi*k);
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
  TLine *l1_2 = new TLine(162.5, -2300, 162.5, 2300);
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
  TLine *l2_2 = new TLine(162.5, -2300, 162.5, 2300);
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

  TLine *l3_2 = new TLine(162.5, -10, 162.5, 10);

  if (n_und==93)
    l3_2 = new TLine(162.5, -300, 162.5, 300);
  l3_1->SetLineStyle(2);
  l3_2->SetLineStyle(2);
  l3_1->SetLineWidth(2);
  l3_2->SetLineWidth(2);
  l3_1->Draw();
  l3_2->Draw();
//  leg->Draw();

  c->cd(4);
  TF1 * funcz1 = new TF1("funcz1", "[0]", 40, 122.5-32.5);
  funcz1->SetParLimits(0, 650, 2500);
  gr_abs->Fit(funcz1, "R");
  gr_abs->Draw("AP");
  if (n==3)
    gr_steel_abs->Draw("PSame");
  if (n>=2)
    gr_finite_abs->Draw("PSame");
  TLine *l4_1 = new TLine(0., 0, 0, 2300);
  TLine *l4_2 = new TLine(162.5, 0, 162.5, 2300);
  l4_1->SetLineStyle(2);
  l4_2->SetLineStyle(2);
  l4_1->SetLineWidth(2);
  l4_2->SetLineWidth(2);
  l4_1->Draw();
  l4_2->Draw();
//  leg->Draw();
  c->SaveAs(Form("field_%d.gif", n_und));
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
            b_abs[nn]=scale*sqrt(bx*bx+by*by);
            nn++;
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



void read_field_data(string);
void read_field_data_3(string);
void read_field_data_2(string);
void read_field_data_1(string);
void draw_plots();

double bx_diff_arr[10000];
double by_diff_arr[10000];
double bz_diff_arr[10000];
double babs_diff_arr[10000];

TGraph * gr_x_diff;
TGraph * gr_y_diff;
TGraph * gr_z_diff;
TGraph * gr_abs_diff;

TGraph * gr_x;
TGraph * gr_y;
TGraph * gr_z;
TGraph * gr_abs;

TGraph * gr_2_x;
TGraph * gr_2_y;
TGraph * gr_2_z;
TGraph * gr_2_abs;

TGraph * gr_3_x;
TGraph * gr_3_y;
TGraph * gr_3_z;
TGraph * gr_3_abs;

TGraph * gr_1_x;
TGraph * gr_1_y;
TGraph * gr_1_z;
TGraph * gr_1_abs;

int n;
int i_und1;
int i_und2;

double x_0=0.0;
double  y_0=0.0;
double n_turns=5;
double scale=1;

void field_compare()
{
/*
  read_field_data("../v0_ideal/ideal.table");
  read_field_data_1("../v9_many/hundulator_07_m1_908_xyz.table");
  read_field_data_2("../v7_osc_geom_2_cor_field/hundulator_07_908_xyz.table");
*/
  n=2;
//  read_field_data(  "../v9_4_many_xare/hundulator_602_393_xyz.table");
//  read_field_data_1("../v9_4_many_xare/hundulator_702_393_xyz.table");
//  read_field_data_2("../v9_4_many_xare/hundulator_803_393_xyz.table");
  i_und1=85352;
  i_und2=85342;
//  read_field_data("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_82044771_228_xyz.table");
//  read_field_data("field_extended.dat");
  scale=1500./1485.2;
  read_field_data(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_228_xyz.table", i_und1));
//  scale=1500./1497.45;
  scale=1500./1489.7;
  read_field_data_1(Form("/nfs/acc/user/vk348/opera/v9_4_many_xare/hundulator_%d_228_xyz.table", i_und2));
//  read_field_data_2("../v9_4_many_xare/hundulator_66005_450_xyz.table");
//  read_field_data_3("../v9_4_many_xare/hundulator_66007_450_xyz.table");
//  read_field_data_3( "../v9_4_many_xare/hundulator_905_393_xyz.table");

  draw_plots();
}
/*
66010 - 906
66011 - 907
66013 - 909
66015 - 902
66016 - 901

66000 - 916
66001 - 917
66003 - 919
66005 - 912
66006 - 911
*/

void draw_plots()
{
//  hbz_2D->Draw("colz");
//  hbz_1D->Draw("colz");
//  hbx_1D->Draw("colz");
  gr_x->SetMarkerStyle(7);
  gr_y->SetMarkerStyle(7);
  gr_z->SetMarkerStyle(7);
  gr_abs->SetMarkerStyle(7);

  gr_x_diff->SetMarkerStyle(7);
  gr_y_diff->SetMarkerStyle(7);
  gr_z_diff->SetMarkerStyle(7);
  gr_abs_diff->SetMarkerStyle(7);

  gr_x->SetLineWidth(4);
  gr_y->SetLineWidth(4);
  gr_z->SetLineWidth(4);
  gr_abs->SetLineWidth(4);

  gr_x_diff->SetLineWidth(3);
  gr_y_diff->SetLineWidth(3);
  gr_z_diff->SetLineWidth(3);
  gr_abs_diff->SetLineWidth(3);


  if (n>=3)
  {
    gr_2_x->SetLineWidth(2);
    gr_2_y->SetLineWidth(2);
    gr_2_z->SetLineWidth(2);
    gr_2_abs->SetLineWidth(2);
  }

  if (n==4)
  {
    gr_3_x->SetLineWidth(2);
    gr_3_y->SetLineWidth(2);
    gr_3_z->SetLineWidth(2);
    gr_3_abs->SetLineWidth(2);
  }

  gr_1_x->SetLineWidth(2);
  gr_1_y->SetLineWidth(2);
  gr_1_z->SetLineWidth(2);
  gr_1_abs->SetLineWidth(2);


  if (n>=3)
  {
    gr_2_x->SetLineColor(2);
    gr_2_y->SetLineColor(2);
    gr_2_z->SetLineColor(2);
    gr_2_abs->SetLineColor(2);
  }

  if (n==4)
  {
    gr_3_x->SetLineColor(3);
    gr_3_y->SetLineColor(3);
    gr_3_z->SetLineColor(3);
    gr_3_abs->SetLineColor(3);
  }

  gr_1_x->SetLineColor(4);
  gr_1_y->SetLineColor(4);
  gr_1_z->SetLineColor(4);
  gr_1_abs->SetLineColor(4);


  gr_x->SetMarkerSize(1.5);
  gr_y->SetMarkerSize(1.5);
  gr_z->SetMarkerSize(1.5);
  gr_abs->SetMarkerSize(1.5);

  if (n>=3)
  {
    gr_2_x->SetMarkerStyle(7);
    gr_2_y->SetMarkerStyle(7);
    gr_2_z->SetMarkerStyle(7);
    gr_2_abs->SetMarkerStyle(7);
  }

  if (n==4)
  {
    gr_3_x->SetMarkerStyle(7);
    gr_3_y->SetMarkerStyle(7);
    gr_3_z->SetMarkerStyle(7);
    gr_3_abs->SetMarkerStyle(7);
  }

  gr_1_x->SetMarkerStyle(7);
  gr_1_y->SetMarkerStyle(7);
  gr_1_z->SetMarkerStyle(7);
  gr_1_abs->SetMarkerStyle(7);

  if (n>=3)
  {
    gr_2_x->SetMarkerColor(2);
    gr_2_y->SetMarkerColor(2);
    gr_2_z->SetMarkerColor(2);
    gr_2_abs->SetMarkerColor(2);
  }

  if (n>=4)
  {
    gr_3_x->SetMarkerColor(3);
    gr_3_y->SetMarkerColor(3);
    gr_3_z->SetMarkerColor(3);
    gr_3_abs->SetMarkerColor(3);
  }

  gr_1_x->SetMarkerColor(4);
  gr_1_y->SetMarkerColor(4);
  gr_1_z->SetMarkerColor(4);
  gr_1_abs->SetMarkerColor(4);

  gr_abs->SetTitle("#sqrt{B_{x}^{2}+B_{y}^{2}} vs. z");
  gr_x->SetTitle("B_{x} vs. z");
  gr_y->SetTitle("B_{y} vs. z");
  gr_z->SetTitle("B_{z} vs. z");

  gr_abs->GetYaxis()->SetTitle("B_{xy} [Gauss]");
  gr_x->GetYaxis()->SetTitle("B_{x} [Gauss]");
  gr_y->GetYaxis()->SetTitle("B_{y} [Gauss]");
  gr_z->GetYaxis()->SetTitle("B_{z} [Gauss]");

  gr_abs->GetYaxis()->SetTitleOffset(0.85);
  gr_x->GetYaxis()->SetTitleOffset(0.85);
  gr_y->GetYaxis()->SetTitleOffset(0.85);
  gr_z->GetYaxis()->SetTitleOffset(0.85);

  gr_abs->GetYaxis()->SetTitleSize(0.05);
  gr_x->GetYaxis()->SetTitleSize(0.05);
  gr_y->GetYaxis()->SetTitleSize(0.05);
  gr_z->GetYaxis()->SetTitleSize(0.05);

  gr_abs->GetXaxis()->SetTitleSize(0.05);
  gr_x->GetXaxis()->SetTitleSize(0.05);
  gr_y->GetXaxis()->SetTitleSize(0.05);
  gr_z->GetXaxis()->SetTitleSize(0.05);

  gr_abs->GetXaxis()->SetTitle("z [cm]");
  gr_x->GetXaxis()->SetTitle("z [cm]");
  gr_y->GetXaxis()->SetTitle("z [cm]");
  gr_z->GetXaxis()->SetTitle("z [cm]");

  gr_abs_diff->SetTitle("Difference of #sqrt{B_{x}^{2}+B_{y}^{2}} vs. z");
  gr_x_diff->SetTitle("Difference of B_{x} vs. z");
  gr_y_diff->SetTitle("Difference of B_{y} vs. z");
  gr_z_diff->SetTitle("Difference of B_{z} vs. z");

  gr_abs_diff->GetYaxis()->SetTitle("#DeltaB_{xy} [Gauss]");
  gr_x_diff->GetYaxis()->SetTitle("#DeltaB_{x} [Gauss]");
  gr_y_diff->GetYaxis()->SetTitle("#DeltaB_{y} [Gauss]");
  gr_z_diff->GetYaxis()->SetTitle("#DeltaB_{z} [Gauss]");

  gr_abs_diff->GetXaxis()->SetTitle("z [cm]");
  gr_x_diff->GetXaxis()->SetTitle("z [cm]");
  gr_y_diff->GetXaxis()->SetTitle("z [cm]");
  gr_z_diff->GetXaxis()->SetTitle("z [cm]");

  gr_abs_diff->GetXaxis()->SetTitleSize(0.05);
  gr_x_diff->GetXaxis()->SetTitleSize(0.05);
  gr_y_diff->GetXaxis()->SetTitleSize(0.05);
  gr_z_diff->GetXaxis()->SetTitleSize(0.05);

  gr_abs_diff->GetYaxis()->SetTitleSize(0.05);
  gr_x_diff->GetYaxis()->SetTitleSize(0.05);
  gr_y_diff->GetYaxis()->SetTitleSize(0.05);
  gr_z_diff->GetYaxis()->SetTitleSize(0.05);

  gr_abs_diff->GetXaxis()->SetLabelSize(0.05);
  gr_x_diff->GetXaxis()->SetLabelSize(0.05);
  gr_y_diff->GetXaxis()->SetLabelSize(0.05);
  gr_z_diff->GetXaxis()->SetLabelSize(0.05);
  gr_abs_diff->GetYaxis()->SetLabelSize(0.05);
  gr_x_diff->GetYaxis()->SetLabelSize(0.05);
  gr_y_diff->GetYaxis()->SetLabelSize(0.05);
  gr_z_diff->GetYaxis()->SetLabelSize(0.05);


  gr_x->SetMinimum(-0.23*10000.);
  gr_x->SetMaximum(0.23*10000.);
  gr_y->SetMinimum(-0.23*10000.);
  gr_y->SetMaximum(0.23*10000.);
  gr_z->SetMinimum(-0.001*10000.);
  gr_z->SetMaximum(0.001*10000.);
  gr_abs->SetMaximum(0.23*10000.);

  TCanvas *c = new TCanvas("cc","cc",100, 0, 1600, 900);
  c->Divide(2,2);

  c->cd(1);
  gr_x->Draw("AL");
  if (n>=3)
    gr_2_x->Draw("LSame");
  if (n>=4)
    gr_3_x->Draw("LSame");
  gr_1_x->Draw("LSame");
  TLegend *leg = new TLegend(0.6, 0.8, 0.99, 0.99);
  leg->AddEntry(gr_x, "Model 1 (ideal und.)", "l");
  leg->AddEntry(gr_1_x, "Model 2 (modified und.)", "l");
  if (n>=3)
    leg->AddEntry(gr_2_x, "Model 3", "l");
  if (n>=4)
    leg->AddEntry(gr_3_x, "Model 4", "l");
  leg->Draw();
  TLine *l1_1 = new TLine(0., -2300, 0, 2300);
  TLine *l1_2 = new TLine(n_turns*32.5, -2300, n_turns*32.5, 2300);
  l1_1->SetLineStyle(2);
  l1_2->SetLineStyle(2);
  l1_1->SetLineWidth(2);
  l1_2->SetLineWidth(2);
  l1_1->Draw();
  l1_2->Draw();

  c->cd(2);
  gr_y->Draw("AL");
  if (n>=3)
    gr_2_y->Draw("LSame");
  if (n>=4)
    gr_3_y->Draw("LSame");
  gr_1_y->Draw("LSame");
  TLine *l2_1 = new TLine(0., -2300, 0, 2300);
  TLine *l2_2 = new TLine(n_turns*32.5, -2300, n_turns*32.5, 2300);
  l2_1->SetLineStyle(2);
  l2_2->SetLineStyle(2);
  l2_1->SetLineWidth(2);
  l2_2->SetLineWidth(2);
  l2_1->Draw();
  l2_2->Draw();
//  leg->Draw();

  c->cd(3);
  gr_z->Draw("AL");
  if (n>=3)
    gr_2_z->Draw("LSame");
  if (n>=4)
    gr_3_z->Draw("LSame");
  gr_1_z->Draw("LSame");
  TLine *l3_1 = new TLine(0., -10, 0, 10);
  TLine *l3_2 = new TLine(n_turns*32.5, -10, n_turns*32.5, 10);
  l3_1->SetLineStyle(2);
  l3_2->SetLineStyle(2);
  l3_1->SetLineWidth(2);
  l3_2->SetLineWidth(2);
  l3_1->Draw();
  l3_2->Draw();
//  leg->Draw();

  c->cd(4);
  gr_abs->Draw("AP");
  if (n>=3)
    gr_2_abs->Draw("PSame");
  if (n>=4)
    gr_3_abs->Draw("PSame");
  gr_1_abs->Draw("PSame");
  TLine *l4_1 = new TLine(0., 0, 0, 2300);
  TLine *l4_2 = new TLine(n_turns*32.5, 0, n_turns*32.5, 2300);
  l4_1->SetLineStyle(2);
  l4_2->SetLineStyle(2);
  l4_1->SetLineWidth(2);
  l4_2->SetLineWidth(2);
  l4_1->Draw();
  l4_2->Draw();
  leg->Draw();
  c->SaveAs(Form("field_compare_%d_%d_autosave.gif", i_und1, i_und2));

  TCanvas *c2 = new TCanvas("c2","c2",100, 0, 1600, 700);
  c2->Divide(2,2);
  c2->cd(1);
  gr_x_diff->Draw("APC");

  c2->cd(2);
  gr_y_diff->Draw("APC");

  c2->cd(3);
  gr_z_diff->Draw("APC");

  c2->cd(4);
  gr_abs_diff->Draw("APC");

  c2->SaveAs(Form("field_compare_%d_%d_difference.gif", i_und1, i_und2));
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

          if ( (x==x_0) && (y==y_0) )
          {
            x_arr[nn]=x;
            y_arr[nn]=y;
//            z_arr[nn]=z-32.4/4.;
            z_arr[nn]=z;
            bx_arr[nn]=scale*bx;
            by_arr[nn]=scale*by;
            bz_arr[nn]=scale*bz;
            b_abs[nn]=scale*sqrt(bx*bx+by*by);
            bx_diff_arr[nn]=bx_arr[nn];
            by_diff_arr[nn]=by_arr[nn];
            bz_diff_arr[nn]=bz_arr[nn];
            babs_diff_arr[nn]=b_abs[nn];
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

void read_field_data_3(string fname)
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
          if ( (x==x_0) && (y==y_0) )
          {
            x_arr[nn]=x;
            y_arr[nn]=y;
            z_arr[nn]=z;
            bx_arr[nn]=scale*bx;
            by_arr[nn]=scale*by;
            bz_arr[nn]=scale*bz;
            b_abs[nn]=scale*sqrt(bx*bx+by*by);
            nn++;
//            cout<<line<<endl;
          }
        }
      }
    }
  }
  cout<<nn<<endl;
  gr_3_x = new TGraph (nn, z_arr, bx_arr);
  gr_3_y = new TGraph (nn, z_arr, by_arr);
  gr_3_z = new TGraph (nn, z_arr, bz_arr);
  gr_3_abs = new TGraph (nn, z_arr, b_abs);
}

void read_field_data_2(string fname)
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
          if ( (x==x_0) && (y==y_0) )
          {
            x_arr[nn]=x;
            y_arr[nn]=y;
            z_arr[nn]=z;
            bx_arr[nn]=scale*bx;
            by_arr[nn]=scale*by;
            bz_arr[nn]=scale*bz;
            b_abs[nn]=scale*sqrt(bx*bx+by*by);
            nn++;
//            cout<<line<<endl;
          }
        }
      }
    }
  }
  cout<<nn<<endl;
  gr_2_x = new TGraph (nn, z_arr, bx_arr);
  gr_2_y = new TGraph (nn, z_arr, by_arr);
  gr_2_z = new TGraph (nn, z_arr, bz_arr);
  gr_2_abs = new TGraph (nn, z_arr, b_abs);
}

void read_field_data_1(string fname)
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
          if ( (x==x_0) && (y==y_0) )
          {
            x_arr[nn]=x;
            y_arr[nn]=y;
            z_arr[nn]=z;
            bx_arr[nn]=scale*bx;
            by_arr[nn]=scale*by;
            bz_arr[nn]=scale*bz;
            b_abs[nn]=scale*sqrt(bx*bx+by*by);
            bx_diff_arr[nn]-=bx_arr[nn];
            by_diff_arr[nn]-=by_arr[nn];
            bz_diff_arr[nn]-=bz_arr[nn];
            babs_diff_arr[nn]-=b_abs[nn];
            nn++;
//            cout<<line<<endl;
          }
        }
      }
    }
  }
  cout<<nn<<endl;
  gr_1_x = new TGraph (nn, z_arr, bx_arr);
  gr_1_y = new TGraph (nn, z_arr, by_arr);
  gr_1_z = new TGraph (nn, z_arr, bz_arr);
  gr_1_abs = new TGraph (nn, z_arr, b_abs);

  gr_x_diff = new TGraph (nn, z_arr, bx_diff_arr);
  gr_y_diff = new TGraph (nn, z_arr, by_diff_arr);
  gr_z_diff = new TGraph (nn, z_arr, bz_diff_arr);
  gr_abs_diff = new TGraph (nn, z_arr, babs_diff_arr);
}


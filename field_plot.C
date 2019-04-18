
void read_field_data(string);
void read_field_data_3(string);
void read_field_data_2(string);
void read_field_data_4(string);
void draw_plots();

TH2D *hbx_2D = new TH2D("Bx [Gaus] vs [x:z]", "Bx [Gaus] vs [x:z]", 400, -100, 300, 21, -1.05, 1.05);
TH2D *hby_2D = new TH2D("By [Gaus] vs [x:z]", "By [Gaus] vs [x:z]", 400, -100, 300, 21, -1.05, 1.05);
TH2D *hbz_2D = new TH2D("Bz [Gaus] vs [x:z]", "Bz [Gaus] vs [x:z]", 400, -100, 300, 21, -1.05, 1.05);
TH2D *hb_2D = new TH2D("B [Gaus] vs [x:z]", "B [Gaus] vs [x:z]", 400, -100, 300, 21, -1.05, 1.05);

TGraph * gr_x;
TGraph * gr_y;
TGraph * gr_z;
TGraph * gr_abs;

TGraph * gr_3_x;
TGraph * gr_3_y;
TGraph * gr_3_z;
TGraph * gr_3_abs;

TGraph * gr_4_x;
TGraph * gr_4_y;
TGraph * gr_4_z;
TGraph * gr_4_abs;

TGraph * gr_2_x;
TGraph * gr_2_y;
TGraph * gr_2_z;
TGraph * gr_2_abs;

int n=3;

void field_plot()
{
  read_field_data(       "../v9_4_many_xare/hundulator_8200_248_xyz.table");
  read_field_data_2(     "../v9_4_many_xare/hundulator_82001_248_xyz.table");
  read_field_data_3(     "../v9_4_many_xare/hundulator_82002_248_xyz.table");
  read_field_data_4(     "../v9_4_many_xare/hundulator_82003_248_xyz.table");
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


  if (n>=3)
  {
    gr_3_x->SetLineWidth(2);
    gr_3_y->SetLineWidth(2);
    gr_3_z->SetLineWidth(2);
    gr_3_abs->SetLineWidth(2);

    gr_4_x->SetLineWidth(2);
    gr_4_y->SetLineWidth(2);
    gr_4_z->SetLineWidth(2);
    gr_4_abs->SetLineWidth(2);
  }

  gr_2_x->SetLineWidth(2);
  gr_2_y->SetLineWidth(2);
  gr_2_z->SetLineWidth(2);
  gr_2_abs->SetLineWidth(2);


  if (n>=3)
  {
    gr_3_x->SetLineColor(2);
    gr_3_y->SetLineColor(2);
    gr_3_z->SetLineColor(2);
    gr_3_abs->SetLineColor(2);

    gr_4_x->SetLineColor(3);
    gr_4_y->SetLineColor(3);
    gr_4_z->SetLineColor(3);
    gr_4_abs->SetLineColor(3);
  }

  gr_2_x->SetLineColor(4);
  gr_2_y->SetLineColor(4);
  gr_2_z->SetLineColor(4);
  gr_2_abs->SetLineColor(4);


  gr_x->SetMarkerSize(1.5);
  gr_y->SetMarkerSize(1.5);
  gr_z->SetMarkerSize(1.5);
  gr_abs->SetMarkerSize(1.5);

  if (n>=3)
  {
    gr_3_x->SetMarkerStyle(7);
    gr_3_y->SetMarkerStyle(7);
    gr_3_z->SetMarkerStyle(7);
    gr_3_abs->SetMarkerStyle(7);

    gr_4_x->SetMarkerStyle(7);
    gr_4_y->SetMarkerStyle(7);
    gr_4_z->SetMarkerStyle(7);
    gr_4_abs->SetMarkerStyle(7);
  }

  gr_2_x->SetMarkerStyle(7);
  gr_2_y->SetMarkerStyle(7);
  gr_2_z->SetMarkerStyle(7);
  gr_2_abs->SetMarkerStyle(7);

  if (n>=3)
  {
    gr_3_x->SetMarkerColor(2);
    gr_3_y->SetMarkerColor(2);
    gr_3_z->SetMarkerColor(2);
    gr_3_abs->SetMarkerColor(2);

    gr_4_x->SetMarkerColor(3);
    gr_4_y->SetMarkerColor(3);
    gr_4_z->SetMarkerColor(3);
    gr_4_abs->SetMarkerColor(3);
  }

  gr_2_x->SetMarkerColor(4);
  gr_2_y->SetMarkerColor(4);
  gr_2_z->SetMarkerColor(4);
  gr_2_abs->SetMarkerColor(4);

  gr_abs->SetTitle("#sqrt{B_{x}^{2}+B_{y}^{2}} vs. z");
  gr_x->SetTitle("B_{x} vs. z");
  gr_y->SetTitle("B_{y} vs. z");
  gr_z->SetTitle("B_{z} vs. z");

  gr_abs->SetTitle("B_{xy} [Gaus]");
  gr_x->GetYaxis()->SetTitle("B_{x} [Gaus]");
  gr_y->GetYaxis()->SetTitle("B_{y} [Gaus]");
  gr_z->GetYaxis()->SetTitle("B_{z} [Gaus]");

  gr_abs->GetXaxis()->SetTitle("z [cm]");
  gr_x->GetXaxis()->SetTitle("z [cm]");
  gr_y->GetXaxis()->SetTitle("z [cm]");
  gr_z->GetXaxis()->SetTitle("z [cm]");


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
  {
    gr_4_x->Draw("LSame");
    gr_3_x->Draw("LSame");
  }
  gr_2_x->Draw("LSame");
  TLegend *leg = new TLegend(0.6, 0.8, 0.99, 0.99);
  leg->AddEntry(gr_2_x, "1 period model", "l");
  if (n>=3)
  {
    leg->AddEntry(gr_3_x, "2 period model", "l");
    leg->AddEntry(gr_4_x, "3 period model", "l");
  }
  leg->AddEntry(gr_x, "5 period model", "l");
  leg->Draw();
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
  if (n>=3)
  {
    gr_4_y->Draw("LSame");
    gr_3_y->Draw("LSame");
  }
  gr_2_y->Draw("LSame");
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
  if (n>=3)
  {
    gr_4_z->Draw("LSame");
    gr_3_z->Draw("LSame");
  }
  gr_2_z->Draw("LSame");
  TLine *l3_1 = new TLine(0., -10, 0, 10);
  TLine *l3_2 = new TLine(162.5, -10, 162.5, 10);
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
  {
    gr_4_abs->Draw("PSame");
    gr_3_abs->Draw("PSame");
  }
  gr_2_abs->Draw("PSame");
  TLine *l4_1 = new TLine(0., 0, 0, 2300);
  TLine *l4_2 = new TLine(162.5, 0, 162.5, 2300);
  l4_1->SetLineStyle(2);
  l4_2->SetLineStyle(2);
  l4_1->SetLineWidth(2);
  l4_2->SetLineWidth(2);
  l4_1->Draw();
  l4_2->Draw();
  leg->Draw();
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
            bx_arr[nn]=1.*bx;
            by_arr[nn]=1.*by;
            bx_err[nn]=1.;
            by_err[nn]=1.;
            bz_arr[nn]=1.*bz;
            b_abs[nn]=1.*sqrt(bx*bx+by*by);
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

void read_field_data_4(string fname)
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
//  ifstream file_fort("../v7_osc_geom_4/hundulator_01_1101_xyz.table", ios::in);
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
  gr_4_x = new TGraph (nn, z_arr, bx_arr);
  gr_4_y = new TGraph (nn, z_arr, by_arr);
  gr_4_z = new TGraph (nn, z_arr, bz_arr);
  gr_4_abs = new TGraph (nn, z_arr, b_abs);
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
//  ifstream file_fort("../v7_osc_geom_3/hundulator_01_1101_xyz.table", ios::in);
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
//  ifstream file_fort("../v7_osc_geom_3/hundulator_01_1101_xyz.table", ios::in);
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
  gr_2_x = new TGraph (nn, z_arr, bx_arr);
  gr_2_y = new TGraph (nn, z_arr, by_arr);
  gr_2_z = new TGraph (nn, z_arr, bz_arr);
  gr_2_abs = new TGraph (nn, z_arr, b_abs);
}


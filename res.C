int get_bin_n(TH1D *, int );


Double_t myfunction(Double_t *, Double_t *);

Double_t myfunction(Double_t *x, Double_t *par)
{
  double f1 = par[1]*cos(par[2]*(x[0]-par[0]))-par[3];
  return f1;
}

/*
200 - cut_place1=0.00, cut_place_2=0.2 (out cylinder cut place), steel_width_scale=0.9, end current 100%
201 - cut_place1=0.25, cut_place_2=0.2 (out cylinder cut place), steel_width_scale=0.9, end current 100%
202 - cut_place1=0.50, cut_place_2=0.2 (out cylinder cut place), steel_width_scale=0.9, end current 100%
203 - cut_place1=0.75, cut_place_2=0.2 (out cylinder cut place), steel_width_scale=0.9, end current 100%
204 - cut_place1=1.00, cut_place_2=0.2 (out cylinder cut place), steel_width_scale=0.9, end current 100%
205 - cut_place1=0.00, cut_place_2=0.4 (out cylinder cut place), steel_width_scale=0.9, end current 100%
206 - cut_place1=0.25, cut_place_2=0.4 (out cylinder cut place), steel_width_scale=0.9, end current 100%
207 - cut_place1=0.50, cut_place_2=0.4 (out cylinder cut place), steel_width_scale=0.9, end current 100%
208 - cut_place1=0.75, cut_place_2=0.4 (out cylinder cut place), steel_width_scale=0.9, end current 100%
209 - cut_place1=1.00, cut_place_2=0.4 (out cylinder cut place), steel_width_scale=0.9, end current 100%
210 - cut_place1=0.00, cut_place_2=0.6 (out cylinder cut place), steel_width_scale=0.9, end current 100%
211 - cut_place1=0.25, cut_place_2=0.6 (out cylinder cut place), steel_width_scale=0.9, end current 100%
212 - cut_place1=0.50, cut_place_2=0.6 (out cylinder cut place), steel_width_scale=0.9, end current 100%
213 - cut_place1=0.75, cut_place_2=0.6 (out cylinder cut place), steel_width_scale=0.9, end current 100%
214 - cut_place1=1.00, cut_place_2=0.6 (out cylinder cut place), steel_width_scale=0.9, end current 100%
215 - cut_place1=0.00, cut_place_2=0.8 (out cylinder cut place), steel_width_scale=0.9, end current 100%
216 - cut_place1=0.25, cut_place_2=0.8 (out cylinder cut place), steel_width_scale=0.9, end current 100%
217 - cut_place1=0.50, cut_place_2=0.8 (out cylinder cut place), steel_width_scale=0.9, end current 100%
218 - cut_place1=0.75, cut_place_2=0.8 (out cylinder cut place), steel_width_scale=0.9, end current 100%
219 - cut_place1=1.00, cut_place_2=0.8 (out cylinder cut place), steel_width_scale=0.9, end current 100%
*/

void res()
{
  double l_cut_cyl[30];
  double l_cut_spir[30];
  double xp[30];
  double yp[30];
  double xyp[30];
  l_cut_spir[0]= 1.00; l_cut_cyl[0]=0.0;
  l_cut_spir[1]= 0.75; l_cut_cyl[1]=0.0;
  l_cut_spir[2]= 0.50; l_cut_cyl[2]=0.0;
  l_cut_spir[3]= 0.25; l_cut_cyl[3]=0.0;
  l_cut_spir[4]= 0.00; l_cut_cyl[4]=0.0;
  l_cut_spir[5]= 1.00; l_cut_cyl[5]=0.2;
  l_cut_spir[6]= 0.75; l_cut_cyl[6]=0.2;
  l_cut_spir[7]= 0.50; l_cut_cyl[7]=0.2;
  l_cut_spir[8]= 0.25; l_cut_cyl[8]=0.2;
  l_cut_spir[9]= 0.00; l_cut_cyl[9]=0.2;
  l_cut_spir[10]= 1.00; l_cut_cyl[10]=-0.10;
  l_cut_spir[11]= 0.75; l_cut_cyl[11]=-0.10;
  l_cut_spir[12]= 0.50; l_cut_cyl[12]=-0.10;
  l_cut_spir[13]= 0.25; l_cut_cyl[13]=-0.10;
  l_cut_spir[14]= 0.00; l_cut_cyl[14]=-0.10;
  l_cut_spir[15]= 1.00; l_cut_cyl[15]=0.4;
  l_cut_spir[16]= 0.75; l_cut_cyl[16]=0.4;
  l_cut_spir[17]= 0.50; l_cut_cyl[17]=0.4;
  l_cut_spir[18]= 0.25; l_cut_cyl[18]=0.4;
  l_cut_spir[19]= 0.00; l_cut_cyl[19]=0.4;


  xp[1]=0.406833;     yp[1]=-0.913596;
  xp[2]=-0.444077;    yp[2]=0.404128;
  xp[3]=-0.115885;    yp[3]=1.95737;
  xp[4]=1.34078;      yp[4]=2.82063;
  xp[6]=0.187661;     yp[6]=-0.961779;
  xp[7]=-0.673635;    yp[7]=0.360873;
  xp[8]=-0.278407;    yp[8]=1.97899;
  xp[9]=1.31989;      yp[9]=2.83662;
  xp[11]=0.526071;    yp[11]=-0.927912;
  xp[12]=-0.341205;   yp[12]=0.389801;
  xp[13]=0.0011244;   yp[13]=1.93769;
  xp[14]=1.38458;     yp[14]=2.78604;
  xp[16]=0.0279296;   yp[16]=-1.09873;
  xp[17]=-0.829921;   yp[17]=0.279746;
  xp[18]=-0.346707;   yp[18]=1.98255;
  xp[19]=1.32065;     yp[19]=2.8236;


/*
  xp[0]=2.59522;     yp[0]=-1.03679;
  xp[1]=1.63248;     yp[1]=-1.29741;
  xp[2]=0.352064;    yp[2]=-0.501841;
  xp[3]=0.0118727;   yp[3]=0.979995;
  xp[4]=0.879344;    yp[4]=2.26062;
  xp[5]=2.52354;     yp[5]=-1.53869;
  xp[6]=1.29031;     yp[6]=-1.70927;
  xp[7]=-0.0663285;  yp[7]=-0.858692;
  xp[8]=-0.35793;    yp[8]=0.889112;
  xp[9]=0.764501;    yp[9]=2.27649;
  xp[10]=2.53707;     yp[10]=-1.26424;
  xp[12]=0.0852351;   yp[12]=-0.662451;
  xp[13]=-0.259747;   yp[13]=0.913454;
  xp[14]=0.784221;    yp[14]=2.27602;
  xp[17]=0.237458;    yp[17]=-0.553932;
  xp[18]=-0.116477;   yp[18]=0.947403;
  xp[19]=0.815451;    yp[19]=2.27509;
  xp[22]=0.541849;    yp[22]=-0.49287;
  xp[23]=0.188955;    yp[23]=0.983634;
  xp[24]=1.02946;     yp[24]=2.24046;
  xp[26]=1.99433;     yp[26]=-1.31661;
  xp[27]=0.715064;    yp[27]=-0.535741;
  xp[28]=0.355521;    yp[28]=0.936828;
  xp[29]=1.16059;     yp[29]=2.2051;
*/




  TH2D * hh_1 =  new TH2D("", "P_{x, 0} vs steel geometry", 7,  -0.15, 0.55, 5, -0.125, 1.125);
  TH2D * hh_2 =  new TH2D("", "P_{y, 0} vs steel geometry", 7,  -0.15, 0.55, 5, -0.125, 1.125);
  TH2D * hh_3 =  new TH2D("", "P_{t, 0} vs steel geometry", 7,  -0.15, 0.55, 5, -0.125, 1.125);
  for (int i=0; i<30; i++)
  if (fabs(xp[i])>1.e-10)
  {
    hh_1->Fill(l_cut_cyl[i], l_cut_spir[i], double(int(xp[i]*1000))/1000.);
    hh_2->Fill(l_cut_cyl[i], l_cut_spir[i], double(int(yp[i]*1000))/1000.);
    hh_3->Fill(l_cut_cyl[i], l_cut_spir[i], double(int(sqrt(xp[i]*xp[i]+yp[i]*yp[i])*1000))/1000.);
  }

  TF1 *myfunc = new TF1("myfunc",myfunction, -0.2, 1., 4);
  myfunc->SetParNames("P_{0}","P_{1}","P_{2}", "P_{3}");

  myfunc->SetParameter(1, 2);
  myfunc->SetParLimits(1, 0.1, 5);
  myfunc->SetParLimits(2, 0.1, 10.);
//  myfunc->SetParLimits(1, 1, 5);
//  myfunc->SetParLimits(2, 0.1, 10.);


  TH1D *hy_proj[10];
  double gr_py_0_x[20];
  double gr_py_0_y[20];
  int ny_gr=0;
  for (int ii=1; ii<=7; ii++)
  {
    hy_proj[ii-1] = hh_2->ProjectionY(Form("projy_%d", ii), ii, ii);
    hy_proj[ii-1]->SetTitle(Form("hy_proj %d",ii));
    if (get_bin_n(hy_proj[ii-1], 5)>=3)
    {
      TCanvas *c_proj_y = new TCanvas(Form("cy_proj %d",ii), Form("cy_proj %d", ii), 1000, 800, 1000, 1000);
      c_proj_y->cd();
      hy_proj[ii-1]->Draw();
      hy_proj[ii-1]->Fit("myfunc", "R");
      double par_0=myfunc->GetParameter(0);
      double par_1=myfunc->GetParameter(1);
      double par_2=myfunc->GetParameter(2);
      double par_3=myfunc->GetParameter(3);
//      double f1 = par[1]*sin(par[2]*(x[0]-par[0]))-par[3];
      double asin_part=acos(par_3/par_1);
      cout<<"asin="<<asin_part<<endl;
      double py_0 = (asin_part+par_0*par_2)/par_2;
      cout<<"--------------------------------------------------------------------------------------------------------------->"<<py_0<<endl;
      if (py_0<0)
      {
        py_0=((3.1415927-asin_part)+par_0*par_2)/par_2;
        cout<<"--------------------------------------------------------------------------------------------------------------->"<<py_0<<endl<<endl;
      }
      cout<<"--------------------------------------------------------------------------------------------------------------->"<<py_0<<endl<<endl<<endl<<endl;
      gr_py_0_x[ny_gr] = hh_2->GetXaxis()->GetBinCenter(ii);
      gr_py_0_y[ny_gr] = py_0;
      ny_gr++;
//      if ((asin_part+par_0*par_2) < 0) asin_part=0.5*3.1415927-asin_part;
    }
  }
  TGraph *gr_y = new TGraph(ny_gr, gr_py_0_x, gr_py_0_y);
  gr_y->SetMarkerColor(2);
  gr_y->SetMarkerStyle(3);
  gr_y->SetMarkerSize(2);









  TH1D *hx_proj[10];
  double gr_px_0_x[20];
  double gr_px_0_y[20];
  int nx_gr=0;
  for (int ii=1; ii<=7; ii++)
  {
    hx_proj[ii-1] = hh_1->ProjectionY(Form("projx_%d", ii), ii, ii);
    hx_proj[ii-1]->SetTitle(Form("hx_proj %d",ii));
    if (get_bin_n(hx_proj[ii-1], 5)>=3)
    {
      TCanvas *c_proj_x = new TCanvas(Form("cx_proj_x %d",ii), Form("cx_proj_x %d", ii), 1000, 800, 1000, 1000);
      c_proj_x->cd();

      hx_proj[ii-1]->Draw();
      hx_proj[ii-1]->Fit("myfunc", "R");
      double par_0=myfunc->GetParameter(0);
      double par_1=myfunc->GetParameter(1);
      double par_2=myfunc->GetParameter(2);
      double par_3=myfunc->GetParameter(3);
//      double f1 = par[1]*cos(par[2]*(x[0]-par[0]))-par[3];
      double asin_part=acos(par_3/par_1);
      cout<<"asin="<<asin_part<<endl;
      double px_0 = (2.*3.1415927-1.*asin_part+par_0*par_2)/par_2;
      px_0 = (asin_part+par_0*par_2)/par_2;
      cout<<"--------------------------------------------------------------------------------------------------------------->"<<px_0<<endl;
/*
      if (px_0<0)
      {
        px_0=((3.1415927-asin_part)+par_0*par_2)/par_2;
        cout<<"--------------------------------------------------------------------------------------------------------------->"<<px_0<<endl<<endl;
      }
*/
      gr_px_0_x[nx_gr] = hh_1->GetXaxis()->GetBinCenter(ii);
      gr_px_0_y[nx_gr] = px_0;
      cout<<ii<<"    "<<gr_px_0_x[nx_gr]<<" --------------------------------------------------------------------------------------------------------------->"<<px_0<<endl<<endl<<endl<<endl;
      nx_gr++;
//      if ((asin_part+par_0*par_2) < 0) asin_part=0.5*3.1415927-asin_part;
//      cout<<"--------------------------------------------------------------------------------------------------------------->"<<py_0<<endl<<endl;
    }
//    cout<<"f-n res="<<get_bin_n(h_proj, 5)<<endl;
  }
  TGraph *gr_x = new TGraph (nx_gr, gr_px_0_x, gr_px_0_y);
  gr_x->SetMarkerColor(4);
  gr_x->SetMarkerStyle(3);
  gr_x->SetMarkerSize(2);
  TF1 *poll2 = new TF1("poll2", "pol2");
  gr_x->Fit("poll2");
  double par0_x=poll2->GetParameter(0);
  double par1_x=poll2->GetParameter(1);
  double par2_x=poll2->GetParameter(2);
  gr_y->Fit("poll2");
  double par0_y=poll2->GetParameter(0);
  double par1_y=poll2->GetParameter(1);
  double par2_y=poll2->GetParameter(2);
  double aa=par2_y-par2_x;
  double bb=par1_y-par1_x;
  double cc=par0_y-par0_x;
//  (p2y-p2x)*x*x+(p1y-p1x)*x+(p0y-p0x)=0
  double x01=-1.*bb+sqrt(bb*bb-4.*aa*cc)/2./aa;
  double x02=-1.*bb-sqrt(bb*bb-4.*aa*cc)/2./aa;
  cout<<"x1="<<x01<<"        x2="<<x02<<endl;




  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1);
  TCanvas *c = new TCanvas("c", "c", 0, 0, 2000, 1000);
  c->cd();
//  c->Divide(3,1);
  hh_1->GetXaxis()->SetLabelSize(0.05);
  hh_1->GetYaxis()->SetLabelSize(0.05);
/*
  hh_1->GetXaxis()->SetBinLabel(1, "0.2#upoint#lambda_{0}/2");
  hh_1->GetXaxis()->SetBinLabel(2, "0.4#upoint#lambda_{0}/2");
  hh_1->GetXaxis()->SetBinLabel(3, "0.6#upoint#lambda_{0}/2");
  hh_1->GetXaxis()->SetBinLabel(4, "0.8#upoint#lambda_{0}/2");
  hh_1->GetYaxis()->SetBinLabel(1, "0");
  hh_1->GetYaxis()->SetBinLabel(2, "0.25#upoint#lambda_{0}/2");
  hh_1->GetYaxis()->SetBinLabel(3, "0.5#upoint#lambda_{0}/2");
  hh_1->GetYaxis()->SetBinLabel(4, "0.75#upoint#lambda_{0}/2");
  hh_1->GetYaxis()->SetBinLabel(5, "#lambda_{0}/2");
*/
  hh_2->GetXaxis()->SetLabelSize(0.05);
  hh_2->GetYaxis()->SetLabelSize(0.05);
/*
  hh_2->GetXaxis()->SetBinLabel(1, "0.2#upoint#lambda_{0}/2");
  hh_2->GetXaxis()->SetBinLabel(2, "0.4#upoint#lambda_{0}/2");
  hh_2->GetXaxis()->SetBinLabel(3, "0.6#upoint#lambda_{0}/2");
  hh_2->GetXaxis()->SetBinLabel(4, "0.8#upoint#lambda_{0}/2");
  hh_2->GetYaxis()->SetBinLabel(1, "0");
  hh_2->GetYaxis()->SetBinLabel(2, "0.25#upoint#lambda_{0}/2");
  hh_2->GetYaxis()->SetBinLabel(3, "0.5#upoint#lambda_{0}/2");
  hh_2->GetYaxis()->SetBinLabel(4, "0.75#upoint#lambda_{0}/2");
  hh_2->GetYaxis()->SetBinLabel(5, "#lambda_{0}/2");
*/
  hh_3->GetXaxis()->SetLabelSize(0.05);
  hh_3->GetYaxis()->SetLabelSize(0.05);
/*
  hh_3->GetXaxis()->SetBinLabel(1, "0.2#upoint#lambda_{0}/2");
  hh_3->GetXaxis()->SetBinLabel(2, "0.4#upoint#lambda_{0}/2");
  hh_3->GetXaxis()->SetBinLabel(3, "0.6#upoint#lambda_{0}/2");
  hh_3->GetXaxis()->SetBinLabel(4, "0.8#upoint#lambda_{0}/2");
  hh_3->GetYaxis()->SetBinLabel(1, "0");
  hh_3->GetYaxis()->SetBinLabel(2, "0.25#upoint#lambda_{0}/2");
  hh_3->GetYaxis()->SetBinLabel(3, "0.5#upoint#lambda_{0}/2");
  hh_3->GetYaxis()->SetBinLabel(4, "0.75#upoint#lambda_{0}/2");
  hh_3->GetYaxis()->SetBinLabel(5, "#lambda_{0}/2");
*/
  hh_1->GetXaxis()->SetTitle("Tube cut place");
  hh_1->GetYaxis()->SetTitle("Spiral cut place");
  hh_2->GetXaxis()->SetTitle("Tube cut place");
  hh_2->GetYaxis()->SetTitle("Spiral cut place");
  hh_3->GetXaxis()->SetTitle("Tube cut place");
  hh_3->GetYaxis()->SetTitle("Spiral cut place");

  hh_1->GetXaxis()->SetTitleOffset(1.0);
  hh_1->GetYaxis()->SetTitleOffset(1.5);
  hh_2->GetXaxis()->SetTitleOffset(1.0);
  hh_2->GetYaxis()->SetTitleOffset(1.5);
  hh_3->GetXaxis()->SetTitleOffset(1.0);
  hh_3->GetYaxis()->SetTitleOffset(1.5);
  hh_1->GetXaxis()->SetTitleSize(0.05);
  hh_1->GetYaxis()->SetTitleSize(0.05);
  hh_2->GetXaxis()->SetTitleSize(0.05);
  hh_2->GetYaxis()->SetTitleSize(0.05);
  hh_3->GetXaxis()->SetTitleSize(0.05);
  hh_3->GetYaxis()->SetTitleSize(0.05);

  hh_1->SetMinimum(-3.);
  hh_1->SetMaximum(3.);
  hh_2->SetMinimum(-3.);
  hh_2->SetMaximum(3.);
  hh_3->SetMinimum(-3.);
  hh_3->SetMaximum(3.);

//  c->cd(1);
  TPad *c_1 = new TPad("c_1", "c_1",0.01,0.01,0.3233333,0.99);
  c_1->Draw();
  c_1->cd();
  c_1->Range(-0.1144504,-0.2826999,1.01355,1.281062);
  c_1->SetFillColor(0);
  c_1->SetBorderMode(0);
  c_1->SetBorderSize(2);
  c_1->SetLeftMargin(0.1901156);
  c_1->SetFrameBorderMode(0);
  c_1->SetFrameBorderMode(0);
  hh_1->Draw("colztext");
  gr_y->Draw("PSame");
  gr_x->Draw("PSame");


  c->cd();
  TPad *c_2 = new TPad("c_2", "c_2",0.3433333,0.01,0.6566667,0.99);
  c_2->Draw();
  c_2->cd();
  c_2->Range(-0.1053929,-0.2826999,1.012536,1.281062);
  c_2->SetFillColor(0);
  c_2->SetBorderMode(0);
  c_2->SetBorderSize(2);
  c_2->SetLeftMargin(0.1837263);
  c_2->SetFrameBorderMode(0);
  c_2->SetFrameBorderMode(0);
//  c->cd(2);
  hh_2->Draw("colztext");
  gr_y->Draw("PSame");
  gr_x->Draw("PSame");

//  c->cd(3);
  c->cd();
  TPad *c_3 = new TPad("c_3", "c_3",0.6766667,0.01,0.99,0.99);
  c_3->Draw();
  c_3->cd();
  c_3->Range(-0.1053929,-0.2826999,1.012536,1.281062);
  c_3->SetFillColor(0);
  c_3->SetBorderMode(0);
  c_3->SetBorderSize(2);
  c_3->SetLeftMargin(0.1837263);
  c_3->SetFrameBorderMode(0);
  c_3->SetFrameBorderMode(0);
  hh_3->Draw("colztext");
}

int get_bin_n(TH1D *htmp, int n_bins)
{
  int res_n=0;
  for (int i=1; i<=n_bins; i++)
  {
    if ( htmp->GetBinContent(i)!=0 ) res_n++;
  }
  return res_n;
}


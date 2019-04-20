void cooling_calc(double , double, double );
void plot_all();
double cool_pres, tot_power, cden_final, cur_single,lcond_total, steel_mass, voltage_drop, tot_resist;
double nx[20], field[20], ny[12];
double inch = 2.54;
double dcond = 0.25*inch;                           //conductor diameter
double dhole = 0.12*inch;                           //conductor hole diameter


void round_cond_cooling_calc_many()
{
  ny[0]=7;
  ny[1]=8;
  ny[2]=9;
  ny[3]=10;
  ny[4]=11;
  ny[5]=12;
  ny[6]=13;
  ny[7]=14;


  nx[0]=5.0;
  nx[1]=6.0;
  nx[2]=7.0;
  nx[3]=8.0;
  nx[4]=9.0;
  nx[5]=10.0;
  nx[6]=11.0;
  nx[7]=12.0;
  nx[8]=13.0;
  nx[9]=14.0;
  nx[10]=15.0;

  field[0]=1.020;
  field[1]=1.204;
  field[2]=1.377;
  field[3]=1.537;
  field[4]=1.682;
  field[5]=1.811;
  field[6]=1.920;
  field[7]=2.008;
  field[8]=2.072;
  field[9]=2.107;
  field[10]=2.073;

  TCanvas *c_fld_cur = new TCanvas("c_fld_cur", "c_fld_cur");
  c_fld_cur->cd();
  TGraph * gr_wid_field = new TGraph(11, nx, field);
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




  double width_new=0.25*inch;
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
  plot_all();
}

void plot_all()
{
  TH2D * hh_pres = new TH2D ("Water pressure vs conductor geometry", "Water pressure vs conductor geometry", 11, 4.5, 15.5, 8, 6.5, 14.5);
  TH2D * hh_pow  = new TH2D ("Total power vs conductor geometry",   "Total power vs conductor geometry", 11, 4.5, 15.5, 8, 6.5, 14.5);
  TH2D * hh_cden = new TH2D ("Current density vs conductor geometry", "Current density vs conductor geometry", 11, 4.5, 15.5, 8, 6.5, 14.5);
  TH2D * hh_cur  = new TH2D ("Current for single wire", "Current for single wire", 11, 4.5, 15.5, 8, 6.5, 14.5);
  TH2D * hh_lcond  = new TH2D ("lcond", "lcond", 11, 4.5, 15.5, 8, 6.5, 14.5);
  TH2D * hh_steel  = new TH2D ("steel", "steel", 11, 4.5, 15.5, 8, 6.5, 14.5);
  TH2D * hh_voltage= new TH2D ("volts", "volts", 11, 4.5, 15.5, 8, 6.5, 14.5);
  TH2D * hh_resist = new TH2D ("resist", "resist", 11, 4.5, 15.5, 8, 6.5, 14.5);

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


  double pow_gr[20];
  double pres_gr[20];
  int i=0;
  int j=3;

  for (j =0; j<8; j++)
  for (i =0; i<11; i++)
//  for (j =4; j<5; j++)
//  for (i =1; i<2; i++)
  {
    lcond_total=0;
    voltage_drop=0;
    tot_resist=0;
    steel_mass=(32.5-nx[i]*2.)/32.5*3.1415927*((4.5+0.665*ny[j])*(4.5+0.665*ny[j])-4.5*4.5)*32.5*14.*7.850;
    cooling_calc(nx[i], ny[j], field[i]*ny[j]/10.);
    pow_gr[i]=tot_power/1000.;
    pres_gr[i]=cool_pres;
    hh_pow    ->Fill(nx[i], ny[j], double(int(pow_gr[i]*100))/100.);
    hh_pres   ->Fill(nx[i], ny[j], double(int(pres_gr[i]*100))/100.);
    hh_cden   ->Fill(nx[i], ny[j], double(int(cden_final*100))/100.);
    hh_cur    ->Fill(nx[i], ny[j], double(int(cur_single*100))/100.);
    hh_lcond  ->Fill(nx[i], ny[j], double(int(0.0328084*lcond_total*100))/100.);
    hh_steel  ->Fill(nx[i], ny[j], double(int(steel_mass/1000.*100))/100.);
    hh_voltage->Fill(nx[i], ny[j], double(int(voltage_drop*100))/100.);
    hh_resist ->Fill(nx[i], ny[j], double(int(tot_resist*100))/100.);
  }


/*
//  for (j =0; j<8; j++)
  for (i =0; i<11; i++)
  {
    cooling_calc(nx[i], ny[j], field[i]*ny[j]/10.);
    pow_gr[i]=tot_power/1000.;
    pres_gr[i]=cool_pres;
    hh_pow->Fill(nx[i], ny[j], pow_gr[i]);
    hh_pres->Fill(nx[i], ny[j], pres_gr[i]);
    hh_cden->Fill(nx[i], ny[j], cden_final);
  }

  i=5;
  for (j=0; j<6; j++)
  if (j!=3)
  {
    cooling_calc(nx[i], ny[j], field[i]*ny[j]/10.);
    pow_gr[i]=tot_power/1000.;
    pres_gr[i]=cool_pres;
    hh_pow->Fill(nx[i], ny[j], pow_gr[i]);
    hh_pres->Fill(nx[i], ny[j], pres_gr[i]);
    hh_cden->Fill(nx[i], ny[j], cden_final);
  }
*/

  TGraph * gr_pow = new TGraph(11, nx, pow_gr);
  TGraph * gr_pres = new TGraph(11, nx, pres_gr);
  gr_pow->SetMinimum(0);
  gr_pres->SetMinimum(0);


  TCanvas *c_pow = new TCanvas("power", "power", 0, 0, 1000, 700);
  c_pow->cd();
  c_pow->SetGridx();
  c_pow->SetGridy();
  gr_pow->Draw("AP*");
  c_pow->SaveAs("test_pow.gif");


  TCanvas *c_pres = new TCanvas("pres", "pres", 1000, 0, 1000, 700);
  c_pres->cd();
  c_pres->SetGridx();
  c_pres->SetGridy();
  gr_pres->Draw("AP*");
  c_pres->SaveAs("test_pres.gif");

  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);
  hh_pow->SetMinimum(5);
  hh_pres->SetMinimum(-2);
  TCanvas *c_pow1 = new TCanvas("power1", "power1", 0, 800, 1000, 700);
  c_pow1->cd();
  c_pow1->SetGridx();
  c_pow1->SetGridy();
  hh_pow->Draw("colztext");

  TCanvas *c_pres1 = new TCanvas("pres1", "pres1", 1000, 800, 1000, 700);
  c_pres1->cd();
  c_pres1->SetGridx();
  c_pres1->SetGridy();
  hh_pres->Draw("colztext");

  TCanvas *c_cden1 = new TCanvas("cden1", "cden1", 500, 400, 1000, 700);
  c_cden1->cd();
  c_cden1->SetGridx();
  c_cden1->SetGridy();
  hh_cden->Draw("colztext");

  TCanvas *c_cur = new TCanvas("cur_sing", "cur_sing", 700, 400, 1000, 700);
  c_cur->cd();
  c_cur->SetGridx();
  c_cur->SetGridy();
  hh_cur->Draw("colztext");

  TCanvas *c_lcond = new TCanvas("lcond_sing", "lcond_sing", 700, 400, 1000, 700);
  c_lcond->cd();
  c_lcond->SetGridx();
  c_lcond->SetGridy();
  hh_lcond->Draw("colztext");

  TCanvas *c_steel = new TCanvas("steel_sing", "steel_sing", 700, 400, 1000, 700);
  c_steel->cd();
  c_steel->SetGridx();
  c_steel->SetGridy();
  hh_steel->Draw("colztext");

  TCanvas *c_volts = new TCanvas("volts", "volts", 700, 400, 1000, 700);
  c_volts->cd();
  c_volts->SetGridx();
  c_volts->SetGridy();
  hh_voltage->Draw("colztext");

  TCanvas *c_resist = new TCanvas("resist", "resist", 700, 400, 1000, 700);
  c_resist->cd();
  c_resist->SetGridx();
  c_resist->SetGridy();
  hh_resist->Draw("colztext");

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
  double tot_width=nx*dcond;                          //total width of helix conductor
  double tot_height=ny*dcond;                         //total width of helix conductor
  double field=field1;










  double portion = 1.5/field;                         //field scale
//  portion = 1.;                                       //field scale
  double op3_cur_den=300;
  double current=op3_cur_den*tot_width*tot_height*portion;  //total current per helix
  double pi=TMath::Pi();
  double deltat = 35;

  double ahole = pi*(dhole*dhole)/4.;                 // conductor corner radius
  double acond = pi*(dcond*dcond)/4.-ahole;           // conductor area

  double total_power=0;
  double total_volts=0;
  double currdens = current/(nx*ny*acond);            // current density
  double pscurr = current/(nx*ny);                    // Power supply current

//  cout<<"model No:"<<n_model<<endl;
  cool_res<<"nx="<<nx<<",  ny="<<ny<<",  cur_dens="<<op3_cur_den*portion<<" A/cm2,    pow. sup current = "<<pscurr<<" Amps,   diam_cond="<<dcond<<" cm,    diam_hole="<<dhole<<" cm"<<endl;
//  cout<<"Width = "<<tot_width<<"     (opera width = "<<tot_width/3.28*5<<")"<<endl;
//  cout<<"height = "<<tot_height<<endl;
  cool_res<<"Width = "<<tot_width<<"     (opera width = "<<tot_width/3.28*5<<")"<<endl;
  cool_res<<"Height = "<<tot_height<<" cm"<<endl;
  cool_res<<"deltat = "<<deltat<<" deg"<<endl;
  cool_res<<"N_layer   L_turn (cm)    l_cond(cm)     power(Wt)      Voltage(V)     reynolds       dP(Pascal)"<<endl;
  cden_final=op3_cur_den*portion;



  for (int i_layer=0; i_layer < int(ny+0.1); i_layer++)
  {
    double rad = 4.5+0.5*dcond+double(i_layer)*dcond;
    double lrad = 2.*pi*rad*n_period;
    double length = 32.5*n_period;
    double lturn = sqrt(length*length+lrad*lrad);       // Average length of one turn of each helix
    lturn+=4.5+2.*7.+pi*rad;                            // end regions
//    lturn=450;
    double lcond = nx*lturn+100;                        // We obtain the total coil length, multiplying by the number of turns. 2 helices
                                                        // +100 cm is for connecting to power supply
    lcond_total+=2.*(nx*lturn+100);



    //We obtain the coil resistance multiplying by the copper resistivity.  
    //We can then obtain the power per coil and the voltage per magnet.
    //resCoil=1.7e-8*lcond/acond.   1.7e-8 ohm meter.

    double rescoil = 1.7e-6*lcond/acond;                // resistence of nx turns, one helix
    double powcoil = rescoil*pscurr*pscurr;             // power per each helix
    double psvolts = pscurr*rescoil;                    // Power drop for each turn
    double single_cur = pscurr;
    cur_single = single_cur;
    double lcirc = 0.01*lcond;                          // Length per water circuit in meters
    total_power+=2.*powcoil;
    total_volts+=2.*psvolts;

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
    //The pressure drop must be less than the available in the facility (310 kPa, i.e. 3.1 bar, in our case).
    //If it is not so, we have to increment deltaT, until it is so.
    //---------------------------------------------------------------------------------------
    //
//    cout<<endl<<endl;
    n_layer[i_layer]=double(i_layer)+1;
    n_l++;
    pres[i_layer]=delp/1.e5;
    cool_pres=pres[i_layer];
    voltage_per_wire[i_layer] = psvolts;
    resist_per_wire[i_layer] = rescoil;
    lcond_per_wire[i_layer] = lcond/100.;
    voltage_drop += 2.*psvolts;
    tot_resist += 2.*rescoil;
  }
  cout<<"total power = "<<total_power<<"   total volts = "<<total_volts<<endl;
  cool_res<<"total power = "<<total_power<<"   total volts = "<<total_volts<<endl;
  cool_res<<endl<<endl;
  cool_res.close();
  tot_power = total_power;
  if(0)
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


    TCanvas *cc3 = new TCanvas("h_pressure", "h_pressure", 0, 0, 1000, 700);
    cc3->cd();
    cc3->SetGridy();
    cc3->SetGridx();
    gr->Draw("AP");


    TCanvas *c_res_wire = new TCanvas("c_res_wire", "c_res_wire", 0, 0, 1000, 700);
    c_res_wire->cd();
    c_res_wire->SetGridy();
    c_res_wire->SetGridx();
    gr_res_wire->Draw("AP");

    TCanvas *c_volt_wire = new TCanvas("c_volt_wire", "c_volt_wire", 0, 0, 1000, 700);
    c_volt_wire->cd();
    c_volt_wire->SetGridy();
    c_volt_wire->SetGridx();
    gr_volt_wire->Draw("AP");

    TCanvas *c_lcond_wire = new TCanvas("c_lcond_wire", "c_lcond_wire", 0, 0, 1000, 700);
    c_lcond_wire->cd();
    c_lcond_wire->SetGridy();
    c_lcond_wire->SetGridx();
    gr_lcond_wire->Draw("AP");

  }

  // End of cooling calculation
  //------------------------------------
}

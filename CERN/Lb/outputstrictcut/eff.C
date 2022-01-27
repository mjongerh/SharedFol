{
//========= Macro generated from object: eff/
//========= by ROOT version6.25/01
   Double_t xAxis1[13] = {0, 0.5, 1, 2, 3, 4, 5, 7, 10, 13, 16, 20, 24}; 
   
   TH1F *eff__1 = new TH1F("eff__1","",12, xAxis1);
   eff__1->SetBinContent(3,0.000533745);
   eff__1->SetBinContent(4,0.00425843);
   eff__1->SetBinContent(5,0.0125);
   eff__1->SetBinContent(6,0.0293431);
   eff__1->SetBinContent(7,0.0573671);
   eff__1->SetBinContent(8,0.116674);
   eff__1->SetBinContent(9,0.177702);
   eff__1->SetBinContent(10,0.224296);
   eff__1->SetBinContent(11,0.256548);
   eff__1->SetBinContent(12,0.304348);
   eff__1->SetBinError(3,0.000177962);
   eff__1->SetBinError(4,0.000416464);
   eff__1->SetBinError(5,0.000694497);
   eff__1->SetBinError(6,0.00114249);
   eff__1->SetBinError(7,0.00137707);
   eff__1->SetBinError(8,0.00244395);
   eff__1->SetBinError(9,0.00513754);
   eff__1->SetBinError(10,0.00932056);
   eff__1->SetBinError(11,0.0138522);
   eff__1->SetBinError(12,0.0235959);
   eff__1->SetEntries(1606.87);
   eff__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   eff__1->SetLineColor(ci);
   eff__1->SetLineWidth(2);
   eff__1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   eff__1->GetXaxis()->SetRange(1,300);
   eff__1->GetXaxis()->SetLabelFont(42);
   eff__1->GetXaxis()->SetLabelOffset(0.015);
   eff__1->GetXaxis()->SetTitleSize(0.045);
   eff__1->GetXaxis()->SetTitleOffset(1);
   eff__1->GetXaxis()->SetTitleFont(42);
   eff__1->GetYaxis()->SetTitle(" Reconstruction Efficiency");
   eff__1->GetYaxis()->CenterTitle(true);
   eff__1->GetYaxis()->SetLabelFont(42);
   eff__1->GetYaxis()->SetLabelOffset(0.01);
   eff__1->GetYaxis()->SetTitleSize(0.045);
   eff__1->GetYaxis()->SetTitleOffset(0.8);
   eff__1->GetYaxis()->SetTitleFont(42);
   eff__1->GetZaxis()->SetLabelFont(42);
   eff__1->GetZaxis()->SetTitleOffset(1);
   eff__1->GetZaxis()->SetTitleFont(42);
   eff__1->Draw("");
}

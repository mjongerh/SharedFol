{
//========= Macro generated from object: hBkgPerEvent/
//========= by ROOT version6.24/06
   Double_t xAxis2[11] = {0, 1, 2, 3, 4, 5, 6, 8, 12, 24, 36}; 
   
   TH1D *hBkgPerEvent__2 = new TH1D("hBkgPerEvent__2","",10, xAxis2);
   hBkgPerEvent__2->SetBinContent(2,0.0721559);
   hBkgPerEvent__2->SetBinContent(3,0.0470498);
   hBkgPerEvent__2->SetBinContent(4,0.0161972);
   hBkgPerEvent__2->SetBinContent(5,0.00639254);
   hBkgPerEvent__2->SetBinContent(6,0.0032242);
   hBkgPerEvent__2->SetBinContent(7,0.00206754);
   hBkgPerEvent__2->SetBinContent(8,0.00132713);
   hBkgPerEvent__2->SetBinContent(9,0.000547367);
   hBkgPerEvent__2->SetBinContent(10,0.000132626);
   hBkgPerEvent__2->SetEntries(9);
   hBkgPerEvent__2->SetStats(0);

   ci = TColor::GetColor("#ff0000");
   hBkgPerEvent__2->SetLineColor(ci);
   hBkgPerEvent__2->SetLineWidth(3);
   hBkgPerEvent__2->GetXaxis()->SetTitle("p_{T}(J/#psi)(GeV/c)");
   hBkgPerEvent__2->GetXaxis()->SetLabelFont(42);
   hBkgPerEvent__2->GetXaxis()->SetLabelOffset(0.015);
   hBkgPerEvent__2->GetXaxis()->SetTitleSize(0.045);
   hBkgPerEvent__2->GetXaxis()->SetTitleOffset(1);
   hBkgPerEvent__2->GetXaxis()->SetTitleFont(42);
   hBkgPerEvent__2->GetYaxis()->SetTitle("Bkg/nEvents");
   hBkgPerEvent__2->GetYaxis()->CenterTitle(true);
   hBkgPerEvent__2->GetYaxis()->SetLabelFont(42);
   hBkgPerEvent__2->GetYaxis()->SetLabelOffset(0.01);
   hBkgPerEvent__2->GetYaxis()->SetTitleSize(0.045);
   hBkgPerEvent__2->GetYaxis()->SetTitleOffset(0.8);
   hBkgPerEvent__2->GetYaxis()->SetTitleFont(42);
   hBkgPerEvent__2->GetZaxis()->SetLabelFont(42);
   hBkgPerEvent__2->GetZaxis()->SetTitleOffset(1);
   hBkgPerEvent__2->GetZaxis()->SetTitleFont(42);
   hBkgPerEvent__2->Draw("");
}

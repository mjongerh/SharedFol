{
//========= Macro generated from object: hBkgPerEvent/
//========= by ROOT version6.25/01
   Double_t xAxis1[13] = {0, 0.5, 1, 2, 3, 4, 5, 7, 10, 13, 16, 20, 24}; 
   
   TH1D *hBkgPerEvent__1 = new TH1D("hBkgPerEvent__1","",12, xAxis1);
   hBkgPerEvent__1->SetBinContent(3,6.85822e-07);
   hBkgPerEvent__1->SetBinContent(4,6.71668e-07);
   hBkgPerEvent__1->SetBinContent(5,6.89928e-07);
   hBkgPerEvent__1->SetBinContent(6,6.27719e-07);
   hBkgPerEvent__1->SetBinContent(7,7.6731e-07);
   hBkgPerEvent__1->SetBinContent(8,7.972e-07);
   hBkgPerEvent__1->SetBinContent(9,7.17078e-07);
   hBkgPerEvent__1->SetBinContent(10,7.33937e-07);
   hBkgPerEvent__1->SetBinContent(11,7.62791e-07);
   hBkgPerEvent__1->SetBinContent(12,7.20594e-07);
   hBkgPerEvent__1->SetEntries(11);
   hBkgPerEvent__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ff0000");
   hBkgPerEvent__1->SetLineColor(ci);
   hBkgPerEvent__1->SetLineWidth(3);
   hBkgPerEvent__1->GetXaxis()->SetTitle("p_{T}(#Lambda_{b}^{0})(GeV/c)");
   hBkgPerEvent__1->GetXaxis()->SetLabelFont(42);
   hBkgPerEvent__1->GetXaxis()->SetLabelOffset(0.015);
   hBkgPerEvent__1->GetXaxis()->SetTitleSize(0.045);
   hBkgPerEvent__1->GetXaxis()->SetTitleOffset(1);
   hBkgPerEvent__1->GetXaxis()->SetTitleFont(42);
   hBkgPerEvent__1->GetYaxis()->SetTitle("Bkg/nEvents");
   hBkgPerEvent__1->GetYaxis()->CenterTitle(true);
   hBkgPerEvent__1->GetYaxis()->SetLabelFont(42);
   hBkgPerEvent__1->GetYaxis()->SetLabelOffset(0.01);
   hBkgPerEvent__1->GetYaxis()->SetTitleSize(0.045);
   hBkgPerEvent__1->GetYaxis()->SetTitleOffset(0.8);
   hBkgPerEvent__1->GetYaxis()->SetTitleFont(42);
   hBkgPerEvent__1->GetZaxis()->SetLabelFont(42);
   hBkgPerEvent__1->GetZaxis()->SetTitleOffset(1);
   hBkgPerEvent__1->GetZaxis()->SetTitleFont(42);
   hBkgPerEvent__1->Draw("");
}

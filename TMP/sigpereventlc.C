{
//========= Macro generated from object: histosignal/
//========= by ROOT version6.24/06
   Double_t xAxis1[11] = {0, 1, 2, 3, 4, 5, 6, 8, 12, 24, 36}; 
   
   TH1F *histosignal__1 = new TH1F("histosignal__1","",10, xAxis1);
   histosignal__1->SetBinContent(1,4.92914e+08);
   histosignal__1->SetBinContent(2,2.21432e+09);
   histosignal__1->SetBinContent(3,3.10382e+09);
   histosignal__1->SetBinContent(4,2.82725e+09);
   histosignal__1->SetBinContent(5,2.23624e+09);
   histosignal__1->SetBinContent(6,1.35756e+09);
   histosignal__1->SetBinContent(7,1.48177e+09);
   histosignal__1->SetBinContent(8,7.71874e+08);
   histosignal__1->SetBinContent(9,1.46573e+08);
   histosignal__1->SetBinContent(10,1.36606e+07);
   histosignal__1->SetBinError(2,25476.9);
   histosignal__1->SetBinError(3,14678.1);
   histosignal__1->SetBinError(4,9457.04);
   histosignal__1->SetBinError(5,7514.49);
   histosignal__1->SetBinError(6,8792.39);
   histosignal__1->SetBinError(7,6455.13);
   histosignal__1->SetBinError(8,9924.99);
   histosignal__1->SetBinError(9,33541.4);
   histosignal__1->SetBinError(10,177081);
   histosignal__1->SetEntries(5110);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("histosignal");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 5110   ");
   ptstats_LaTex = ptstats->AddText("Mean  =  4.089");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  2.742");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   histosignal__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(histosignal__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   histosignal__1->SetLineColor(ci);
   histosignal__1->GetXaxis()->SetTitle("p_{T} (GeV)");
   histosignal__1->GetXaxis()->SetRange(1,100);
   histosignal__1->GetXaxis()->SetLabelFont(42);
   histosignal__1->GetXaxis()->SetTitleOffset(1);
   histosignal__1->GetXaxis()->SetTitleFont(42);
   histosignal__1->GetYaxis()->SetTitle("Lc d#sigma^{PYTHIA}/dp_{T} (#mu b/GeV)");
   histosignal__1->GetYaxis()->SetLabelFont(42);
   histosignal__1->GetYaxis()->SetTitleFont(42);
   histosignal__1->GetZaxis()->SetLabelFont(42);
   histosignal__1->GetZaxis()->SetTitleOffset(1);
   histosignal__1->GetZaxis()->SetTitleFont(42);
   histosignal__1->Draw("");
}

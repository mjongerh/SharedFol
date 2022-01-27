{
//========= Macro generated from object: histosignal/
//========= by ROOT version6.25/01
   Double_t xAxis1[13] = {0, 0.5, 1, 2, 3, 4, 5, 7, 10, 13, 16, 20, 24}; 
   
   TH1F *histosignal__1 = new TH1F("histosignal__1","",12, xAxis1);
   histosignal__1->SetBinContent(3,287.836);
   histosignal__1->SetBinContent(4,4014.78);
   histosignal__1->SetBinContent(5,10417.6);
   histosignal__1->SetBinContent(6,15872.5);
   histosignal__1->SetBinContent(7,34434.6);
   histosignal__1->SetBinContent(8,45446.8);
   histosignal__1->SetBinContent(9,22650.1);
   histosignal__1->SetBinContent(10,10218.3);
   histosignal__1->SetBinContent(11,5436.2);
   histosignal__1->SetBinContent(12,1943.32);
   histosignal__1->SetBinContent(13,7.92764e-08);
   histosignal__1->SetBinError(3,37.8817);
   histosignal__1->SetBinError(4,535.329);
   histosignal__1->SetBinError(5,1478.92);
   histosignal__1->SetBinError(6,2282.17);
   histosignal__1->SetBinError(7,3418.69);
   histosignal__1->SetBinError(8,3535.53);
   histosignal__1->SetBinError(9,1824.16);
   histosignal__1->SetBinError(10,848.561);
   histosignal__1->SetBinError(11,424.271);
   histosignal__1->SetBinError(13,4.6963e-09);
   histosignal__1->SetEntries(100012);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("histosignal");
   ptstats_LaTex->SetTextSize(0.0368);
   ptstats_LaTex = ptstats->AddText("Entries = 100012 ");
   ptstats_LaTex = ptstats->AddText("Mean  =  8.363");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  3.908");
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
   histosignal__1->GetYaxis()->SetTitle("Lb d#sigma^{PYTHIA}/dp_{T} (#mu b/GeV)");
   histosignal__1->GetYaxis()->SetLabelFont(42);
   histosignal__1->GetYaxis()->SetTitleFont(42);
   histosignal__1->GetZaxis()->SetLabelFont(42);
   histosignal__1->GetZaxis()->SetTitleOffset(1);
   histosignal__1->GetZaxis()->SetTitleFont(42);
   histosignal__1->Draw("");
}

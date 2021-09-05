 #include <cstdlib>
 #include <iostream>
 #include <map>
 #include <string>

 #include "TChain.h"
 #include "TFile.h"
 #include "TTree.h"
 #include "TString.h"
 #include "TObjString.h"
 #include "TSystem.h"
 #include "TROOT.h"

void graph() {
  const Int_t nbins = 6;
  Double_t edges[nbins + 1] = {0.0, 1.0, 2.0, 4., 6.0, 8.0, 12.0};
  TH1F* h = new TH1F("h1", "Significance with optimal BDT cut", nbins, edges);
  h->Fill(0.5, 2.7873);
  h->Fill(1.5, 7.3744);
  h->Fill(3, 12.114);
  h->Fill(5, 7.74659);
  h->Fill(7, 5.22184);
  h->Fill(10, 3.91036);

  h->GetXaxis()->SetTitle("P_{T} (GeV/c)");
  h->GetYaxis()->SetTitle("S/#sqrt{S+B}");

  h->Draw("hist");
}
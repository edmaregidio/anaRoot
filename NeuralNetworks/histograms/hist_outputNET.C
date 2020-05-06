void hist_outputNET() {

  
   TCanvas *c1 = new TCanvas("c1","transparent pad",200,10,700,500);
   TPad *pad1 = new TPad("pad1","",0,0,1,1);
   TPad *pad2 = new TPad("pad2","",0,0,1,1);
   pad2->SetFillStyle(4000); //will be transparent
   pad1->Draw();
   pad1->cd();
   TH1F *h1 = new TH1F("h1","SLFN Output: Constrained MOCMA-ES Training",100,-1,1);
   TH1F *h0 = new TH1F("h0","h0",100,-1,1);
   TRandom r;

   ifstream inp0, inp1; float x0[668],x1[1232];
   inp0.open("h0_cma99.txt");
   inp1.open("h1_cma99.txt");

   for (int i=1; i<=668; i++) {
      inp0 >> x0[i];
      h0->Fill(x0[i]);
   }

   for (int i=1; i<=1232; i++) {
      inp1 >> x1[i];
      h1->Fill(x1[i]);
   }



   h1->Draw();
   pad1->Update(); //this will force the generation of the "stats" box
   
   h0->SetLineColor(kRed);
   h0->Draw("][sames");
   
   h0->SetFillStyle(3003);
   h0->SetFillColor(kRed);
   h0->SetLineColor(kRed);


   h1->SetFillStyle(3008);
   h1->SetFillColor(kBlue);
   h1->SetLineColor(kBlue+1);

  TLegend *legend = new TLegend(.75,.80,.95,.95);
  legend->AddEntry(h1,"Signal (gamma)");
  legend->AddEntry(h0,"Background (hadron)");
  legend->Draw();
   h1->GetXaxis()->SetTitle("Output");
   h1->GetYaxis()->SetTitle("Count");


}



void roccurve(){
	

	int n = 1904;
	
	ifstream inpPD_cma, inpPF_cma, inpPD_lm,inpPF_lm; 
	float pd_cma[n],pf_cma[n],pd_lm[n],pf_lm[n];
   	
   	inpPD_cma.open("pd_cma.txt");
   	inpPF_cma.open("pf_cma.txt");

   	inpPD_lm.open("pd_lm.txt");
   	inpPF_lm.open("pf_lm.txt");

   	for (int i=1; i<=n; i++) {

      inpPD_cma >> pd_cma[i];
      inpPF_cma >> pf_cma[i];

      inpPD_lm >> pd_lm[i];
      inpPF_lm >> pf_lm[i];
      
   	}

	auto c1 = new TCanvas("c1","c1",200,10,600,400);
	c1->SetGrid();

   	TGraph *roc1 = new TGraph (n, pf_cma, pd_cma);
	TGraph *roc2 = new TGraph (n, pf_lm, pd_lm);

	roc1->SetTitle("Classifier ROC Curve");

	roc1->GetXaxis()->SetRangeUser(20,80);
	roc1->SetMinimum(90);
   	roc1->SetMaximum(100);

   	roc1->GetXaxis()->SetTitle("False Alarm Rate [%]");
   	roc1->GetYaxis()->SetTitle("Signal Efficiency [%]");

	roc2->GetXaxis()->SetRangeUser(15,80);
	roc2->SetMinimum(90);
   	roc2->SetMaximum(100);

 
   	roc1->SetLineColor(1);
   	roc1->SetLineWidth(3);
   	roc1->SetLineStyle(1);
   	
   	roc1->Draw();


   	roc2->SetLineColor(6);
   	roc2->SetLineWidth(3);
   	roc2->SetLineStyle(1);
   	roc2->Draw("same");


   	TLegend *legend = new TLegend(.75,.80,.95,.95);
  	legend->AddEntry(roc1,"MO-CMAES");
  	legend->AddEntry(roc2,"BP:Levenberg Maquart");
  	legend->Draw();
	


}
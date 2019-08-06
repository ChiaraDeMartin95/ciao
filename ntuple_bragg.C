//questa macro funziona!


#include <Riostream.h>
#include <TH1.h>
#include <TH2.h>
#include <TF1.h>
#include <TFile.h>
#include <TNtuple.h>
#include <TH1F.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TPave.h>
#include <TLatex.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TVirtualPad.h>
#include <TString.h>

void ntuple_bragg() {

  TString file;
  for (Int_t j=1; j<=25; j++) {
    if (j==1){
      file = "Bragg/2011180927_vuoto_prima_misura";
    } else if (j==2){
      file = "Bragg/2011180947_100mb";
    } else if (j==3){
      file = "Bragg/2011181014_300mb";
    } else if (j==4){
      file = "Bragg/2011181028_500mb";
    } else if (j==5){
      file = "Bragg/2011181043_535mb";
    } else if (j==6){
      file = "Bragg/2011181058_550mb";
    } else if (j==7){
      file = "Bragg/2011181114_565mb";
    } else if (j==8){
      file = "Bragg/2011181146_570mb";
    } else if (j==9){
      file = "Bragg/2011181219_575mb";
    } else if (j==10){
      file = "Bragg/2011181252_580mb";
    } else if (j==11){
      file = "Bragg/2011181324_585mb";
    } else if (j==12){
      file = "Bragg/2011181357_590mb";
    } else if (j==13){
      file = "Bragg/2011181429_595mb";
    } else if (j==14){
      file = "Bragg/2011181536_600mb";
    } else if (j==15){
      file = "Bragg/2011181611_605mb";
    } else if (j==16){
      file = "Bragg/2011181644_612mb";
    } else if (j==17){
      file = "Bragg/2011181719_619mb";
    } else if (j==18){
      file = "Bragg/2011181754_626mb";
    } else if (j==19){
      file = "Bragg/2011181828_633mb";
    } else if (j==20){
      file = "Bragg/2011181901_640mb";
    } else if (j==21){
      file = "Bragg/2011181935_647mb";
    } else if (j==22){
      file = "Bragg/2011181948_654mb";
    } else if (j==23){
      file = "Bragg/2011182005_659mb";
    } else if (j==24){
      file = "Bragg/2011182024_665mb";
    } else if (j==25){
      file = "Bragg/2111181022_1013mb";
    }
   
    ifstream in; 
    TString filein = file ;
    TString fileout = file;
    filein += ".dat";
    fileout += "_bis.root";
    cout<<filein<<endl;
    in.open(filein); // apertura file.dat
    Float_t bin,conteggio ;
    Int_t nlines = 0;

    TFile *myfile_bis = new TFile (fileout, "RECREATE"); //creo file.root
    TNtuple *ntuple = new TNtuple("ntuple","ntuple", "bin:conteggio");
 
    while (1) {
      in >> bin >> conteggio;
      if (!in.good()) break;
      ntuple->Fill(bin, conteggio);
      nlines++;
    }
    
    in.close();
    myfile_bis->Write();
  }
}


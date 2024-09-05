#include<bits/stdc++.h>
using namespace std;

int main(){
	//Deklarasi Variabel
	int total=0, skor=0;
	int isi, angka, High_Score, simpan;
	bool bomb=false;
	string x;
	
	//setting
	srand(static_cast<unsigned int>(time(0)));
	ifstream inputFile("max_value.txt");
	if(inputFile.is_open()){
		inputFile>>High_Score;
		inputFile.close();
	}

	//main program
	cout<<endl<<"                                ENDLESS GACHA"<<endl;
	cout<<"                              High Score : "<<High_Score<<endl<<endl;;
	while(!bomb){
		//memunculkan teks
		cout<<"                                  Score : "<<skor<<endl;
		cout<<"                               Total Gacha : "<<total<<endl;
		cout<<"A : Single pull"<<endl<<"B : 10x pull"<<endl;
		cout<<"                                  Gacha : ";
		cin>>x;
		cout<<"\033[2J\033[H"; //menghapus teks sebelumnya
		simpan=0;
		if(x=="A"){
			isi=1;
		}
		else{
			isi=10;
		}
		for(int i=1; i<=isi; i++){
			if(total<=60){
				angka=rand()%100+1;
				simpan+=angka;
				if(angka==1){
					cout<<"\033[2J\033[H";
					cout<<endl<<"                                  END OF GACHA"<<endl;
					cout<<"                                  Score : "<<skor<<endl;
					if(skor>High_Score){
						High_Score=skor;
						cout<<"                                !!!Rekor Baru!!!"<<endl;
						ofstream outputFile("max_value.txt");
						if(outputFile.is_open()){
							outputFile<<High_Score;
							outputFile.close();
						}
					}
					cout<<"                               High Score : "<<High_Score<<endl<<endl;
					cout<<"                  99% penjudi akan berhenti sebelum mereka maxwin"<<endl<<endl;
					exit(0);
				}
				else if(angka==100){
					cout<<"!!!Jackpot!!!"<<endl;
					total=0;
				}
				else{
					cout<<angka<<endl;
					total++;
				}
			}
			else{
				angka=rand()%100+1;
				if(angka<=10){
					cout<<"\033[2J\033[H";
					cout<<endl<<"                                  END OF GACHA"<<endl;
					cout<<"                                  Score : "<<skor<<endl;
					if(skor>High_Score){
						High_Score=skor;
						cout<<"                                !!!Rekor Baru!!!"<<endl;
						ofstream outputFile("max_value.txt");
						if(outputFile.is_open()){
							outputFile<<High_Score;
							outputFile.close();
						}
					}
					cout<<"                               High Score : "<<High_Score<<endl<<endl;
					cout<<"                  99% penjudi akan berhenti sebelum mereka maxwin"<<endl<<endl;
					exit(0);
				}
				else if(angka>=70){
					cout<<"!!!Jackpot!!!"<<endl;
					total=0;
				}
				else{
					cout<<angka<<endl;
					total++;
				}
			}
		}
		skor+=simpan;
		cout<<endl;
	}
}
//Tambah 1 line lagi biar jadi kaya nilaiku besok Aamiin
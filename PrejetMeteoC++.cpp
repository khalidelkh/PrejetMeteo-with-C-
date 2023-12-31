#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>
#include<windows.h>
#include<time.h>

using namespace std;
typedef struct date{
    int jour;
    string mois;
    string nom_jour;
    int hour;
    int minutte;
}date;
class StationMeteo{
    time_t t =time(0);
    char *dt=ctime(&t);
    date Dt;
    fstream fechPrev;//donner prevision pour les jour
    fstream datafile;//donnee actualle
    fstream fechPrevHours;//prevision pour l'hours
    int jour_actualle;
    double LastTemperature;
    double LastPression;
    double LastHumidite;

    double PressionActuelle;
    double TemperatureActuelle;
    double HumiditeActuelle;

    double PrevisionTemperature;
    double PrevisionPression;
    double PrevisionHumidite;

    double MoyenneHumidite,MoyenneTemperature,MoyennePression;
    double TemperatureMin,PressionMin,HumiditeMin;
    double HumiditeMax,PressionMax,TemperatureMax;
public:
        StationMeteo(){
                // tm *T = localtime(&t);

               for(int j=0;j<5;j++){
                    cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tStarting";
                        for(int i=0;i<5;i++){
                            cout<<" .";
                            Sleep(200);
                        }
                        system("cls");
                }

                fechPrev.open("C:\\donneePrevision_Jour.txt");
                datafile.open("C:\\donnee_Actualle.txt",ios::app|ios::out|ios::in);
                datafile.open("C:\\donnee_Prevision_Hours.txt",ios::app|ios::out|ios::in);
                ifstream fin;
                fin.open("C:\\donnee_Actualle.txt");
                //test si le fichier est vide ou non
                string line;
                getline(fin,line);
                if((line.length())==0)datafile<<"date\t\t\tTemperature\tPression\tHumidite\n"<<endl;
                fin.close();

                fin.open("C:\\donneePrevision.txt");
                getline(fin,line);
                if((line.length())==0)fechPrev<<"date\t\t\tTemperature\t Pression\t humidite\n";
                fin.open("C:\\donnee_Prevision_Hours.txt");
                getline(fin,line);
                if((line.length())==0)fechPrevHours<<"temps\t\t\tTemperature\t Pression\t humidite\n";
        }

        //suprimmer les donner previsionner de ce jour pour le jour
        void suppr_donner_prevision(){
        }

        void affiche(){
            cout<<"\n                                         "<<dt;
            cout<<"\n\n";
            cout<<"\n                              Etat Actualle     Maximun   Minimin   Moyenne ";
            cout<<"\n       Temperature            "<<TemperatureActuelle;cout<<"\t"<< TemperatureMax;cout<<"\t   "<< TemperatureMin;cout<<"\t\t"<< MoyenneTemperature<<" ";
            cout<<"\n       Hymidite               "<< HumiditeActuelle;cout<<"%\t"<< HumiditeMax;cout<<"%\t   "<< HumiditeMin;cout<<"%\t\t"<< MoyenneHumidite<<"%";
            cout<<"\n       Pression               "<< PressionActuelle;cout<<"\t"<< PressionMax;cout<<"\t   "<< PressionMin;cout<<"\t\t"<< MoyennePression<<"";
            cout<<"\n\n";
             //creation eterator sur le map
        }
          void saisir_donnee_actualle(){
                    cout<<"\n\n";
                    cout<<"\n           saisir la date (11:45 landi 12 Nov ) ";
                    cout<<"\n           nom de jour    (Mardi)             :";cin >>Dt.nom_jour;
                    cout<<"\n           nombre de jour (12)                :";cin>>Dt.jour;
                    cout<<"\n           le mois        (Nov)               :";cin>>Dt.mois;
                    cout<<"\n           hour           (12)                :";cin >>Dt.hour;
                    cout<<"\n           minutte        (00)                :";cin >>Dt.minutte;
                    cout <<"\n          Temperature actuelle               :";cin>>TemperatureActuelle;
                    cout <<"\n          Pression actuelle  %               :";cin>>PressionActuelle;
                    cout <<"\n          Humidite actuelle  %               :";cin>>HumiditeActuelle;
                    //ecricre les donner sur le ficher
                    datafile<<Dt.nom_jour<<" "<<Dt.jour<<" "<<Dt.mois<<" "<<Dt.hour<<":"<<Dt.minutte<<" "<<"\t\t"<<TemperatureActuelle<<"\t\t"<<PressionActuelle<<"\t\t"<<HumiditeActuelle<<endl;
        }
        void  saisir_donnee_prevision_hours(){
                        cout<<"\n        saisir le temps (12:00 ) ";
                        cout<<"\n           hour           (12)             :";cin >>Dt.hour;
                        cout<<"\n           minutte        (00)             :";cin >>Dt.minutte;
                        cout<<"\n        nsaisir la temperature prevision   :";cin>>PrevisionTemperature;
                        cout<<"\n        nsaisir le pression prevision      :";cin>>PrevisionPression;
                        cout<<"\n        nsaisir l'humidite prevision       :";cin>>PrevisionHumidite;
                        //ecrire les donner previsionner sur les fichier de  donner prevision
                        fechPrevHours<<"\n"<<Dt.hour<<":"<<Dt.minutte<<" "<<Dt.mois<<"\t"<<PrevisionTemperature<<"\t"<<PrevisionPression<<"\t"<<PrevisionHumidite<<"%";
                        system("cls");
        }
        void sasir_donner_prevision(){
                        cout<<"\n        saisir la date (landi 12 Nov ) ";
                        cout<<"\n        nom de jour                        :";cin >>Dt.nom_jour;
                        cout<<"\n        nombre de jour                     :";cin>>Dt.jour;
                        cout<<"\n        le mois                            :";cin>>Dt.mois;
                        cout<<"\n        nsaisir la temperature prevision   :";cin>>PrevisionTemperature;
                        cout<<"\n        nsaisir le pression prevision      :";cin>>PrevisionPression;
                        cout<<"\n        nsaisir l'humidite prevision       :";cin>>PrevisionHumidite;
                        //ecrire les donner previsionner sur les fichier de  donner prevision
                        fechPrev<<"\n"<<Dt.nom_jour<<" "<<Dt.jour<<" "<<Dt.mois<<"\t"<<PrevisionTemperature<<"\t"<<PrevisionPression<<"\t"<<PrevisionHumidite<<"%";
                        system("cls");
        }

        void  recueille_donner(){

            cout<<"\n                                         "<<dt;
            saisir_donnee_actualle();
            jour_actualle=Dt.jour;
            //*****add data to file ;
            system("cls");
            int nb=0;
            char *day;
            HumiditeMin=HumiditeActuelle;
            PressionMin=PressionActuelle;
            TemperatureMin=TemperatureActuelle;

            HumiditeMax=HumiditeActuelle;
            PressionMax=PressionActuelle;
            TemperatureMax=TemperatureActuelle;

            int  x=1;
            while (true) {
                                //statistique
                //temp
                //if(strncmp(day,dt,4))MoyenneTemperature=0;
                MoyenneHumidite=(MoyenneHumidite*nb+HumiditeActuelle)/ (nb+1);
                MoyenneTemperature=(MoyenneTemperature*nb+TemperatureActuelle)/ (nb+1);
                MoyennePression=(MoyennePression*nb+PressionActuelle)/(nb+1);
                ++nb;//nbre de fois saisir par jour ;
                if(HumiditeActuelle>HumiditeMax)HumiditeMax=HumiditeActuelle;
                if(PressionActuelle>PressionMax)PressionMax=PressionActuelle;
                if(TemperatureActuelle>TemperatureMax)TemperatureMax=TemperatureActuelle;

                if(HumiditeActuelle<HumiditeMin)HumiditeMin=HumiditeActuelle;
                if(PressionActuelle<PressionMin)PressionMin=PressionActuelle;
                if(TemperatureActuelle<TemperatureMin)TemperatureMin=TemperatureActuelle;

                affiche();
                x=saisir_info();
                if(x==0)break;
            }
        }
        int saisir_info() {
                int choix;
                cout<<"\n\n";
                cout<<"\n               saisir donnees actuelles ....................:1";
                cout<<"\n               saisir les donner Previson...................:2";
                cout<<"\n               Affiche donner de ce jour ...................:3";
                cout<<"\n               quitter .....................................:0\n";
                cout <<"                                       :";cin>>choix;
                system("cls");
                if(choix==1){
                    saisir_donnee_actualle();
                    if(jour_actualle!=Dt.jour){
                        MoyenneHumidite=0;
                        MoyenneTemperature=0;
                        MoyennePression=0;
                        jour_actualle++;
                    }
                    affiche();
                    system("cls");
                }
                if(choix==2){
                    affiche();
                    int nbJ,nb,nbH;
                    cout<<"\nsaisir donner de ce jour     : 1";
                    cout<<"\nsaisir les donner des jours  : 2";
                    cout<<"\n           :";cin>>nb;
                    system("cls");
                    if(nb==1){
                            cout<<"\n       saisir nombre d'hours :";cin>>nbH;
                            for(int i=1;i<=nbH;i++){
                                system("cls");
                                affiche();
                                saisir_donnee_prevision_hours();
                            }
                    }
                    else if(nb==2){
                            cout<<"\n        saisir nombre de jour              :";cin>>nbJ;
                            for(int i=1;i<=nbJ;i++){
                                system("cls");
                                affiche();
                                sasir_donner_prevision();
                            }
                    }
                }
                if(choix==3){
                }
                return choix;
        }
};
int main(){
    StationMeteo *donnemeteo=new StationMeteo();
    donnemeteo->recueille_donner();
}





































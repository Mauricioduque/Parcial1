#include <iostream>
#include <math.h>

using namespace std;

void simulaciondefensiva(float HD, float posy, float ang, float Vin,float d);
void simulacionreal(float HD,float H0, float ang, float Vin,float d);
void generarpuntos(float *angle, float *vel, float d, float HD,float H0);
void generarofensivos(float *angle,float *vel,float d,float H0);


int main()
{
    float d=1000;
    float HD=200;
    float H0=50;
    float angle[3]={0.3,0.5,1};// se definene 3 angulos como condicion inicial
    float vel[3]={0,0,0};      // se define 3 velocidades inicales para cada angulo

    generarpuntos(angle,vel,d,HD,H0);
    cout<<"Se defiene los valores inciales para d,HD y H0 de la siguiente manera:"<<endl;
    cout<<"d(metros): "<<d<<'\n'<<"HD(metros): "<<HD<<'\n'<<"H0(metros): "<<H0<<'\n';
    cout<<"Las condiciones que generan al defensivo peligro son:"<<endl;
    for (int i=0;i<3;i++) cout<<"Vin: "<<vel[i]<<" m/s "<<" Angulo: "<<angle[i]<<" rad"<<endl;
    generarofensivos(angle,vel,d,H0);
    cout<<"Las condiciones que generan peligro al ofensivo son:"<<endl;
    for (int i=0;i<3;i++) cout<<"Vin: "<<vel[i]<<" m/s "<<" Angulo: "<<angle[i]<<" rad"<<endl;
    return 0;
}

void simulaciondefensiva(float HD,float x0, float posy, float ang, float Vin,float d ){ //determina si se dispara o no el canon defensivo

    float tsim=0,x,y,vi,vx,vy,aux;
    bool efectivo=false;
    cout<<"Las condiciones de velocidad inical que pueden  generan peligro son:"<<endl;
    for (vi=5;vi<=200;vi++){
        vx=vi*cos(ang);
        vy=vi*sin(ang);
        for(int t=0;t<=200;t++){
            x=x0+vi*cos(ang)*t;
            y=posy+vi*sin(ang)*t-4.9*t*t;
            if (sqrt(pow((x0-x),2)+pow((posy-y),2))<=0.05*d){//si esta dentro del rango de la circunferencia
                cout<<vi<<" m/s"<<endl;
            }

        }
    }
}


void generarpuntos(float *angle,float *vel,float d,float HD,float H0){
    double xy[3][2]={{d,HD},{(d-0.025*d),HD},{(d+0.025*d),(HD+0.025*d)}};
    for(int i=0;i<3;i++){
        vel[i]=(xy[i][0]/cos(angle[i]))*sqrt(4.9/(xy[i][0]*tan(angle[i])+H0-xy[i][1]));// velocidad que compromete el canon defensivo
    }
}

void generarofensivos(float *angle,float *vel,float d,float H0){
    double xy[3][2]={{0.1,H0},{(0.05*d),H0},{(0.05*d),(H0+0.05*d)}};
    for(int i=0;i<3;i++){
        vel[i]=(xy[i][0]/cos(angle[i]))*sqrt(4.9/(xy[i][0]*tan(angle[i])+H0-xy[i][1]));// velocidad que compromete el canon defensivo
    }
}



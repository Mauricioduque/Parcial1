#include <iostream>
#include <math.h>

using namespace std;

bool simulaciondefensiva(float HD, float posy, float ang, float Vin,float d);
void simulacionreal(float HD,float H0, float ang, float Vin,float d);
void generarpuntos(float *angle, float *vel, float d, float HD,float H0);


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
    cout<<"Las condiciones que generan peligro son:"<<endl;
    for (int i=0;i<3;i++) cout<<"Vin: "<<vel[i]<<" m/s "<<" Angulo: "<<angle[i]<<" rad"<<endl;
     //simulacionreal(200,50,,,1000)

    return 0;
}

bool simulaciondefensiva(float HD, float posy, float ang, float Vin,float d ){ //determina si se dispara o no el canon defensivo
    float tsuelo= (Vin*sin(ang)+sqrt(Vin*Vin*sin(ang)*sin(ang)+2*9.81*posy))/9.81;      // tiempo que se demora en llegar al suelo la bala ofensiva
    float tsim=0,x,y;
    int tampaso=1000;
    bool efectivo=false;
    for(int i=0;i<=tampaso;i++){
        tsim=tsuelo*i/tampaso; // genera los diferetnes tiempos para generar la parabola de tiro
        x=Vin*cos(ang)*tsim;
        y=posy+Vin*sin(ang)*tsim-4.9*tsim*tsim;
        if (sqrt(pow((d-x),2)+pow((HD-y),2))<=0.05*d){//si esta dentro del rango de la circunferencia
            efectivo=true;
            break;
        }

    }
    return efectivo;
}

void simulacionreal(float HD,float H0, float ang, float Vin,float d){//simulacion del mundo fisico real que s eencarga de comprobar

}

void generarpuntos(float *angle,float *vel,float d,float HD,float H0){
    double xy[3][2]={{d,HD},{(d-0.025*d),HD},{(d+0.025*d),(HD+0.025*d)}};
    for(int i=0;i<3;i++){
        vel[i]=(xy[i][0]/cos(angle[i]))*sqrt(4.9/(xy[i][0]*tan(angle[i]+H0-xy[i][1])));// velocidad que compromete el canon defensivo
    }

}



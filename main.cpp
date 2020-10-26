#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.14159265


/*
 Не використовуючи тривимірну графіку, змоделювати поворот об’ємного
 куба в ортогональній системі координат.
 */
 
void newcoorX(float a, float b , float c, long double x, long double y,  long double z){
    
    float sinus = a;
    sinus =  sin(sinus * PI / 180);
    float cosinus = a;
    cosinus = cos(cosinus * PI / 180);
    
    float newx = x;
    float newy = (y*cosinus)+(z*sinus);
    float newz = (z*cosinus)-(y*sinus);
    
    float sinus1 = b;
    sinus1 =  sin(sinus1 * PI / 180);
    float cosinus1 = b;
    cosinus1 = cos(cosinus1 * PI / 180);
    
    float newx1 = (newx*cosinus1)+(newz*sinus1);
    float newy1 = newy;
    float newz1 = (newz*cosinus1)-(newx*sinus1);
    
    float sinus2 = c;
    sinus2 =  sin(sinus2 * PI / 180);
    float cosinus2 = c;
    cosinus2 = cos(cosinus2 * PI / 180);
    
    float newx2 = (newx1*cosinus2)-(newy1*sinus2);
    float newy2 = -(newx1*sinus2)-(newy1*cosinus2);
    float newz2 = newz1;
    
    cout<<"("<<setprecision(2)<<newx2<<";"<< setprecision(2) <<newy2<<";"<<setprecision(2)<<newz2<<")"<<endl;
    
}


void task_15(){
    long double ax=0,ay=0,az=3;
    long double bx=0,by=0,bz=0;
    long double cx=3,cy=0,cz=0;
    long double dx=3,dy=0,dz=3;
    long double a1x=0,a1y=3,a1z=3;
    long double b1x=0,b1y=3,b1z=0;
    long double c1x=3,c1y=3,c1z=0;
    long double d1x=3,d1y=3,d1z=3;
    
    cout<<"A "<<"("<<ax<<";"<<ay<<";"<<az<<")"<<endl;
    cout<<"B "<<"("<<bx<<";"<<by<<";"<<bz<<")"<<endl;
    cout<<"C "<<"("<<cx<<";"<<cy<<";"<<cz<<")"<<endl;
    cout<<"D "<<"("<<dx<<";"<<dy<<";"<<dz<<")"<<endl;
    cout<<"A1 "<<"("<<a1x<<";"<<a1y<<";"<<a1z<<")"<<endl;
    cout<<"B1 "<<"("<<b1x<<";"<<b1y<<";"<<b1z<<")"<<endl;
    cout<<"C1 "<<"("<<c1x<<";"<<c1y<<";"<<c1z<<")"<<endl;
    cout<<"D1 "<<"("<<d1x<<";"<<d1y<<";"<<d1z<<")"<<endl;
    
    cout<<"*******************************"<<endl;
    
    float a;
    cout<<"Enter the angle for the x axis : ";
    cin>>a;
    float b;
    cout<<"Enter the angle for the y axis : ";
    cin>>b;
    float c;
    cout<<"Enter the angle for the z axis : ";
    cin>>c;
    
    newcoorX(a,b,c,ax,ay,az);
    newcoorX(a,b,c,bx,by,bz);
    newcoorX(a,b,c,cx,cy,cz);
    newcoorX(a,b,c,dx,dy,dz);
    newcoorX(a,b,c,a1x,a1y,a1z);
    newcoorX(a,b,c,b1x,b1y,b1z);
    newcoorX(a,b,c,c1x,c1y,c1z);
    newcoorX(a,b,c,d1x,d1y,d1z);
    
    
}


/*Дано трикутник. Визначити центр та радіус вписаного та описаного кола.*/


void task_10(){
    int ax,ay,bx,by,cx,cy;
    cout<<"ax : ";
    cin>>ax;
    cout<<"ay : ";
    cin>>ay;
    cout<<"bx : ";
    cin>>bx;
    cout<<"by : ";
    cin>>by;
    cout<<"cx : ";
    cin>>cx;
    cout<<"cy : ";
    cin>>cy;
    
    float ABx = bx-ax;
    float ABy = by - ay;
        
    float BAx = ax-bx;
    float BAy = ay - by;

    float BCx = cx-bx;
    float BCy = cy - by;
    
    float CBx = bx-cx;
    float CBy = by - cy;
    
    float CAx = ax-cx;
    float CAy = ay - cy;

    float  ACx = cx-ax;
    float ACy = cy-ay;
    
    float AB = sqrt(pow(ABx,2)+pow(ABy,2));
    float BC = sqrt(pow(BCx,2)+pow(BCy,2));
    float AC = sqrt(pow(ACx,2)+pow(ACy,2));
    

    float angleB = (BAx*BCx+BAy*BCy)/(sqrt(pow(BAx,2)+pow(BAy,2))*sqrt(pow(BCx,2)+pow(BCy,2)));
    float angleA = (ABx*ACx+ABy*ACy)/(sqrt(pow(ABx,2)+pow(ABy,2))*sqrt(pow(ACx,2)+pow(ACy,2)));
    float angleC = (CAx*CBx+CAy*CBy)/(sqrt(pow(CAx,2)+pow(CAy,2))*sqrt(pow(CBx,2)+pow(CBy,2)));

    int result1;
      result1 = acos (angleB) * 180.0 / PI;
      cout<<"1 angle : "<<result1<<endl;

    int result2;
      result2 = acos (angleA) * 180.0 / PI;
      cout<<"2 angle : "<<result2<<endl;

    int result3;
      result3 = acos (angleC) * 180.0 / PI;
      cout<<"3 angle : "<<result3<<endl;
    
    
    float p = (AB+BC+AC)/2;
    float square = sqrt(p*(p-AB)*(p-BC)*(p-AC));
    float r = 2*square/(AB+BC+AC);
    float R = (AB*BC*AC)/(4*square);
    float seredX = (ax+bx+cx)/3;
    float seredY = (ay+by+cy)/3;
    
    
    if (result1<90 && result2<90 && result3<90){
        
            cout<<"r : "<<r<<endl;
            cout<<"R : "<<R<<endl;
            cout<<"CENTER : "<<"("<<seredX<<";"<<seredY<<")"<<endl;
        
    }
    else if(result1==90 || result2==90 || result3==90){
            if(AB>AC && AB>BC){
                float middlex = (ax + bx)/2;
                float middley = (ay + by)/2;
                cout<<"Center described : ("<<middlex<<";"<<middley<<")"<<endl;
            }
            else if (BC>AC && BC>AB){
                float middlex = (bx + cx)/2;
                float middley = (by + cy)/2;
                cout<<"Center described : ("<<middlex<<";"<<middley<<")"<<endl;
            }
            else {
                float middlex = (cx + ax)/2;
                float middley = (cy + ay)/2;
                cout<<"Center described : ("<<middlex<<";"<<middley<<")"<<endl;
            }
        
            cout<<"Center inscribed : ("<<seredX<<";"<<seredY<<")"<<endl;
            cout<<"r : "<<r<<endl;
            cout<<"R : "<<R<<endl;
    }
    
    else{
            cout<<"r : "<<r<<endl;
            cout<<"R : "<<R<<endl;
            cout<<"CENTER : "<<"("<<seredX<<";"<<seredY<<")"<<endl;
    }
   
}





int main()
{
    task_15();
  return 0;
}

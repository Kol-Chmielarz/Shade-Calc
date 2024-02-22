#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979323846

struct towers{
double x;
double h;
double s;
double scoord1;
double scoord2;
};

double getShade(double A, double h){
  double radian;
  radian = tan(A);

  
  double s = (h)/(radian);
  return s;
};

double getshade_from_west(double A, double N,double L,double P,struct towers towers[]){
  int truth=1;
 
  double shadeHolder=0;
    double percCov=0;

  

  while(truth==1){
    

  for(int i=0;i<N;i++){//sun in east loop
     

    
//double A=PI/14;
    
    double s=getShade(A, towers[i].h);
    towers[i].scoord2=towers[i].x+s;

    if(i==(N-1)){
      if( towers[i].scoord2<0){//shade outside of park on left side going west
       towers[i].scoord2=0;
    }
    if( towers[i].scoord2>L){//shade outside of park on right side going east
       towers[i].scoord2=L;
    }

      
    }else{
      
    

    if( towers[i].scoord2<0){//shade outside of park on left side going west
       towers[i].scoord2=0;
    }
    if( towers[i].scoord2>L){//shade outside of park on right side going east
       towers[i].scoord2=L;
    }

    if(towers[i].scoord2>towers[i+1].scoord1&&(towers[i].scoord2>=towers[i+1].scoord2)){//shadow overlaps whole other triangle sun in east
      towers[i+1].scoord1=L;
      towers[i+1].scoord2=L;
    }

     if(towers[i].scoord2>towers[i+1].scoord1&&(towers[i].scoord2<towers[i+1].scoord2)){//shadow over laps just some of triangle sun in east
      
      towers[i].scoord2=towers[i+1].scoord1;
    }

    
    
      }
    
    
  }

    
    for(int i=0;i<N;i++){
      shadeHolder+=(towers[i].scoord2-towers[i].scoord1);
      
      
      
      
    }
    percCov=shadeHolder/L;
    truth=0;

    

    

    }




  //printf("\n\n%lf %lf", shadeHolder, percCov);
  return percCov*100;
  

  
  
}





int main(void) {
 

  int N, L;
  double P;
  
  scanf("%d %d %lf", &N, &L, &P);
  //printf("\n%d %d %d", N, L, P);
  struct towers towers[N];
  double heights[N];
  double xcoord[N];

  

  for(int i=0;i<N;i++){
    scanf("%lf %lf", &xcoord[i], &heights[i] );
    
      towers[i].scoord1=xcoord[i];
    towers[i].x=xcoord[i];
    towers[i].h=heights[i];
      
      
    }
    //function start here (double getshade_from_east(double double N,double L,double P,double heights[],double xcoord[],struct tower[])

  struct towers *towerss;

  towerss=&towers;
 
      
    double angle2=PI/4;
      double cover2;




 cover2 = getshade_from_west(angle2, N, L, P, towerss);

  


  int found_angle2=0;
  

  while(found_angle2==0){
    

  if(cover2==P||(cover2>P-0.000001&&cover2<P+0.000001)){
    angle2=angle2*180/PI;
  printf("\n%0.5lf", 180-angle2);
    found_angle2=1;
    }
  else if(cover2>P){
    angle2=(angle2*2+angle2)/2;
    cover2 =getshade_from_west(angle2, N, L, P, towerss);
    
    
  }
  else if(cover2<P){
    angle2=(angle2/2+angle2)/2;
    cover2 =getshade_from_west(angle2, N, L, P, towerss);
    
    }


    }



  }
  
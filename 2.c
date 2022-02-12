#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 2
double f1(double y,double z){
    return -y/5+z/20;
}

double f2(double y,double z){
    return y/5-z/5;
}
int main(){
    double y=60;
    double z=0;
    double ka[N],kb[N],kc[N],kd[N];
    double h=0.2;
    double x=0;
    
    printf("    x         y         z\n");
    printf("%lf  %lf  %lf\n",x,y,z);
    do{
        ka[0]=h*f1(y,z);
        ka[1]=h*f2(y,z);
        kb[0]=h*f1(y+ka[0]/2,z+ka[1]/2);
        kb[1]=h*f2(y+ka[0]/2,z+ka[1]/2);
        kc[0]=h*f1(y+kb[0]/2,z+kb[1]/2);
        kc[1]=h*f2(y+kb[0]/2,z+kb[1]/2);
        kd[0]=h*f1(kc[0]+y,kc[1]+z);
        kd[1]=h*f2(kc[0]+y,kc[1]+z);
        x+=0.2;
        y=y+(ka[0]+2*kb[0]+2*kc[0]+kd[0])/6;
        z=z+(ka[1]+2*kb[1]+2*kc[1]+kd[1])/6;
        printf("%lf  %lf  %lf\n",x,y,z);
    }while(x<2.0);


}

/*
    x         y         z
0.000000  60.000000  0.000000
0.200000  57.658896  2.306048
0.400000  55.431297  4.432139
0.600000  53.311043  6.389658
0.800000  51.292327  8.189308
1.000000  49.369670  9.841150
1.200000  47.537904  11.354645
1.400000  45.792153  12.738683
1.600000  44.127816  14.001622
1.800000  42.540555  15.151315
2.000000  41.026273  16.195145
2.200000  39.581105  17.140045
*/
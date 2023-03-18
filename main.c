#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float** generate(int h, int w)
{
    srand(time(0));
    int number;
    float** rndm=malloc(h*sizeof(float*));
    for(int i=0; i<h; i++)
        rndm[i]=malloc(w*sizeof(float));
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            number=rand()%1000;
            if(number==0) rndm[i][j]=0;
            else rndm[i][j]=1.f/number;
        }
    }
    return rndm;
}

void afisare(int h,int w,float** rndm)
{

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
            printf("%.3f ",rndm[i][j]);
        printf("\n");
    }
    printf("\n");
}

int ver_par(int h,int w,int idx,char ov)
{

    int adv1=0,adv2=0;
    if(ov=='o' || ov=='v') adv1=1;
    if((idx>=0 && idx<h) || (idx>=0 && idx<w)) adv2=1;
    return adv1*adv2;
}

float** delete_rc(int h,int w,float** a,int idx,char ov)
{
    float** c_a;
    if(ver_par(h,w,idx,ov)==0)
    {
        printf("parametrii de intrare sunt gresiti");
        return -1;
    }

    if(ov=='v')
    {
        c_a=malloc(h*sizeof(float*));
        for(int i=0; i<h; i++)
            c_a[i]=malloc((w-1)*sizeof(float));
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<idx; j++)
                c_a[i][j]=a[i][j];
        }
        for(int i=0; i<h; i++)
        {
            for(int j=idx+1; j<w; j++)
                c_a[i][j-1]=a[i][j];
        }

    }
    else if(ov=='o')
    {
        c_a=malloc((h-1)*sizeof(float*));
        for(int i=0; i<h-1; i++)
            c_a[i]=malloc(w*sizeof(float));
        for(int i=0; i<idx; i++)
        {
            for(int j=0; j<w; j++)
                c_a[i][j]=a[i][j];
        }
        for(int i=idx+1; i<h; i++)
        {
            for(int j=0; j<w; j++)
                c_a[i-1][j]=a[i][j];
        }
    }

    return c_a;
}


int main()
{
    int h,w,idx,w1,h1;
    char ov;
    scanf("%d %d %d %c",&h,&w,&idx,&ov);
    float** t;
    float** b=generate(h,w);
    afisare(h,w,b);
    t=delete_rc(h,w,b,idx,ov);
    if(ov=='v' && ver_par(h,w,idx,ov)==1)
    {
        afisare(h,w-1,t);
    }
    else if(ov=='o' && ver_par(h,w,idx,ov)==1)
    {

        afisare(h-1,w,t);
    }
    //VVVV mai jos realizam calcularea determinantului VVVV

    float** det1;
    float** det2;
    double sum=0,sum1=0,sum2=0,sumtotal;
    char ov1='o';
    char ov2='v';
    float x1,x2,x3;
    if(h==3 && w==3)
    {
        x1=b[0][0];
        x2=b[0][1]*(-1);
        x3=b[0][2];
        for(int j=0; j<w; j++)
        {
            det1=delete_rc(h,w,b,0,ov1);
            det2=delete_rc(h-1,w,det1,j,ov2);
            if(j==0) sum=sum+x1*(det2[0][0]*det2[1][1]-det2[0][1]*det2[1][0]);
            if(j==1) sum1=sum1+x2*(det2[0][0]*det2[1][1]-det2[0][1]*det2[1][0]);
            if(j==2) sum2=sum2+x3*(det2[0][0]*det2[1][1]-det2[0][1]*det2[1][0]);
        }
        printf("\n");
        printf("valoarea determinantului este:  ");
        sumtotal=sum+sum1+sum2;
        printf("%.15f",sumtotal);
    }
    else printf("matricea nu este de 3X3, nu putem calcula valoarea determinantului");
    for(int i=0; i<h; i++)
        free(b[i]);
    free(b);
}

#include<iostream>
#include<fstream>
#include<ctime>
#include"function.h"
#include<cmath>
const double eps = 0.000001;
using namespace std;

int change(int n,int i, double**A, double*B){
double temp;
int flag = 0;
if(abs(A[i][i])>eps){
    flag=1;
}
if(abs(A[i][i])<eps){
        for(int s=i+1;s<=n;s++){
            if(abs(A[s][i])>eps){
                for(int j=i;j<=n;j++){
                    temp = A[i][j];
                    A[i][j]=A[s][j];
                    A[s][j]=temp;
                    temp=B[i];
                    B[i]=B[s];
                    B[s]=temp;
                }
                flag=1;
            }
        }
    }
    if (flag==0){return 5;}
    return 0;
}

void diagonal(int n, int i, double**A, double*B){
double temp = A[i][i];
for(int j=i;j<=n;j++){
    A[i][j]/=temp;
}
    B[i]/=temp;
        for(int r=1;r<i;r++){
            temp = A[r][i];
            for(int j=i;j<=n;j++){
                A[r][j]-=(temp*A[i][j]);
            }
            B[r]-=(temp*B[i]);
    }
    for(int r=i+1;r<=n;r++){
            temp = A[r][i];
            for(int j=i;j<=n;j++){
                A[r][j]-=(temp*A[i][j]);
            }
            B[r]-=(temp*B[i]);
    }
}

/*void cleared(int n, int i, double**A, double*B){
    for(int l=1; l<=n-i;l++){
        double temp=A[i][i+l]; 
        for(int j=i+l;j<=n;j++){
            A[i][j]-=(A[i+l][j]*temp);
        }
        B[i]-=temp*B[i+l];
    }
}*/

int func(int n, double**A, double*B){
        //ofstream fout("output.txt");
    for(int i=1;i<=n;i++){
        if(change(n, i, A, B)==5){return 5;}    
        diagonal(n, i, A, B);
    /*for (int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            fout << A[k][j];
            fout << " ";
        }
        fout << '\n';
    }*/
    }
 /*   for(int i=n-1;i>=0;i--){
        cleared(n, i, A, B);
    }*/
    return 0;
}

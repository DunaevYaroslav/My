#include<iostream>
#include<fstream>
#include<ctime>
#include"function.h"
using namespace std;

double f(int k,int n,int i,int j){
    if(k==1){
        return n-max(i,j)+1;
    }
    if(k==2){
        return max(i,j);
    }
    if(k==3){
        return abs(i-j);
    }
    if(k==4){
        return 1.0/(i+j-1);
    }
    return 0;
}

void create_b(int n,double*b, double**a){
    ofstream fb("vector_b.txt");
    int i, j;
    for(i=1; i<=n; i++){
        b[i]=0;
        for(j=1;j<n && (j%2==1);j++){//!!!!!!!!!!!!!!!!!!!!!!!!!!
            b[i]+=a[i][j];
        } 
        b[i]+=a[i][n];
    fb << b[i];
    fb << '\n';
    }
}

int main(){
ofstream fout("output.txt");
//ifstream fin("input.txt");

int n, m, k,i,j;
string filename;
cin >> n;
cin >> m;
cin >> k;
cin >> filename;

ifstream fin(filename);
if(fin.is_open()==0 && (k==0)){
     cout << "Filename is bad\n";
}

double * b = new double[n+1];

double ** a = new double*[n+1];
for(i=0;i<n+1;i++){
    a[i]=new double[n+1];
}


if(k==0){
    if(fin.is_open())
    {
        int count=0;
        double temp;
        while (!fin.eof())// пробегаем пока не встретим конец файла eof
            {
                fin >> temp;//в пустоту считываем из файла числа
                count++;// увеличиваем счетчик числа чисел
            }
        fin.seekg(0, ios::beg);
        for (int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    fin >> a[i][j];
                    //cout << a[i][j];
                    //fout << a[i][j];
                    //fout << " ";
                }
                //fout << '\n';
            }
    }
}
if(k!=0){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=f(k,n,i,j);
        }
    }
}

create_b(n, b, a);
srand(time(0));

if(func(n, a, b)==5){
    cout<<"determinant=0";
    }

cout << "Time: " << clock()/1000.0 << " sec";

for (i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fout << a[i][j];
            fout << " ";
        }
        fout << b[i];
        fout << '\n';
    }

fin.close();
fout.close();
return 0;
}

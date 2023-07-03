#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;
int main()
{  
int esperar[10], cons[10], rodando[10],num,quantum,tot;
cout<<"Quantidade de processos: "; 
cin>>num;
 
cout<<"Tempo do consumo: ";
for(int i=0;i<num;i++)
{  cout<<"\nP["<<i+1<<"]: "; cin>>cons[i];
   rodando[i] = cons[i];
   esperar[i]=0;
}
cout<<"\n\nDigite um quantum: "; cin>>quantum;
int i=0;
int r = num;
int tempo=0;
cout<<"0"; 
esperar[0]=0; 
while(r!=0) { 
 if(rodando[i]>quantum)
 {
   rodando[i]=rodando[i]-quantum;
   cout<<" | P["<<i+1<<"] | ";
   tempo+=quantum;
   cout<<tempo;
   }
 else if(rodando[i]<=quantum && rodando[i]>0)
 {tempo+=rodando[i];
  rodando[i]=rodando[i]-rodando[i];
  cout<<" | P["<<i+1<<"] | ";
  r--;
  cout<<tempo;
 }
 
i++;
if(i==num)
{
i=0;
}
}
getch();
}
#include <iostream>
#include <fstream>

using namespace std;

float V[100][3];
int n,G;

void read_data()
{
    ifstream f ("read");
    f>>G;
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>V[i][1];
        f>>V[i][2];
    }
}
void fill_data()
{
    for(int i=1;i<=n;i++)
    {
        V[i][3]=V[i][2]/V[i][1];
    }
}
void sort_data()
{
    int m;
    int i=1;
    while(i<=n)
    {
        float minimum= INT_MAX;
        for(int j=i;j<=n;j++)
        {
            if(V[j][3]<minimum)
            {
                minimum=V[j][3];
                m=j;
            }
        }
        for(int j=1;j<=3;j++)
        {
            swap(V[m][j],V[i][j]);
        }
        i++;
    }
}
int print_data()
{
    ofstream g ("print");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            g<<V[i][j]<<" ";
        }
        g<<endl;
    }

}
/*
float greedy()
{

G greutatea rucsacului
n numarul de obiecte
O matrice cu 3 coloane ( greutate , profit , eficienta )

 pseudocod

 profit=0
 i=1  // index la obiectului curent in sirul sortat descescator dupa eficienta

 atata timp cat in rucsac se mai pot depune obiecte si sirul de obiecte este neepuizat
                                        G>=0                                  si  i<=n
   {
    daca ( G>=O[i][1] )  atunci {
                                                        profit=profit+O[i][3]
                                                        G=G-O[i][1]
                                                  }
                     altfel {
                                aux=(G*100)/O[i][1]
                                profit_aux=(O[i][3]*aux)/100;
                                profit=profit+profit_aux;
                                G=0;
                                stop
                               }
    i=i+1;
   }
*/
float greedy()
{
    int profit=0;
    int i=1;
    while(G>=0 && i<=n)
    {
        if(G>=V[i][2])
        {
            profit=profit+V[i][3];
            G=G-V[i][2];
        }else{
            int aux=(G*100)/V[i][2];
            int profit_aux=(V[i][3]*aux)/100;
            profit=profit+profit_aux;
            G=0;
        }
        i++;
    }
    return profit;
}

int main()
{
    read_data();
    fill_data();
    sort_data();
    print_data();
    cout<<greedy(); // 1315
    return 0;
}

//#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
int main()
{
    while(1)
    {
    srand(time(0));
    int n ,c;
    while(1)
    {
    cout << "Enter N to find result of N-Queen : " ;
    cin>>n;
    if(n==2 || n==3)
     cout <<endl<< " 2 or 3 don't have any result  " <<endl<<endl;
    else
        break;
    }
    int d[n][n] ,t[n],chek[n],un,ur,b,a,y(0),temp,h;
    for(int k=0; k<n; k++)
    {
    chek[k]=-1;
    t[k]=-1;
    }
     for(int k=0; k<n; k++)
     for(int r=0;r<n;r++)
    d[k][r]=0;

    for(int r=0;r<n;r++)
    {
        while(1)
        {
          for(int g=0;g<n;g++)
            {
              if(chek[g]==1)
                  h++;
          }

            if(h==n)
            {
              r=0;
              for(int k=0; k<n; k++)
              {
              chek[k]=-1;
              t[k]=-1;
              }
               for(int k=0; k<n; k++)
               for(int l=0;l<n;l++)
              d[k][l]=0;
               h=0;
            }
            else
                h=0;
        c=rand()%(n);
        while(1)
        {
            if(chek[c]==1)
                c=(c+1)%n;
            else
                break;
        }
        chek[c]=1;
        d[c][r]=1;
        t[r]=c;
        un=r;
        ur=c;
        ////////////////
        a=un;
        while(1)
        {
            a=(a+1) % n;
            /// ///
            if(a==un)
                break;
            if(d[ur][a]==1){
                y++;
                break;
            }
        }
        a=un;
        b=ur;
        while(1)
        {
            if((a==(n-1)) || (b==0))
            {
              temp=a;
              a=b;
              b=temp;
            }
            else
            {
            a++;
            b--;
            }
            if(a==un && b==ur)
                break;
            if(d[b][a]==1)
            {
                y++;
                break;
            }
        }
        a=un;
        b=ur;
        while(1)
        {
            if(a==(n-1) || b==(n-1))
            {
              temp=(n-1)-a;
              a=(n-1)-b;
              b=temp;
            }
            else
            {
            a++;
            b++;
            }
            if(a==un && b==ur)
                break;
            if(d[b][a]==1)
            {
                y++;
                break;
            }
        }
        ////////////////
        if(y==0)
            break;
        else
        {
           d[ur][un] =0;
           t[r]=-1;
           y=0;
        }
        }
        //////////////////
        y=0;
        for(int k=0; k<n; k++)
        chek[k]=-1;
        ////////////////////////////////////////////////////////////////////////////////////////
    }
    cout<<n<<"-Queen"<<endl<<"Result : "<<endl<<endl;
    for(int k=0; k<n; k++)
    {
        cout<<endl;
    for(int r=0;r<n;r++)
    {

   cout<<" "<< d[k][r]<<" ";
    }
   }
    cout<<endl;
    cout<<endl;
    cout<<endl;

     for(int k=0; k<n; k++)
     {if (k%25==0)
             cout<<endl;
    cout<<" "<< t[k]<<" ";

     }
     cout<<endl<<endl<<endl;
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <windows.h>
#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int L=1024,l=768;
int k,n,R,i;
float pi=3.141592564,M_x1,M_y1,M_x2,M_y2;
int color_rnd;
struct punct
{
    int x,y;
} C;
void draw_polygon()
{
    cout<<"Enter a number> = 3:";
    cin>>i;
    cout<<"Enter the radius:";
    cin>>R;
    ///Checking if the input data respects the imposed restrictions
    if(i>=3)
    {
        initwindow(L,l,"Drawing polygons with n sides");///opening a graphic window of size Lxl
        srand(time(NULL));///makes use of the computer's internal clock to control the choice of the seed
        ///using a for-loop instruction, "traverse" each polygon to determine the coordinates of each side
        for(n=3; n<=i; n++)
        {
            for(k=0; k<=n; k++)
            {
                setcolor(15);
                color_rnd=rand()%14+1;///generates a random color between 0 and 14
                setcolor(color_rnd);
                /**
                The coordinates of the points on the "imaginary circle" are determined
                using mathematical formulas from complex numbers;
                For example:
                M_x1 = R * cos(a) , where a represents the angle on the circle.
                */
                M_x1=R*cos((2*k*pi)/n)+L/2;
                M_y1=R*sin((2*k*pi)/n)+l/2;
                M_x2=R*cos((2*(k+1)*pi)/n)+L/2;
                M_y2=R*sin((2*(k+1)*pi)/n)+l/2;
                line(M_x1,M_y1,M_x2,M_y2);///draw the line, using the determined coordinates
                setlinestyle(0,0,3);
                delay(50);
            }
            ///used to obtain diagonal coordinates and draw them (the same steps as above)
            for(int k1=0; k1<n; k1++)
            {
                for(int k2=k1; k2<n; k2++)
                {
                    setcolor(15);
                    color_rnd=rand()%14+1;
                    setcolor(color_rnd);
                    M_x1=R*cos((2*k1*pi)/n)+L/2;
                    M_y1=R*sin((2*k1*pi)/n)+l/2;
                    M_x2=R*cos((2*k2*pi)/n)+L/2;
                    M_y2=R*sin((2*k2*pi)/n)+l/2;
                    line(M_x1,M_y1,M_x2,M_y2);
                    setlinestyle(0,0,3);
                    delay(50);
                }
            }
            delay(3000);
            setfillstyle(1,0);
            floodfill(L/2,l/2,15);
            setfillstyle(1,0);
            floodfill(10,10,15);
        }
    }
    else
    {
        cout<<"Cannot build a polygon with "<<n<<" sides. Enter another number. "<<endl;
        draw_polygon();
    }
    system("pause");
}
void draw_n_polygon()
{
    cout<<"Enter a number> = 3:";
    cin>>i;
    cout<<"Enter the radius:";
    cin>>R;
    if(i>=3)
    {
        initwindow(L,l,"Drawing polygons with n sides");
        srand(time(NULL));
        for(n=i; n<=i; n++)
        {
            for(k=0; k<=n; k++)
            {
                setcolor(15);
                color_rnd=rand()%14+1;
                setcolor(color_rnd);
                M_x1=R*cos((2*k*pi)/n)+L/2;
                M_y1=R*sin((2*k*pi)/n)+l/2;
                M_x2=R*cos((2*(k+1)*pi)/n)+L/2;
                M_y2=R*sin((2*(k+1)*pi)/n)+l/2;
                line(M_x1,M_y1,M_x2,M_y2);
                setlinestyle(0,0,3);
                delay(10);
            }
            for(int k1=0; k1<n; k1++)
            {
                for(int k2=k1; k2<n; k2++)
                {
                    setcolor(15);
                    color_rnd=rand()%14+1;
                    setcolor(color_rnd);
                    M_x1=R*cos((2*k1*pi)/n)+L/2;
                    M_y1=R*sin((2*k1*pi)/n)+l/2;
                    M_x2=R*cos((2*k2*pi)/n)+L/2;
                    M_y2=R*sin((2*k2*pi)/n)+l/2;
                    line(M_x1,M_y1,M_x2,M_y2);
                    setlinestyle(0,0,3);
                    delay(10);
                }
            }
            delay(5000);
            setfillstyle(1,0);
            floodfill(L/2,l/2,15);
            setfillstyle(1,0);
            floodfill(10,10,15);
        }
    }
    else
    {
        cout<<"Cannot build a polygon with "<<n<<" sides. Enter another number. "<<endl;
        draw_n_polygon();
    }
    system("pause");
}
void menu()
{
    cout<<"This is the menu. Please select one of the options below:"<<endl;
    cout<<"Press 1 if you want to draw a polygon with n sides. "<<endl;
    cout<<"Press 2 if you want to draw the polygons up to a n read (including the diagonals)."<<endl;
    char ch=_getch();
    if(ch=='1')
    {
        cout<<"You pressed "<<ch<<"."<<endl;
        draw_n_polygon();
    }
    else if(ch=='2')
    {
        cout<<"You pressed "<<ch<<"."<<endl;
        draw_polygon();
    }
    else
    {
        cout<<endl;
        cout<<"You did not press one of the above keys. Please try again!"<<endl;
        cout<<endl<<"Welcome back!"<<endl;
        menu();
    }
}
int main()
{
    menu();
    system("pause");
    return 0;
}

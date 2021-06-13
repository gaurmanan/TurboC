//Run in turboC
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
/////////////////////////////////////
void draw(char *);
int  checkwin(char *);
void draw1(char *,int);
void draw2(char ,int, int);
void setc(void);
void intro(void);
void manan(void);
void gofirst(void);
void draw_win(char);
void cont(void);
void loading(int);
///////////////////////////////
void main(void)
{
   int i, t, f2;
   char a[9], b[2], f= 'n',tf;
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "");

   intro();
   while(1){
   cleardevice();
   gofirst();
   tf = getch();
   if(tf== '1')
	{ b[0] = 'X';	b[1] = 'O';}
   else
	{ b[1] = 'X';	b[0] = 'O';}
   for(i =0; i <9; i++)
	a[i] = '1'+i;
   for(i = 0;i<=8 ; i++)
   {
	cleardevice();
	draw(&a[0]); f2 = 1;
	do{
		tf = getch();
		t = (int)tf-49;
		if(a[t]=='X'||a[t]=='O');
		else
		{
			if(i%2==0)
				a[t]=b[0];
			else
				a[t]=b[1];
		       f2 = 0;

	       }
	       printf("\nPlease input a valid unoccupied value\n");
	}while(f2==1); clrscr();
	f = checkwin(&a[0]);
	if(f!='n')
	break;
	clrscr();
   }
   cleardevice();
   draw(&a[0]);
   cleardevice();
   draw_win(f); tf = 'c';
   getch();
   while(1){
    if( tf=='y'||tf=='Y')
    break;
    if( tf=='n'||tf=='N')
    {
    closegraph();
    exit(0);
    }
    cont();
    tf = getch();
    }
    cleardevice();
   }
}
/////////////////////////////
void draw(char *a)
{
	int i;
	for(i =1; i <=2; i++)
	{
		setc();
		line(getmaxx()*i/3-1,0,getmaxx()*i/3-1,getmaxy());    setc();
		line(getmaxx()*i/3,0,getmaxx()*i/3,getmaxy());        setc();
		line(getmaxx()*i/3+1,0,getmaxx()*i/3+1,getmaxy());    setc();
		line(0,getmaxy()*i/3-1,getmaxx(),getmaxy()*i/3-1);    setc();
		line(0,getmaxy()*i/3,getmaxx(),getmaxy()*i/3);        setc();
		line(0,getmaxy()*i/3+1,getmaxx(),getmaxy()*i/3+1);
	}
	for(i = 0; i < 9; i++)
		draw1((a+i),i);

	manan();
}
///////////////////////////////////
void draw1(char *a,int n)
{
	switch(n){
		case 0:
		draw2(*a,getmaxx()/6, getmaxy()*5/6);
		break;
		case 1:
		draw2(*a,getmaxx()/2, getmaxy()*5/6);
		break;
		case 2:
		draw2(*a,getmaxx()*5/6, getmaxy()*5/6);
		break;
		case 3:
		draw2(*a,getmaxx()/6, getmaxy()/2);
		break;
		case 4:
		draw2(*a,getmaxx()/2, getmaxy()/2);
		break;
		case 5:
		draw2(*a,getmaxx()*5/6, getmaxy()/2);
		break;
		case 6:
		draw2(*a,getmaxx()/6, getmaxy()/6);
		break;
		case 7:
		draw2(*a,getmaxx()/2, getmaxy()/6);
		break;
		case 8:
		draw2(*a,getmaxx()*5/6, getmaxy()/6);
	}
}
///////////////////////////////////
void draw2(char a,int x, int y)
{
	char b[2];
	b[0] = a; b[1] = '\0';
	setc();
	if(a == 'O'){
	circle(x,y,40); circle(x,y,41);}
	else if(a == 'X'){
		line(x-56,y-56,x+56,y+56);
		line(x-56,y+56,x+56,y-56);
	}
	else{
		settextstyle(3,0,3);
		outtextxy(x,y,b);
	}
}
/////////////////////////////////
int checkwin(char *a)
{
	if(*(a)==*(a+1)&&*(a)==*(a+2))
		return *a;
	else if(*(a+3)==*(a+4)&&*(a+4)==*(a+5))
		return *(a+3);
	else if(*(a+6)==*(a+7)&&*(a+6)==*(a+8))
		return *(a+6);
	else if(*(a)==*(a+3)&&*(a)==*(a+6))
		return *a;
	else if(*(a+1)==*(a+4)&&*(a+1)==*(a+7))
		return *(a+1);
	else if(*(a+2)==*(a+5)&&*(a+2)==*(a+8))
		return *(a+2);
	else if(*(a)==*(a+4)&&*(a)==*(a+8))
		return *a;
	else if(*(a+2)==*(a+4)&&*(a+2)==*(a+6))
		return *(a+4);
	else
		return 'n';
}
////////////////////////////////////////
void setc()
{
	int t;
	t = rand()%16;
	if(t == 0)
	 t = 3;
	setcolor(t);
}
////////////////////////////////////////////
void intro()
{
	int i;
	for(i=1;i<=99;i++){
		setc();
		settextstyle(1,0,3);
		outtextxy(getmaxx()/2,getmaxy()/2,"Tic Tac Toe");
		manan();
		//circle(getmaxx()/2,getmaxy()/2,99+i);
		loading(i);
		delay(50);
		cleardevice();
	}
}

void manan()
{
	char a[6];
	sprintf(a,"%cManan",'@');
	setc();
	settextstyle(1,0,2);
	outtextxy(getmaxx()-80,getmaxy()-20,a);
}
////////////////////////////////////////
void gofirst()
{
	setc();
	settextstyle(1,0,3);
	outtextxy(32,32,"Who Goes First");
	setc();
	line(getmaxx()/3-56,getmaxy()/2-56,getmaxx()/3+56,getmaxy()/2+56);
	line(getmaxx()/3-56,getmaxy()/2+56,getmaxx()/3+56,getmaxy()/2-56);
	outtextxy(getmaxx()/3-25,getmaxy()/2+55,"Press: 1");
	setc(); circle(getmaxx()*2/3,getmaxy()/2,40);
	circle(getmaxx()*2/3,getmaxy()/2,41);
	outtextxy(getmaxx()*2/3-25,getmaxy()/2+55,"Press: 2");
	manan();
}
//////////////////////////////////////
void draw_win(char a)
{
	if(a == 'O'){
	settextstyle(1,0,3);
	setc();
	circle(getmaxx()/2,getmaxy()/2,40);
	circle(getmaxx()/2,getmaxy()/2,41);
	outtextxy(getmaxx()/2-25,getmaxy()/2+55,"Wins");
	}
	else if(a == 'X'){
	settextstyle(1,0,3);
	setc();
	outtextxy(getmaxx()/2-25,getmaxy()/2+55,"Wins");
	line(getmaxx()/2-56,getmaxy()/2-56,getmaxx()/2+56,getmaxy()/2+56);
	line(getmaxx()/2-56,getmaxy()/2+56,getmaxx()/2+56,getmaxy()/2-56);
	}
	else{
	settextstyle(1,0,3);
	outtextxy(getmaxx()/2-25,getmaxy()/2,"Nobody Wins");
	}
	manan();
}
////////////////////////////////////////////////////////////
void cont()
{
	setc();
	cleardevice();
	settextstyle(1,0,3);
	outtextxy(getmaxx()/2-100,getmaxy()/2,"Do you want to continue? (Y/N)");
	manan();
}

void loading(int i){
	char a[11];
	if(i<10)
	sprintf(a,"%cLoading..%d",'#',i);
	else
	sprintf(a,"%cLoading.%d",'#',i);
	setcolor(GREEN);
	settextstyle(1,0,2);
	outtextxy(80,getmaxy()-30,a);
	setcolor(RED);
	//rectangle(10,20,(getmaxx()*i/100),20);
}

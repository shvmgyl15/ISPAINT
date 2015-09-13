#include<fstream.h>
#include<stdio.h>
#include<conio.h>



void line()
{
 int x=160,y=90,z=470,w=370;
 setcolor(8);
 line(x,y,z,y);
 line(x,y,x,w);
 setcolor(0);
 line(x+1,y+1,z-1,y+1);
 line(x+1,y+1,x+1,w-1);
 }

int lines=25;

void SCROLLER()
{
settextstyle(SMALL_FONT,0,4);
    int x=163,y=93;
 ifstream fp("help.dat",ios::in|ios::binary);   //file name
 char s[80],ch;
 int c=0,ud=0,lr=0;
 do
 {
  if(c<=lines)  //lines that can fit your screen
  {
		  setcolor(0);
   fp.getline(s,80);
   outtextxy(x,y,s);
   c++;
   y+=14;
  }
  else
  {
   ch=getch();
   if(ch==80)            //down arrow
   {

  setfillstyle(SOLID_FILL,15);
   bar(160,90,470,370);
   line();
    ud++;
    if(ud>=0 && ud<lines+2)
     lr=1;
    fp.seekg(0,ios::beg);
    int i=0;
    while(i!=ud)
     {
      i++;
      fp.getline(s,80);
     }
    if(ud%(lines+2)==0)
     lr++;
    c=-1;
    y=93;
   }
   else if(ch==72 && ud!=0)        //up arrow
	{
	   setfillstyle(SOLID_FILL,15);
   bar(160,90,470,370);
	 line();
	 ud--;
	 if(ud==0)
	  lr=0;
	 fp.seekg(0,ios::beg);
	 int i=0;
	 while(i!=ud)
	 {
	  i++;
	  fp.getline(s,80);
	 }
	 if(ud%(lines+2)==0)
	 {
	  lr--;
	 }
	 c=-1;
	  y=93;
	}
	else if(ch==77)               //right arrow
	     {
		setfillstyle(SOLID_FILL,15);
   bar(160,90,470,370);
	       line();
	     // clrscr();
	      lr++;
	      ud+=lines+2;
	      c=-1;
	       y=93;
	     }
	     else if(ch==75 && lr>=0) //left arrow
		  {
		     setfillstyle(SOLID_FILL,15);
   bar(160,90,470,370);

		  line();
		   lr--;
		   if(ud>=lines+2)
		    ud-=lines+2;
		   else
		    ud=0;
		   fp.seekg(0,ios::beg);
		   int i=0;
		   while(i!=ud)
		   {
		    i++;
		    fp.getline(s,80);
		   }
		   c=-1;
		    y=93;
		  }
  }
 }while(ch!=27 && ch!=13);
 fp.close();
}

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<graphics.h>

int c=1,cc=7;
void bar(int a);
void corner_button(int,int);
void close_button(int,int);
int password();

void bar(int a)
{
  setfillstyle(SOLID_FILL,a);
  bar(612,290,627,310);
  setcolor(8);
  line(611,289,628,289);
  line(611,289,611,311);
  setcolor(7);
  line(612,290,627,290);
  line(612,290,612,310);
  setcolor(15);
  line(613,311,629,311);
  line(629,290,629,311);
}


void barpattern(int a,int cc)
{
  setfillstyle(cc,a);
  bar(12,290,27,310);
  setcolor(8);
  line(11,289,28,289);
  line(11,289,11,311);
  setcolor(0);
  line(12,290,27,290);
  line(12,290,12,310);
  setcolor(15);
  line(13,311,29,311);
  line(29,290,29,311);
}


void corner_button(int x,int y)
{
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,7);
 settextstyle(SMALL_FONT,0,6);
 rectangle(x-5,y-3,x+8,y+8);
 setcolor(8);
 rectangle(x-4,y-2,x+9,y+9);
 bar(x-4,y-2,x+8,y+8);
}


void close_button(int x,int y)
{
 corner_button(x,y);
 setcolor(BLACK);
 outtextxy(x-1,y-9,"x");
 outtextxy(x-2,y-9,"x");
}


/*void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"\\tc\\bgi");

if(password())
 bar(0,0,200,200);
else
 bar(200,200,205,205);

getch();
closegraph();

} */


void SCREEN()
{
// int gd=DETECT,gm;
// initgraph(&gd,&gm,"\\tc\\bgi");


 setcolor(15);
 settextstyle(0,HORIZ_DIR,0);
 rectangle(0,0,637,477);
 setcolor(8);
 rectangle(0,0,638,478);
 setcolor(15);
 rectangle(0,0,636,476);
 setfillstyle(SOLID_FILL,7);
 bar(1,1,599,59);
 bar(1,1,40,475);
 bar(599,1,636,476);
 bar(1,461,636,479);
// bar(40,60,600,460); canvas

 //top bar
 setcolor(8);
 line(40,60,600,60);
 line(40,60,40,460);
 setcolor(0);
 line(41,61,599,61);
 line(41,61,41,459);
 setcolor(15);
 line(42,459,598,459);
 line(600,62,600,458);
 setfillstyle(SOLID_FILL,1);
 setcolor(1);
 bar(2,2,636,16);
 //top bar

 //logo
 setcolor(YELLOW);
 outtextxy(15,4,"/");
 outtextxy(16,4,"/");
 outtextxy(17,6,"/");
 outtextxy(18,6,"/");
 outtextxy(19,8,"/");
 outtextxy(20,8,"/");
 setcolor(15);
 outtextxy(30,6,"ISPAINT-(G.C.G)");
 setfillstyle(SOLID_FILL,7);  //coord help bar
 bar(40,463,600,475);
 setcolor(15);
 //end of logo

  close_button(626,6);  //cross button top right corner

 // setfillstyle(SOLID_FILL,15); //has to be called during first load
 // bar(43,62,597,458.5);        //actual exact canvas coords


 //Drawing Menu    and some lines...
 int t=0;

 char men[][20]={"OPEN","SAVE","NEW","PASSWORD","HELP"};
 settextstyle(SMALL_FONT,0,4);
 setfillstyle(SOLID_FILL,7);
 bar(4,21,630,30);
 setcolor(0);

 for(int yy=0;yy<5;yy++)
 {
  t+=textwidth(men[yy]);
 }

 line(4,40,80+t,40);
 line(4,40,4,55);
 setcolor(15);
 line(5,41,79+t,41);
 line(5,41,5,54);
 setcolor(8);
 line(5,55,79+t,55);
 line(79+t,42,79+t,55);

 int tc ,xc=10;
 //setcolor(0);
 for(int i=0;i<5;i++)
 {
  setcolor(0);
  tc=textwidth(men[i]);
  outtextxy(xc,42,men[i]);
  xc=xc+tc+15;
  if(i!=4)
  {
   setcolor(8);
   line(xc-10,42,xc-10,53);
  }
 }
 setcolor(8);
 line(3,62,39,62);
 setcolor(15);
 line(3,60,600,60);
 line(3,63,39,63);
 line(40,61,40,459);
 //end of draw menu


 //drawing colour pallete
 setfillstyle(SOLID_FILL,7);
 bar(602,64,635,300);
 setcolor(8);
 line(602,61,635,61);
 setcolor(15);
 line(602,60,635,60);
 line(602,62,635,62);
 int x=604,y=70,z=616,w=84;
 for( i=0;i<8;i++,y+=25,w+=25)
 {
  setcolor(i);
  setfillstyle(SOLID_FILL,i);
  rectangle(x,y,z,w);
  floodfill(x+1,y+1,i);
  setcolor(8);
  line(x-1,y-1,z+1,y-1);
  line(x-1,y-1,x-1,w+1);
  setcolor(0);
  line(x,y,z,y);
  line(x,y,x,w);
  setcolor(15);
  line(x+1,w+1,z+1,w+1);
  line(z+1,y+1,z+1,w+1);
 }

 x=621,y=70,z=633,w=84;
 for(i=8;i<16;i++,y+=25,w+=25)
 {
  setcolor(i);
  setfillstyle(SOLID_FILL,i);
  rectangle(x,y,z,w);
  floodfill(x+1,y+1,i);
  setcolor(8);
  line(x-1,y-1,z+1,y-1);
  line(x-1,y-1,x-1,w+1);
  setcolor(0);
  line(x,y,z,y);
  line(x,y,x,w);
  setcolor(15);
  line(x+1,w+1,z+1,w+1);
  line(z+1,y+1,z+1,w+1);
 }
 //end drawing color pallette

 //Drawing tools area bar bar(3,64,38,300)
 setfillstyle(SOLID_FILL,7);
 bar(3,64,38,300);
  x=6,y=70,z=18,w=84;
 for( i=0;i<4;i++,y+=25,w+=25)
 {
  setcolor(8);
  rectangle(x-1,y-1,z+1,w+1);
  setcolor(15);
  line(x,y-1,z,y-1);
  line(x,y,z,y);
  setcolor(8);
  line(x,w,z,w);
  line(x,w+1,z,w+1);
  line(x,w+1,z,w+1);
 }


 x=24,y=70,z=36,w=84;
 for(i=0;i<3;i++,y+=25,w+=25)
 {
  setcolor(8);
  rectangle(x-1,y-1,z+1,w+1);
  setcolor(15);
  line(x,y-1,z,y-1);
  line(x,y,z,y);
  setcolor(8);
  line(x,w,z,w);
  line(x,w+1,z,w+1);
  line(x,w+1,z,w+1);
 }
 settextstyle(SMALL_FONT,0,5);
 setcolor(0);
 outtextxy(9,67,"/");
 outtextxy(10,67,"/");
 rectangle(26,73,34,81);
 setcolor(15);
 line(26,82,34,82);
 setcolor(0);
 circle(12,102,4);
 setfillstyle(SOLID_FILL,0);
 circle(30,102,3);
 floodfill(31,103,0);
 setcolor(1);
 setfillstyle(SOLID_FILL,1);
 rectangle(27,126,33,131);
 floodfill(28,127,1);
 setcolor(0);
 line(30,122,30,125);
 setcolor(1);
 rectangle(11,122,13,127);
 floodfill(12,123,1);
 setcolor(0);
 line(12,127,12,129);
 setcolor(1);
 putpixel(12,131,1);
 setcolor(15);
 rectangle(10,149,14,155);
 setfillstyle(SOLID_FILL,15);
 floodfill(12,151,15);
 setcolor(0);
 rectangle(10,149,14,155);
 //end drawing toolbox


 //drawing fill patterns
 setfillstyle(SOLID_FILL,7);
 bar(605,320,637,457);
 int y4=330;
 int z4=346;
 setcolor(15);
 rectangle(603,318,637,459);
 cc=7;
 for(int ii=0;ii<5;ii++,cc++,y4+=25,z4+=25)
 {
  setfillstyle(cc,15);
  bar(611,y4,630,z4);
 }
 setcolor(0);

//end of fill patterns

//drawing fill patterns
 setfillstyle(SOLID_FILL,7);
 bar(5,320,37,457);
 y4=330;
 z4=346;
 setcolor(15);
 rectangle(3,318,37,459);
 cc=2;
 for(ii=0;ii<5;ii++,cc++,y4+=25,z4+=25)
 {
  setfillstyle(cc,15);
  bar(11,y4,30,z4);
 }
 setcolor(0);
 rectangle(42,61,598,459);
 bar(c);
 barpattern(cc,c);
//end of fill patterns

/*
getch();
closegraph();*/
}

int password()
{
 int ii=0;
 char s[20],t[20];
  ifstream fp("pass.txt");
  fp.getline(t,20);
  ii=strlen(t);
  fp.close();
 for(int j=0;j<ii;j++)
 {
  s[j]=t[j]+27;
 }
 s[j]='\0';
 if(ii==0)
 {
  ii=7;
  strcpy(s,"ISPAINT");
  cout<<s;
 }

 char aa[20];
 int k=0;
 int a[8]={240,210,40,270,240,320,40,370};
 int b[8]={240,240,40,300,240,350,40,400};
 setfillstyle(SOLID_FILL,15);
 bar3d(100,100,150,300,25,1);
 setcolor(RED);
 drawpoly(4,a);
 drawpoly(4,b);
 line(240,210,240,240);
 line(40,270,40,300);
 line(240,320,240,350);
 line(40,370,40,400);
 setfillstyle(SOLID_FILL,RED);
 floodfill(230,215,RED);
 floodfill(45,280,RED);
 floodfill(45,300,RED);
 floodfill(230,330,RED);
 floodfill(45,375,RED);

 settextstyle(7,HORIZ_DIR,8);
 setcolor(1);
 outtextxy(260,350,"PAINT");
 settextstyle(SMALL_FONT,0,10);
 setcolor(15);
 outtextxy( 245,315,"MART");
 outtextxy(200,260,"NTERACTIVE");
 settextstyle(0,0,0);
 setcolor(15);
 rectangle(200,170,450,250);
 setcolor(8);
 rectangle(200,170,451,251);
 setcolor(15);
 rectangle(200,170,449,249);
 setfillstyle(SOLID_FILL,7);
 bar(201,171,449,249);
 setfillstyle(SOLID_FILL,1);
 bar(201,171,449,185);
 setcolor(YELLOW);
 outtextxy(205,173,"/");
 outtextxy(206,173,"/");
 outtextxy(207,175,"/");
 outtextxy(208,175,"/");
 outtextxy(209,177,"/");
 outtextxy(210,177,"/");
 setcolor(15);

 outtextxy(270,174,"ENTER PASSWORD");
 setfillstyle(SOLID_FILL,15);
 bar(226,210,420,230);
 setcolor(8);
 line(226,210,420,210);
 line(226,210,226,230);
 setcolor(0);
 line(227,211,419,211);
 line(227,211,227,229);

 settextstyle(0,HORIZ_DIR,0);
 do
 {
 setfillstyle(SOLID_FILL,15);
 bar(226,210,420,230);
 setcolor(8);
 line(226,210,420,210);
 line(226,210,226,230);
 setcolor(0);
 line(227,211,419,211);
 line(227,211,227,229);
 close_button(440,175);
 settextstyle(0,HORIZ_DIR,0);
 setcolor(0);
 int x=300;
 for(int i=0;i<ii;i++,x+=10)
 {
  char ch;
  ch=getch();
  if(ch==27)
   exit(0);

  if(ch=='\b' && i>=0)
   {setcolor(15);
    x-=10;
    outtextxy(x,215,"*");
    i--;
    aa[i]='\0';
    i--;
    setcolor(0);
    x-=10;
   }
  else
   {
    aa[i]=ch;
    outtextxy(x,215,"*");
   }
 }

 aa[i]='\0';

 if(strncmpi(aa,s,ii)==0)
  return 1;
 else
 {
  setcolor(RED);
  outtextxy(230,195,"WRONG PASSWORD !");
  k++;
  if(k==3)
   return 0;
 }

}while(k<3);
 return 0;
}

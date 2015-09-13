#include<iostream.h>
#include<alloc.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include"PSCREEN.CPP"
#include"fmc.cpp"
#include"oimg.cpp"
#include"simg.cpp"
#include"infinity.cpp"

#define MYICON 1

void Mouse(char);
void main(char);
void write(char);
char pass[30];
int op(char ch);     //o or b or c
char s[20],f[20];   //open save name string
ofstream fout("temp.cpp");

double SQRT(long double num)
{
 long double min=0, max=1000,answer=0,test=0;

 if(num < 0)
 {
  printf("Negative numbers are not allowed");
  return -1;
 }
 else if(num == 0)
	return 0;

 while(1)
 {
  test = (min + max) / 2;
  answer = test * test;
  if( num > answer)
   min = test;
  else if(num < answer)
	max = test;
  if(num == answer)
   break;
  if(num > (answer - 0.0001) && num < (answer + 0.0001))
   break;
 }
 return test;
}



void fillp()
{
 int a[2];
 int x,y,button;

 setcolor(c);
 hidemouse();
 rectangle(42,62,598,458);
 mousecall();

 mousepos(button,x,y);
 if(button==1)
 {
  setfillstyle(cc,c);
  a[0]=x;
  a[1]=y;

 static int v1=0,v2=0;
 hidemouse();
 floodfill(a[0],a[1],c);
 if(v1!=a[0] || v2!=a[1])
  {
   fout<<"floodfill("<<a[0]<<','<<a[1]<<','<<c<<");\n";
   v1=a[0],v2=a[1];
  }
 mousecall();
 }
}



void help()
{
 setfillstyle(SOLID_FILL,0);
 bar(129,59,501,401);

 setfillstyle(SOLID_FILL,8);
 bar(130,60,500,400);
 setfillstyle(SOLID_FILL,7);
 bar(140,70,490,390);
 setfillstyle(SOLID_FILL,1);
 bar(140,60,490,75);

 setcolor(YELLOW);
 outtextxy(145,58,"/");
 outtextxy(146,58,"/");
 outtextxy(147,60,"/");
 outtextxy(148,60,"/");
 outtextxy(149,62,"/");
 outtextxy(150,62,"/");
 settextstyle(SMALL_FONT,0,6);

 setcolor(4);
 outtextxy(255,58,"HELP INDEX");
 setfillstyle(SOLID_FILL,15);
 int x=160,y=90,z=470,w=370;
 bar(x,y,z,w);

 setcolor(8);
 line(x,y,z,y);
 line(x,y,x,w);
 setcolor(0);
 line(x+1,y+1,z-1,y+1);
 line(x+1,y+1,x+1,w-1);
 settextstyle(SMALL_FONT,0,4);
// corner_button(460,380);
 setcolor(0);
 int key=0;
 int k1;
 char butt[4][10]={"UP   ","DN   ","LT   ","RT   "};
 char  hp[5][10]={"^","v","<",">"};
 while(key<4)
 {
  switch(key)
  {
   case 0: k1=160;
	   break;
   case 1: k1=160+70;
	   break;
   case 2: k1=160+140;
	   break;
   case 3: k1=160+210;
	   break;
  }
  setcolor(0);
  corner_button(k1+33,380);
  outtextxy(k1,373,butt[key]);
  outtextxy(k1+32,373,hp[key]);
  outtextxy(k1+33,373,hp[key]);
  key++;
 }

 lines=17;  //no. of lines in window
 SCROLLER();
 hidemouse();
 mousecall();

}



void brush(int x1,int y1)
{
 int x2,y2;
 int button=0;
 setcolor(c);
 mousecall();
 mousepos(button,x2,y2);
 do
 {
  if(button==1)
  {
   static int v1=0,v2=0,v3=0,v4=0;
   hidemouse();
   line(x1,y1,x2,y2);
   if(v1!=x1 || v2!=y1 || v3!=y2 || v4!=x2)
   {
    fout<<"line("<<x1<<','<<y1<<','<<x2<<','<<y2<<");\n";
    v1=x1,v2=y1,v3=y2,v4=x2;
   }
   mousecall();
   x1=x2,y1=y2;
  }
  else
   mousepos(button,x1,y1);
  mousepos(button,x2,y2);
 }while(x2>43 && x2<597 && y2>63  && y2<457);
}



void bucket()
{
 int a[2];
 int x,y,button;

 setcolor(c);
 hidemouse();
 rectangle(42,62,598,458);
 mousecall();

 mousepos(button,x,y);

 if(button==1)
 {
  setfillstyle(SOLID_FILL,c);
  a[0]=x;
  a[1]=y;

  static int v1=0,v2=0;
  hidemouse();
  floodfill(a[0],a[1],c);
  if(v1!=a[0] || v2!=a[1])
  {
   fout<<"floodfill("<<a[0]<<','<<a[1]<<','<<c<<");\n";
   v1=a[0],v2=a[1];
  }
  mousecall();
 }
}


void eraser()
{
 bar(15);

 setfillstyle(SOLID_FILL,15);
 int button,x,y;

  mousepos(button,x,y);
  if(button==1 && x>48&&x<592&&y<452&&y>68)
  {
   static int v1=0,v2=0;
   hidemouse();
   pieslice(x, y, 0, 360, 6);
   if(v1!=x ||v2!=y)
   {
    fout<<"pieslice("<<x<<','<<y<<','<<"0,360,6);\n";
    v1=x,v2=y;
   }
   mousecall();
  }

}


int help_bar(int gg)
{
 if(gg==1)
  {
  setfillstyle(SOLID_FILL,7);
  bar(40,463,600,475);
  return 0;
  }
 return 1;
}


void Mouse(char ch)
{
 if(ch=='o')
  bar(0);
 else if(ch=='n')
      {
       setfillstyle(SOLID_FILL,15);
       hidemouse();
       bar(42,62,598,458);
       mousecall();
       setcolor(c);
       bar(c);
      }
 int cl,x5,y5,tool;
 int x1=604,y1=70,z=616,w=84;
 setfillstyle(cc,c);
 bar(12,290,27,310);       //fillp show bar
 do
 {
  if(ch=='n')
  {
   ch='k';
   if(tool==4)
    fout<<"setfillstyle(SOLID_FILL,"<<c<<");\n";
   else
       if(tool==1)
	fout<<"setfillstyle(SOLID_FILL,15);\n";
       else
	   if(tool==6)
	    fout<<"setfillstyle("<<cc<<','<<c<<");\n";
   fout<<"setcolor("<<c<<");\n";
   fout<<"rectangle(42,62,598,458);\n";
  }
  mousecall();
  x1=604,y1=70,z=616,w=84;
  for(int i=0;i<8;i++,y1+=25,w+=25)
  {
   mousepos(cl,x5,y5);
   if(x5>=x1&&x5<=z&&y5>=y1&&y5<=w)
    if(cl==1)
     {
      static int v=1;
      if(v!=c)
      {
       fout<<"setfillstyle(SOLID_FILL,"<<c<<");\n";
       fout<<"setcolor("<<c<<");\n";
       fout<<"rectangle(42,62,598,458);\n";
       v=c;
      }
      c=i;
      setfillstyle(cc,c);
      bar(12,290,27,310);
      setfillstyle(SOLID_FILL,c);

     }
  }

  x1=621,y1=70,z=633,w=84;
  for( i=8;i<16;i++,y1+=25,w+=25)
  {
   mousepos(cl,x5,y5);
   if(x5>=x1&&x5<=z&&y5>=y1&&y5<=w)
    if(cl==1)
    {
     static int v=0;
     c=i;

       setfillstyle(cc,c);
       bar(12,290,27,310);
       setfillstyle(SOLID_FILL,c);
     if(v!=c)
     {
      fout<<"setfillstyle(SOLID_FILL,"<<c<<");\n";
      fout<<"setcolor("<<c<<");\n";
      fout<<"rectangle(42,62,598,458);\n";
      v=c;
     }
    }
  }

  x1=605,y1=320,z=637,w=457;
  for(i=7;i<11;i++,y1+=25,w+=25)
  {
   mousepos(cl,x5,y5);
   if(x5>=x1&&x5<=z&&y5>=y1&&y5<=w)
    if(cl==1)
     {
      static int v=0;
      cc=i;
      setfillstyle(cc,c);
      bar(12,290,27,310);
      if(v!=cc)
      {
       fout<<"setfillstyle("<<cc<<','<<c<<");\n";
       v=cc;
      }
     }
  }
  x1=5,y1=320,z=37,w=457;
  for(i=2;i<7;i++,y1+=25,w+=25)
  {
   mousepos(cl,x5,y5);
   if(x5>=x1&&x5<=z&&y5>=y1&&y5<=w)
    if(cl==1)
     {
      static int v=0;
      cc=i;
      setfillstyle(cc,c);
      bar(12,290,27,310);
      if(v!=cc)
      {
       fout<<"setfillstyle("<<cc<<','<<c<<");\n";
       v=cc;
      }
     }
  }

  bar(c);
  delay(100);
  mousepos(cl,x5,y5);

  if(x5>=621&&x5<=635&&y5>=3&&y5<=16)     //changes made !!!
  {
   if(cl==1)
   {
    hidemouse();
    break;
   }
  }

  mousepos(cl,x5,y5);
  int gg=0;

  gg=help_bar(gg);

  while(x5>=24&&x5<=36&&y5>=70&&y5<=84)
  {
   mousepos(cl,x5,y5);
   setcolor(0);
   settextstyle(SMALL_FONT,0,4);
   outtextxy(45,464,"RECTANGLE ");
   gg=1;
   if(cl==1)
   {
    tool=0;
   }
  }

  gg=help_bar(gg);
  static int er=1;
  mousepos(cl,x5,y5);
  while(x5>=6&&x5<=18&&y5>=145&&y5<=159)
  {
   mousepos(cl,x5,y5);
   setcolor(0);
   settextstyle(SMALL_FONT,0,4);
   outtextxy(45,464,"ERASER ");
   gg=1;

   if(cl==1 && er==1)
   {
    tool=1;
    bar(15);
    fout<<"setfillstyle(SOLID_FILL,15);\n";
    fout<<"setcolor(15);\n";
    er=2;
   }
  }


  if(tool!=1)
  {
   bar(c);
   er=1;
  }
  gg=help_bar(gg);

  mousepos(cl,x5,y5);

  while(x5>=6&&x5<=18&&y5>=70&&y5<=84)
  {
   mousepos(cl,x5,y5);
   setcolor(0);
   settextstyle(SMALL_FONT,0,4);
   outtextxy(45,464,"LINE");
   gg=1;

   if(cl==1)
   {
    tool=2;
   }
  }

  gg=help_bar(gg);

  mousepos(cl,x5,y5);

  while(x5>=6&&x5<=18&&y5>=90&&y5<=109)
  {
   mousepos(cl,x5,y5);
   setcolor(0);
   settextstyle(SMALL_FONT,0,4);
   outtextxy(45,464,"CIRCLE");
   gg=1;

   if(cl==1)
   {
    tool=3;
   }
  }

  gg=help_bar(gg);

  mousepos(cl,x5,y5);

  while(x5>=24&&x5<=36&&y5>=120&&y5<=134)
  {
   mousepos(cl,x5,y5);
   setcolor(0);
   settextstyle(SMALL_FONT,0,4);
   outtextxy(45,464,"BUCKET");
   gg=1;
   if(cl==1)
   {
    if(cc!=1)
    {
     fout<<"setfillstyle(SOLID_FILL,"<<c<<");\n";
     cc=1;
    }
    tool=4;
   }
  }

  gg=help_bar(gg);

   mousepos(cl,x5,y5);

  while(x5>=24&&x5<=36&&y5>=90&&y5<=109)
  {
   mousepos(cl,x5,y5);
   setcolor(0);
   settextstyle(SMALL_FONT,0,4);
   outtextxy(45,464,"BRUSH ");
   gg=1;
   if(cl==1)
   {
    tool=5;
   }
  }


  gg=help_bar(gg);


  mousepos(cl,x5,y5);

  while(x5>=6&&x5<=18&&y5>=120&&y5<=134)
  {
   mousepos(cl,x5,y5);
   setcolor(0);
   settextstyle(SMALL_FONT,0,4);
   gg=1;
   outtextxy(45,464,"FILLER");
   if(cl==1)
   {
    tool=6;
   }
  }

  gg=help_bar(gg);

  mousepos(cl,x5,y5);
  static int v=0;
  if(x5>39 && x5<78 && y5>=42 && y5<=55)     //save
  {
   if(cl==1)
   {
    char f[20];
    hidemouse();
    SBMP("temp.bmp");
    if(op('b'))
    {
     strcpy(f,s);
     if(!strchr(f,'.'))
      strcat(f,".bmp");
     int check;
     check=rename("temp.bmp",f);
     if(check==-1)
     {
      remove(f);
      rename("temp.bmp",f);
     }
    }

    if(v==0)
    {
     if(op('c'))
     {
      v=1;
      if(!strchr(s,'.'))
       strcat(s,".cpp");
      strcpy(::f,s);
     }
     else if(bmp("temp.bmp",0,0))
	  {}
	  else
	   bmp(f,0,0);

    }
    if(bmp(f,0,0));
    else
     bmp("temp.bmp",0,0);
    mousecall();
   }
  }

   mousepos(cl,x5,y5);

  if(x5>=10 && x5<39 && y5>=42 && y5<=55)          //open
  {
   if(cl==1)
   {
    hidemouse();
    SBMP("temp.bmp");
    if(op('o'))
    {
     if(!strchr(s,'.'))
      strcat(s,".bmp");

     if(bmp(s,0,0))
     {
      settextstyle(2,0,7);
      cleardevice();
      setcolor(RED);
      outtextxy(200,220," SUCH FILE DOES NOT EXIST");
      outtextxy(200,280,"PRESS ENTER TO CONTINUE:");
      getch();
      bmp("temp.bmp",0,0);
     }
     }
    else
     bmp("temp.bmp",0,0);
    mousecall();
   }

  }

    mousepos(cl,x5,y5);
  if(x5>78 && x5<111 && y5>=42 && y5<=55)          //new
  { if(cl==1)
  {
   v=0;
   main('n');
  }
  }


    mousepos(cl,x5,y5);
 if(x5>111 && x5<174 && y5>=42 && y5<=55)          //password change
  { if(cl==1)
   {
    hidemouse();
    SBMP("temp.bmp");
    if(op('p'))
    {
     ofstream fout("pass.txt");
     char t[20];
     for(int m=0;s[m]!='\0';m++)
     {
      t[m]=s[m]-27;
     }
     t[m]='\0';
     fout<<t;
     fout.close();
    }
    bmp("temp.bmp",0,0);
    mousecall();

   }
  }


    mousepos(cl,x5,y5);
 if(x5>174 && x5<217 && y5>=42 && y5<=55)          //help
  { if(cl==1)
   {
    hidemouse();
    SBMP("temp.bmp");
    help();
    bmp("temp.bmp",0,0);
    mousecall();
   }
  }



  while(x5>43 && x5<597 && y5>63  && y5<457)
  {
   mousepos(cl,x5,y5);
   mousecall();
   if(cl==1 && x5>43 && x5<597 && y5>63  && y5<457 )
   {
    double a,b,p,x1,y1,x2,y2;
    static int v1=0,v2=0,v3=0,v4=0;
    double r;
    switch(tool)
    {
     case 0://rectangle

     mousecall();
     x1=x5;
     y1=y5;

     delay(500);
     restrict(43,597,63,457);
     mousepos(cl,x5,y5);

     x2=x5,y2=y5;
     setcolor(c);
     hidemouse();
     rectangle(x1,y1,x2,y2);
     if(v1!=x1 || v2!=x2 || v3!=y1 || v4!=y2)
     {
      fout<<"rectangle("<<x1<<','<<y1<<','<<x2<<','<<y2<<");\n";
      v1=x1,v2=x2,v3=y1,v4=y2;
     }
     mousecall();
     restrict(0,640,0,480);
	  break;
   case 1:eraser();
	  break;
   case 2://line();

   mousecall();
   x1=x5;
   y1=y5;

   delay(500);
   restrict(43,597,63,457);
   mousepos(cl,x5,y5);

   x2=x5,y2=y5;
   setcolor(c);
   hidemouse();
   line(x1,y1,x2,y2);
   if(v1!=x1 || v2!=x2 || v3!=y1 || v4!=y2)
   {
    fout<<"line("<<x1<<','<<y1<<','<<x2<<','<<y2<<");\n";
    v1=x1,v2=x2,v3=y1,v4=y2;
   }
   mousecall();
   restrict(0,640,0,480);
	  break;
   case 3://circle();

   mousecall();
   x1=x5;
   y1=y5;

   delay(500);

   restrict(43,597,63,457);
   mousepos(cl,x5,y5);

   x2=x5,y2=y5;
   a=(x1-x2)*(x1-x2),b=(y1-y2)*(y1-y2);
   p=a+b;
   r=SQRT(p);
   setcolor(c);
   int c1=x1+r,c2=x1-r,c3=y1+r,c4=y1-r;
   hidemouse();
   circle(x1,y1,r);
   if(v1!=x1 || v2!=y1)
   {
    fout<<"circle("<<x1<<','<<y1<<','<<r<<");\n";
    v1=x1,v2=y1;
   }
   if(c1>597 || c2<43 || c3>457 || c4<63)
    SCREEN();
   mousecall();
   restrict(0,640,0,480);
   break;
   case 4:bucket();
	  break;
   case 5:brush(x5,y5);
	  break;
   case 6:fillp();
	  break;
   default:brush(x5,y5);
    }
   }
  }
 }while(1);
}


void write(char ch='o')
{
  fout<<"#include<graphics.h>\n"
      <<"#include<conio.h>\n\n"
      <<"void main()\n"
      <<"{\nint gd=DETECT,gm;\n"
      <<"initgraph(&gd,&gm,\"\\\\tc\\\\bgi\");\n\n";
  fout<<"setfillstyle(SOLID_FILL,15);\n"
      <<"bar(0,0,640,480);\n"
      <<"/*remove the above 2 lines if u dont want white background*/\n\n";
  if(ch=='o')
  {
   fout<<"setfillstyle(SOLID_FILL,1);\n"
       <<"setcolor(1);\n";
   fout<<"rectangle(42,62,598,458);\n";
  }
   Mouse(ch);
   fout<<"getch();\nclosegraph();\n}";
   rename("temp.cpp",f);

}

void main(char ch='k')
{
 if(ch=='n')
 {
  fout<<"getch();\nclosegraph();\n}";
  rename("temp.cpp",f);
  fout.close();
  fout.open("temp.cpp");
  write('n');
 }
 else
 {
  int a=400,b=400;
  clrscr();
  int gd=DETECT,gm  ;
  initgraph(&gd,&gm,"\\tc\\bgi");
  if(password())
  {
  setfillstyle(SOLID_FILL,15);
  bar(43,62,597,458.5);
  SCREEN();
  mousecall();
  restrict(0,640,0,480);
  setmouse(a,b);
  write('o');
  }
 }
 closegraph();
}


int op(char ch)
{


 setfillstyle(SOLID_FILL,0);
 bar(179,109,451,351);

 setfillstyle(SOLID_FILL,8);
 bar(180,110,450,350);
 setfillstyle(SOLID_FILL,7);
 bar(190,140,440,340);
 setfillstyle(SOLID_FILL,1);
 bar(180,110,450,130);

 setcolor(YELLOW);
 outtextxy(183,110,"/");
 outtextxy(184,110,"/");
 outtextxy(185,112,"/");
 outtextxy(186,112,"/");
 outtextxy(187,114,"/");
 outtextxy(188,114,"/");
 settextstyle(SMALL_FONT,0,6);

 if(ch=='o')
 {
  setcolor(4);
  outtextxy(300,110,"OPEN");
 }
 else if(ch=='b')
 {
  setcolor(4);
  outtextxy(300,110,"SAVE AS BMP");
 }
 else if(ch=='c')
 {
  setcolor(4);
  outtextxy(300,110,"SAVE AS CPP");
 }
 else if(ch=='p')
 {
  setcolor(4);
  outtextxy(300,110,"PASSWORD");
 }


 setfillstyle(SOLID_FILL,15);
 bar(300,200,420,230);

 setcolor(8);
 line(300,200,420,200);
 line(300,200,300,230);
 setcolor(0);
 line(301,201,419,201);
 line(301,201,301,229);


 int i=-1;
 setcolor(0);
 if(ch=='o'|| ch=='b'|| ch=='c')
 {
 outtextxy(200,210,"FILE :");
 outtextxy(201,210,"FILE :");
 }
 else if(ch=='p')
 {
 outtextxy(200,210,"NEW :");
 outtextxy(201,210,"NEW :");
 }

 if(ch=='o')
 {
  outtextxy(200,300,"PRESS ENTER TO LOAD");
  outtextxy(201,300,"PRESS ENTER TO LOAD");
 }
 else if(ch=='b' || ch=='c')
 {
  outtextxy(200,300,"PRESS ENTER TO SAVE");
  outtextxy(201,300,"PRESS ENTER TO SAVE");
 }
 else if(ch=='p')
 {
  outtextxy(200,300,"PRESS ENTER TO CHANGE");
  outtextxy(201,300,"PRESS ENTER TO CHANGE");
 }

 int x=305,y=205;
 for( i=0; ;i++,x+=10)
 {
  char ch;
  ch=getch();
  if(ch==27)
   return 0;
  if(ch=='\b')
   {
    setcolor(15);
    x-=10;
    i--;
    char t[2];
    t[0]=s[i];
    t[1]='\0';

    outtextxy(x,y,t);
    s[i]='\0';
    i--;
    setcolor(0);
    x-=10;
   }
  else if(ch==13)
	break;
       else
       {
	 s[i]=ch;
	 char t[2];
	 t[0]=ch;
	 t[1]='\0';
	 outtextxy(x,y,t);
       }
 }

 s[i]='\0';
 return 1;
}

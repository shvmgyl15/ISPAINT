#include<stdlib.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
void graph();
void clearscreen();
void cursor(int,int);
void colo(int);
int bmp(char *,int,int,int,int);
int CANVASSX=50,CANVASSY=40,CANVASEX=600,CANVASEY=450;
int colo1,colo2;

void colo(int no)
{
  int num[8]={0,0,0,0,0,0,0,0},i=0;
  while(no!=0)
  {
    num[i]=no%2;
    no=no/2;
    i++;
  }
  colo1=8*num[7]+4*num[6]+2*num[5]+num[4];
  colo2=8*num[3]+4*num[2]+2*num[1]+num[0];
}

void canvasresize(int px=0,int py=0)
{
  if(CANVASEX>600)
  CANVASEX=600;
  if(CANVASEY>450)
  CANVASEY=450;
  if(px!=0||py!=0)
  {
    setfillstyle(1,15);
    if(px<CANVASEX)
    bar(px,CANVASSY,CANVASEX,py);
    if(py<CANVASEY)
    bar(CANVASSX,py,CANVASEX,CANVASEY);
  }
  setfillstyle(1,7);
  if(CANVASEX!=600)
  bar(CANVASEX+1,CANVASSY+1,599,449);
  if(CANVASEY!=450)
  bar(CANVASSX+1,CANVASEY+1,599,449);
  setcolor(0);
  rectangle(CANVASSX,CANVASSY,CANVASEX,CANVASEY);
}

void initiatebmp()
{
  struct palettetype pal;
  getpalette(&pal);
  setrgbpalette(pal.colors[1],96,0,0);         // MAROON
  setrgbpalette(pal.colors[2],0,96,0);         // DARK GREEN
  setrgbpalette(pal.colors[3],96,96,0);        // DARK YELLOW
  setrgbpalette(pal.colors[4],0,0,96);         // DARK BLUE
  setrgbpalette(pal.colors[5],96,0,96);        // MAGENTA
  setrgbpalette(pal.colors[6],0,96,96);        // CYAN
  setrgbpalette(pal.colors[7],48,48,48);       // LIGHT GRAY
  setrgbpalette(pal.colors[8],96,96,96);       // DARK GRAY
  setrgbpalette(pal.colors[9],63,0,0);         // RED
  setrgbpalette(pal.colors[10],0,63,0);        // GREEN
  setrgbpalette(pal.colors[11],63,63,0);       // YELLOW
  setrgbpalette(pal.colors[12],0,0,63);        // BLUE
  setrgbpalette(pal.colors[13],63,0,63);       // PINK
  setrgbpalette(pal.colors[14],0,63,63);       // LIGHT CYAN
}


int bmp(char *ptr,int shiftx,int shifty,int use=0,int type=0)
{
  char ch;
  long i,filesize=0,blankspace,Xlimit=0,Ylimit=0;
  ifstream fi;
  fi.open(ptr,ios::binary);
  fi.get(ch);
  while(fi)
  {
    filesize++;
    fi.get(ch);
  }
  fi.close();
  fi.open(ptr,ios::binary);
  fi.get(ch);
  if(ch!='B')
   return 1;
  fi.get(ch);
  if(ch!='M')
   return 1;
  fi.seekg(18);
  fi.get(ch);
  Xlimit=int(ch);
  if(Xlimit<0)
   Xlimit=256+Xlimit;
  fi.get(ch);
  if(int(ch)<0)
   Xlimit=256*(256+int(ch))+Xlimit;
  else
   Xlimit=256*int(ch)+Xlimit;
  fi.seekg(22);
  fi.get(ch);
  Ylimit=int(ch);
  if(Ylimit<0)
   Ylimit=256+Ylimit;
  fi.get(ch);
  if(int(ch)<0)
   Ylimit=256*(256+int(ch))+Ylimit;
  else
   Ylimit=256*int(ch)+Ylimit;
  int size=(Xlimit+1)/2,y=Ylimit-1,num;
  blankspace=filesize-118-Ylimit*size;
  blankspace/=(Ylimit-1);
  i=0;
  fi.seekg(118);
  fi.get(ch);
  if(use==1)
  {
    CANVASEX=CANVASSX+Xlimit+1;
    CANVASEY=CANVASSY+Ylimit+1;
    canvasresize();
  }
  while(fi)
  {
    for(int j=0;j<size;j++)
    {
      num=int(ch);
      if(num<0)
      num+=256;
      colo(num);
      if(type==1)
      {
	if(shiftx+(j*2)<CANVASEX&&shifty+y<CANVASEY)
	 putpixel(shiftx+(j*2),shifty+y,colo1);
	if(shiftx+(j*2)<CANVASEX-1&&shifty+y<CANVASEY)
	 putpixel(shiftx+1+(j*2),shifty+y,colo2);
      }
      else
      {
	putpixel(shiftx+(j*2),shifty+y,colo1);
	putpixel(shiftx+1+(j*2),shifty+y,colo2);
      }
      fi.get(ch);
    }
    i++;
    y--;
    fi.seekg(118+(size+blankspace)*i);
    fi.get(ch);
  }
  return 0;
}
void cursor(int x,int y)
{
 while(!kbhit())
 {
  setcolor(15);
  line(x,y,x+10,y);
  delay(500);
  setcolor(0);
  line(x,y,x+10,y);
  delay(500);
 }
}
void clearscreen()
{
	clrscr();
	cleardevice();
	setbkcolor(BLUE);
}

void graph()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;
	int midx, midy;

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "");

	/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}

}

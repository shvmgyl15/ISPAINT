#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

char fname[20];
int SBMP(char []);
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
void Main()
{
//Graphics initiallize
//SaveBMP16(fname);  to save image (bmp)
}

struct BMP
{

// BitMap File Header
byte bfType[2]; /* 1 2 must always be set to 'BM' to declare that this is a .bmp file.*/
dword bfSize; /* 3 4 specifies the size of the file in bytes.*/
word bfReserved1;// 7 2 must always set to zero. */
word bfReserved2;// 9 2 must always be set to zero.
dword bfOffset; // 11 4 specifies the offset from the beginning of the file to bitmap data.

// BitMap Image Header
dword biSize; // 15 4 specifies the size of the BitMap Header structure, in bytes.
dword biWidth; // 19 4 specifies the width of image, in pixels.
dword biHeight; // 23 4 specifies the height of image, in pixels.
word biPlanes; // 27 2 specifies the number of planes of the target device,must be set to 0
word biBitCount; // 29 2 specifies the number of bits per pixel.
dword biCompression; //31 4 Specifies the type of compression, usually set to 0 - No Compres
dword biSizeImage; // 35 4 specifies the size of the image data, in bytes. If there is no compression, it is valid to set this member to zero.
dword biXPelsPerMeter; //39 4 specifies the the horizontal pixels per meter on the designated targer device, usually set to zero.
dword biYPelsPerMeter; // 43 4 specifies the the vertical pixels per meter on the designated targer device, usually set to zero
dword biClrUsed; // 47 4 specifies the number of colors used in bitmap, if set to 0 number of colors is calculated using the biBitCount member.
dword biClrImportant; // 51 4 specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.
};


int SBMP(char file[])
{
int i=0, j=0, r, g, b;

FILE *fp;
BMP *bmp;

bmp=(BMP *)malloc(54);

bmp->bfType[0]='B';
bmp->bfType[1]='M';
bmp->bfSize=153718;
bmp->bfReserved1=0;
bmp->bfReserved2=0;
bmp->bfOffset=118;
bmp->biSize=40;
bmp->biWidth=640;
bmp->biHeight=480;
bmp->biPlanes=1;
bmp->biBitCount=4;
bmp->biCompression=0;
bmp->biSizeImage=153600; //Fixed Size ?
bmp->biXPelsPerMeter=0;
bmp->biYPelsPerMeter=0;
bmp->biClrUsed=0;
bmp->biClrImportant=0;

fp=fopen(file, "wb");
if(fp == NULL)
{
printf("File can't be open");
getch();
return 1;
}


fwrite(bmp, 54, 1, fp);
fseek(fp, 54L, SEEK_SET);

// Upto Here its OK.


// Question 1. What do next 16x4 Lines do ?

fputc(0x0, fp);
fputc(0x0, fp);
fputc(0x0, fp);
fputc(0x0, fp);

fputc(127, fp);
fputc(0x0, fp);
fputc(0x0, fp);
fputc(0x0, fp);

fputc(0x0, fp);
fputc(127, fp);
fputc(0x0, fp);
fputc(0x0, fp);

fputc(127, fp);
fputc(127, fp);
fputc(0x0, fp);
fputc(0x0, fp);

fputc(0x0, fp);
fputc(0x0, fp);
fputc(127, fp);
fputc(0x0, fp);

fputc(127, fp);
fputc(0x0, fp);
fputc(127, fp);
fputc(0x0, fp);

fputc(0x0, fp);
fputc(192, fp);
fputc(192, fp);
fputc(0x0, fp);

fputc(192, fp);
fputc(192, fp);
fputc(192, fp);
fputc(0x0, fp);

fputc(128, fp);
fputc(128, fp);
fputc(128, fp);
fputc(0x0, fp);

fputc(255, fp);
fputc(0x0, fp);
fputc(0x0, fp);
fputc(0x0, fp);

fputc(0x0, fp);
fputc(255, fp);
fputc(0x0, fp);
fputc(0x0, fp);

fputc(255, fp);
fputc(255, fp);
fputc(0x0, fp);
fputc(0x0, fp);

fputc(0x0, fp);
fputc(0x0, fp);
fputc(255, fp);
fputc(0x0, fp);

fputc(255, fp);
fputc(0x0, fp);
fputc(255, fp);
fputc(0x0, fp);

fputc(0x0, fp);
fputc(255, fp);
fputc(255, fp);
fputc(0x0, fp);

fputc(255, fp);
fputc(255, fp);
fputc(255, fp);
fputc(0x0, fp);

i=0;
j=479;

fseek(fp, 118, SEEK_SET);

while(j>=0)
{
i=0;
while(i<640)
{
fputc((getpixel(i, j)<<4) | getpixel(i+1, j), fp); //Que 2. What does this do ? Why Left Shift 4 times and why Bit wise ORing of two pixles.
i+=2;
}
j--;
}
free(bmp);
fclose(fp);
return 0;
}


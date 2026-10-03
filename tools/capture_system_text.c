/* Independent native whole-string TextOutA raster evidence. */
#include <windows.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char **argv){
    if(argc!=2)return 2;
    const char *texts[]={"Sailing Tactics Simulator 2002","Press spacebar to begin.","WIND 017  BOAT 5.2","Windward Mark","0123456789 .,-+/?()","Apparent Wind","TACK / JIBE","ABCDEFGHIJKLMNOPQRSTUVWXYZ","abcdefghijklmnopqrstuvwxyz","\260 degrees"};
    const int x_positions[]={0,1,-3,480},y_positions[]={0,3,-3,25};
    const COLORREF colors[]={0,0xffffff,0x7f7f7f,0x8000},backgrounds[]={0xffffff,0,0x808080,0x7f0000};
    HDC dc=CreateCompatibleDC(NULL);BITMAPINFO info={0};void *pixels=NULL;
    info.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);info.bmiHeader.biWidth=512;info.bmiHeader.biHeight=-32;
    info.bmiHeader.biPlanes=1;info.bmiHeader.biBitCount=32;info.bmiHeader.biCompression=BI_RGB;
    HBITMAP bitmap=CreateDIBSection(dc,&info,DIB_RGB_COLORS,&pixels,NULL,0);if(!dc||!bitmap||!pixels)return 3;
    HGDIOBJ previous=SelectObject(dc,bitmap);FILE *file=fopen(argv[1],"wb");if(!file)return 4;
    HBRUSH clear=CreateSolidBrush(0x123456);RECT rect={0,0,512,32};
    for(unsigned profile=0;profile<8;profile++)for(unsigned text=0;text<10;text++){
        FillRect(dc,&rect,clear);SetBkMode(dc,profile<4?OPAQUE:TRANSPARENT);
        SetTextColor(dc,colors[profile%4]);SetBkColor(dc,backgrounds[profile%4]);
        TextOutA(dc,x_positions[profile%4],y_positions[profile%4],texts[text],(int)strlen(texts[text]));GdiFlush();
        if(fwrite(pixels,4,512*32,file)!=512*32)return 5;
    }
    fclose(file);DeleteObject(clear);SelectObject(dc,previous);DeleteObject(bitmap);DeleteDC(dc);return 0;
}

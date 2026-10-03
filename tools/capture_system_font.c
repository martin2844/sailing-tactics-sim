/* Capture the default font of an unchanged, newly created Windows GDI DC.
 * The browser may consume its glyph bitmaps instead of substituting a font. */
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
int main(int argc,char **argv){
    if(argc!=2)return 2;
    HDC dc=CreateCompatibleDC(NULL);BITMAPINFO info={0};void *pixels=NULL;
    info.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);info.bmiHeader.biWidth=1024;
    info.bmiHeader.biHeight=-1024;info.bmiHeader.biPlanes=1;info.bmiHeader.biBitCount=32;info.bmiHeader.biCompression=BI_RGB;
    HBITMAP bitmap=CreateDIBSection(dc,&info,DIB_RGB_COLORS,&pixels,NULL,0);
    if(!dc||!bitmap||!pixels)return 3;
    HGDIOBJ previous=SelectObject(dc,bitmap);PatBlt(dc,0,0,1024,1024,WHITENESS);
    SetTextColor(dc,RGB(0,0,0));SetBkMode(dc,TRANSPARENT);
    char face[128]={0};TEXTMETRICA metric;GetTextFaceA(dc,128,face);GetTextMetricsA(dc,&metric);
    printf("%s\n%d %d %d %d %d %d\n",face,metric.tmHeight,metric.tmAscent,metric.tmDescent,metric.tmInternalLeading,metric.tmExternalLeading,metric.tmAveCharWidth);
    for(unsigned code=0;code<256;code++){
        char character=(char)code;SIZE extent;GetTextExtentPoint32A(dc,&character,1,&extent);
        TextOutA(dc,(code%16)*64,(code/16)*64,&character,1);printf("%d%s",extent.cx,code==255?"\n":" ");
    }
    printf("kerning %lu\n",(unsigned long)GetKerningPairsA(dc,0,NULL));GdiFlush();
    FILE *file=fopen(argv[1],"wb");if(!file)return 4;
    if(fwrite(pixels,4,1024*1024,file)!=1024*1024)return 5;fclose(file);
    SelectObject(dc,previous);DeleteObject(bitmap);DeleteDC(dc);return 0;
}

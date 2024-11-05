#include <stdio.h>
#include <windows.h>

//座標構造体
POINT pt;

//☆は必要ない。試行錯誤の痕を残したいだけ
//☆
ICONINFO iconinfo;
BITMAP bitmap;
//☆

int main(){
    
    //☆
    GetIconInfo( LoadCursorA( NULL , IDC_ARROW) , &iconinfo );
    GetObject( iconinfo.hbmColor, sizeof(BITMAP), &bitmap );
    //☆

    SetConsoleOutputCP(CP_UTF8);
    long t = 0;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    //☆
    printf("%d,%d|%d,%d\n",screenWidth,bitmap.bmWidth,screenHeight,bitmap.bmHeight);
    //☆

	while(1){
		GetCursorPos(&pt);
		printf("時刻 : %d\nx : y = %d : %d \n",t,pt.x,pt.y);
        SetCursorPos(pt.x+50,pt.y+50);
        if (pt.x==screenWidth-1 || pt.y==screenHeight-1)
        {
            SetCursorPos(0,0);
        }

		Sleep(500);
        
    t++;
	}
	return 0;
}
#include <stdio.h>
#include <windows.h>

int flag=0;

POINT pt;

INPUT inputs[2] = {};

LPCWSTR lpCaption = L"メインメニュー" ;

int main(){

    SetConsoleOutputCP(CP_UTF8);

    LPCWSTR lpText = L"このウィンドウを閉じた後、クリックする場所を指定してください.\n10回クリックします" ;

    MessageBoxW(  NULL , lpText , lpCaption , MB_OK );

    while(1){

		GetCursorPos(&pt);
		printf("x : y = %d : %d \n",pt.x,pt.y);

        if(GetAsyncKeyState(VK_LBUTTON)){
            printf("ok");
            break;
        }

		Sleep(10);

	}

    inputs[0].type=INPUT_MOUSE;
    inputs[0].mi.dwFlags=MOUSEEVENTF_LEFTDOWN;
    
    inputs[1].type=INPUT_MOUSE;
    inputs[1].mi.dwFlags=MOUSEEVENTF_LEFTUP;

    while (flag<10)
    {

        SetCursorPos(pt.x,pt.y);

        SendInput(ARRAYSIZE(inputs),inputs,sizeof(INPUT));

        Sleep(500);

        flag++;

    }
    
    return 0;

}
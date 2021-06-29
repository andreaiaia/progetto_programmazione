#include <Windows.h>
#include "Personaggio.cpp"
#include "Funzioni.h"
#include "Mappa.h"

#define TIMER1 1
#define TIMER2 1
#define TIMER3 1
#define TIMER4 1
#define TIMER5 1
#define TIMER10 1

const int defaultx=200;
const int defaulty=200;

struct lista_mappe {
	Mappa schermata;
	lista_mappe * next;
	lista_mappe * prev;
};

Personaggio CHIOCCIOLINO(26,470);

lista_mappe * listacontenentemappe=new lista_mappe;

void cambiaschermata(int n){
	lista_mappe * head = listacontenentemappe;
	if (n==1 && head->next == NULL) {
		head->next = new lista_mappe;
		head->next->prev = head;
		head = head->next;
		head->next = NULL;
		CHIOCCIOLINO.nuova_posizione(defaultx, defaulty);
	}
	else if (n==3 && head->prev != NULL) {
		head = head->prev;
		CHIOCCIOLINO.nuova_posizione(defaultx, defaulty);
	} 
    else if (n==1 && head->next != NULL) {
		head = head->next;
		CHIOCCIOLINO.nuova_posizione(defaultx, defaulty);
	}
};

void disegna(HDC hdc){
    LOGBRUSH brush;
    COLORREF col = 0;
    DWORD pen_style = PS_DASHDOT | PS_JOIN_MITER | PS_GEOMETRIC;
    brush.lbStyle = BS_SOLID;
    brush.lbColor = col;
    brush.lbHatch = 0;
    PAINTSTRUCT ps;
    HGDIOBJ hPen = ExtCreatePen(pen_style, 3, &brush, 0, NULL);
    HGDIOBJ holdPen = SelectObject(hdc, hPen);
    POINT points[4] = {{ 20, 20 }, { 760, 20 }, { 760, 540 }, { 20, 540 }};
    Polygon(hdc, points, 4);
    SelectObject(hdc, holdPen);
    DeleteObject(hPen);
    Rectangle(hdc, 23, 58, 758, 538);
    HFONT hFont = CreateFontW(35, 0, 0, 0, FW_MEDIUM, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
    HGDIOBJ holdFont = SelectObject(hdc, hFont);
    TextOutA(hdc, 25, 23, "Vita:", 5);
    TextOutA(hdc, 270, 23, "Score:", 6);
    TextOutA(hdc, 590, 23, "Scudo:", 6);
    TextOutA(hdc, 92, 23, CHIOCCIOLINO.svita(), CHIOCCIOLINO.lvita()); //vita
    TextOutA(hdc, 364, 23, CHIOCCIOLINO.sscore(), CHIOCCIOLINO.lscore()); //score FUNZIONE DA FARE
    TextOutA(hdc, 692, 23, CHIOCCIOLINO.sscudo(), CHIOCCIOLINO.lscudo()); //scudo da inserire con funzione
    SelectObject(hdc, holdFont);
    DeleteObject(hFont);
}

void disegnaMappa(HDC hdc){
    HFONT hFont = CreateFontW(50, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
    HGDIOBJ holdFont = SelectObject(hdc, hFont);
    listacontenentemappe->schermata.disegnamappa(hdc);         //per disegna mappa
    SelectObject(hdc, holdFont);
    DeleteObject(hFont);
}

const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); //colore sfondo grigio CreateSolidBrush(RGB(128, 128, 128));
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Registrazione della Finestra Fallita!", "Errore!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    //Creazione della finestra
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Titolo della mia finestra",
        WS_OVERLAPPEDWINDOW,
        100, 100, 800, 600,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Creazione della Finestra Fallita!", "Errore!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    SetTimer(hwnd, TIMER1, 1000, NULL);

    ShowWindow(hwnd, nCmdShow); //secondo parametro SW_MAXIMIZE per schermo intero
    //ShowWindow(GetConsoleWindow(), SW_HIDE);   //per togliere la schermata nera dietro
    UpdateWindow(hwnd);

    //messaggi
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){

    HDC hdc;
    PAINTSTRUCT ps;
    HRGN vita = CreateRectRgn (92, 24, 269, 56);
    HRGN punteggio = CreateRectRgn (364, 24, 589, 56);
    HRGN scudo = CreateRectRgn (692, 24, 758, 56);
    
    HRGN casachiocciolino = CreateRectRgn (24, 59, 757, 537);

    HRGN chiocciola = CreateRectRgn (CHIOCCIOLINO.ritorna_x(), CHIOCCIOLINO.ritorna_y(),CHIOCCIOLINO.ritorna_x()+40, CHIOCCIOLINO.ritorna_y())+40;

    switch(msg)
    {
        case WM_TIMER:
            switch (wParam)
            {
            case TIMER1:
                CHIOCCIOLINO.incrementascore(hwnd,punteggio);
                break;
            default:

                break;
            }
            break;
        case WM_PAINT:
            {
            hdc = BeginPaint(hwnd, &ps);
            disegna(hdc);

            disegnaMappa(hdc);

            HBRUSH hBrush = CreateSolidBrush(RGB(0,255,255));
            SelectObject(hdc, hBrush);
            //PaintRgn (hdc, casachiocciolino);
            //PaintRgn (hdc, vita);
            //PaintRgn (hdc, punteggio);
            //PaintRgn (hdc, scudo);
            DeleteObject(hBrush);

            HFONT hFont = CreateFontW(30, 0, 0, 0, FW_NORMAL, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial"); //grandezza chiocciola
            HGDIOBJ holdFont = SelectObject(hdc, hFont);
            TextOutA(hdc, CHIOCCIOLINO.ritorna_x(), CHIOCCIOLINO.ritorna_y(), "@", 1);
            SelectObject(hdc, holdFont);
            DeleteObject(hFont);

            printf("prova");

            EndPaint(hwnd, &ps);
            break;
            }
		case WM_CHAR: 
            switch (wParam) 
            { 
                case 0x20:          // Process a spacebar.
                    //funzione di sparo
                break;
				case 'w':           // Process a W.
                    CHIOCCIOLINO.muovi(0,hwnd,casachiocciolino);
                break; 
				case 's':           // Process a S.
                    CHIOCCIOLINO.muovi(2,hwnd,casachiocciolino);
                break; 
				case 'a':           // Process a A.
                    if (CHIOCCIOLINO.ritorna_x()>23){
                        CHIOCCIOLINO.muovi(3,hwnd,casachiocciolino);
                    } else {
                        cambiaschermata(3);
                    }
                break; 
				case 'd':           // Process a D.
                    if (CHIOCCIOLINO.ritorna_x()<758){
                        CHIOCCIOLINO.muovi(1,hwnd,casachiocciolino);
                    } else {
                        cambiaschermata(1);
                    }
                break;
				default:
                    
				break;  
			}
		break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            //InvalidateRgn(hwnd, vita, false);
            //InvalidateRgn(hwnd, punteggio, false);
            //InvalidateRgn(hwnd, scudo, false);
            //InvalidateRgn(hwnd, casachiocciolino, false);
        break;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
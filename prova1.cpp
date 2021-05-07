#include <Windows.h>

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
    TextOutA(hdc, 25, 22, "Vita: 999", 9); //vita
    TextOutA(hdc, 300, 22, "Score: 999", 10); //score FUNZIONE DA FARE
    TextOutA(hdc, 595, 22, "Scudo: OFF", 10); //scudo da inserire con funzione
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

    ShowWindow(hwnd, nCmdShow); //secondo parametro SW_MAXIMIZE per schermo intero
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
    //HRGN hrgn = CreateRectRgn( 0, 0, 800, 600);

    switch(msg)
    {
        case WM_SIZE:
            
            break;
        case WM_PAINT:
            {
            hdc = BeginPaint(hwnd, &ps);
            disegna(hdc);

            TextOutA(hdc, 25, 122, __TIME__, 8);

            EndPaint(hwnd, &ps);
            break;
            }
		case WM_CHAR: 
            switch (wParam) 
            { 
                case 0x20:          // Process a spacebar.
                    RedrawWindow(hwnd, NULL, NULL, RDW_ERASE|RDW_INVALIDATE|RDW_NOERASE|RDW_NOFRAME|RDW_NOINTERNALPAINT);
                break;
				case 'w':           // Process a W.
                    
                break; 
				case 's':           // Process a S.
					
                break; 
				case 'a':           // Process a A.
                    
                break; 
				case 'd':           // Process a D.
					
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
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
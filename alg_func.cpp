#include "roles.h"
#include "service.h"
#include "definition.h"


string InPassword()
{
    string password;
    char c;
    cout << "Введите пароль: ";
    while ((c = _getch()) != '\r')
    {
        if (c == '\b') {
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else 
        {
            password.push_back(c);
            cout << "*";
        }
    }
    return password;
}

void getCursorPosition(int& x, int& y) {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    x = cursorPos.x;
    y = cursorPos.y;
}

bool isMouseClicked() {
    return GetAsyncKeyState(VK_LBUTTON) & 0x8000;
}

void EditCursor(int hight, int width)
{
    COORD position = { hight, width };
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, position);
}

bool isMouseBox(int mouseX, int mouseY, int rectX, int rectY, string text) 
{
    int rectWidth;
    rectWidth = text.size() + 4;

    mouseX = mouseX / 10;
    mouseY = mouseY / 20;
    return mouseX >= rectX && mouseX < rectX + rectWidth && mouseY >= rectY && mouseY < rectY + 3;
}

bool isMouse(int mouseX, int mouseY, int rectX, int rectY, int rectWidth)
{
    mouseX = mouseX / 10;
    mouseY = mouseY / 20;
    return mouseX >= rectX && mouseX < rectX + rectWidth && mouseY >= rectY && mouseY < rectY + 3;
}

BOOL ShowConsoleCursor(BOOL bShow)
{
    CONSOLE_CURSOR_INFO cci;
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return FALSE;
    if (!GetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    cci.bVisible = bShow;
    if (!SetConsoleCursorInfo(hStdOut, &cci))
        return FALSE;
    return TRUE;
}

void Line(int a)
{
    for (int i = 0; i < a; i++)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"─";
        _setmode(_fileno(stdout), _O_TEXT);
    }
}

void LineUp()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"│";
    _setmode(_fileno(stdout), _O_TEXT);
}

void LineUpUgol(int a)
{
    if (a == 1)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"┌";
        _setmode(_fileno(stdout), _O_TEXT);
    }
    else if (a == 2)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"└";
        _setmode(_fileno(stdout), _O_TEXT);
    }
    else if (a == 3)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"┐";
        _setmode(_fileno(stdout), _O_TEXT);
    }
    else if (a == 4)
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"┘";
        _setmode(_fileno(stdout), _O_TEXT);
    }
}

void drawTextBox(const string& text, int x, int y)
{
    int width = static_cast<int>(text.length()) + 4; 
    int height = 3;

    EditCursor(x, y);
    LineUpUgol(1);
    Line(width - 2);
    LineUpUgol(3);
    cout << endl;

    EditCursor(x, y + 1);
    for (int i = 0; i < height - 2; ++i) {
        LineUp();
        if (i == (height - 2) / 2) {
            cout << " " << text << " ";
        }
        else {
            for (int j = 0; j < width - 2; ++j) {
                cout << " ";
            }
        }
        LineUp();
    }

    EditCursor(x, y + 2);
    LineUpUgol(2);
    Line(width - 2);
    LineUpUgol(4);
    cout << endl;
}

bool isValidLogin(string login) 
{
    if (login.length() >= 4) 
    {
        for (int i = 0; i < login.length(); ++i)
        {
            char c = login[i];
            if (!isascii(c))
            {
                return false; 
            }
        }
        return true;
    }
    return false; 
}
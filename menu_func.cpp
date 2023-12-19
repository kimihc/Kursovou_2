#include "roles.h"
//#include "definition.h"
HANDLE hConsole;

using namespace adm;

template <class T>
extern void file_write_Order(T& obj, string name);
extern void Line(int a);
extern void LineUp();
extern void LineUpUgol(int a);
extern void drawTextBox(const string& text, int x, int y);
extern void EditCursor(int hight, int width);
extern bool isMouseClicked();
extern void getCursorPosition(int& x, int& y);
extern bool isMouseBox(int mouseX, int mouseY, int rectX, int rectY, string text);
extern bool isMouse(int mouseX, int mouseY, int rectX, int rectY, int rectWidth);

void ConsoleColor()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);

    auto h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi = {};
    cfi.cbSize = sizeof(cfi);
    GetCurrentConsoleFontEx(h, FALSE, &cfi);
    cfi.dwFontSize.Y *= 3;
    SetCurrentConsoleFontEx(h, FALSE, &cfi);
    SetCurrentConsoleFontEx(h, FALSE, &cfi);
}

void draw_first()
{
    EditCursor(43, 4);
    Line(61);
    EditCursor(43, 5);
    cout << "   Добро пожаловать в систему заказа косметических услуг              ";
    EditCursor(43, 7);
    cout << "        пожалуйста выберите необходимое действие";
    EditCursor(43, 8);
    Line(61);
    EditCursor(43, 17);
    Line(61);
    EditCursor(42, 4);
    LineUpUgol(1);
    EditCursor(42, 17);
    LineUpUgol(2);
    EditCursor(104, 4);
    LineUpUgol(3);
    EditCursor(104, 17);
    LineUpUgol(4);
    for (int i = 0; i < 12; i++)
    {
        EditCursor(42, i + 5);
        LineUp();
        EditCursor(104, i + 5);
        LineUp();
    }
}

int menu_signUp()
{
    int x, y;
    Sleep(80);
    draw_first();
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);
        drawTextBox("Пользователь", 45, 12);
        drawTextBox("Администратор", 66, 12);
        drawTextBox("Сотрудник", 88, 12);
        getCursorPosition(x, y);

        if (isMouseBox(x, y, 43, 12, "Пользователь"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Пользователь", 45, 12);
            if (isMouseClicked())
            {
                system("cls");
                return 1;
            }
        }
        else if (isMouseBox(x, y, 64, 12, "Администратор"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Администратор", 66, 12);
            if (isMouseClicked())
            {
                system("cls");
                return 2;
            }
        }
        else if (isMouseBox(x, y, 86, 12, "Сотрудник"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Сотрудник", 88, 12);
            if (isMouseClicked())
            {
                system("cls");
                return 3;
            }
        }

        Sleep(100);

    }
}

int menu_()
{

    int x, y;
    draw_first();
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);
        drawTextBox("Зарегистрироваться", 45, 12);

        drawTextBox("Выход", 73, 12);

        drawTextBox("Войти", 88, 12);
        getCursorPosition(x, y);

        if (isMouseBox(x, y, 43, 12, "Зарегистрироваться"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Зарегистрироваться", 45, 12);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                return 1;
            }
        }
        else if (isMouseBox(x, y, 71, 12, "Выход"))
        {
            SetConsoleTextAttribute(hConsole, 4);
            drawTextBox("Выход", 73, 12);
            if (isMouseClicked())
            {
                system("cls");
                return 3;
            }
        }
        else if (isMouseBox(x, y, 86, 12, "Войти"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Войти", 88, 12);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                return 2;
            }
        }

        Sleep(100);
       
    }
    SetConsoleTextAttribute(hConsole, 7);
}

void Edit_servicePrice(vector<Service>& services)
{
    int x, y;

    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getCursorPosition(x, y);

        for (vector<Service>::iterator i = services.begin(); i < services.end(); i++)
        {
            if (isMouse(x, y, 0, distance(services.begin(), i) * 2 + 15, 141))
            {
                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(0, distance(services.begin(), i) * 2 + 15);
                cout << *i;
                if (isMouseClicked())
                {
                    services.erase(i);
                    SetConsoleTextAttribute(hConsole, 15);
                    return;
                }
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 15);
                EditCursor(0, distance(services.begin(), i) * 2 + 15);
                cout << *i;
            }
        }

    }
}

void delete_service(vector<Service>& services)
{
    int x, y;

    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getCursorPosition(x, y);

        for (vector<Service>::iterator i = services.begin(); i < services.end(); i++)
        {
            if (isMouse(x, y, 0, distance(services.begin(), i) * 2 + 15, 141))
            {
                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(0, distance(services.begin(), i) * 2 + 15);
                cout << *i;
                if (isMouseClicked())
                {
                    services.erase(i);
                    SetConsoleTextAttribute(hConsole, 15);
                    return;
                }
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 15);
                EditCursor(0, distance(services.begin(), i) * 2 + 15);
                cout << *i;
            }
        }

    }
}

void addUserEmployee(vector<Employee> employees)
{
    int x, y;

    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getCursorPosition(x, y);

        for (vector<Employee>::iterator i = employees.begin(); i != employees.end() ; i++)
        {
            if (isMouse(x, y, 0, distance(employees.begin(), i) * 2 + 15, 141))
            {

            }
        }
    }
}

void addUserService(vector<Service>& services, vector<Employee> employees)
{
    int x, y;

    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getCursorPosition(x, y);

        for (vector<Service>::iterator i = services.begin(); i < services.end(); i++)
        {
            if (isMouse(x, y, 0, distance(services.begin(), i) * 2 + 15, 141))
            {
                SetConsoleTextAttribute(hConsole, 6);
                EditCursor(0, distance(services.begin(), i) * 2 + 15);
                cout << *i;
                if (isMouseClicked())
                {
                    
                    SetConsoleTextAttribute(hConsole, 15);
                    return;
                }
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 15);
                EditCursor(0, distance(services.begin(), i) * 2 + 15);
                cout << *i;
            }
        }

    }
}

void getTime()
{
    auto now = chrono::system_clock::now();
    time_t time_now = chrono::system_clock::to_time_t(now);
    tm* tm_now = localtime(&time_now);
    locale russian_locale("ru_RU.utf8");
    cout.imbue(russian_locale);
    EditCursor(23, 9);
    cout << "Время: " << put_time(tm_now, "%H:%M:%S") << endl;
    EditCursor(23, 10);
    cout << "Дата: " << put_time(tm_now, "%d %B %Y") << endl;
}

template<class T>
void menu_profile(T &obj)
{
    system("cls");
    if (obj.getRole() == "Пользователь")
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"    ⢀⣤⣶⠶⠟⠛⠛⠻⠶⣶⣤⡀⠀⠀⠀⠀" << endl;
        wcout << L"⠀⠀⣠⣾⠟⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⣷⣄⠀⠀" << endl;
        wcout << L"⠀⣴⡟⠁⠀⠀⠀⣠⣴⠶⠶⣦⣄⠀⠀⠀⠈⢻⣦⠀" << endl;
        wcout << L"⢸⡟⠀⠀⠀⠀⣾⠋⠀⠀⠀⠀⠙⣷⠀⠀⠀⠀⢻⣇" << endl;
        wcout << L"⣿⠁⠀⠀⠀⠸⣿⠀⠀⠀⠀⠀⠀⣿⠇⠀⠀⠀⠈⣿" << endl;
        wcout << L"⣿⡀⠀⠀⠀⠀⠻⣦⣀⠀⠀⣀⣴⠟⠀⠀⠀⠀⢀⣿" << endl;
        wcout << L"⢸⣧⠀⠀⠀⢀⣤⡾⠿⠛⠛⠿⢷⣤⡀⠀⠀⠀⣼⡏" << endl;
        wcout << L"⠀⠻⣧⡀⢠⡿⠉⠀⠀⠀⠀⠀⠀⠉⢿⡄⢀⣼⠟⠀" << endl;
        wcout << L"  ⠙⢿⣿⣁⠀⠀⠀⠀⠀⠀⠀⠀⣈⣿⡿⠋⠀⠀" << endl;
        wcout << L"⠀ ⠀⠀⠈⠛⠿⢶⣦⣤⣤⣴⡶⠿⠛⠁⠀⠀" << endl;
        _setmode(_fileno(stdout), _O_TEXT);
        cout << "    Пользователь";
    }
    else if (obj.getRole() == "Администратор")
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"⠀   ⢀⣤⣶⡶⠿⠿⠿⠿⢶⣶⣤⡀⠀⠀" << endl;
        wcout << L"⠀⠀⣠⣾⠟⠉⠀⠀⠀ ⠀⠀⠀⠀⠉⠻⣷⣄⠀⠀" << endl;
        wcout << L"⠀⣴⡟⠁⠀⠀⠀⢰⣿⣿⣿⣿⡆⠀⠀⠀⠈⢻⣦⠀" << endl;
        wcout << L"⢸⡿⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⢿⡇" << endl;
        wcout << L"⣿⡇⠀⠀⠀⠀⠀⠸⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⢸⣿" << endl;
        wcout << L"⣿⡇⠀⠀⠀⠀⠀⠀⣸⣿⣿⣃⠀⠀⠀⠀⠀⠀⢸⣿" << endl;
        wcout << L"⢸⣷⠀⠀⠀⣴⣾⣿⣿⣿⣿⣿⣿⣷⣦⠀⠀⠀⣼⡇" << endl;
        wcout << L" ⠻⣧⡀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⢀⣼⠟⠀" << endl;
        wcout << L"⠀ ⠙⢿⣦⣀⠀⠀⠉⠉⠉⠁⠀⠀⣀⣴⡿⠋⠀⠀" << endl;
        wcout << L"⠀   ⠈⠛⠿⠷⣶⣶⣶⣶⠶⠿⠛⠁⠀⠀⠀⠀" << endl;
        _setmode(_fileno(stdout), _O_TEXT);
        cout << "    Администратор";
    }
    else if (obj.getRole() == "Сотрудник")
    {
        _setmode(_fileno(stdout), _O_U16TEXT);
        wcout << L"     ⢀⣠⣴⡾⠟⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀" << endl;
        wcout << L"⠀⢀⣰⡾⠏⠉⣀⣴⣶⣶⣶⣶⣶⣶⠀⠘⠛⠛⠛⠛" << endl;
        wcout << L"⢀⣾⡏⠁⠀⠀⣿⠉⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀" << endl;
        wcout << L"⣾⠏⠀⠀⠀⣾⡟⠀⠀⠀⠀⠀⠀⢻⣷⠀⠀⠀⠀⠀" << endl;
        wcout << L"⣿⠀⠀⠀⠀⠙⣿⡀⠀⠀⠀⠀⢀⣿⠋⠀⠀⠀⠀⣀" << endl;
        wcout << L"⣿⠀⠀⠀⠀⠀⠙⢿⣶⣤⣤⣶⡿⠋⠀⠀⠀⠀⠀⣿" << endl;
        wcout << L"⢿⣆⠀⢀⣤⣤⣤⣿⠋⠉⠉⠻⣷⣤⣤⣤⡀⠀⣰⡿" << endl;
        wcout << L"⠈⢿⣇⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⢸⣿⣸⡿⠁" << endl;
        wcout << L" ⠈⠹⢿⣇⣀⠀⠀⠀⠀⠀⠀   ⣀⣸⡿⠏⠁" << endl;
        wcout << L" ⠀⠀⠀⠈⠙⠻⢷⣦⣤⣤⣤⣤⣴⡾⠟⠋⠁⠀⠀" << endl;
        _setmode(_fileno(stdout), _O_TEXT);
        cout << "    Сотрудник";
    }

    if (!(is_same<T, Admin>::value))
    {
        obj.getPersonalData(23, 1);
    }

    for (int i = 0; i < 11; i++)
    {
        EditCursor(21, i);
        LineUp();
    }
    for (int i = 0; i < 156; i++)
    {
        EditCursor(i, 11);
        Line(1);
    }

    getTime();


    EditCursor(0, 13);
}

void menu_Service(Admin& appUser, vector<Service>& services)
{
    int x, y;
    menu_profile(appUser);
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        drawTextBox("Добавить услугу", 70, 12);

        drawTextBox("Отменить услугу", 70, 15);

        drawTextBox("Изменить цену на услугу", 65, 21);

        drawTextBox("Просмотреть услуги", 68, 18);

        drawTextBox("Вернуться назад", 137, 8);


        getCursorPosition(x, y);

        if (isMouseBox(x, y, 68, 12, "Добавить услугу"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Добавить услугу", 70, 12);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                menu_profile(appUser);
                Service service;
                service.addService();
                services.push_back(service);
                system("cls");
                menu_profile(appUser);
            }
        }
        else if (isMouseBox(x, y, 68, 15, "Отменить услугу"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Отменить услугу", 70, 15);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                Sleep(200);
                system("cls");
                menu_profile(appUser);
                appUser.getService();
                for (vector<Service>::iterator i = services.begin(); i < services.end(); i++)
                {
                    if (i == services.end() - 1)
                    {
                        cout << *i;
                        LineUpUgol(2);
                        Line(139);
                        LineUpUgol(4);
                    }
                    else
                    {
                        cout << *i;
                        LineUp();
                        Line(139);
                        LineUp();
                    }
                }

                delete_service(services);
                system("cls");
                menu_profile(appUser);



            }
        }
        else if (isMouseBox(x, y, 63, 21, "Изменить цену на услугу"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Изменить цену на услугу", 65, 21);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                menu_profile(appUser);
                appUser.getService();
                for (vector<Service>::iterator i = services.begin(); i < services.end(); i++)
                {
                    if (i == services.end() - 1)
                    {
                        cout << *i;
                        LineUpUgol(2);
                        Line(139);
                        LineUpUgol(4);
                    }
                    else
                    {
                        cout << *i;
                        LineUp();
                        Line(139);
                        LineUp();
                    }
                }

                delete_service(services);
                system("cls");
                menu_profile(appUser);
            }
        }
        else if (isMouseBox(x, y, 66, 18, "Просмотреть услуги"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Просмотреть услуги", 68, 18);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                menu_profile(appUser);
                appUser.getService();
                for (vector<Service>::iterator i = services.begin(); i != services.end(); i++)
                {
                    if (i == services.end() - 1)
                    {
                        cout << * i;
                        LineUpUgol(2);
                        Line(139);
                        LineUpUgol(4);
                    }
                    else
                    {
                        cout << * i;
                        LineUp();
                        Line(139);
                        LineUp();
                    }
                    
                }
                cout << endl;
                system("pause");
                system("cls");
                menu_profile(appUser);
            }
        }
        else if (isMouseBox(x, y, 135, 8, "Вернуться назад"))
        {
            SetConsoleTextAttribute(hConsole, 4);
            drawTextBox("Вернуться назад", 137, 8);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                break;
            }
        }

        Sleep(200);
    }
    SetConsoleTextAttribute(hConsole, 15);
}

void menu_UsersProfile(Admin& appUser, vector<User>& users)
{
    int x, y;
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getTime();

        drawTextBox("Просмотреть всех пользователей", 70, 16);
        drawTextBox("", 67, 20);
        drawTextBox("Забанить пользователя", 68, 24);
        drawTextBox("Выйти с аккаунта", 136, 8);


        getCursorPosition(x, y);

        if (isMouseBox(x, y, 68, 16, "Услуги"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Услуги", 70, 16);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                Sleep(300);
                cin.ignore();

                menu_profile(appUser);
            }
        }
    }
}

void menu_Admin(Admin& appUser, vector<Service>& services, vector<User>& users, vector<Employee>& employees)
{
    menu_profile(appUser);
// Заказать улугу, посмотреть заказанные услуги, отменить заказанную услугу, изменить цену на услугу
    int x, y;
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);
       
        getTime();

        drawTextBox("Услуги", 70, 16);
        drawTextBox("Пользователи", 67, 20);
        drawTextBox("Сотрудники", 68, 24);
        drawTextBox("Выйти с аккаунта", 136, 8);


        getCursorPosition(x, y);

        if (isMouseBox(x, y, 68, 16, "Услуги"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Услуги", 70, 16);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                Sleep(300);
                menu_Service(appUser, services);
                Sleep(100);
                menu_profile(appUser);
            }
        }
        else if (isMouseBox(x, y, 65, 20, "Пользователи"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Пользователи", 67, 20);
            if (isMouseClicked())
            {
                system("cls");
                
            }
        }
        else if (isMouseBox(x, y, 66, 24, "Сотрудники"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Сотрудники", 68, 24);
            if (isMouseClicked())
            {
                system("cls");

            }
        }
        else if (isMouseBox(x, y, 134, 8, "Выйти с аккаунта"))
        {
            SetConsoleTextAttribute(hConsole, 4);
            drawTextBox("Выйти с аккаунта", 136, 8);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                break;
            }
        }

        Sleep(100);
    }
    SetConsoleTextAttribute(hConsole, 15);
}

void serviceDisplayMenu(User appUser, vector<Service> service)
{
    system("cls");
    menu_profile(appUser);
    appUser.getService();
    for (vector<Service>::iterator i = service.begin(); i != service.end(); i++)
    {
        if (i == service.end() - 1)
        {
            cout << *i;
            LineUpUgol(2);
            Line(139);
            LineUpUgol(4);
        }
        else
        {
            cout << *i;
            LineUp();
            Line(139);
            LineUp();
        }
    }
}

template<typename T>
void search(User& appUser, vector<Service> service, T obj)
{
    ShowConsoleCursor(FALSE);
    bool isSearch = false;
    for (vector<Service>::iterator i = service.begin(); i != service.end(); i++)
    {
        if (i.operator->()->search(obj))
        {
            if (isSearch == false)
            {
                system("cls");
                menu_profile(appUser);
                appUser.getService();
            }
            cout << *i;
            LineUpUgol(2);
            Line(139);
            LineUpUgol(4);
            isSearch = true;
        }
        else if (i == service.end() - 1 && isSearch == false)
        {
            system("cls");
            menu_profile(appUser);
            EditCursor(70, 13);
            cout << "Данной услуги не найдено";
        }
    }
}

void menu_User(User &appUser, vector<Service> service, vector<Employee> &employee) // Ввести личные данные, Заказать услугу, Посмотреть список услуг, Посмотреть список моих услуг, отменить заказанную услугу, выйти с аккаунта
{
    int x, y;
    menu_profile(appUser);
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getTime();
        Sleep(200);
        drawTextBox("Ввести личные данные", 67, 16);
        drawTextBox("Просмотретю услуги салона", 67, 20);
        drawTextBox("Заказать услугу", 67, 24);
        drawTextBox("Просмотреть заказанные услуги", 67, 28);
        drawTextBox("Отменить заказанную услугу", 67, 32);

        drawTextBox("Выйти с аккаунта", 136, 8);


        getCursorPosition(x, y);

        if (isMouseBox(x, y, 65, 16, "Ввести личные данные"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Ввести личные данные", 67, 16);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                Sleep(300);
                menu_profile(appUser);
                appUser.setPersonalData(23, 1);
                file_write_personDate(appUser, "personalDate.txt");
                system("cls");
                menu_profile(appUser);
               
            }
        }
        else if (isMouseBox(x, y, 65, 20, "Просмотретю услуги салона"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Просмотретю услуги салона", 67, 20);
            SetConsoleTextAttribute(hConsole, 15);

            if (isMouseClicked())
            {
                serviceDisplayMenu(appUser, service);
                Sleep(100);
                int x1, y1;
                while (true)
                {

                    Sleep(100);
                    drawTextBox("Вернуться назад", 137, 8);
                    drawTextBox("Сортировать", 115, 8);
                    drawTextBox("Поиск", 95, 8);
                    drawTextBox("Фильтровать", 75, 8);

                    getTime();
                    getCursorPosition(x1, y1);

                    if (isMouseBox(x1, y1, 135, 8, "Вернуться назад"))
                    {
                        SetConsoleTextAttribute(hConsole, 4);
                        drawTextBox("Вернуться назад", 137, 8);
                        SetConsoleTextAttribute(hConsole, 15);
                        if (isMouseClicked())
                        {
                            system("cls");
                            menu_profile(appUser);
                            Sleep(300);
                            break;
                        }
                    }
                    if (isMouseBox(x1, y1, 113, 8, "Сортировать"))
                    {
                        SetConsoleTextAttribute(hConsole, 6);
                        drawTextBox("Сортировать", 115, 8);
                        SetConsoleTextAttribute(hConsole, 15);
                        if (isMouseClicked())
                        {
                            Sleep(100);
                            system("cls");
                            serviceDisplayMenu(appUser, service);
                            int x, y;
                            while (true)
                            {
                                SetConsoleTextAttribute(hConsole, 15);

                                getTime();
                                getCursorPosition(x, y);
                                Sleep(100);
                                drawTextBox("Сортировать по цене", 112, 8);
                                drawTextBox("Сортировать по длительности", 80, 8);
                                drawTextBox("Вернуться назад", 137, 8);
                                if (isMouseBox(x, y, 135, 8, "Вернуться назад"))
                                {
                                    SetConsoleTextAttribute(hConsole, 4);
                                    drawTextBox("Вернуться назад", 137, 8);
                                    SetConsoleTextAttribute(hConsole, 15);
                                    if (isMouseClicked())
                                    {
                                        system("cls");
                                        menu_profile(appUser);
                                        serviceDisplayMenu(appUser, service);
                                        Sleep(300);
                                        break;
                                    }
                                }
                                if (isMouseBox(x, y, 111, 8, "Сортировать по цене"))
                                {
                                    SetConsoleTextAttribute(hConsole, 6);
                                    drawTextBox("Сортировать по цене", 112, 8);
                                    SetConsoleTextAttribute(hConsole, 15);
                                    if (isMouseClicked())
                                    {
                                        system("cls");
                                        menu_profile(appUser);
                                        serviceDisplayMenu(appUser, service);
                                        Sleep(100);
                                        int x1, y1;
                                        while (true)
                                        {
                                            SetConsoleTextAttribute(hConsole, 15);

                                            getTime();
                                            getCursorPosition(x1, y1);
                                            Sleep(100);
                                            drawTextBox("Сортировать по цене (мин)", 104, 8);
                                            drawTextBox("Сортировать по цене (макс)", 70, 8);
                                            drawTextBox("Вернуться назад", 137, 8);

                                            if (isMouseBox(x1, y1, 135, 8, "Вернуться назад"))
                                            {
                                                SetConsoleTextAttribute(hConsole, 4);
                                                drawTextBox("Вернуться назад", 137, 8);
                                                SetConsoleTextAttribute(hConsole, 15);
                                                if (isMouseClicked())
                                                {
                                                    system("cls");
                                                    menu_profile(appUser);
                                                    serviceDisplayMenu(appUser, service);
                                                    Sleep(300);
                                                    break;
                                                }
                                            }
                                            if (isMouseBox(x1, y1, 102, 8, "Сортировать по цене (мин)"))
                                            {
                                                SetConsoleTextAttribute(hConsole, 6);
                                                drawTextBox("Сортировать по цене (мин)", 104, 8);
                                                SetConsoleTextAttribute(hConsole, 15);
                                                if (isMouseClicked())
                                                {
                                                    system("cls");
                                                    menu_profile(appUser);
                                                    
                                                    sort(service.begin(), service.end(), Service::compPrice);
                                                    serviceDisplayMenu(appUser, service);
                                                    Sleep(300);
                                                    
                                                }
                                            }
                                            if (isMouseBox(x1, y1, 68, 8, "Сортировать по цене (макс)"))
                                            {
                                                SetConsoleTextAttribute(hConsole, 6);
                                                drawTextBox("Сортировать по цене (макс)", 70, 8);
                                                SetConsoleTextAttribute(hConsole, 15);
                                                if (isMouseClicked())
                                                {
                                                    system("cls");
                                                    menu_profile(appUser);
                                                    sort(service.begin(), service.end(), Service::compPrice);
                                                    reverse(service.begin(), service.end());
                                                    serviceDisplayMenu(appUser, service);
                                                    Sleep(300);
                                                    
                                                }
                                            }
                                        }
                                    }
                                }
                                if (isMouseBox(x, y, 78, 8, "Сортировать по длительности"))
                                {
                                    SetConsoleTextAttribute(hConsole, 6);
                                    drawTextBox("Сортировать по длительности", 80, 8);
                                    SetConsoleTextAttribute(hConsole, 15);
                                    if (isMouseClicked())
                                    {
                                        system("cls");
                                        menu_profile(appUser);
                                        serviceDisplayMenu(appUser, service);
                                        Sleep(100);
                                        int x1, y1;
                                        while (true)
                                        {
                                            SetConsoleTextAttribute(hConsole, 15);

                                            getTime();
                                            getCursorPosition(x1, y1);
                                            Sleep(100);
                                            drawTextBox("Сортировать по длительности (мин)", 99, 8);
                                            drawTextBox("Сортировать по длительности (макс)", 60, 8);
                                            drawTextBox("Вернуться назад", 137, 8);

                                            if (isMouseBox(x1, y1, 135, 8, "Вернуться назад"))
                                            {
                                                SetConsoleTextAttribute(hConsole, 4);
                                                drawTextBox("Вернуться назад", 137, 8);
                                                SetConsoleTextAttribute(hConsole, 15);
                                                if (isMouseClicked())
                                                {
                                                    system("cls");
                                                    menu_profile(appUser);
                                                    serviceDisplayMenu(appUser, service);
                                                    Sleep(300);
                                                    break;
                                                }
                                            }
                                            if (isMouseBox(x1, y1, 97, 8, "Сортировать по длительности (мин)"))
                                            {
                                                SetConsoleTextAttribute(hConsole, 6);
                                                drawTextBox("Сортировать по длительности (мин)", 99, 8);
                                                SetConsoleTextAttribute(hConsole, 15);
                                                if (isMouseClicked())
                                                {
                                                    system("cls");
                                                    menu_profile(appUser);

                                                    sort(service.begin(), service.end(), Service::compDuration);
                                                    serviceDisplayMenu(appUser, service);
                                                    Sleep(300);

                                                }
                                            }
                                            if (isMouseBox(x1, y1, 58, 8, "Сортировать по длительности (макс)"))
                                            {
                                                SetConsoleTextAttribute(hConsole, 6);
                                                drawTextBox("Сортировать по длительности (макс)", 60, 8);
                                                SetConsoleTextAttribute(hConsole, 15);
                                                if (isMouseClicked())
                                                {
                                                    system("cls");
                                                    menu_profile(appUser);
                                                    sort(service.begin(), service.end(), Service::compDuration);
                                                    reverse(service.begin(), service.end());
                                                    serviceDisplayMenu(appUser, service);
                                                    Sleep(300);

                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (isMouseBox(x1, y1, 93, 8, "Поиск"))
                    {
                        SetConsoleTextAttribute(hConsole, 6);
                        drawTextBox("Поиск", 95, 8);
                        SetConsoleTextAttribute(hConsole, 15);
                        if (isMouseClicked())
                        {
                            system("cls");
                            menu_profile(appUser);
                            serviceDisplayMenu(appUser, service);
                            Sleep(100);
                            int x1, y1;
                            while (true)
                            {
                                SetConsoleTextAttribute(hConsole, 15);

                                getTime();
                                getCursorPosition(x1, y1);
                                Sleep(100);
                                drawTextBox("Ввести название", 110, 8);
                                drawTextBox("Ввести цену", 90, 8);
                                drawTextBox("Ввести длительность", 60, 8);
                                drawTextBox("Вернуться назад", 137, 8);

                                if (isMouseBox(x1, y1, 135, 8, "Вернуться назад"))
                                {
                                    SetConsoleTextAttribute(hConsole, 4);
                                    drawTextBox("Вернуться назад", 137, 8);
                                    SetConsoleTextAttribute(hConsole, 15);
                                    if (isMouseClicked())
                                    {
                                        system("cls");
                                        menu_profile(appUser);
                                        serviceDisplayMenu(appUser, service);
                                        Sleep(300);
                                        break;
                                    }
                                }
                                if (isMouseBox(x1, y1, 108, 8, "Ввести название"))
                                {
                                    SetConsoleTextAttribute(hConsole, 6);
                                    drawTextBox("Ввести название", 110, 8);
                                    SetConsoleTextAttribute(hConsole, 15);
                                    
                                    if (isMouseClicked())
                                    {
                                        Sleep(200);
                                        system("cls");
                                        menu_profile(appUser);
                                        serviceDisplayMenu(appUser, service);
                                        string search_name;
                                        EditCursor(65, 9);
                                        cout << "Введите название: ";
                                        ShowConsoleCursor(TRUE);
                                        getline(cin, search_name);
                                        search(appUser, service, search_name);
                                    }
                                }
                                if (isMouseBox(x1, y1, 88, 8, "Ввести цену"))
                                {
                                    SetConsoleTextAttribute(hConsole, 6);
                                    drawTextBox("Ввести цену", 90, 8);
                                    SetConsoleTextAttribute(hConsole, 15);
                                    if (isMouseClicked())
                                    {
                                        system("cls");
                                        menu_profile(appUser);
                                        serviceDisplayMenu(appUser, service);
                                        float price;
                                        EditCursor(65, 9);
                                        cout << "Введите цену(BYN): ";
                                        ShowConsoleCursor(TRUE);
                                        cin >> price;
                                        cin.ignore();
                                        search(appUser, service, price);
                                    }
                                }
                                if (isMouseBox(x1, y1, 58, 8, "Ввести длительность"))
                                {
                                    SetConsoleTextAttribute(hConsole, 6);
                                    drawTextBox("Ввести длительность", 60, 8);
                                    SetConsoleTextAttribute(hConsole, 15);
                                    if (isMouseClicked())
                                    {
                                        system("cls");
                                        menu_profile(appUser);
                                        serviceDisplayMenu(appUser, service);
                                        int duration;
                                        EditCursor(65, 9);
                                        ShowConsoleCursor(TRUE);
                                        cout << "Введите длительность(мин): ";
                                        cin >> duration;
                                        cin.ignore();
                                        search(appUser, service, duration);
                                    }
                                }
                            }
                           
                        }
                    }
                    if (isMouseBox(x1, y1, 73, 8, "Фильтровать"))
                    {
                        SetConsoleTextAttribute(hConsole, 6);
                        drawTextBox("Фильтровать", 75, 8);
                        SetConsoleTextAttribute(hConsole, 15);
                        if (isMouseClicked())
                        {
                            system("cls");
                            menu_profile(appUser);
                            Sleep(300);
                            break;
                        }
                    }
                }
            }
        }
        else if (isMouseBox(x, y, 65, 24, "Заказать услугу"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Заказать услугу", 67, 24);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
               /* if (appUser.getSurname() == "неопределено")
                {
                    system("cls");
                    EditCursor(60, 25);
                    cout << "Необходимо ввести личные данные";

                }
                else
                {*/
                Service new_service;
                Employee new_employee;
                bool now = false;
                
                    char exit;
                    do {
                       // EditCursor(0, 13);
                        system("cls");
                        menu_profile(appUser);
                        appUser.getService();
                        for (vector<Service>::iterator i = service.begin(); i != service.end(); i++)
                        {
                            if (i == service.end() - 1)
                            {
                                cout << *i;
                                LineUpUgol(2);
                                Line(139);
                                LineUpUgol(4);
                            }
                            else
                            {
                                cout << *i;
                                LineUp();
                                Line(139);
                                LineUp();
                            }
                        }
                        Sleep(300);
                        new_service = appUser.addOrder(service);
                        if (new_service.getPrice() == 0)
                        {
                            break;
                        }
                        Sleep(300);

                        system("cls");
                        menu_profile(appUser);
                        Calendar<tm> date;
                        tm time;
                        time = date.printCalendar();
                        
                        


                        system("cls");
                        menu_profile(appUser);
                        appUser.getEmployee();
                        for (vector<Employee>::iterator i = employee.begin(); i != employee.end() ; i++)
                        {
                            if (i == employee.end() - 1)
                            {
                                    cout << *i;
                                    LineUpUgol(2);
                                    Line(127);
                                    LineUpUgol(4);
                            }
                            else
                            {
                                    cout << *i;
                                    LineUp();
                                    Line(127);
                                    LineUp();
                            }
                        }
                        

                       // new_employee = appUser.addOrder(employee);

                        int x, y;
                        bool exit_ = false;
                        bool state;
                        while (true)
                        {
                            if (exit_)
                                break;
                            Sleep(100);
                            SetConsoleTextAttribute(hConsole, 15);
                            drawTextBox("Вернуться назад", 137, 8);

                            getCursorPosition(x, y);

                            for (vector<Employee>::iterator i = employee.begin(); i < employee.end(); i++)
                            {
                                if (isMouse(x, y, 0, distance(employee.begin(), i) * 2 + 15, 141))
                                {
 
                                        SetConsoleTextAttribute(hConsole, 6);
                                        EditCursor(0, distance(employee.begin(), i) * 2 + 15);
                                        if (!i.operator->()->getStatus(date.getCurrDay(), date.getCurrTimeSlot()))
                                        {
                                            SetConsoleTextAttribute(hConsole, 4);
                                        }
                                        cout << *i;
                                    Sleep(100);
                                    if (isMouseClicked())
                                    {
                                        SetConsoleTextAttribute(hConsole, 15);
                                        if (!i.operator->()->getStatus(date.getCurrDay(), date.getCurrTimeSlot()))
                                        {
                                            EditCursor(70, 8);
                                            cout << "Данное время занято, попробуйте снова";
                                            Sleep(1200);
                                            EditCursor(70, 8);
                                            cout << "                                     ";
                                            state = false;
                                            break;
                                        }
                                        else
                                        {
                                            i.operator->()->setDateStatus(date.getCurrDay(), date.getCurrTimeSlot(), false);
                                            i.operator->()->setService(new_service);
                                            i.operator->()->setDateService(time);
                                            i.operator->()->setInfoUser(appUser.getSurname(), appUser.getName(), appUser.getPatronymic());
                                            new_employee = *i;
                                            EditCursor(70, 8);
                                            cout << "Запись прошла успешно" << endl;
                                            Sleep(1200);
                                            exit_ = true;
                                            state = true;
                                            break;
                                        }

                                    }
                                }
                                else
                                {
                                        SetConsoleTextAttribute(hConsole, 15);
                                        EditCursor(0, distance(employee.begin(), i) * 2 + 15);
                                        if (!i.operator->()->getStatus(date.getCurrDay(), date.getCurrTimeSlot()))
                                        {
                                            SetConsoleTextAttribute(hConsole, 4);
                                        }
                                        cout << *i;
                                }
                            }
                            if (isMouseBox(x, y, 135, 8, "Вернуться назад"))
                            {
                                SetConsoleTextAttribute(hConsole, 4);
                                drawTextBox("Вернуться назад", 137, 8);
                                SetConsoleTextAttribute(hConsole, 15);
                                if (isMouseClicked())
                                {
                                    system("cls");
                                    Sleep(300);
                                    state = false;
                                    break;
                                }
                            }

                        }

                       

                        system("cls");

                        if (state)
                            appUser.addOrder(new_service, new_employee, time);
                        


                           // system("pause");
                            now = true;
                            cout << endl << "Для выхода нажмите клавишу ESC, для продолжения любую другую клавишу" << endl;
                            exit = _getch();
                        
                    } while (exit != 27);
                    if (new_service.getPrice() != 0)
                    {
                        appUser.setOrder();
                        file_write_Order(appUser, "orders.txt");
                    }

                    menu_profile(appUser);
            }
            
        }
            else if (isMouseBox(x, y, 65, 28, "Просмотреть заказанные услуги"))
            {
                SetConsoleTextAttribute(hConsole, 6);
                drawTextBox("Просмотреть заказанные услуги", 67, 28);
                SetConsoleTextAttribute(hConsole, 15);
                if (isMouseClicked())
                {
                    system("cls");
                    menu_profile(appUser);
                    appUser.displayOrder();
                    system("pause");
                    system("cls");
                    menu_profile(appUser);
                }
            }
            else if (isMouseBox(x, y, 65, 32, "Отменить заказанную услугу"))
            {
                SetConsoleTextAttribute(hConsole, 6);
                drawTextBox("Отменить заказанную услугу", 67, 32);
                SetConsoleTextAttribute(hConsole, 15);
                if (isMouseClicked())
                {
                    system("cls");
                    break;
                }
            }
            else if (isMouseBox(x, y, 134, 8, "Выйти с аккаунта"))
            {
                SetConsoleTextAttribute(hConsole, 4);
                drawTextBox("Выйти с аккаунта", 136, 8);
                SetConsoleTextAttribute(hConsole, 15);
                if (isMouseClicked())
                {
                    system("cls");
                    break;
                }
            }
      Sleep(100);
    }
    SetConsoleTextAttribute(hConsole, 15);
}

void menu_Employee(Employee& appUser) // ввести личные данные,  Посмотреть мои заказы, отменить заказ, 
{
    int x, y;
    menu_profile(appUser);
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getTime();

        drawTextBox("Изменить личные данные", 67, 16);
        drawTextBox("Просмотреть график работы", 67, 20);

        drawTextBox("Выйти с аккаунта", 136, 8);


        getCursorPosition(x, y);

        if (isMouseBox(x, y, 65, 16, "Изменить личные данные"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Изменить личные данные", 67, 16);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                Sleep(300);
                menu_profile(appUser);
                appUser.setPersonalData(23, 1);

            }
        }
        else if(isMouseBox(x, y, 65, 20, "Просмотреть график работы"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Просмотреть график работы", 67, 20);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                menu_profile(appUser);
                appUser.displayDate();
                while (true)
                {
                    SetConsoleTextAttribute(hConsole, 15);

                    getTime();
                    drawTextBox("Вернуться назад", 137, 8);
                    if (isMouseBox(x, y, 135, 8, "Вернуться назад"))
                    {
                        SetConsoleTextAttribute(hConsole, 4);
                        drawTextBox("Вернуться назад", 137, 8);
                        SetConsoleTextAttribute(hConsole, 15);
                        if (isMouseClicked())
                        {
                            system("cls");
                            Sleep(300);
                            menu_profile(appUser);
                            break;
                        }
                    }
                }
            }
        }
        else if (isMouseBox(x, y, 134, 8, "Выйти с аккаунта"))
        {
            SetConsoleTextAttribute(hConsole, 4);
            drawTextBox("Выйти с аккаунта", 136, 8);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");
                break;
            }
        }

        Sleep(100);
    }
    SetConsoleTextAttribute(hConsole, 15);
}
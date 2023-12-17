#include "roles.h"
//#include "definition.h"
HANDLE hConsole;

using namespace adm;

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
                cin.ignore();
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

void menu_User(User &appUser, vector<Service> service, vector<Employee> employee) // Ввести личные данные, Заказать услугу, Посмотреть список услуг, Посмотреть список моих услуг, отменить заказанную услугу, выйти с аккаунта
{
    int x, y;
    menu_profile(appUser);
    while (true)
    {
        SetConsoleTextAttribute(hConsole, 15);

        getTime();

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

                    //appUser.addOrder(service);
                }
                cout << endl;
                system("pause");
                system("cls");
                menu_profile(appUser);
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
                        Sleep(300);

                        system("cls");
                        menu_profile(appUser);
                        Calendar<tm> date;
                        tm time;
                        time = date.printCalendar();
                        /*wcout << time.tm_mday << "/" << time.tm_mon + 1 << "/" << time.tm_year + 1900 << "   " << time.tm_hour << ":" << time.tm_min << "0";
                        cout << endl << endl;
                        system("pause");*/


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

                        new_employee = appUser.addOrder(employee);
                        system("cls");

                        appUser.addOrder(new_service, new_employee, time);

                        system("pause");
                        now = true;
                        cout << endl << "Для выхода нажмите клавишу ESC, для продолжения любую другую клавишу" << endl;
                        exit = _getch();
                    } while (exit != 27);
                    appUser.setOrder();

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

        drawTextBox("Ввести личные данные", 67, 16);
        drawTextBox("Просмотреть мои заказы", 67, 20);
        drawTextBox("Отменить заказ", 67, 24);

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

            }
        }
        else if(isMouseBox(x, y, 65, 20, "Просмотреть мои заказы"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Просмотреть мои заказы", 67, 20);
            SetConsoleTextAttribute(hConsole, 15);
            if (isMouseClicked())
            {
                system("cls");

            }
        }
        else if (isMouseBox(x, y, 65, 24, "Отменить заказ"))
        {
            SetConsoleTextAttribute(hConsole, 6);
            drawTextBox("Отменить заказ", 67, 24);
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
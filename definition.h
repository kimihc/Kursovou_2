#pragma once
#include "roles.h"
#include "service.h"

using namespace adm;

extern void ConsoleColor();
extern int menu_signUp();
extern int menu_();

extern void EditCursor(int hight, int width);

extern void menu_User(User& appUser, vector<Service> service, vector<Employee> employee);
extern void menu_Admin(Admin& appUser, vector<Service>& services, vector<User>& users, vector<Employee>& employees);
extern void menu_Employee(Employee& appUser);
extern bool isMouse(int mouseX, int mouseY, int rectX, int rectY, int rectWidth);
extern BOOL ShowConsoleCursor(BOOL bShow);

//template<class T>
//void signUp(vector<T>& appUsers);

template<class T>
typename vector<T>::iterator signIn(vector<T>& appUsers, string password, string login)
{

        for (typename vector<T>::iterator i = appUsers.begin(); i != appUsers.end(); i++)
        {
            if (i->getPassword() == password && i->getLogin() == login)
            {
                cout << endl << "Вход выполнен, вы вошли как " << i->getRole();
                Sleep(1500);
                return i;
            }
        }
        return appUsers.end();
}

extern void getTime();

template<class T>
void menu_profile(T& obj)
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
        wcout << L"⠈⢿⣇⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣸⡿⠁" << endl;
        wcout << L" ⠀⠈⠹⢿⣇⣀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣸⡿⠏⠁" << endl;
        wcout << L" ⠀⠀⠀⠈⠙⠻⢷⣦⣤⣤⣤⣤⣴⡾⠟⠋⠁⠀⠀" << endl;
        _setmode(_fileno(stdout), _O_TEXT);
        cout << "      Сотрудник";
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
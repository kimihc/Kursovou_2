#include "definition.h"

template <class T>
void file_write(T& obj, string name)
{
	ofstream file;
	file.open(name, ofstream::app);

	if (!file.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		file << obj.getRole() << " " << obj.getLogin() << " " << obj.getPassword() << endl;
	}

	file.close();
}

template <class T>
void file_write_personDate(T& obj, string name)
{
	ofstream file;
	file.open(name, ofstream::app);

	if (!file.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		file << obj.getRole() << " " << obj.getLogin() << " " << obj.getSurname() << " " << obj.getName() << " " << obj.getPatronymic() << endl;
	}

	file.close();
}

template <class T>
void file_write_Order(T& obj, string name)
{
	ofstream file;
	file.open(name, ofstream::app);

	if (!file.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		file << obj;
	}
	file.close();
}
template void file_write_Order<User>(User&, string);


template void file_write_personDate<User>(User&, string);

template<class T>
bool signUp(vector<T>& appUsers, vector<string> logins)
{
	if (!appUsers.back().addLogin(logins))
	{
		appUsers.pop_back();
		return false;
	}
	else
	{
		appUsers.back().addPassword();
		return true;
	}
}

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	ConsoleColor();
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_MAXIMIZE);


	SetConsoleTextAttribute(hConsole, 15);
	vector<string> logins;
	vector<User> users;
	vector<Admin> admins;
	vector<Employee> employees;

	vector<Service> services;

	ifstream file_;
	file_.open("service.txt", ios::in);

	if (!file_.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		Service service;
		file_.seekg(0, ios::beg);
		while (file_ >> service)
		{
			services.push_back(service);
		}
	}
	file_.clear();
	file_.close();


	ifstream file;
	file.open("log.txt", ios::in);
	
	if (!file.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		Account appUser;
		file.seekg(0, ios::beg);
		while (file >> appUser)
		{
			if (appUser.getRole() == "Пользователь")
			{
				User user;
				user.setRole(appUser.getRole());
				user.setLogin(appUser.getLogin());
				user.setPassword(appUser.getPassword());
				logins.push_back(appUser.getLogin());
				users.push_back(user);
			}
			else if (appUser.getRole() == "Администратор")
			{
				Admin user;
				user.setRole(appUser.getRole());
				user.setLogin(appUser.getLogin());
				user.setPassword(appUser.getPassword());
				logins.push_back(appUser.getLogin());
				admins.push_back(user);
			}
			else if (appUser.getRole() == "Сотрудник")
			{
				Employee user;
				user.setRole(appUser.getRole());
				user.setLogin(appUser.getLogin());
				user.setPassword(appUser.getPassword());
				logins.push_back(appUser.getLogin());
				employees.push_back(user);
			}
		}
		file.clear();
		file.close();
	}

	ifstream file_2;
	file_2.open("personalDate.txt", ios::in);

	if (!file_2.is_open())
		cout << "Ошибка открытия файла" << endl;
	else
	{
		User user;
		
		file_2.seekg(0, ios::beg);
		while (!file_2.eof())
		{
			file_2 >> user;
			if (user.getRole() == "Пользователь")
			{
				for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
				{
					if (i.operator->()->getLogin() == user.getLogin())
					{
						i.operator->()->setSurname(user.getSurname());
						i.operator->()->setName(user.getName());
						i.operator->()->setPatronymic(user.getPatronymic());
						break;
					}
				}
			}
			else
			{
				for (vector<Employee>::iterator i = employees.begin(); i != employees.end(); i++)
				{
					if (i.operator->()->getLogin() == user.getLogin())
					{
						i.operator->()->setSurname(user.getSurname());
						i.operator->()->setName(user.getName());
						i.operator->()->setPatronymic(user.getPatronymic());
						break;
					}
				}
			}

		}
		file_2.clear();
		file_2.close();
	}

	int choice;
	do
	{
		system("cls");
		choice = menu_();
		Sleep(100);
		switch (choice)
		{
		case 1:
		{
			int sign = menu_signUp();
			SetConsoleTextAttribute(hConsole, 15);

			if (sign == 1)
			{
				User user;
				users.push_back(user);
				if (signUp(users, logins))
				{
					logins.push_back(users.back().getLogin());
					file_write(users.back(), "log.txt");
				}

			}
			else if (sign == 2)
			{
				Admin admin;
				admins.push_back(admin);
				if (signUp(admins, logins))
				{
					logins.push_back(admins.back().getLogin());
					file_write(admins.back(), "log.txt");
				}
			}
			else if (sign == 3)
			{
				Employee employee;
				employees.push_back(employee);
				if (signUp(employees, logins))
				{
					logins.push_back(employees.back().getLogin());
					employees.back().setPersonalData(0, 0);
					file_write_personDate(employees.back(), "personalDate.txt");
					file_write(employees.back(), "log.txt");
				}
			}
			break;
		}
		case 2:

			EditCursor(0, 0);
		
			for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
			{
				cout << i.operator->()->getRole() << "  " << i.operator->()->getLogin() << "  " << i.operator->()->getPassword() << endl;
			}

			for (vector<Admin>::iterator i = admins.begin(); i != admins.end(); i++)
			{
				cout << i.operator->()->getRole() << "  " << i.operator->()->getLogin() << "  " << i.operator->()->getPassword() << endl;
			}

			for (vector<Employee>::iterator i = employees.begin(); i != employees.end(); i++)
			{
				cout << i.operator->()->getRole() << "  " << i.operator->()->getLogin() << "  " << i.operator->()->getPassword() << endl;
			}
			system("pause");

			int choice_ = 0;
			vector<Admin>::iterator admin;
			vector<User>::iterator user;
			vector<Employee>::iterator employee;

			string login;
			string password;
			char exit;
			do
			{
			system("cls");
			cout << "Введите логин: ";
			cin >> login;
			cin.ignore();
			password = InPassword();

			admin = signIn(admins, password, login);
			if (admin != admins.end())
				choice_ = 1;
			if (choice_ == 0)
			{
				user = signIn(users, password, login);
				if (user != users.end())
					choice_ = 2;
			}
			if (choice_ == 0)
			{
				employee = signIn(employees, password, login);
				if (employee != employees.end())
					choice_ = 3;
			}
			if (choice_ == 0)
			{
				cout << endl << "Введен неверный логин или пароль." << endl << "Для выхода нажмите клавишу ESC, для продолжения любую другую клавишу" << endl;
				exit = _getch();
			}
			else
				break;
			} while (exit != 27);

			ShowConsoleCursor(FALSE);

			if (choice_ == 0)
				break;
			
			switch (choice_)
			{
			case 1:
			{
				menu_Admin(*admin, services, users, employees);
			}
				break;
			case 2:
			{
				menu_User(*user, services, employees);
			}
				break;
			case 3:
			{
				menu_Employee(*employee);
			}
				break;
			}
			break;
		}
	}while (choice != 3);
}
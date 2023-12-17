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
//
////template <class T>
//void file_read(AppUser& obj, string name)
//{
//	ifstream file;
//	file.open(name, ios::in);
//
//	if (!file.is_open())
//		cout << "Ошибка открытия файла" << endl;
//	else
//	{
//		file.seekg(0, ios::beg);
//		while (!file.eof())
//		{
//			file >> obj;
//		}
//		file.clear();
//		file.close();
//	}
//}

//void writeToFile(const std::string& filename, const std::vector<std::shared_ptr<AppUser>>& appUsers) {
//	std::ofstream outFile(filename, std::ios::binary | std::ios::out);
//	if (outFile.is_open()) {
//		for (const auto& user : appUsers) {
//			// Write each object to the file
//			outFile.write(reinterpret_cast<const char*>(user.get()), sizeof(AppUser));
//		}
//		outFile.close();
//	}
//	else {
//		std::cerr << "Error opening file for writing: " << filename << std::endl;
//	}
//}
//
//std::vector<std::shared_ptr<AppUser>> readFromFile(const std::string& filename) {
//	std::vector<std::shared_ptr<AppUser>> appUsers;
//	std::ifstream inFile(filename, std::ios::binary | std::ios::in);
//	if (inFile.is_open()) {
//		while (inFile.peek() != EOF) 
//		{
//			shared_ptr<AppUser> user;
//			char typeName[sizeof(string)];
//			inFile.read(typeName, sizeof(string));
//			if (strcmp(typeName, "Администратор"))
//			{
//				shared_ptr<AppUser> user1 = make_shared<Admin>();
//				user = user1;
//			}
//			if (strcmp(typeName, "Пользователь"))
//			{
//				shared_ptr<AppUser> user1 = make_shared<User>();
//				user = user1;
//			}
//			if (strcmp(typeName, "Сотрудник"))
//			{
//				shared_ptr<AppUser> user1 = make_shared<Employee>();
//				user = user1;
//			}
//
//
//			inFile.read(reinterpret_cast<char*>(user.get()), sizeof(AppUser));
//			appUsers.push_back(user);
//		}
//		inFile.close();
//	}
//	else {
//		std::cerr << "Error opening file for reading: " << filename << std::endl;
//	}
//	return appUsers;
//}


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
				users.push_back(user);
			}
			else if (appUser.getRole() == "Администратор")
			{
				Admin user;
				user.setRole(appUser.getRole());
				user.setLogin(appUser.getLogin());
				user.setPassword(appUser.getPassword());
				admins.push_back(user);
			}
			else if (appUser.getRole() == "Сотрудник")
			{
				Employee user;
				user.setRole(appUser.getRole());
				user.setLogin(appUser.getLogin());
				user.setPassword(appUser.getPassword());
				employees.push_back(user);
			}
		}
		file.clear();
		file.close();
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
					file_write(employees.back(), "log.txt");
				}
			}
			break;
		}
		case 2:
			////////

			EditCursor(0, 0);
			
			///////
		
			/*shared_ptr<AppUser> now;*/
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

			
			// Вход выполнен // 
			break;
		}
	}while (choice != 3);
}
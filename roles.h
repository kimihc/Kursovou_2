#pragma once
#include "service.h"

using namespace std;


	extern Service add_service(vector<Service>& services);
	extern string InPassword();
	extern bool isMouseClicked();
	extern bool isMouseBox(int mouseX, int mouseY, int rectX, int rectY, string text);
	template<class T>
	extern void menu_profile(T& obj);
	extern HANDLE hConsole;
	extern bool isValidLogin(string login);

	class Account
	{
	protected:
		string role;
		string login;
		string password;
		/*string name;
		string surname;*/

	public:
		Account()
		{
			login = "����������";
			password = "����������";
		}

		Account(string login, string password, string name, string surname)
		{
			this->login = login;
			this->password = password;
		}

		string getLogin()
		{
			return login;
		}

		string getPassword()
		{
			return password;
		}

		string getRole()
		{
			return role;
		}

		void setRole(string role)
		{
			this->role = role;
		}

		void setLogin(string login)
		{
			this->login = login;
		}

		void setPassword(string password)
		{
			this->password = password;
		}

		void appUserDisplay()
		{
			cout << role << "  " << login << "  " << password << endl;
		}

		bool addLogin(vector<string> logins)
		{
			string log;
			char exit = 0;
			bool loginExists;
			do
			{
				loginExists = false;
				cout << "������� �����: ";
				try
				{
					cin >> log;
					if (!isValidLogin(log))
						throw runtime_error("����� ������ ���� �� ����� 4 �������� � �������� ������ �� ��������� ����.");
				}
				catch (const exception& e) {
					cerr << e.what() << endl;
					cout << "���������� �����." << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					Sleep(1200);
					system("cls");
					continue;
				}
				for (vector<string>::iterator i = logins.begin(); i != logins.end(); i++)
				{
					if (log == *i)
					{
						cout << "������ ����� �����, ���������� �����." << endl;
						loginExists = true;
						break;
					}
				}
				if (loginExists)
				{
					cout << endl << "��� ������ ������� ������� ESC, ��� ����������� ����� ������ �������" << endl;
					exit = _getch();
				}
				else
				{
					login = log;
					return true;
				}
			} while (exit != 27);

			return false;
		}

		virtual void addPassword()
		{
			this->password = InPassword();
		}

		friend ifstream& operator>>(ifstream& file, Account& user)
		{
			file >> user.role >> user.login >> user.password;
			return file;
		}
	};

	template<class T>
	class Calendar
	{
	private:
		time_t currentDate;
		vector<vector<bool>> status;
		vector<T> dates;

	public:
		Calendar()
		{
			currentDate = time(0);
			createCalendar();
		}

		void createCalendar() 
		{
			status.resize(7, vector<bool>(6, false));
			dates.resize(7);

			for (int day = 0; day < 7; ++day) {
				currentDate += 24 * 60 * 60;
				dates[day] = *localtime(&currentDate);

				for (int timeSlot = 0; timeSlot < 6; ++timeSlot) {
					status[day][timeSlot] = true; 
				}
			}
		}

		string getTimeString(int timeSlot) const 
		{
			switch (timeSlot) {
			case 0: return "10:00";
			case 1: return "12:00";
			case 2: return "14:00";
			case 3: return "16:00";
			case 4: return "18:00";
			case 5: return "20:00";
			}
		}

		string getFormattedDate(const T& date) const 
		{
				stringstream ss;
			ss << put_time(&date, "%d/%m/%Y");
			return ss.str();
		}

		T printCalendar(int day, T &time) const
		{
			int x1 = 0;
			int y1 = 13;
			int x, y;
			while (true)
			{
				SetConsoleTextAttribute(hConsole, 15);

				for (int i = 0; i < 6; i++)
				{
					getCursorPosition(x, y);
					drawTextBox(getTimeString(i), x1 + 50 + i * 10, y1);

					if (isMouseBox(x, y, x1 + 50 + i * 10 - 2, y1, getTimeString(i)))
					{
						SetConsoleTextAttribute(hConsole, 6);
						drawTextBox(getTimeString(i), x1 + 50 + i * 10, y1);
						SetConsoleTextAttribute(hConsole, 15);
						if (isMouseClicked())
						{
							system("cls");
							time.tm_hour = i * 2 + 10;
							time.tm_min = 0;
							return time;
						}
					}
				}
			}
		}

		T printCalendar()
		{
			T time;
			int x1 = 75;
			int y1 = 13; 
			
			int x, y;
			while (true)
			{
				SetConsoleTextAttribute(hConsole, 15);
				y1 = 13;
				for (int day = 0; day < 7; ++day)
				{
					getCursorPosition(x, y);

					drawTextBox(getFormattedDate(dates[day]), x1, y1);

					if (isMouseBox(x, y, x1 - 2, y1, getFormattedDate(dates[day])))
					{
						SetConsoleTextAttribute(hConsole, 6);
						drawTextBox(getFormattedDate(dates[day]), x1, y1);
						SetConsoleTextAttribute(hConsole, 15);
						if (isMouseClicked())
						{
							system("cls");
							time = printCalendar(day, time);
							//shedule[day][timeSlot] = false;
							time.tm_year = dates[day].tm_year;
							time.tm_mon = dates[day].tm_mon;
							time.tm_mday = dates[day].tm_mday;
							return time;
						}
					}
					y1 += 4;
				}
			}
		}
		
	};

	class Person
	{
	protected:
		string name;
		string surname;
		string fname;

	public:
		Person()
		{
			name = "������������";
			surname = "������������";
			fname = "������������";
		}

		string getSurname()
		{
			return surname;
		}

		virtual void setPersonalData(int x, int y) = 0;
		virtual void getPersonalData(int x, int y) = 0;
	};

	class Employee : public Account, public Person
	{
	private:
		Calendar<tm> date;

	public:
		Employee()
		{
			role = "���������";
		}

		void addPassword() override
		{
			this->password = InPassword();
		}

		void add_Service()
		{
			cout << "��� ������ ���������" << endl;
		}

		void setPersonalData(int x, int y) override
		{
			EditCursor(x, y);
			cout << "                       ";
			EditCursor(x, y);
			cout << "�������: ";
			cin >> surname;
			EditCursor(x, y + 2);
			cout << "                       ";
			EditCursor(x, y + 2);
			cout << "���: ";
			cin >> name;
			EditCursor(x, y + 4);
			cout << "                       ";
			EditCursor(x, y + 4);
			cout << "��������: ";
			cin >> fname;
		}

		void getPersonalData(int x, int y) override
		{
			EditCursor(x, y);
			cout << "�������: " << surname;
			EditCursor(x, y + 2);
			cout << "���: " << name;
			EditCursor(x, y + 4);
			cout << "��������: " << fname;
		}

		void displayEmployee()
		{
			string name_employee;
			name_employee = surname + " " + name[0] + "." + " " + fname[0] + ".";
			cout << " " << setw(25) << name_employee;
			LineUp();
		}

		friend ostream& operator<<(ostream& cout, const Employee& obj)
		{
			cout << endl;
			LineUp();
			cout << " " << setw(30) << obj.surname;
			LineUp();
			cout << " " << setw(30) << obj.name;
			LineUp();
			cout << " " << setw(61) << obj.fname;
			LineUp();
			cout << endl;

			return cout;
		}
	};

	class Order
	{
	private:
		// set of OrderLine
		float totalPrice;
		vector<Service> services;
		vector<Employee> employees;
		vector<tm> timeService;
		int count_line;

	public:
		Order()
		{
			totalPrice = 0;
			//service = nullptr;
			//employye = nullptr;
			//services

			count_line = 0;
		}

		void add_Order(Service service, Employee employee, tm timeService)
		{
			//shared_ptr<Service> new_service(new Service[count_line + 1]);
			//shared_ptr<Employee> new_employee(new Employee[count_line + 1]);

			this->services.push_back(service);
			this->employees.push_back(employee);
			this->timeService.push_back(timeService);
			this->totalPrice = service.getPrice();
			this->count_line++;
		}

		void delete_orderInfo()
		{
			count_line = 0;
			services.clear();
			employees.clear();
		}

		void display_order(int j)
		{
			LineUp();
			
			cout.width(4);
			cout << j + 1;
			LineUp();
			totalPrice = 0;
			
			for (int i = 0; i < this->count_line; i++)
			{
				totalPrice += services[i].getPrice();
			}

			wcout << setw(15) << left << totalPrice;

			LineUp();

			for (int i = 0; i < this->count_line; i++)
			{
				services[i].displayService();
				wcout << " " << timeService[i].tm_mday << "/" << timeService[i].tm_mon + 1 << "/" << timeService[i].tm_year + 1900 - 2000 << " " << timeService[i].tm_hour << ":" << timeService[i].tm_min << "0";
				LineUp();
				employees[i].displayEmployee();
				if (i + 1 != count_line)
				{
					LineUp();
					cout.width(4);
					cout << " ";
					LineUp();
					cout.width(15);
					cout << " ";
					LineUp();
				}
			}
			
			cout << endl;
			LineUp();
			Line(154);
			LineUp();

		}

		float getTotalPrice()
		{
			return totalPrice;
		}

		friend ostream& operator<<(ostream& cout, const Order& obj)
		{
			cout << endl;
			cout << obj.services[0] << endl;
			cout << obj.totalPrice << endl;
			cout << obj.employees[0] << endl;
			cout << endl;

			return cout;
		}
	};

	class User : public Account, public Person
	{
	private:
		int numberPhone;
		vector<Order> orders;
		Order order;


	public:
		User()
		{
			role = "������������";
			numberPhone = 111111;
		}

		/*void add_Service() override
		{
			order.add_Order();
			orders.push_back(order);
		}*/
		void setPersonalData(int x, int y) override
		{
			EditCursor(x, y);
			cout << "                       ";
			EditCursor(x, y);
			cout << "�������: ";
			cin >> surname;
			EditCursor(x, y + 2);
			cout << "                       ";
			EditCursor(x, y + 2);
			cout << "���: ";
			cin >> name;
			EditCursor(x, y + 4);
			cout << "                       ";
			EditCursor(x, y + 4);
			cout << "��������: ";
			cin >> fname;
			EditCursor(x, y + 6);
			cout << "                       ";
			EditCursor(x, y + 6);
			cout << "����� ��������: +375 ";
			cin >> numberPhone;
		}

		void getPersonalData(int x, int y) override
		{
			EditCursor(x, y);
			cout << "�������: " << surname;
			EditCursor(x, y + 2);
			cout << "���: " << name;
			EditCursor(x, y + 4);
			cout << "��������: " << fname;
			EditCursor(x, y + 6);
			cout << "����� ��������: +375" << numberPhone;

		}

		void addPassword() override
		{
			this->password = InPassword();
		}

		void getService()
		{
			LineUpUgol(1);
			Line(139);
			LineUpUgol(3);
			cout << endl;

			LineUp();
			cout << setw(31) << left << "            ��������";
			LineUp();
			cout << setw(31) << left << "            ������������";
			LineUp();
			cout << setw(62) << left << "                  ��������";
			LineUp();
			cout << setw(12) << left << "    ����";
			LineUp();

			cout << endl;
			LineUp();
			Line(139);
			LineUp();
		}

		void getEmployee()
		{
			LineUpUgol(1);
			Line(127);
			LineUpUgol(3);
			cout << endl;

			LineUp();
			cout << setw(31) << left << "            �������";
			LineUp();
			cout << setw(31) << left << "            ���";
			LineUp();
			cout << setw(62) << left << "                  ��������";
			LineUp();

			cout << endl;
			LineUp();
			Line(127);
			LineUp();
		}

		template<typename T>
		T addOrder(vector<T> obj)
		{
			int x, y;

			while (true)
			{
				SetConsoleTextAttribute(hConsole, 15);

				getCursorPosition(x, y);

				for (typename vector<T>::iterator i = obj.begin(); i < obj.end(); i++)
				{
					if (isMouse(x, y, 0, distance(obj.begin(), i) * 2 + 15, 141))
					{
						SetConsoleTextAttribute(hConsole, 6);
						EditCursor(0, distance(obj.begin(), i) * 2 + 15);
						cout << *i;
						if (isMouseClicked())
						{
							SetConsoleTextAttribute(hConsole, 15);
							return *i;
						}
					}
					else
					{
						SetConsoleTextAttribute(hConsole, 15);
						EditCursor(0, distance(obj.begin(), i) * 2 + 15);
						cout << *i;
					}
				}

			}
		}

		void addOrder(Service service, Employee employee, tm time)
		{

			order.add_Order(service, employee, time);


		}

		void setOrder()
		{
			orders.push_back(order);

			order.delete_orderInfo();
			
		}

		void displayOrder()
		{

			LineUpUgol(1);
			Line(154);
			LineUpUgol(3);
			cout << endl;

			LineUp();
			cout << setw(20) << left << "       �����";
			LineUp();
			cout << setw(25) << left << "         ��������";
			LineUp();
			cout << setw(10) << left << " ������������ ";
			LineUp();
			cout << setw(38) << left << "          ��������";
			LineUp();
			cout << setw(10) << left << "���� (BYN)";
			LineUp();
			cout << setw(15) << left << " ���� � �����";
			LineUp();
			cout << setw(26) << left << "         ������";
			LineUp();

			cout << endl;
			LineUp();
			Line(20);
			LineUp();
			cout << setw(25) << " ";
			LineUp();
			cout << setw(14) << " ";
			LineUp();
			cout << setw(38) << " ";
			LineUp();
			cout << setw(10) << " ";
			LineUp();
			cout << setw(15) << " ";
			LineUp();
			cout << setw(26) << " ";
			LineUp();

			cout << endl;
			LineUp();
			cout << setw(4) << left << " �";
			LineUp();
			cout << setw(10) << left << "����� ���������";
			LineUp();
			cout << setw(25) << " ";
			LineUp();
			cout << setw(14) << " ";
			LineUp();
			cout << setw(38) << " ";
			LineUp();
			cout << setw(10) << " ";
			LineUp();
			cout << setw(15) << " ";
			LineUp();
			cout << setw(26) << " ";
			LineUp();

			cout << endl;
			LineUp();
			Line(154);
			LineUp();

			float all_price = 0;
			cout << endl;
			int j = 0;
			for (vector<Order>::iterator i = orders.begin(); i != orders.end(); i++)
			{
				i.operator->()->display_order(j);
				all_price += i.operator->()->getTotalPrice();
				j++;
			}

			

			


			LineUp();
			wcout << "��������� ���� �������: " << setw(126) << left << all_price << left << " BYN";
			LineUp();
			LineUpUgol(2);
			Line(154);
			LineUpUgol(4);

			cout << endl << endl;
		}

	};
	namespace adm {
		class Admin : public Account
		{
		private:
			vector<Service> services;

		public:
			Admin()
			{
				role = "�������������";
			}

			void add_Service() // ��������� ���������� � ��
			{
				char exit;
				Service service;
				do
				{
					service.addService();
					services.push_back(service);

					cout << endl << "��� ������ ������� ������� ESC, ��� ����������� ����� ������ �������" << endl;
					exit = _getch();
				} while (exit != 27);
			}

			void getService()
			{
				LineUpUgol(1);
				Line(139);
				LineUpUgol(3);
				cout << endl;

				LineUp();
				cout << setw(31) << left << "            ��������";
				LineUp();
				cout << setw(31) << left << "            ������������";
				LineUp();
				cout << setw(62) << left << "                  ��������";
				LineUp();
				cout << setw(12) << left << "    ����";
				LineUp();

				cout << endl;
				LineUp();
				Line(139);
				LineUp();

				//for (vector<Service>::iterator i = services.begin() ; i != services.end(); i++)
				//{
				//	/*if (i == services.end() - 1)
				//	{
				//		LineUpUgol(2);
				//		Line(139);
				//		LineUpUgol(4);
				//	}
				//	else*/
				//		cout << *i;
				//}

			}

			//void getAllUserInfo(vector<shared_ptr<AppUser>> appUsers)
			//{
			//	for (vector<shared_ptr<AppUser>>::iterator i = appUsers.begin(); i < appUsers.end(); i++)
			//	{
			//		if (i->get()->getRole() == "������������")
			//		{
			//			// ����� ��������� �������������
			//		}
			//	}
			//}

			void addPassword() override
			{
				this->password = InPassword();
			}

			void getPersonalData(int x, int y)
			{

			}
		};

	}

	
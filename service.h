#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <conio.h>
#include <Windows.h>
#include <io.h>
#include <iomanip>
#include <fcntl.h>
#include <fstream>
#include <ctime>
#include <chrono>
#include <locale>
#include <array>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <memory>

extern HANDLE hConsole;
extern bool isMouse(int mouseX, int mouseY, int rectX, int rectY, int rectWidth);
extern BOOL ShowConsoleCursor(BOOL bShow);

using namespace std;

extern void Line(int a);
extern void LineUp();
extern void LineUpUgol(int a);
extern void drawTextBox(const string& text, int x, int y);
extern void EditCursor(int hight, int width);
extern bool isMouseClicked();
extern void getCursorPosition(int& x, int& y);
extern bool isMouseClickInRect(int mouseX, int mouseY, int rectX, int rectY, int rectWidth, int rectHeight);


//
//class TypeService
//{
//private:
//	string nameType;
//
//public:
//	TypeService()
//	{
//		nameType = "Неизвестно";
//	}
//
//
//};

//class RawMaterial
//{
//private:
//	string nameRaw;
//	int qunatityRaw;
//
//public:
//	RawMaterial()
//	{
//		nameRaw = "Неизвестно";
//		qunatityRaw = 0;
//	}
//};
class Service
{
private:
	string name_service;
	float price;
	float time; 
	int duration; 
	string description;

public:
	Service() 
	{
		name_service = "Неизвестно";
		price = 0;
		time = 0;
	}

	Service addService()
	{
		ShowConsoleCursor(TRUE);
		cout.setf(ios::left);

		cout << setw(60) << " " << "Введите название услуги: ";
		getline(cin, name_service);
		bool state = true;
		do {
			cout << setw(60) << " " << "Введите цену за услугу(BYN): ";
			try {
				cin >> price;

				if (cin.fail())
					throw exception("Введено неверное значение");

				ostringstream oss;
				oss << price;
				string priceString = oss.str();
				size_t dotPosition = priceString.find('.');
				size_t count = priceString.length() - dotPosition - 1;
				if (count > 2 && priceString.length() != count)
					throw exception("Цена должна иметь меньше двух знаков после точки.");

				state = true;
				cin.clear();
				cin.ignore(1024, '\n');
			}
			catch (exception& error)
			{
				cerr << setw(60) << " " << error.what() << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				state = false;
			}
		} while (!state);
		

		do {
			cout << setw(60) << " " << "Введите длительность услуги(Мин): ";
			try {
				cin >> duration;

				if (cin.fail())
					throw exception("Введено неверное значение");

				state = true;
				cin.clear();
				cin.ignore(1024, '\n');
			}
			catch (exception& error)
			{
				cerr << setw(60) << " " << error.what() << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				state = false;
			}
		} while (!state);

		cout << setw(60) << " " << "Введите описание услуги: ";
		getchar();
		getline(cin, description);

		ofstream file;
		file.open("service.txt", ofstream::app);

		if (!file.is_open())
			cout << "Ошибка открытия файла" << endl;
		else
		{
			file << name_service << ";" << price << ";" << duration << ";" << description << endl;
		}

		file.close();

		cout.unsetf(ios::left);
		ShowConsoleCursor(FALSE);
		return *this;

	}

	static bool compPrice(Service& service1, Service& service2)
	{
		return service1.getPrice() < service2.getPrice();
	}

	static bool compDuration(Service& service1, Service& service2)
	{
		return service1.getDuration() < service2.getDuration();
	}

	bool search(string &obj)
	{
		return name_service == obj;
	}

	bool search(float& obj)
	{
		return price == obj;
	}

	void setPrice(float price)
	{
		this->price = price;
	}

	bool search(int& obj)
	{
		return duration == obj;
	}

	float getPrice()
	{
		return price;
	}

	int getDuration()
	{
		return duration;
	}

	void displayService()
	{
		cout << " " << setw(24) << name_service;
		LineUp();
		wcout << " " << setw(13) << left << duration;
		LineUp();
		cout << " " << setw(37) << description;
		LineUp();
		wcout << " " << setw(9) << left << price;
		LineUp();
	}
	
	friend ostream& operator<<(ostream& cout, const Service& obj)
	{	
		cout << endl;
		LineUp();
		cout << " " << setw(30) << obj.name_service;
		LineUp();
		cout << " " << setw(30) << obj.duration;
		LineUp();
		cout << " " << setw(61) << obj.description;
		LineUp();
		cout << " " << setw(11) << obj.price;
		LineUp();
		cout << endl;

		return cout;
	}



	friend ifstream& operator>>(ifstream& file, Service& service)
	{
		getline(file, service.name_service, ';');
		file >> service.price;
		file.ignore();
		file >> service.duration;
		file.ignore();
		getline(file >> noskipws, service.description);

		return file;
	}
};


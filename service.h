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
		cout << setw(60) << " " << "Введите цену за услугу(BYN): ";
		cin >> price; // Ввод цены 
		cin.ignore();
		cout << setw(60) << " " << "Введите длительность услуги(Мин): ";
		cin >> duration;
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

	float getPrice()
	{
		return price;
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
		std::getline(file, service.name_service, ';');
		file >> service.price;
		file.ignore();
		file >> service.duration;
		file.ignore();
		std::getline(file >> noskipws, service.description);

		return file;
	}
};


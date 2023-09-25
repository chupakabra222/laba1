

#include <iostream>
#include <string>
using namespace std;

int* separate(string);
string getStr();
double long calculateDuration(int*, int*);
void compare(int*, int*);
string reInput(string);

int main()
{
    cout << "This program calculates time execution of any process\n";
	char again = 'y';
    do 
	{
		string start;
		string end; 
		char sep = ':';

		cout << "Enter start time like HH:MM:SS \n";

		start = getStr();

		cout << "Enter end time like HH:MM:SS \n";

		end = getStr();

		int* strTime = separate(start);
		int* endTime = separate(end);
		compare(strTime, endTime);

		double long duration = calculateDuration(strTime, endTime);
		cout << duration << " seconds " << round(duration/60) << " minutes \n";
		cout << "Press any key to continue or n \n";
		//cin.clear();
		//cin.ignore(10000, '\n');
	} while (cin.get()!= 'n');
	
}
double long calculateDuration(int* startTime, int*  endTime)//возвращает разницу конца и начала в секундах
{
	int strHours = *startTime;
	int strMin = *(startTime + 1);
	int strSec = *(startTime + 2);

	int endHours = *endTime;
	int endMin = *(endTime + 1);
	int endSec = *(endTime + 2);

	return (endHours - strHours) * 3600 + (endMin - strMin) * 60 + (endSec - strSec);
}
int* separate(string str) //делит строку на массив из 3 элементов и возвращает указатель на его 1-й элемент
{
	int indSep = 0;
	int *subStrs = new int[3]{stoi(str.substr(0, 2)), stoi(str.substr(3, 2)), stoi(str.substr(6, 2))};
	return subStrs;
}
string getStr()
{
	string str;
	getline(cin, str);
	while (1)
	{
		bool isNum = 1;//true - если все символы по индексам не равным 2 и 5 числа
		bool isSep = 1;//true - если символы по индексам 2 и 5 это :
		if (str.length() == 8)
		{
			char curr;
			for (int i = 0; i < 8; i++)
			{
				curr = str[i];
				if (curr == ':' && i != 2 && i != 5)
				{
					isSep = 0;
				}
				else if (curr != '0' && curr != '1' && curr != '2' && curr != '3' && curr != '4' && curr != '5' && curr != '6' && curr != '7' && curr != '8' && curr != '9' && i != 2 && i != 5)
				{
					isNum = 0;
				}
			}
			if (isNum && isSep)
			{
				int* time = separate(str);
				int h = *time;
				int m = *(time + 1);
				int s = *(time + 2);
				if (h > -1 && h < 24 && m > -1 && m < 60 && s > -1 && s < 60)
				{
					return str;
				}
			}
		}
		str = reInput(str);
	}
}
void compare(int* strTime, int* endTime)//сравнивает начальное и конечное время, если конечное меньше начального, то повторный ввод. Параметры передаются по ссылке для их редактирования
{
	if (calculateDuration(strTime, endTime) < 0) 
		*endTime += 24;
	
}
string reInput(string str)
{
	cout << "Invalid input, retry" << endl;
	cin.clear();
	getline(cin, str);
	return str;
}


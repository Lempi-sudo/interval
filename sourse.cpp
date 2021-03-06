// проба пера 1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <conio.h>
#include<iostream>
using namespace std;
class interval
{
private:
	double _a, _b;
	bool _alogic, _blogic;
public:
	interval()
	{
		_a = 0;
		_b = 0;
		_alogic = false;
		_blogic = false;
	}
	void input();
	static interval combinstatic(const interval &otr1, const interval &otr2)
	{
		return otr1.combine(otr2);
	}
	bool is_common_point(const interval& otr2)const;
		interval combine(const interval& otr2)const;
		//const interval i1(...);
		//const interval i2(...)
		//auto i3=i2.combine(i1)
	interval crossing(const interval &otr2) const;
	void output_res() const;
};
void interval::output_res()const
{
	_alogic ? printf("[") : printf("(");
	printf("%lf %lf", _a, _b);
	_blogic? printf("]") : printf(")");
}
interval interval :: combine(const interval &otr2)const
{
	interval res;
	if (!is_common_point(otr2))
	{
		return res;
	}
	if (otr2._a < _a)
	{
		res._a = otr2._a;
		res._alogic = otr2._alogic;
	}
	else
	{
		res._a =_a;
		res._alogic =_alogic;
	}
	if (otr2._b > _b)
	{
		res._b = otr2._b;
		res._blogic = otr2._blogic;
	}
	else
	{
		res._b = _b;
		res._blogic = _blogic;
	}
	return res;
}
bool interval::is_common_point(const interval&  otr2) const 
{
	bool flag = false;
	if ((_b < otr2._a) || (otr2._b <_a))
	{
		flag = false;
		return flag;
	}
	if ((_b == otr2._a) || (otr2._b ==_a))
	{
		if (((!_blogic) || (!otr2._alogic)) || ((!otr2._blogic) || (!_alogic)))
		{
			flag = false;
			return flag;
		}
		else 
		{
			flag = true;
			return flag;
		}
	}
	return true;
}
void interval:: input()
{
	int k;
	puts("Выберите один из видов промежутков:\n[1]-ОТРЕЗОК[]  [2]-ИНТЕРВАЛ() [3]-Полуинтервал[)  [4]-ПОЛУИНТЕРВАЛ(]");
	do
	{
		do
		{
			k = getch();
		} while ((k < 1) || (k > 223));
	} while ((k != 49) && (k != 52) && (k != 50) && (k != 51));
	switch (k)
	{
	case 49: 
		_alogic = true;
		_blogic = true;
		break;
	case 50:
		_alogic = false;
	    _blogic = false;
		break;
	case 51:
		_alogic = true;
		_blogic = false;
		break;
	case 52:
		_alogic = false;
		_blogic = true;
		break;
	default:cout << "неверное значение";
	}
	cout << "Введите координаты(начало и конец): " << endl;
    double st, end;
	cout << "Начало:"<<endl;
	cin >> st;
	cout << "Конец:";
	cin >> end;
	if (st < end)
	{
		_a = st;
		_b = end;
	}
	else {
		_a =end ;
		_b = st;
	}
}
interval interval::crossing(const interval &otr2)const
{
	interval res;
	if (!is_common_point(otr2))
	{
			return res;
	}
	else
	{
		if (otr2._a < _a)
		{
			res._a = _a;
			res._alogic = _alogic;
		}
		else 
		{
			res._a = otr2._a;
			res._alogic = otr2._alogic;
		}
		if (otr2._b < _b)
		{
			res._b = otr2._b;
			res._blogic =otr2._blogic;
		}
		else
		{
			res._b = _b;
			res._blogic = _blogic;
		}
	}
	return res;
}
void sdvig(int*arr,int N)
{
	
	for (size_t i = 0; i < N-1; i++)
	{
		arr[N-i-1] =arr[N-i-2] ;
	}
	arr[0] = 0;
 }








int main()
{
	/*int arr[5];
	for (size_t i = 0; i < 5; i++)
	{
		arr[i] = i+5;
	}
	sdvig(arr,5);
	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i];
	}
	getchar();*/
	setlocale(LC_ALL, "RUS");
	interval otr1;
	interval otr2;
	interval res_otr;
	while (1)
	{
		system("cls");
		cout << "[1]-Ввести проммежутки\n[2]-Показать пересечение\n[3]-Показать объединение\n [ESC]-Выход ";
		int key = getch();
		if (key == 27)
		{
			break;
		}
		switch(key)
		{
		case 49: 
			system("cls");
			otr1.input();
			otr2.input();
		    break;
		case 50:
			system("cls");
			res_otr = otr1.crossing(otr2);
			cout << "Первый отрезок" << endl;
			otr1.output_res();
			printf("\n");
			cout << "Второй отрезок" << endl;
			otr2.output_res();
			printf("\n");
			cout << "Пересечение этих  отрезков" << endl;
			res_otr.output_res();
			getchar();
			break;
		case 51:
			system("cls");
			res_otr = interval::combinstatic(otr1, otr2);
			cout << "Первый отрезок" << endl;
			otr1.output_res();
			printf("\n");
			cout << "Второй отрезок" << endl;
			otr2.output_res();
			printf("\n");
			cout << "Объединение этих  отрезков" << endl;
			res_otr.output_res();
			getchar();
			break;
		default:
			break;
		}
	}
   return 0;
}


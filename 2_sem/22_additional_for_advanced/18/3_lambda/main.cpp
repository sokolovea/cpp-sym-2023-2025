#include <iostream> 
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void myFunc(void (*lambda)(const string&))
{
	lambda("Кирилл");
}

void sendAsFuncObject(const function<void(int,int)>& func)
{
	func(77,88);
}

int main(int argc, char** argv) 
{

	// Лямбда-выражение (или просто «лямбда») позволяет определить  
	// функцию внутри другой функции.
	auto myLambda = [](const string& name)
					{
						cout << "Привет, " << name << "!" << endl;
					};
					
	myLambda("Иван");
	myLambda("Владимир");
	
	// можно передавать как параметр в другие функции (конвертируя их в указатель на функцию)
	myFunc(myLambda);
	
	/*	
	class 
	{
	public: 
		void operator ()(const string& name) const 
		{ 
			cout << "Привет, " << name << "!" << endl; 
		} 
	} myLambda;
	
	*/
	
	cout << endl;
	
	// захват контекста
	int a = 3, b = 4, c = 7, d = 6;
	
	auto gotAvg = [a,b,c]()
				{
					cout << "Минимальное значение равно " << min(min(a,b),c) << endl;
					
					// cout << d << endl; 
				};
	
	gotAvg();
	
	//захват значений по ссылке через &
	auto modThem = [&a,&b,&c]()
				{
					a = 1;
					b = 2;
					c = 3;
				};
	modThem();
	
	cout << a << " " << b << " " << c << endl;
	
	cout << endl;
	
	/*
		[&] - захватить все переменные по ссылке
		[=] - захватить все по значению
	*/
	auto printThem = [=]()
				{
					cout << a << " " << b << " " << c << " " << d << endl;
					myLambda("Ярослав"); // даже другая лямбда была захвачена!
				};
	printThem();
	
	/*
		Лямбда без захвата [] может быть преобразована к указателю на функцию,
		но с захватом - нет. Поэтому удобнее преобразовывать лямбды в специальный
		функциональный объект function из стандартной библиотеки <functional>
		синтаксис объявления:
		
		function<возвр. знач.(парам1,парам2...)>
	*/
	
	function<void(int,int)> myFuncObject = 
		[a,b](int num1, int num2)
		{
			cout << a << " " << b << " " << num1 << " " << num2 << endl;
		};
				
	sendAsFuncObject(myFuncObject);
	
	cout << endl;
	
	
	// лямбды и функциональные объекты function очень часто используются 
	// в стандартной библиотеке
	
	vector<string> months{
		"Январь",
		"Февраль",
		"Март",
		"Апрель",
		"Май",
		"Июнь",
		"Июль",
		"Август",
		"Сентябрь",
		"Октябрь",
		"Ноябрь",
		"Декабрь"
	};
	
  // Подсчитываем количество месяцев с названиями в 4 буквы
  auto fourLetterMonths = count_if(months.begin(), months.end(),
                                       [](const string& str) 
									   {
                                         return (str.length() == 4);
                                       });
 
  cout << "Всего " << fourLetterMonths << " месяца из 4 букв" << endl;
  
  return 0;
}


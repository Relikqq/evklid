/*evklid.cpp : Этот файл содержит функцию "main".Здесь начинается и заканчивается выполнение программы.

https://ru.wikipedia.org/wiki/Расширенный_алгоритм_Эвклида

*/

#include <iostream>
#include <tuple>
#include <chrono> 

static void evklid(int a, int b, int c)
{
	int temp;
	int old_s = 1, s = 0, 
		old_t = 0, t = 1,
		old_r = a, r = b;
	while (r != 0)
	{
		temp = old_r / r;
		std::tie(old_r, r) = std::make_tuple(r, old_r - temp * r);
		std::tie(old_s, s) = std::make_tuple(s, old_s - temp * s);
		std::tie(old_t, t) = std::make_tuple(t, old_t - temp * t);
	}
	/*
	в конце цикла old_s, old_t и old_r будут равны x0, y0 и nod соответсвенно из уравнения a*x0+b*y0=nod
	x=x0+k*(b/nod)
	y=y0-k*(a/nod)
	*/
	if (c % old_r != 0) { std::cout << "Impossible";}
	/*std::cout << "x: " << old_s << "y: " << old_t; */ 
	else
	{
		int x = 2147483647;
		old_s *= (c / old_r);
		old_t *= (c / old_r);
		for (int k = -1; k <= 2; k++)
		{
			int ghx = old_s + (k * (b / old_r));
			if (ghx > -1 and x > ghx)
			{
				x = ghx;
			}
		}
		int y = (c - a * x) / b;
		std::cout << " x: " << x << " y: " << y;
	}
	
}

int main()
{
	int a, b, c;
	std::cout << "a: ";
	std::cin >> a;
	std::cout << "b: ";
	std::cin >> b;
	std::cout << "c: ";
	std::cin >> c;
	auto start = std::chrono::high_resolution_clock::now();
	evklid(a, b, c);
	auto end = std::chrono::high_resolution_clock::now();

	// Вычисляем продолжительность выполнения
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds> (end - start);
	std::cout << std::endl << "time: " << duration.count() << " milliseconds" << std::endl;
	std::cout << "Maryasov Stanislav Sergeevich. Group: 090304-RPIb-o24";
}


#include "stdafx.h"
#include "Combi.h"
#include "Auxil.h"
#include "Salesman.h"

#include <iostream>
#include <ctime>

#define INF 0xFFFFF
#define N 4

int main()
{
	clock_t t1, t2;

	setlocale(LC_ALL, "rus");
	auxil::start();
	char  set[] = { 'A', 'B', 'C', 'D'};

	int** distance;
	distance = new int*[N];
	for (int i = 0; i < N; i++)
	{
		distance[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			distance[i][j] = auxil::iget(10, 300);
			if (i == j)
			{
				distance[i][j] = 0;
			}
		}
	}

	std::cout << "Исходная матрица расстояний между городами" << std::endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (distance[i][j] == INF)
			{
				std::cout << "INF\t";
			}
			else
			{
				std::cout << distance[i][j] << "\t";
			}
		}
		std::cout << std::endl << std::endl;
	}

	
	combi::Permutation perm(N);
	perm.SetFirstPerm(set);
	perm.DoPermutations();
	t1 = clock();
	salesman::FindSmallestRoute(perm, N, distance, set);
	t2 = clock();
	std::cout << "\nВремя затраченное на поиск маршрута: " << (t2 - t1) << " у.е.\n";
	system("pause");
	return 0;
}
#include "stdafx.h"
#include "Combi.h"
#include "Auxil.h"
#include "Salesman.h"

#include <iostream>

#define INF 0xFFFFF
#define N 5

int main()
{
	setlocale(LC_ALL, "rus");
	auxil::start();
	char  set[] = { '1', '2', '3', '4', '5' };

	/*int** distance;
	distance = new int*[N];
	for (int i = 0; i < N; i++)
	{
		distance[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((i == N - 3 && j == N - 7) || (i == N - 7 && j == N - 4) || (i == N - 1 && j == N - 5))
			{
				distance[i][j] = INF;
			}
			else
			{
				distance[i][j] = auxil::iget(10, 300);
			}
			if (i == j)
			{
				distance[i][j] = 0;
			}
		}
	}*/

	int** distance;
	distance = new int*[N];
	for (int i = 0; i < N; i++)
		distance[i] = new int[N];



	int Tempdistance[5][5]{ { INF, 26, 34, INF, 13 },
	{ 13, INF, 28, 55, 71 },
	{ 15, 39, INF, 86, 62 },
	{ 30, 45, 52, INF, 39 },
	{ 80, 79, 52, 26, INF } };

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			distance[i][j] = Tempdistance[i][j];

	std::cout << "»сходна€ матрица рассто€ний между городами" << std::endl;
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

	combi::Permutation perm(sizeof(set));
	perm.SetFirstPerm(set);
	perm.DoPermutations();
	/*for (int i = 0; i < perm.GetAount(); i++)
	{
		std::cout << i + 1 << ")  {";
		for (int j = 0; j < perm.GetSize(); j++)
		{
			std::cout << " " << perm.GetPerm()[i][j] << " ";
		}
		std::cout << "}" << std::endl;
	}
	*/
	salesman::FindSmallestRoute(perm, N, distance, set);

	system("pause");
	return 0;
}
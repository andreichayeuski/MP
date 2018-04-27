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
	char  set[] = { 'A', 'B', 'C', 'D', 'E' };

	int** distance;
	distance = new int*[N];
	for (int i = 0; i < N; i++)
	{
		distance[i] = new int[N];
	}
	
	
	int Tempdistance[5][5] { 
					{ INF, 10, INF, 2, 5 },  
					{ 5, INF, 42, 63, 79  },
					{ 7, 15, INF, 6, 54  },
					{ 5, INF, 20, INF, 15 },
					{ 8, 76, INF, 18, INF } 
	};

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			distance[i][j] = Tempdistance[i][j];
		}
	}

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
	for (int i = 0; i < perm.GetAount(); i++)
	{
		std::cout << i + 1 << ")  {";
		for (int j = 0; j < perm.GetSize(); j++)
		{
			std::cout << " " << perm.GetPerm()[i][j] << " ";
		}
		std::cout << "}" << std::endl;
	}

	salesman::FindSmallestRoute(perm, N, distance, set);
	
	system("pause");
	return 0;
}
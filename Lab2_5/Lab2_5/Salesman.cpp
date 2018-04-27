#include "stdafx.h"
#include "Salesman.h"

#define INF 0xFFFFF

namespace salesman
{
	void FindSmallestRoute(combi::Permutation perm, int cities, int** dest, char* set)
	{
		int min = INF, r = 0, n;
		char* rc;
		rc = new char[cities];
		int check = 0;
		for (int i = 0; i < perm.GetAount(); i++)
		{
			for (int j = 0; j < cities - 1; j++)
			{
				if ((check = dest[perm.GetPerm()[i][j]][perm.GetPerm()[i][j + 1]]) != INF)
				{
					r += dest[perm.GetPerm()[i][j]][perm.GetPerm()[i][j + 1]];
				}
				else
				{
					r = INF;
					break;
				}
			}
			r += dest[perm.GetPerm()[i][cities-1]][perm.GetPerm()[i][0]];
			if (r < min)
			{
				min = r;
				n = i;
			}
 			r = 0;
		}

		std::cout << "Расстояние: " << min << std::endl;
		std::cout << "Путь №" << n + 1 << ": ";
		
		for (int i = 0; i < cities; i++)
		{
			std::cout << set[perm.GetPerm()[n][i]] << "  ";
		}
		std::cout << set[perm.GetPerm()[n][0]] << std::endl;
	}
}
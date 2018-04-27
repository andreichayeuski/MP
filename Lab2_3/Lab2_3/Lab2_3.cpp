#include "stdafx.h"
#include <iostream>
#include "Combi.h"


int main()
{
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D'};
	std::cout << " --- Генератор перестановок ---" << std::endl;

	combi::Permutation perm(sizeof(set));
	std::cout << "Количество перестановок: " << perm.GetAount() << std::endl;

	perm.SetFirstPerm(set);
	perm.DoPermutations();
	std::cout << "Возможные варианты:" << std::endl;
	for (int i = 0; i < perm.GetAount(); i++)
	{
		std::cout << i+1 << ")  {";
		for (int j = 0; j < perm.GetSize(); j++)
		{
			std::cout << " " << set[perm.GetPerm()[i][j]] << " ";
		}
		std::cout << "}" << std::endl;
	}
	system("pause");
	return 0;
}
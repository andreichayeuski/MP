#include "stdafx.h"
#include "Combi.h"

#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	char  set[] = { 'A', 'B', 'C', 'D' };
	std::cout << std::endl << " --- Генератор размещений ---";

	std::cout << "Исходное множество: {  ";
	for (int i = 0; i < sizeof(set); i++)
	{
		std::cout << set[i] << "  ";
	}
	std::cout << "}" << std::endl;

	combi::Subs sub(sizeof(set), 3);
	sub.SetSubsInZero();
	sub.Masks();
	sub.SelectSubs();

	std::cout << "Количество cочетаний: " << sub.GetComdAmount() << std::endl;

	sub.SelectSubs();
	char **subs;
	subs = new char*[sub.GetAmount()];
	for (int i = 0; i < sub.GetComdAmount(); i++)
	{
		subs[i] = new char[sub.GetSizeOfComb()];
	}
	for (int i = 0; i < sub.GetComdAmount(); i++)
	{
		for (int j = 0, z = 0; j < 4; j++)
		{
			if (sub.GetCombs()[i][j] == '1')
			{
				subs[i][z] = set[j];
				z++;
			}
		}
	}
	std::cout << "Cочетания:" << std::endl;
	for (int i = 0; i < sub.GetComdAmount(); i++)
	{
		std::cout << i+1 << ")  {";
		for (int j = 0; j < sub.GetSizeOfComb(); j++)
		{
			std::cout << " " << subs[i][j] << " ";
		}
		std::cout << "}" << std::endl;
	}

	std::cout << std::endl << std::endl;
	combi::Permutation perm(sub.GetSizeOfComb());
	std::cout << "Количество перестановок для каждого сочетания: " << perm.GetAount() << std::endl;
	for (int z = 0; z < sub.GetComdAmount(); z++)
	{
		perm.SetFirstPerm(subs[z]);
		perm.DoPermutations();
		std::cout << std::endl << "Перестановки для сочетания " << z+1 << ":" << std::endl;
		for (int i = 0; i < perm.GetAount(); i++)
		{
			std::cout << "  " << i+1 << ".  {";
			for (int j = 0; j < perm.GetSize(); j++)
			{
				std::cout << " " << subs[z][perm.GetPerm()[i][j]] << " ";
			}
			std::cout << "}" << std::endl;
		}
	}

	system("pause");
	return 0;
}
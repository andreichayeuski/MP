#include "stdafx.h"
#include <iostream>
#include "Combi.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D'};
	std::cout << " --- Генератор множества всех подмножеств ---" << std::endl;

	combi::Subs sub(sizeof(set));
	sub.SetSubsInZero();
	sub.SetMasks();

	std::cout << "Количество подмножеств: " << sub.GetAmount() << std::endl;

	std::cout << "Подмножества:" << std::endl;
	for (int i = 0; i < sub.GetAmount(); i++)
	{ 
		std::cout << i << ")  {";
		for (int j = 0; j < sub.GetSize(); j++)
		{
			if (sub.GetSubs()[i][j] == '1')
				std::cout << " " << set[j] << " ";
		}
		std::cout << "}" << std::endl;
	}

	system("pause");
	return 0;
}
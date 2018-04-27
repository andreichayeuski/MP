//генератор сочетаний
#include "stdafx.h"
#include <iostream>
#include "Combi.h"

int main()
{
	setlocale(LC_ALL, "rus");
	char set[] = { 'A', 'B', 'C', 'D', 'E' };
	std::cout << " --- Генератор сочетаний ---" << std::endl;

	std::cout << "Исходное множество: {  ";
	for (int i = 0; i < sizeof(set); i++)
	{
		std::cout << set[i] << "  ";
	}
	std::cout << "}" << std::endl;

	combi::Subs sub(sizeof(set), 2);
	sub.SetSubsInZero();
	sub.Masks();
	sub.SelectSubs();

	std::cout << "Количество подмножеств: " << sub.GetComdAmount() << std::endl;
	
	sub.SelectSubs();
	std::cout << "Подмножества:" << std::endl;
	for (int i = 0; i < sub.GetComdAmount(); i++)
	{
		std::cout << i+1 << ") {";
		for (int j = 0; j < sub.GetSize(); j++)
		{
			if (sub.GetCombs()[i][j] == '1')
			{
				std::cout << " " << set[j] << " ";
			}
		}
		std::cout << "}" << std::endl;
	}

	system("pause");
	return 0;
}
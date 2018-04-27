#pragma once
#include "stdafx.h"
#include "Combi.h"
#include <iostream>
namespace salesman
{
	void FindSmallestRoute(
		combi::Permutation perm,	//возможные последовательности
		int cities,					//количество городов
		int** dest,					//расстояния
		char* set
	);
}
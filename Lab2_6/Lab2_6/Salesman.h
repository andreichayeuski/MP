#pragma once
#include "stdafx.h"
#include "Combi.h"
#include <iostream>
namespace salesman
{
	void FindSmallestRoute(
		combi::Permutation perm,	//��������� ������������������
		int cities,					//���������� �������
		int** dest,					//����������
		char* set
	);
}
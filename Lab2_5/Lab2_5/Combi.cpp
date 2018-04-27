#include "stdafx.h"
#include "Combi.h"

#include <iostream>

namespace combi
{
	Permutation::Permutation(int size)
	{
		this->size = size;
		int fact = 1;
		for (int i = 1; i <= size; i++)
		{
			fact *= i;
		}
		this->amount = fact;
		this->perm = new int*[this->amount];
		for (int i = 0; i < this->amount; i++)
		{
			this->perm[i] = new int[this->size];
		}
		this->turns = new int[this->size];
	}
	int Permutation::GetAount()
	{
		return this->amount;
	}
	void Permutation::SetFirstPerm(char* par)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->turns[i] = -1;
			this->perm[0][i] = i;
		}
	}
	void Permutation::DoPermutations()
	{
		int id, tmp, newID, buf;
		for (int i = 0; i < this->amount - 1; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				this->perm[i + 1][j] = this->perm[i][j];
			}
			id = this->GetIdOfMME(perm[i + 1]);
			newID = id + this->turns[id];
			std::swap(this->perm[i + 1][id], this->perm[i + 1][newID]);

			std::swap(this->turns[id], this->turns[newID]);
			this->NewTurns(newID, i + 1);
		}
	}
	void Permutation::NewTurns(int id, int z)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->perm[z][i] > this->perm[z][id])
			{
				this->turns[i] *= -1;
			}
		}
	}
	int Permutation::GetIdOfMME(int* val)
	{
		int rc = 0;
		int max = 0;
		for (int i = 0; i < this->size; i++)
		{
			if (val[i] > max)
			{
				if (abs(val[i + this->turns[i]]) < val[i])
				{
					max = val[i];
					rc = i;
				}
			}
		}
		return rc;
	}
	int** Permutation::GetPerm()
	{
		return this->perm;
	}
	int Permutation::GetSize()
	{
		return this->size;
	}
}
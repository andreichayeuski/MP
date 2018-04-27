#include "stdafx.h"
#include "Combi.h"
#include <algorithm>

namespace combi
{
	//Subs
	Subs::Subs(int psize, int sizeOfComb)
	{
		this->size = psize;
		this->amount = pow(2, this->size);
		subs = new char*[amount];
		for (int i = 0; i < amount; i++)
		{
			subs[i] = new char[this->size];
		}
		///comb
		this->sizeOfComb = sizeOfComb;
		int factN, factK;
		factN = factK = 1;
		for (int i = 1; i <= psize; i++)
		{
			factN *= i;
		}
		for (int i = 1; i <= sizeOfComb; i++)
		{
			factK *= i;
		}
		combAmount = factN / (factK*(psize - sizeOfComb));
		comb = new char*[combAmount];
		for (int i = 0; i < combAmount; i++)
		{
			comb[i] = new char[this->size];
		}
	}
	int Subs::GetSizeOfComb()
	{
		return this->sizeOfComb;
	}
	void Subs::SetSubsInZero()
	{
		for (int i = 0; i < this->amount; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				subs[i][j] = '0';
			}
			subs[i][this->size] = '\0';
		}
	}
	void Subs::SelectSubs()
	{
		int z = 0;
		for (int i = 0; i < this->amount; i++)
		{
			int counter = 0;
			for (int j = 0; j < this->size; j++)
			{
				if (this->subs[i][j] == '1')
				{
					counter++;
				}
			}
			if (counter == this->sizeOfComb)
			{
				this->comb[z] = this->subs[i];
				z++;
			}
		}
	}
	void Subs::Masks()
	{
		char *buf = new char[this->size];
		for (int i = this->amount - 1; i >= 0; i--)
		{
			int z = this->size - 1;
			_itoa(i, buf, 2);
			for (int j = this->size; j >= 0; j--)
			{
				if (buf[j] != '\0')
				{
					this->subs[i][z] = buf[j];
					z--;
				}
			}
		}
	}
	int Subs::GetAmount()
	{
		return this->amount;
	}
	int Subs::GetSize()
	{
		return this->size;
	}
	int Subs::GetComdAmount()
	{
		return this->combAmount;
	}
	char** Subs::GetSubs()
	{
		return this->subs;
	}
	char** Subs::GetCombs()
	{
		return this->comb;
	}

	//Permutation
	Permutation::Permutation(int size)
	{
		this->size = size;
		int fact = 1;
		for (int i = 1; i <= size; i++)
			fact *= i;
		this->amount = fact;

		this->perm = new int*[this->amount];
		for (int i = 0; i < this->amount; i++)
			this->perm[i] = new int[this->size];

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
		int id, newID;
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
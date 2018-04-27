#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "Combi.h"

#include <iostream>

namespace combi
{
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
		int factN, factK, factQ;
		factN = factK = factQ = 1;
		for (int i = 1; i <= psize; i++)
		{
			factN *= i;
		}
		for (int i = 1; i <= sizeOfComb; i++)
		{
			factK *= i;
		}
		for (int i = 1; i <= psize - sizeOfComb; i++)
		{
			factQ *= i;
		}
		combAmount = factN / (factK*factQ);
		comb = new char*[combAmount];
		for (int i = 0; i < combAmount; i++)
		{
			comb[i] = new char[this->size];
		}
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
};
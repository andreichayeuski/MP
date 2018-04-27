#pragma once 

namespace combi
{
	class Subs
	{
	private:
		char **subs;
		int  amount;
		int  size;
		
		//for combination
		char **comb;
		int combAmount;
		int sizeOfComb;
	public:
		//constructors
		Subs(int size, int sizeOfComd);

		//setters
		void SetSubsInZero();

		//gettesrs
		int GetAmount();
		int GetSize();
		char** GetSubs();
		int GetComdAmount();
		char** GetCombs();

		//methods
		void Masks();
		void SelectSubs();
	};
};
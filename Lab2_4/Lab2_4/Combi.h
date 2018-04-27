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
		int GetSizeOfComb();
		char** GetSubs();
		int GetComdAmount();
		char** GetCombs();

		//methods
		void Masks();
		void SelectSubs();
	};

	class Permutation
	{
	private:
		int **perm;
		int *turns;

		int size;
		int amount;

	public:
		// constructors
		Permutation(int size);

		//getters
		int GetAount();
		int GetSize();
		int** GetPerm();

		//setters
		void SetFirstPerm(char* par);

		//methods
		void DoPermutations();
		int GetIdOfMME(int* val);
		void NewTurns(int id, int z);
	};
}

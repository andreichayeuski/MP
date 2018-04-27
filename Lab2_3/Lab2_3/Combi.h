#pragma once 
namespace combi
{
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
};
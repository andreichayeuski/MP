#pragma once 

namespace combi
{
	class Subs
	{
	private:
		char **subs;
		int amount;
		int size;

	public:
		//constructors
		Subs(int size);
		
		//setters
		void SetSubsInZero();
		
		//gettesrs
		int GetAmount();
		int GetSize();
		char** GetSubs();

		//methods
		void SetMasks();
	};
};
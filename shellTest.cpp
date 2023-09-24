#include <vector>
#include <ctime>		// keep this line if you want to generate different random objects for each run
#include "stuff.h"
#include "ShellSort.h"

int main()
{
   srand(time(0));		// keep this line if you want to generate different random objects for each run
   vector<Stuff> vec;

   for (int i = 0; i < 100; i++)
	{
	   Stuff s;
	   vec.push_back(s);
	}

   for (int i = 0; i < 100; i++)
	{
	   cout << vec[i] << endl;
	}

   cout << "-----\n";

   // uncomment this line when the shell sort is implemented
   ShellSort(vec, 2);

   for (int i = 0; i < 100; i++)
	{
	   cout << vec[i] << endl;
	}

   cout << (vec[0] < vec[1]) << endl;
   cout << "compareCount : " << Stuff::compareCount << endl;
   
   return 0;

}

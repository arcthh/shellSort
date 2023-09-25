#include <vector>
#include <ctime>		// keep this line if you want to generate different random objects for each run
#include "stuff.h"
#include "ShellSort.h"
#include <fstream>

// Function to generate a random Stuff object
Stuff generateRandomStuff() {
    Stuff s;
    // Implement logic to generate random Stuff objects here
    return s;
}

// Function to generate a random vector of Stuff objects
std::vector<Stuff> generateRandomStuffVector(int numElements) {
    std::vector<Stuff> stuffVector;
    for (int i = 0; i < numElements; i++) {
        stuffVector.push_back(generateRandomStuff());
    }
    return stuffVector;
}

std::vector<std::vector<Stuff>> generateRandomStuffVectors(int numVectors, int numElementsPerVector) {
    std::vector<std::vector<Stuff>> result;
    for (int i = 0; i < numVectors; i++) {
        result.push_back(generateRandomStuffVector(numElementsPerVector));
    }
    return result;
}

int main()
{
   srand(time(0));		// keep this line if you want to generate different random objects for each run
    // Example: Generate 5 random vectors of Stuff, each with 10 elements
    int numVectors = 100;
    int numElementsPerVector = 9000;
    std::vector<std::vector<Stuff>> vec = generateRandomStuffVectors(numVectors, numElementsPerVector);

    ofstream outputFile("compareCountsn9000.csv");
    outputFile << "Observation Number, Case 0, Case 1, Case 2, Case 3, Case 4\n";

    for (int i = 0; i < numVectors; i++) {
      outputFile << i + 1 << ","; //obs number

      for (int code = 0; code <= 4; code++){
         vector<Stuff> copy = vec[i];
         ShellSort(copy, code);
         outputFile << Stuff::compareCount;

         if (code < 4) {
            outputFile << ',';
         }

         Stuff::compareCount = 0;
      }

      outputFile << '\n';
    }
    outputFile.close();
   return 0;
}

/*
int main()
{
   srand(time(0));		// keep this line if you want to generate different random objects for each run
   vector<Stuff> vec;

   for (int i = 0; i < 1000; i++)
	{
	   Stuff s;
	   vec.push_back(s);
	}

   for (int i = 0; i < 1000; i++)
	{
	   cout << vec[i] << endl;
	}

   cout << "-----\n";

   // uncomment this line when the shell sort is implemented
   ShellSort(vec, 0);

   for (int i = 0; i < 1000; i++)
	{
	   cout << vec[i] << endl;
	}

   cout << (vec[0] < vec[1]) << endl;
   cout << "compareCount : " << Stuff::compareCount << endl;
   
   return 0;

}
*/
#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "stuff.h"
#include <vector>
#include <cmath>

//this code implements shellsort to sort vector s in stuff in DESCENDING ORDER
void ShellSort(vector<Stuff> &s, int code) {
    //s is the vector to be sorted, find the length of vector
    int size = s.size();
    //create h list vector 
    std::vector<int> hlist(size);
    int k = 0;

    //code is the integer denoting how hlist array is to be formed
    switch (code) {
        //code 0 - hlist should be [1] (insertion sort)
        case 0:
            //hlist should be 1 (insertion sort)
            hlist.push_back(1);
            k = 1;
            cout << "Case 0";
            break;

        //code 1 - hlist should be  [k^2, (k-1)^2, ..., 4, 1]
        case 1:
            //increment k to be the max value for k squared
            while ((k * k) < size) {
                k++;
            }
            hlist.resize(k);

            //k is now largest value, so begin generating
            //go through, and generate other values of hlist until we get to last value
            for (int i = 0; i < k; i++) {
                //iteration seq. is k^2, (k-1)^2...
                hlist.at(i) = ((k-i) * (k-i));
            }
            cout << "Case 1";

            break;

        //code 2 - hlist should be [2^k, 2^(k-1) , 2^(k-2) , ... 2, 1] 
        case 2:
            //get the maximum number k
            while(pow(2, k) < size) {
                k++;
            }
            hlist.resize(k);

            //go through and form hlist array based on guidelines given
            for (int i = 0; i < k; i++) {
                hlist.at(i) = pow(2, k-i);
            }
             cout << "Case 2";
           
            break;

        //code 3 - hlist should be [2^k -1, 2^(k-1) -1, 2^(k-2) -1 ... 3, 1] 
        case 3:
            //get max number k
            while(pow(2, k) - 1 < size) {
                k++;
            }
            
            hlist.resize(k);
            //form hlist array based on case 1 = 2^1 - 1
            for (int i = 0; i < k; i++) {
                hlist.at(i) = pow(2, k-i) - 1;
            }
            cout << "Case 3";

            break;

        //code 4
        case 4:
            //get max number k
            while(pow(4, k+1) + (3 * pow(2,k)) + 1 < size) {
                k++;
            }
            
            //cout << "K-VALUE: " << k << endl; 
            //resize hlist to not waste memory
            hlist.resize(k + 1);
            hlist.at(0) = (1);

            //form hlist array based on code 4
            for (int i = 0; i < k; i++) {
                hlist.at(i+1) = ((pow(4, i+1) + (3 * pow(2,i)) + 1));
            }

            //check for 8 or fewer numbers in array to be sorted, list should be 1
            if (size <= 8) {
                hlist.push_back(1);
            }


            for (int i : hlist) {
                cout << i << " ";
            }

            cout << "Case 4";
            break;

        //default
        default:
            cerr << "ERROR: CODE IS INVALID\n";
            exit(1);
    }

    // Implement the Shell Sort algorithm using the generated hlist
    //Implementation of shellsort referenced from King Ip Lin's Lecture on Insertion/Shell Sort
    //hlist is list of descending number of p integers

    //autobased for loop to iterate through individual gap
    for (int gap : hlist) {
        // Perform Shell Sort with gap 
        for (int i = gap; i < size; i++) {
            //store temporary variable from vector s
            Stuff temp = s[i];
            int j = i; // j used for comparison
            // Compare and swap elements within the gap (gap) in descending order
            while (j >= gap && s[j - gap] < temp) {
                s[j] = s[j - gap]; //move element to the right
                j -= gap; // move to previous position in gap
            }

            // Insert temporarily stored element into correct position
            s[j] = temp;
        }
    }

}
#endif
//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

template<typename T>
class ShellSort {
public:
	void operator() (std::vector<T> & v) const{
		// Tokuda increments
		int f;
		int count = 0;
		std::vector<int> increments;
		while((f = ceil((9*(pow(9/4,count++))-4)/5)) <= v.size()/2){
			increments.push_back(f);
		}
		
		int k = increments.size();
		while(increments[--k]>=1){
			for(int i = increments[k]; i < v.size(); i++){
				T backup = v[i];
				int j = i-increments[k];
				while(j >= 0 && backup < v[j]){
					v[j+increments[k]] = v[j];
					j = j-increments[k];
				}
				v[j+increments[k]] = backup;
			}
		}
	}
};

int main(int argc, const char * argv[])
{
	int temp[] = {16,2,77,29, 6, 19, 15, 88};
	vector<int> array (temp, temp + sizeof(temp) / sizeof(int) );
	
	ShellSort<int> shellSort;
	shellSort(array);
	
	cout << "Sorted array is \n";
	for(int i=0; i<array.size(); i++){
		cout<<array[i]<<" ";
	}
	
    return 0;
}


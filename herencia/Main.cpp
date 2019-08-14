#include <iostream>
#include "Array.h"

int main() {
	Array arr (16);
	Array arr1(arr);
	
	

	std::cout << "Sizeof(Array) is " << sizeof(Array) << "\n"
		<< "Sizeof(int) is " << sizeof(int ) << "\n"
		<< "Sizeof(int*) is " << sizeof(int*) << "\n";

	for (int i = 0; i < arr.getsize(); i++) {
		arr[i] = i * 10;
	}

	for (int i = 0; i < arr.getsize(); i++) {
		std::cout << arr[i] << " ";
	}
	
	std::cout << "\n";
	for (int i = 0; i < arr1.getsize(); i++) {
		arr[i] = (i+1) * 100;
	}

	for (int i = 0; i < arr1.getsize(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";



	Array arr2;
	arr2 = arr1;

	for (int i = 0; i < arr2.getsize(); i++) {
		std::cout << arr2[i] << " ";
	}

	system("pause");
}
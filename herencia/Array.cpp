#include "Array.h"

Array::Array(int sz):size(sz) {

	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = 0;
	}

}

void Array::copyFrom(const Array& other) {

	size = other.size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}
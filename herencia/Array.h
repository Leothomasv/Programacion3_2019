#pragma once



class Array {
public:
	Array() :size(0), data(nullptr) {};
	
	Array(int size);

	Array(const Array& other);

	~Array() { delete[] data; }


	int& operator[] (int index) {
		return data[index];
	}

	void operator = (Array& other) {
		copyFrom(other);
	}

	int getsize() {
		return size;
	}
private:
	int size;
	int *data;
	void copyFrom(const Array& other);
};








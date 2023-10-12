#ifndef __BOUNDCHECKARRAY_H__
#define __BOUNDCHECKARRAY_H__

template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& ref) {}
	BoundCheckArray& operator=(const BoundCheckArray& ref) {}

public:
	BoundCheckArray(int len = 100);

	T& operator[](const int idx);
	T operator[](const int idx) const;
	int GetLen() const;

	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) :arrlen(len) {
	arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[](const int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array iddex out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](const int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array iddex out of bound exception" << endl;
		exit(1);
	}

	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetLen() const {
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[] arr;
}

#endif
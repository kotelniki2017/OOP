// Рождественский, задание 1.1
#include <iostream>
#include "stdlib.h"
#include <windows.h> 

using namespace std;

int main() {
	int cache;
	int l = 100;
	int *n = new int[l];
	for (int i = 0; i < 1000; i++) {
		n[i] = i;
		cout << n[i] << endl;
		Sleep(50);
	}

	for (int i = 2; i < l; i++) {

		if (n[i] != 0) {
			for (int j = n[i]*2; j < l; j += n[i]) n[j] = 0;
		}
	}
	
	for (int i = 0; i < l; i++) {
		if (n[i] != 0)
			cout << n[i] << endl;
	}

	system("pause");
	delete[]n;
	return 0;
}
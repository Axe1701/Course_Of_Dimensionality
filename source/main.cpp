#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include <cmath>

//int e = 10000; /*int e = 15000; */
/*int e = 20000; */int e = 25000;
//int d = 4; int d = 6;
//int d = 8; //int d = 10; 
/*int d = 12;*/ int d = 18; 
//int d = 20;

using namespace std;

void d_e(vector<vector<int>>& edant) {//distancia euclidiana
	int aux = 0;
	for (int i = 0; i < e; i++) { //vector A
		for (int j = i + 1; j < e; j++, aux = 0) { //vector B
			for (int k = 0; k < d; k++) { 
				aux += pow( (edant[j][k]-edant[i][k]) , 2); //suma de (B[k]-A[k])^2
			}
			aux = sqrt(aux);
		}
	}
}

void fill(vector<vector<int>> &edant) { //rellenar vectores con aleatorio
	for (int i = 0; i < e; i++) {
		for (int j = 0; j < d; j++) {
			edant[i].push_back(rand() % 100);
		}
	}
}

int main(){
	srand(time(NULL));	

	vector<vector<int>> edant(e);
	fill(edant);

	auto start = chrono::system_clock::now();
	d_e(edant);
	auto end = chrono::system_clock::now();

	chrono::duration<double, milli> duration = end - start;
	cout << "Tiempo empleado en trabjar: " << duration.count()<< endl;

	return 0;
}

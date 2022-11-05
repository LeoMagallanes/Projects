#include <bits/stdc++.h>
#include <ctime>
#include<stdio.h>
//#include <chrono>
//#include <thread>
//#include "Stopwatch.h"

using namespace std;
/*
Heap sort recuperado de: https://prepinsta.com/cpp-program/heap-sort/
radix sort recuperado de: https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/#:~:text=%20Radix%20Sort%20Algorithm%20with%20C%2B%2B%20Code%20%7C,to%20Implement%20Radix%20Sort%20%E2%80%93.%20%20More%20
*/

//prototipos de funciones
void imprimirMenuInicial();
int validarMenu(int);
void menuOrdenamientos();
int validarMenuOrdenamientos(int);
void randomArray(vector<int> &, int);

void burbuja(vector<int> &, int);
void metodosOrdenamiento(vector<int> &, int, int,int,int);
void seleccion(vector<int> &, int);
void insercion(vector<int> &,int);
void countingSort(vector<int> &, int);
int getMax(vector<int>, int);
void heapSort(vector<int> &, int);
void heapify(vector<int> &, int, int);
void quickSort(vector<int> &, int, int);
int partition(vector<int> &, int, int);
void radixSort(vector<int> &, int);
void CountSort(vector<int> &, int, int);
void mergeSort(vector<int> &, int, int);
void merge(vector<int> &, int, int, int);

/*struct Timer{
	std::chrono::time_point<std::chrono::steady_clock> start,end;
	std::chrono::duration<float> duration;
	
	Timer(){
		start = std::chrono::high_resolution_clock::now();
	}
	
	~Timer(){//deconstructor
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		
		float ms = duration.count() * 1000.0f;
		cout << "Duracion: " << ms <<"ms" << endl;
	}
};*/

int main() {
	int opcion = 0, range = 0;
	long long tam = 0;
	cout << "Hola bienvenidos a mi proyecto del curso de estructuras y algoritmos\n";
	cout << "Vamos a hacer un analisis y comparaciones de los metodos de ordenamiento y busqueda\n\n ";
	
	do{
		opcion = validarMenu(opcion);//Validamos que opcion este en el rango
		
		//switch 1
		switch (opcion) {
			case 1: {
				opcion = validarMenuOrdenamientos(opcion);
				
				//sub switch 2 ordenamientos
				switch (opcion) {
					case 1: {//Prueba individual
						int count = 0, reps = 0, gendatos = 0;
						cout << "\nIngrese el numero de repeticiones\n";
						cin >> reps;
						
						for(int i = 0; i < reps; i++){
							cout << "Ingrese el tamanio de su vector" << endl;
							cin >> tam;

							vector<int> array(tam);
							int n = sizeof(array)/sizeof(array[0]);
							randomArray(array, tam);//Llenado vector aleatorio
						
							metodosOrdenamiento(array, tam, opcion, range, tam);
						}//end for
						break;
					}//end case 1 subwitch 2 ordenamientos
					case 2: {//Pruebas grupales			
							cout << "Ingrese el tamanio de su vector" << endl;
							cin >> tam;
							vector<int> v(tam);
							randomArray(v, tam);

						break;
					}//end case 2 subswitch 2 ordenamientos.				
					case 0:{
						int validacion = -1;
						cout << "Seguro que quieres salir(si pon 0): " << endl;
						cin >> validacion;
						if (validacion == 0) {
							return 0;
						}
					}
					break;//break switch principal case 1:
				} // End subswitch 2 ordenamientos
			}//end case 1 switch principal
			case 2:{ // Start case 2 switch principal. Pruebas Todos.
				int n;
				cout << "Ingrese el tamaño de su vector\n";
				cin >> n;
				vector<int> v(n);

				randomArray(v, tam);//Llenado vector aleatorio
				
				
				break;
			}//end case 2 switch principal
			
			case 0:{
				int validacion = -1;
				cout << "Seguro que quieres salir(si pon 0): " << endl;
				cin >> validacion;
				if (validacion == 0) {
					return 0;
				}
				break;
			}//end case 0 switch principal
				
		}//end switch principal
	} while (opcion != 0); //End do while
	
	return 0;
}//end main

//Definicion de funciones
void imprimirMenuInicial() {
	cout << "Elige con que metodos quieres empezar.\n";
	cout << "1) Metodos de ordenamiento.\n";
	cout << "2) Metodos de busqueda\n";
	cout << "0) Salir\n";
}

int validarMenu(int opcion) {
	imprimirMenuInicial();//Imprime el 1er menu
	cin >> opcion;
	while (opcion < 0 || opcion > 2) { // Validar el input del usuario.
		cout << "Ingrese un numero en el rango de 0-2\n";
		cin >> opcion;
	}
	return opcion;
}

void menuOrdenamientos() {
	cout <<  "\nCon que pruebas quieres comenzar?\n";
	cout << "1) Pruebas individuales\n";
	cout << "2) Pruebas grupales\n";
	cout << "0) Salir\n";
}

int validarMenuOrdenamientos(int opcion) {
	menuOrdenamientos();
	cin >> opcion;
	while (opcion < 0 || opcion > 2) { //Validar el input
		cout << "Ingrese un numero en el rango de 0 - 3\n";
		cin >> opcion;
	}
	return opcion;
}
void randomArray(vector<int> &array, int tam) {//Generate random array
	int aleatorio = 0, sup = 0, inf = 0, n = 0;
	srand(time(NULL));
	cout << "numero aleatorio\n";
	cout << "Ingrese el limite inferior\n";
	cin >> inf;
	cout << "Ingrese el limite superior\n";
	cin >> sup;
	
	for (int i = 0; i < tam; i++){
		aleatorio = inf + rand() % (sup + 1 - inf);
		array[i] = aleatorio;
	}
}


//switch metodos ordenamiento
void metodosOrdenamiento(vector<int>& array, int tam, int opcion, int range, int n) {
	cout << "\nQue metodo quieres probar?\n";
	cout << "1)------Bubble Sort-------\n";
	cout << "2)-----Selection Sort-----\n";
	cout << "3)-----Insertion Sort-----\n";
	cout << "4)------Counting Sort-----\n";
	cout << "5)-------Heap Sort--------\n";
	cout << "6)-------Quick Sort-------\n";
	cout << "7)---------Radix----------\n";
	cout << "8)-------Merge Sort-------\n";
	cin >> opcion;
	
	unsigned t0, t1;
	double time = 0;
	switch (opcion) {	
	case 1: {
		t0 = clock();
		burbuja(array, tam);
		t1 = clock();

		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}
	case 2:{
		t0 = clock();
		seleccion(array, tam);
		t1 = clock();
		
		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}	
	case 3:{
		t0 = clock();
		insercion(array, tam);
		t1 = clock();

		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}	
	case 4:{
		t0 = clock();
		countingSort(array, tam);
		t1 = clock();

		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}		
	case 5: {
		t0 = clock();		
		heapSort(array, n);
		t1 = clock();

		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}	
	case 6:{
		t0 = clock();		
		quickSort(array, 0, n - 1);		
		t1 = clock();

		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}
	case 7:{
		t0 = clock();
		radixSort(array, tam);
		t1 = clock();

		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}
	case 8:{
		t0 = clock();			
		mergeSort(array, 0, tam);			
		t1=clock();

		time = double(t1 - t0) / CLOCKS_PER_SEC;
		cout << "Tiempo de ejecucion: " << time << "\n";
		break;
	}
	}//end switch
}

//metodos de ordenamiento
void burbuja(vector<int> &array, int tam) {
	int auxiliar;

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam - 1; j++) {//El tam -1 lo hacemos para no estar iterando siempre el array completo
			if (array[j] > array[j + 1]) {
				auxiliar = array[j];
				array[j] = array[j + 1];
				array[j + 1] = auxiliar;
			}
		}
	}
}
void seleccion(vector<int>& array, int tam) {
	int min = 0, auxiliar;
	
	for (int i = 0; i < tam; i++){
		min = i;
		for (int j = i + 1; j < tam; j++){
			if (array[j] < array[min]){
				min = j;
			}
		}
		auxiliar = array[i];//Despues se le puede agregar un if para preguntar
		array[i] = array[min];//Si vector[min] es igual a vector[i]
		array[min] = auxiliar;
	}
}
void insercion(vector<int>& array, int tam) {
	for (int i = 1, aux = 0; i < tam; i++){
		for (int j = i; j > 0; j--) {
			if (array[j] < array[j - 1]) {
				aux = array[j];
				array[j] = array[j - 1];
				array[j - 1] = aux;
			}
		}
	}
}
void countingSort(vector<int>& array, int size) {
	vector<int> output(size + 1);
	int max = getMax(array, size);
	vector<int> count(max + 1); //create count array (max+1 number of elements)

	for(int i = 0; i <= max; i++)
		count[i] = 0;     //initialize count array to all zero

	for(int i = 1; i <= size; i++)
    	count[array[i]]++;     //increase number count in count array.

	for(int i = 1; i <= max; i++)
    	count[i] += count[i-1];     //find cumulative frequency

	for(int i = size; i >= 1; i--) {
    	output[count[array[i]]] = array[i];
    	count[array[i]] -= 1; //decrease count for same numbers
   }

	for(int i = 1; i <= size; i++) 
    	array[i] = output[i]; //store output array to main array
}
int getMax(vector<int> array, int size) {
	sort(array.begin(), array.end());
   	return array.back(); //the max element from the array
}
void heapify(vector<int>& array, int n, int root){
	int largest = root; // root is the largest element
	int l = (2 * root) + 1; // left = 2*root + 1
	int r = (2 * root) + 2; // right = 2*root + 2
  
	if (l < n && array[l] > array[largest]) // If left child is larger than root
		largest = l;
  
	if (r < n && array[r] > array[largest])// If right child is larger than largest so far
		largest = r;
  
	if (largest != root){// If largest is not root
    	swap(array[root], array[largest]);//swap root and largest
    	heapify(array, n, largest);// Recursively heapify the sub-tree
    }
}
void heapSort(vector<int>& array, int n){
	// build heap
	for (int i = n / 2 - 1; i >= 0; i--)
	heapify(array, n, i);
  
	for (int i=n-1; i>=0; i--){ // extracting elements from heap one by one
    	swap(array[0], array[i]);// Move current root to end
  
      // again call max heapify on the reduced heap
    	heapify(array, i, 0);
   	}
}
void quickSort(vector<int>& array, int low, int high){
	cout << "quickSort\n";
    if (low < high){
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}
int partition(vector<int>& array, int low, int high){
    int pivot = array[low]; 
    int i = low;  // Index of smaller element
	int j = high; // Index of larger element

	while(i < j){
		while(array[i] <= pivot){
			i++;
		}
		while(array[j] > pivot){
			j--;
		}
		if(i < j){
			swap(array[i], array[j]);
		}
	}
	swap(array[j], pivot);
	return j;
}

void radixSort(vector<int>& array, int n){
  int exp, i;
  i = getMax(array, n);
  for (exp = 1; i/exp > 0; exp *= 10)
    CountSort(array, n, exp);
}

void CountSort(vector<int>& array, int n, int exp){  
	int i;
	vector<int> result(n), count(10, 0);
 
  	// Counting occurence of digits
	for (i = 0; i < n; i++)
    	count[(array[i] / exp) % 10]++;
 
  	// Changing the position of count so that it appears at actual position in result.
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 
	// Resultant output array
	for (i = n - 1; i >= 0; i--){
    	result[count[(array[i] / exp) % 10] - 1] = array[i];
    	count[(array[i] / exp) % 10]--;
  	}
	for (i = 0; i < n; i++)
		array[i] = result[i];
}

void mergeSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int middle = low + (high - low) / 2; //calculating middle index of array to divide it in two halves
        mergeSort(array, low, middle); //sorting first half
        mergeSort(array, middle + 1, high); //sorting second half
        merge(array, low, middle, high); //merging 2 sorted halves
    }
}

void merge(vector<int>& array, int low, int mid, int high) {
    int elIzq = mid - low + 1, elDer = high - mid; 

	vector<int> izq(elIzq), der(elDer);
	for(int i = 0; i < elIzq; i++){
		izq[i] = array[low + i];
	}
	for(int i = 0; i < elDer; i++){
		der[i] = array[high + 1 + i];
	}

	int i = 0, j = 0, k = low;
	while(i < elIzq && j < elDer){ //Mientras no se hayan recorrido ninguno de los arreglos.
		if(izq[i] <= der[j]){
			array[k] = izq[i];
			i++; 
		}else{
			array[k] = der[j];
			j++;
		}
		k++;
	}

	while(i < elIzq){
		array[k] = izq[i];
		i++;
		k++;
	}
	while(j < elDer){
		array[k] = der[j];
		j++;
		k++;
	}
}
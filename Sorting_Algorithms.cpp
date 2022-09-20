#include <bits/stdc++.h>
#include <ctime>
#include<stdio.h>
//#include <chrono>
//#include <thread>
//#include "Stopwatch.h"

using namespace std;
/*Quick sort recuperado de: https://www.geeksforgeeks.org/cpp-program-for-quicksort/
Merge sort recuperado de: https://www.codespeedy.com/merge-sort-in-cpp-divide-and-conquer-algorithm/
Heap sort recuperado de: https://prepinsta.com/cpp-program/heap-sort/
radix sort recuperado de: https://simplesnippets.tech/radix-sort-algorithm-with-c-code-sorting-algorithms-data-structures-algorithms/#:~:text=%20Radix%20Sort%20Algorithm%20with%20C%2B%2B%20Code%20%7C,to%20Implement%20Radix%20Sort%20%E2%80%93.%20%20More%20
*/


//prototipos de funciones
void imprimirMenuInicial();
int validarMenu(int);
void menuOrdenamientos();
int validarMenuOrdenamientos(int);
void menuGeneracionDatos();
int validarMenuGeneracionDatos(int);
void randomArray(int[],int,int);

void burbuja(int[], int);
void metodosOrdenamiento(int[], int, int,int,int);
void seleccion(int[], int);
void insercion(int[],int);
void countingSort(int[],int);
int getMax(int[],int);
void heapSort(int[],int);
void heapify(int[],int,int);
void quickSort(int[],int,int);
int partition(int[],int,int);
void swap(int*,int*);
void radixSort(int[],int);
void CountSort(int[],int,int);
void mergeSort(int[],int,int);
void merge(int[],int,int,int);

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

unsigned t0,t1;
int main() {
	int opcion=0,tam=0,range=0;
	cout << "Hola bienvenidos a mi proyecto del curso de estructuras y algoritmos" << endl;
	cout << "Vamos a hacer un analisis y comparaciones de los metodos de ordenamiento y busqueda " << endl << endl;

	
	do{
		opcion = validarMenu(opcion);//Validamos que opcion este en el rango
		
		//switch 1
		switch (opcion) {
		case 1: {
			
			opcion = validarMenuOrdenamientos(opcion);
			
			//sub switch 2 ordenamientos
			switch (opcion) {
			case 1: {
				//Prueba individual
				int count = 0, reps = 0, gendatos = 0;
				
				
			
				cout << endl << "Ingrese el numero de repeticiones" << endl;
				cin >> reps;
				
				for(int i=0;i<reps;i++){
				
					cout << "Ingrese el tama�o de su vector" << endl;
					cin >> tam;
				
					int array[tam];
					int n = sizeof(array)/sizeof(array[0]);

					opcion = validarMenuGeneracionDatos(opcion);//Validamos que opcion este en el rango
				
					
					//subwitch 3 generacion array
					switch(opcion) {
					case 1: 
						for (int i = 0; i < tam - 1; i++) {//llenado vector a mano
							cout << "Ingrese el elemento " << i + 1 << " del arreglo" << endl;
							cin >> array[i];
						}
					break;//end case 1 subswitch 2 generacionDatos
				
					case 2: {
						randomArray(array, tam,range);//Llenado vector aleatorio
						/*cout << endl << "El arreglo es: "<< endl;
						for (int i = 0; i < tam; i++) {
							cout << array[i] << ", ";
						}*/
					}
					break;//end case 2 subswitch 2 generacionDatos
			
					}//end subswitch 2 generacionDatos
				
					cout << endl;
					
					metodosOrdenamiento(array,tam,opcion,range,n);
					
					//calculo de tiempo
					
					//double seconds_since_start = difftime( time(0), start);
					//cout << "Tiempo en ordenar: " << seconds_since_start << endl;
					//estadisticas
					//tiempo- mayor, promedio, menor
					
					/*cout << endl << "El arreglo ordenado es: "<< endl;
					for (int i = 0; i < tam; i++)
					{
						cout << array[i] << " ";
					}
					cout << endl;*/
				
				}//end for
			}//end case 1 subwitch 2 ordenamientos
			break;
			
			
			case 2: {//Pruebas grupales
			
				cout << "hola" << endl;
			}//end case 2 switch principal
			break;//end case 2 subswitch ordenamientos
			
			
			case 3:{//Pruebas grupales 3 metodos de mi eleccion
				cout << "hola" << endl;
				
			}
			break;//end case 3 subswitch ordenamientos
			
				
			case 0:{
				int validacion = -1;
				cout << "Seguro que quieres salir(si pon 0): " << endl;
				cin >> validacion;
				if (validacion == 0) {
					return 0;
				}
			}
			break;//end case 0 switch 2 
			default:
				cout << "hola" << endl;
				break;//end default subswitch ordenamientos

				
			}//end sub switch 2 ordenamientos


		}//end case 1 switch principal
		break;//break switch principal case 1:
		
		
		case 2:{
			
			break;
		}//end case 2 switch principal
		
		
		case 0:{
			int validacion = -1;
			cout << "Seguro que quieres salir(si pon 0): " << endl;
			cin >> validacion;
			if (validacion == 0) {
			return 0;
			}
		}
			break;//end case 0 switch principal
		
		}//end switch principal
		
	} while (opcion != 0);
	
	return 0;
}//end main

//Definicion de funciones
void imprimirMenuInicial() {
	cout << "Elige con que metodos quieres empezar: " << endl;
	cout << "1) Metodos de ordenamiento" << endl;
	cout << "2) Metodos de busqueda" << endl;
	cout << "0) Salir" << endl;
}

int validarMenu(int opcion) {
	imprimirMenuInicial();//Imprime el 1er menu
	cin >> opcion;
	while (opcion < 0 || opcion > 2) {
		cout << "Ingrese un numero en el rango de 0-2" << endl;
		cin >> opcion;
	}
	return opcion;
}

void menuOrdenamientos() {
	cout << endl << "�Con que pruebas quieres comenzar?" << endl;
	cout << "1) Pruebas individuales" << endl;
	cout << "2) Pruebas grupales" << endl;
	cout << "3) Pruebas grupales con Quick sort..." << endl;
	cout << "0) Salir" << endl;
}

int validarMenuOrdenamientos(int opcion) {
	menuOrdenamientos();
	cin >> opcion;
	while (opcion < 0 || opcion > 3) {
		cout << "Ingrese un numero en el rango de 0-3" << endl;
		cin >> opcion;
	}
	return opcion;
}

void menuGeneracionDatos() {
	cout << endl << "�Quieres ingresar los datos a mano o que se generen aleatoriamente?" << endl;
	cout << "1) a mano" << endl;
	cout << "2) aleatoriamente" << endl;
	cout << "0) salir" << endl << endl;
}

int validarMenuGeneracionDatos(int opcion) {
	menuGeneracionDatos();
	cin >> opcion;
	while (opcion < 0 || opcion > 2) {
		cout << "Ingrese un numero en el rango de 0-2" << endl;
		cin >> opcion;
	}
	return opcion;
}

void randomArray(int array[],int tam,int range) {
	int aleatorio, sup = 0, inf = 0, n = 0;
	srand(time(NULL));
	cout << "numero aleatorio" << endl;
	cout << "Ingrese el limite inferior " << endl;
	cin >> inf;
	cout << "Ingrese el limite superior " << endl;
	cin >> sup;
	range = sup;
	
	for (int i = 0; i < tam; i++){
		aleatorio = inf + rand() % (sup + 1 - inf);
		array[i] = aleatorio;
	
	}
}


//switch metodos ordenamiento
void metodosOrdenamiento(int array[],int tam,int opcion,int range,int n) {
	
	cout << "Que metodo quieres probar?" << endl;
	cout << "1)------Bubble Sort-------" << endl;
	cout << "2)-----Selection Sort-----" << endl;
	cout << "3)-----Insertion Sort-----" << endl;
	cout << "4)------Counting Sort-----" << endl;
	cout << "5)-------Heap Sort--------" << endl;
	cout << "6)-------Quick Sort-------" << endl;
	cout << "7)---------Radix----------" << endl;
	cout << "8)-------Merge Sort-------" << endl;
	cin >> opcion;
	
	//start = time(0);
	switch (opcion) {	
	case 1: {
		t0=clock();
		
		burbuja(array, tam);
		
		t1=clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
	}
		break;//end case 1
	
	case 2:{
		t0=clock();
		seleccion(array, tam);
		t1=clock();
		
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
	}
		break;
		
	case 3:{
		t0=clock();
		
		insercion(array, tam);
		
		t1=clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
	}
		break;
		
	case 4:{
		t0=clock();
		
		countingSort(array, tam);
		
		t1=clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
	}
		break;
			
	case 5: {
		t0=clock();
		
		heapSort(array,n);
		
		t1=clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
	}
		break;
		
	case 6:{
		t0=clock();
		
		quickSort(array,0,n-1);
		
		t1=clock();
		double time = (double(t1-t0)/CLOCKS_PER_SEC);
		cout << "Tiempo de ejecucion: " << time << endl;
		break;
	}
	
		case 7:{
			t0=clock();
			
			radixSort(array,tam);
			
			t1=clock();
			double time = (double(t1-t0)/CLOCKS_PER_SEC);
			cout << "Tiempo de ejecucion: " << time << endl;
			break;
		}
		
		case 8:{
			t0=clock();
			
			mergeSort(array, 0, tam);
			
			t1=clock();
			double time = (double(t1-t0)/CLOCKS_PER_SEC);
			cout << "Tiempo de ejecucion: " << time << endl;
			break;
		}
			
		
		
	}//end switch
	
	
	
}

//metodos de ordenamiento
void burbuja(int vector[], int tam) {
	//Timer timer;
	int auxiliar;
	//count time
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam - 1; j++) {//El tam -1 lo hacemos para no estar iterando siempre el array completo
			if (vector[j] > vector[j + 1]) {
				auxiliar = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = auxiliar;
			}
		}
	}
	//end count time
}
void seleccion(int vector[], int tam) {
	int min = 0, auxiliar;
	//
	for (int i = 0; i < tam; i++)
	{
		min = i;
		for (int j = i + 1; j < tam; j++)
		{
			if (vector[j] < vector[min])
			{
				min = j;
			}
		}
		auxiliar = vector[i];//Despues se le puede agregar un if para preguntar
		vector[i] = vector[min];//Si vector[min] es igual a vector[i]
		vector[min] = auxiliar;
	}
}

void insercion(int vector[], int tam) {
	for (int i = 1, aux = 0; i < tam; i++){
		for (int j = i; j > 0; j--) {
			if (vector[j] < vector[j - 1]) {
				aux = vector[j];
				vector[j] = vector[j - 1];
				vector[j - 1] = aux;
			}
		}
	}
}

void countingSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];     //create count array (max+1 number of elements)
   for(int i = 0; i<=max; i++)
      count[i] = 0;     //initialize count array to all zero
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     //increase number count in count array.
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];     //find cumulative frequency
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; //decrease count for same numbers
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; //store output array to main array
   }
}

int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; //the max element from the array
}

void heapify(int arr[], int n, int root){
   int largest = root; // root is the largest element
   int l = 2*root + 1; // left = 2*root + 1
   int r = 2*root + 2; // right = 2*root + 2
  
   // If left child is larger than root
   if (l < n && arr[l] > arr[largest])
   largest = l;
  
   // If right child is larger than largest so far
   if (r < n && arr[r] > arr[largest])
   largest = r;
  
   // If largest is not root
   if (largest != root){
      //swap root and largest
      swap(arr[root], arr[largest]);
  
      // Recursively heapify the sub-tree
      heapify(arr, n, largest);
      }
}

void heapSort(int arr[], int n){
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
   heapify(arr, n, i);
  
   for (int i=n-1; i>=0; i--)// extracting elements from heap one by one
   {
      // Move current root to end
      swap(arr[0], arr[i]);
  
      // again call max heapify on the reduced heap
      heapify(arr, i, 0);
   }
}

void quickSort(int arr[], int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);
 
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition (int arr[], int low, int high){
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++){
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot){
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void radixSort(int a[], int n){
  int exp, i;
  i = getMax(a, n);
  for (exp = 1; i/exp > 0; exp *= 10)
    CountSort(a, n, exp);
}

void CountSort(int a[], int n, int exp){  
  int result[n], i, count[10] = {0};
 
  // Counting occurence of digits
  for (i =0; i <n; i++)
    count[(a[i] / exp) % 10]++;
 
  // Changing the position of count so that it appears at actual position in result.
  for (i =1; i<10; i++)
    count[i] += count[i-1];
 
  // Resultant output array
  for (i =n-1; i>= 0; i--){
    result[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }
  for (i =0; i <n; i++)
    a[i] = result[i];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2; //calculating middle index of array to divide it in two halves
        mergeSort(a, low, middle); //sorting first half
        mergeSort(a, middle + 1, high); //sorting second half
        merge(a, low, middle, high); //merging 2 sorted halves
    }
}

void merge(int a[], int low, int mid, int high) {
	
    int i = low, j = mid + 1, index = low, temp[high], k;
    while ((i <= mid) && (j <= high)) {
        if (a[i] < a[j]) {
            temp[index] = a[i];
            i++;
        }else {
            temp[index] = a[j];
            j++;
        }
        index++;
    }
    //copy the remaining elements of right array
    if (i > mid) {
        while (j <= high) {
            temp[index] = a[j];
            j++;
            index++;
        }
    }else{ //remaining elements of left array{
        while (i <= mid) {
            temp[index] = a[i];
            i++;
            index++;
        }
    }
    for (int k = low; k < index; k++){ //copying into original array{
        a[k] = temp[k];
    }   
}
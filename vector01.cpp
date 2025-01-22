#include <iostream>
using namespace std;

int gVect[100]; // Buffer to save the elements
int gnCount=0; // Counter to know the number of elements used

void Insert(int elem)
{
	if( gnCount < 100 ) // we can only insert if there is space
		gVect[gnCount++] = elem; // Insert the element at the end
}

void Display()
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < gnCount; i++) 
	{
		cout << gVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << gnCount <<endl;
}

int search(int a){
	for (int i = 0; i < gnCount; i++)
	{
		if(gVect[i] == a){  // SI ENCUENTRA EL VALOR, DEVUELVE POSICION
			return i;
		}
	}
	return -1;  // SINO DEVUELVE -1 
}

void borrar(int b){
	int posicion = search(b);
	// if(posicion != -1 && gnCount > 1){
	// 	for (int i = posicion; i < gnCount; i++){
	// 		gVect[i] = gVect[i+1];
	// 		gnCount--;
	// 	}
	// }
	if (posicion != -1){
		for (int i = posicion; i < gnCount -1; i++)
		{
			gVect[i] = gVect[i+1];
		}
		gnCount--;
		if (gnCount == 0){
			gVect[0] = 0; // "limpiamos" la posicion asignando un valor de  0  
		}
	}
}

int main(int argc, char *argv[]) 
{

	Insert(10);  // Insert element 10
	// Insert(20);  // Insert element 20
	// cout<< "20 encontrado en "<< search(20)<<endl ;
	// Insert(30);  // Insert element 30
	
	Display();
	// Display();  // Display the elements in the array
	borrar(10);
	Display();
	
	return 0;
}

/****************
Tarea 1 es borrar

	gVect : 10, 20, 30

    Delete(20)
	Se supone que primero deben buscar el elemento Search()

	gVect : 10, 30

*****************/
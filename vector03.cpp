#include <iostream>
using namespace std;

struct Vector
{
	int*m_pVect, // Pointer to the buffer
		m_nCount, // Control how many elements are actually used
		m_nMax, // Control how many are allocated as maximum
		m_nDelta; // To control the growing
};

void Resize(Vector *pThis);


void Insert(Vector *pThis, int elem)
{
	if( pThis->m_nCount == pThis->m_nMax )
		Resize(pThis);
	
	pThis->m_pVect[pThis->m_nCount++] = elem;
}
void Resize(Vector *pThis)
{
	
	const int delta = 5; // Used to increase the vector size
	int *pTemp, i;
	pTemp = new int[pThis->m_nMax + pThis->m_nDelta]; // Alloc a new vector
	for(i = 0 ; i < pThis->m_nMax ; i++) // Transfer the elements
		pTemp[i] = pThis->m_pVect[i]; // we can also use the function memcpy
	delete [ ] pThis->m_pVect; // delete the old vector
	pThis->m_pVect = pTemp; // Update the pointer
	pThis->m_nMax += pThis->m_nDelta; // The Max has to be increased by delta
	
	
//	pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta)); (REVISARRR)
//	pThis->m_nMax += pThis->m_nDelta;
}

void Display(Vector *pThis)
{
	cout << "Elementos en el arreglo: ";
	for (int i = 0; i < pThis->m_nCount; i++) 
	{
		cout << pThis->m_pVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << pThis->m_nCount <<endl;
}


int search(Vector *pThis, int a){
	for (int i = 0; i < pThis-> m_nCount; i++)
	{
		if(pThis-> m_pVect[i] == a){  // SI ENCUENTRA EL VALOR, DEVUELVE POSICION
			return i;
		}
	}
	return -1;  // SINO DEVUELVE -1 
}

void borrar(Vector *pThis, int b){
	int posicion = search(pThis, b);
	if (posicion != -1){
		for (int i = posicion; i < pThis-> m_nCount -1; i++)
		{
			pThis-> m_pVect[i] = pThis-> m_pVect[i+1];
		}
		pThis-> m_nCount--;
		if (pThis-> m_nCount == 0){
			pThis-> m_pVect[0] = 0; // "limpiamos" la posicion asignando un valor de  0  
		}
	}
}

int main(int argc, char *argv[]) 
{
	Vector myVect;
	myVect.m_pVect = nullptr;  // sino inicializo el puntero da error 
	myVect.m_nCount = 0;
	myVect.m_nMax = 0;
	myVect.m_nDelta = 5;
	
		
	Insert(&myVect, 10);  // Insert element 10
	Insert(&myVect, 20);  // Insert element 10
	Insert(&myVect, 30);  // Insert element 10
		
	Display(&myVect);  // Display the elements in the array

	borrar(&myVect, 20);
	Display(&myVect);
	
	delete[] myVect.m_pVect; // 
	return 0;
}

/****************
Tarea 1 es borrar
	
gVect : 10, 20, 30

Delete(20)
Se supone que primero deben buscar el elemento Search()

gVect : 10, 30

*****************/

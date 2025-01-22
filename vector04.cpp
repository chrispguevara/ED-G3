#include <iostream>
using namespace std;

//ClassCVectordefinition
class CVector
{
    private:
    int*m_pVect, //Pointertothebuffer
        m_nCount, //Controlhowmanyelementsareactuallyused
        m_nMax, //Control howmanyareallocatedasmaximum
        m_nDelta; //Tocontrolthegrowing
    void Init(int delta);// Initourprivatevariables,etc
    void Resize(); // Resizethevectorwhenoccursanoverflow

    public:
    CVector(int delta=10); //Constructor
    void Insert(int elem); //Insertanewelement
    void Display();

    //Moremethodsgohere
};

CVector::CVector(int delta) {
    Init(delta);
}

void CVector::Init(int delta) {
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

void CVector::Insert(int elem)
{
	if(m_nCount==m_nMax) //Verifytheoverflow
		Resize(); //Resizethevectorbeforeinsertingelem
	m_pVect[m_nCount++]=elem;//Inserttheelementattheend
}

void CVector::Resize(){
    const int delta = 5; // Used to increase the vector size
	int *pTemp, i;
	pTemp = new int[m_nMax + m_nDelta]; // Alloc a new vector
	for(i = 0 ; i < m_nMax ; i++) // Transfer the elements
		pTemp[i] = m_pVect[i]; // we can also use the function memcpy
	delete [ ] m_pVect; // delete the old vector
	m_pVect = pTemp; // Update the pointer
	m_nMax += m_nDelta; // The Max has to be increased by delta
}

void CVector::Display(){
	for (int i = 0; i < m_nCount; i++) 
	{
		cout << m_pVect[i] << " ";
	}
	cout << endl;
	cout << "Cantidad de elementos almacenados:" << m_nCount <<endl;
}

int main(int argc, char *argv[]) {
	CVector vector;
    //vector.m_pVect = nullptr;
    vector.Insert(10);
    vector.Insert(20);
    vector.Insert(30);
    
    vector.Display();
	return 0;
}

/****************
Tarea 1 es insertar

gVect : 10, 20, 30


*****************/
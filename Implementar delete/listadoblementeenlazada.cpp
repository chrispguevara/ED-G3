#include <iostream>
using namespace std;

struct NODE
{
	int m_data; 
	struct NODE *m_pNext;
	struct NODE *m_pPrev;
};

class CDoublyLinkedList
{
	private:
		NODE *m_pRoot; 
		NODE *m_pTail;
	public:
		CDoublyLinkedList() : m_pRoot(nullptr), m_pTail(nullptr) {}
		// Method to insert a node at the end
		
		void Insert(int data) 
		{
			NODE* newNode = new NODE;
			newNode->m_data = data;
			newNode->m_pNext = nullptr;
			newNode->m_pPrev = nullptr;
			
			if (m_pRoot == nullptr) 
			{
				m_pRoot = newNode;
				m_pTail = newNode;
			} 
			else 
			{
				m_pTail->m_pNext = newNode;  // El siguiente nodo del último nodo será el nuevo nodo
				newNode->m_pPrev = m_pTail;  // El anterior nodo del nuevo nodo será el último nodo
				m_pTail = newNode;  // Ahora, m_pTail apunta al nuevo nodo
			}
		}

		void Print() const 
		{
			NODE* current = m_pRoot;
			while (current != nullptr) 
			{
				cout << current->m_data << " -> ";
				current = current->m_pNext;
			}
			cout << "nullptr" << endl;
		}
		
		void Delete(int data) 
		{
			if (m_pRoot == nullptr) 
				return; 

            // Special case: deleting the root node            
            if (m_pRoot->m_data == data) 
			{
				NODE* temp = m_pRoot;
				m_pRoot = m_pRoot->m_pNext;
                m_pRoot-> m_pPrev = nullptr;
				delete temp;
				return;
			}

            // Search for the node to delete
			NODE* current = m_pRoot;
			while (current->m_pNext != nullptr && current->m_pNext->m_data != data) 
			{
				current = current->m_pNext;
			}
			
			// If we found the node
			if (current->m_pNext != nullptr) 
			{
				NODE* temp = current->m_pNext;
				current->m_pNext = current->m_pNext->m_pNext;
                current->m_pNext->m_pPrev = current;
				delete temp;
			} else 
			{
				cout << "Value " << data << " not found in the list!" << endl;
			}
		}
};


int main(int argc, char *argv[]) 
{
	CDoublyLinkedList list;
	
	// Insert some elements
	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(5);
	
	// Print the list
	list.Print();
	
	cout << "Deleting 20 from the list." << endl;
	list.Delete(20);
	list.Print();
	
	
	return 0;
}

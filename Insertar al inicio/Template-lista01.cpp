#include <iostream>
using namespace std;


template <typename T> class CLinkedList
{
    private: // Structure for nodes in a Linked List
    struct NODE
    {
        T m_data; // The data goes here
        struct NODE * m_pNext; // Pointer to the next Node

        // Some methods go here
    };
    NODE* m_pRoot; // Pointer to the root
    public: // More methods go here
        CLinkedList() : m_pRoot(nullptr) {}

        //template <class t> void::Insert(T data) <- class member outside template syntax
        // define inside the class template
        void Insert(T data)
        {
			NODE* newNode = new NODE;
			newNode->m_data = data;
			newNode->m_pNext = nullptr;
			
			if (m_pRoot == nullptr) 
			{
				m_pRoot = newNode;
			} 
			else 
			{
				NODE* current = m_pRoot;
				while (current->m_pNext != nullptr) {
					current = current->m_pNext;
				}
				current->m_pNext = newNode;
			}
		}

        void Insert2(T data) 
		{
			NODE* newNode = new NODE;
			newNode->m_data = data;
            newNode->m_pNext = nullptr;
			

			if (m_pRoot == nullptr) 
			{
				m_pRoot = newNode;
			} 
			else 
			{
                newNode-> m_pNext = m_pRoot;
                m_pRoot = newNode;
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

        void Delete(T data) 
		{
			if (m_pRoot == nullptr) 
				return; 
			
			// Special case: deleting the root node
			if (m_pRoot->m_data == data) 
			{
				NODE* temp = m_pRoot;
				m_pRoot = m_pRoot->m_pNext;
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
				delete temp;
			} else 
			{
				cout << "Value " << data << " not found in the list!" << endl;
			}
		}

};

int main(int argc, char *argv[]) 
{
	CLinkedList<int> list;
	list.Insert(1);	
    list.Insert(2);
    list.Insert(3);

	list.Print();
    list.Delete(2);
    list.Insert2(100);
    list.Print();

    CLinkedList<string> lista;
    lista.Insert("primero");
    lista.Insert("segundo");
	lista.Insert("tercero");

    lista.Print();
    lista.Insert2("NUEVO");
    lista.Print();
    return 0;
}
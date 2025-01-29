#include <iostream>
using namespace std;

struct NODE
{
	int m_data; 
	struct NODE *m_pNext;
};

class CLinkedList
{
	private:
		NODE *m_pRoot; 
	public:
		CLinkedList() : m_pRoot(nullptr) {}
		// Method to insert a node at the end
		
		void Insert(int data) 
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

        void Insert2(int data) 
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
				//NODE* current = m_pRoot;
                newNode-> m_pNext = m_pRoot;
                m_pRoot = newNode;

				// while (current->m_pNext != nullptr) {
				// 	current = current->m_pNext;
				// }
				//current->m_pNext = newNode;
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
	CLinkedList list;
	
	// Insert some elements
	list.Insert(10);
	list.Insert(20);
	list.Insert(30);
	list.Insert(5);

	// Print the list
	list.Print();

	list.Delete(5);
	list.Print();
	
    list.Insert2(100);
    list.Print();

	// cout << "Deleting 20 from the list." << endl;
	// list.Delete(20);
	// list.Print();
	
	
	return 0;
}

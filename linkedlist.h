#include <iostream>
#include <vector>
using namespace std;
struct node {
	int value = 0;
	node* next=NULL;
	int occurence = 1;
};
class linkedlist
{
private:
	node* head;
	node* last;
public:
	linkedlist()
	{
		head = NULL;                                       //initializing pointers
		last = NULL;
	}
	void insert(int num)
	{
		node* added = new node;
		node* temp;

		added->value = num;                                // adding the value to the added node
		if (head == NULL)                                  // checking if the list was empty
		{
			head = added;                                  // making head point to the added since it was empty before
			added->next = NULL;
		}
		else
		{
			temp = head;
			while (temp->next != NULL)                   //looping until the end of list
			{
				temp = temp->next;
			}
			temp->next = added;                            //making the last element point to the added node
			added->next = NULL;
		}
		last = added;
	}
	void display()
	{
		node* temp;
		temp = head;
		if (head == NULL)
		{
			cout << "empty";
		}
		else
		{
			while (temp != NULL)                                  //looping over the list
			{
				cout << temp->value << "     occured:   " << temp->occurence << "  times" << endl;
				temp = temp->next;
			}
		}
	}
	void delete_last_node()                                    //delete last node in the list
	{
		node* temp = head;
		if (head == NULL)
		{
			cout << "list is empty" << endl;
		}
		else if (head == last)
		{
			delete last;
			head = NULL;
			last = NULL;
		}
		else
		{
			while (temp->next != last)
			{
				temp = temp->next;
			}
			delete last;
			temp->next = NULL;
		}
	}
	void deletenode(int num)                                    //delete a node that has this value
	{
		node* back, * target;
		target = back = head;
		if (target->value == num)                            //in case the head has the value that was wished to be deleted
		{
			if (target->next == NULL)
			{
				last = NULL;                                // in case it's the only present node so last will be null
			}
			head = target->next;
			delete target;

		}
		else
		{
			while (target->value != num)
			{
				back = target;
				target = target->next;
			}
			if (target->next == NULL)
				last = back;                                    //in case we want to delete the last element so the last pointer should be pointing to the back element

			back->next = target->next;
			delete target;

		}

	}
	int sum()
	{
		int sum = 0;
		node* temp;
		temp = head;
		while (temp != NULL)
		{
			sum += (temp->value) * (temp->occurence);
			temp = temp->next;
		}
		return sum;
	}



	linkedlist copy_vector(vector<int> x)
	{
		vector<int>::iterator it;
		int size = x.size();
		for (int i = 0; i < size; i++)                                  //looping over all the vector
		{


			int occ = 1;
			for (int j = i + 1; j < x.size(); j++)                        //checking front if there are duplicates
			{
				if (x[i] == x[j])
				{
					x.erase(x.begin() + j);
					occ++;
					size--;
					j--;                                                // since an element will be deleted so the size needs to be decremented, also j should be decremented because element of index j was deleted so if we don't decrement we will skip an index
				}


			}

			insert(x[i]);
			last->occurence = occ;



		}

		return *this;
	}
};
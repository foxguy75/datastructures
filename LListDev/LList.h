#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>

struct node_t
{
	T data;
	node_t<T>* next;
	node_t<T>* prev;
};

template <class T>
class LList
{
public:

	LList(){
		head = NULL;
		tail = NULL;
		number_of_nodes = 0;
	}

	~LList(){
		//deconstructor
			node_t<T>* temp = head;
			node_t<T>* to_delete;
			while(temp){
				to_delete = temp;
				temp = temp -> next;
				delete to_delete;
			}
			head = NULL;
			tail = NULL;
			number_of_nodes = 0;
	}

	LList(const LList& other){
		//copy constructor.
		head = NULL;
		tail = NULL;
		number_of_nodes = 0;
		node_t<T>* temp = other.head;
		while(temp){
			push_back(temp -> data);
			temp = temp -> next;
		}
	}

	void push_back(T value){
		//Same as push front except it adds the value to the back.
		//See comments of puch front for more detials.
		node_t<T>* new_node = new node_t<T>;
		new_node -> data = value;
		new_node -> prev = tail;
		new_node -> next = NULL;

		if(!head){
			head = new_node;
		}

		if(tail){
			tail -> next = new_node;
		}

		tail = new_node;
		number_of_nodes++;
		return;
	}

	void push_front(T value){
		// Adds a value of type T to the front of the list
		// Start by making a node_t struct and put the data there
		node_t<T>* new_node = new node_t<T>;
		new_node->data = value;
		new_node->prev = NULL;
		new_node->next = head;

		//since this node is going on the front of the list we make head point to it
		//That means we need to to change the value that was storde at heads current prev to the new node.
		if (head) {
			head->prev = new_node;
		}

		//All this is doing is if tail is not set (meaning the list has only one value) then tail and head are the same
		if (!tail) {
			tail = new_node;
		}

		head = new_node;
		number_of_nodes++;
		return;
	}

	void setAt(int pos, T value){
		get_node(pos) -> data = value;
		return;
	}

	T getAt(int pos) const {
		return get_node(pos) -> data;
	}

	unsigned int size() const {
		return number_of_nodes;
	}

	void clear(){
		// this is just copy paste from the deconstructor.
		node_t<T>* temp = head;
		node_t<T>* to_delete;
		while(temp){
			to_delete = temp;
			temp = temp -> next;
			delete to_delete;
		}
		head = NULL;
		tail = NULL;
		number_of_nodes = 0;
	}

	void remove(int pos){
		//Can not remove what is not there.
		if(number_of_nodes == 0){
			return;
		}

		//Get the node that we want to remove.
		node_t<T>* temp = get_node(pos);

		if(!temp -> next) {
			temp -> prev -> next = NULL;
			tail = temp -> prev;
			delete temp;
			number_of_nodes--;
		}
		else if(!temp -> prev) {
			temp -> next -> prev = NULL;
			head = temp -> next;
			delete temp;
			number_of_nodes--;
		}
		else {
			temp -> next -> prev = temp -> prev;
			temp -> prev -> next = temp -> next;
			delete temp;
			number_of_nodes--;
		}

		if (number_of_nodes == 0){
			head = NULL;
			tail = NULL;
		}

		return; 
	}

	LList<T>& operator= (const LList& other){
		if (head == other.head){
			return this;
		}
		clear();
		node_t<T>* temp = head;
		node_t<T>* otemp = other.head;
		while(otemp){
			temp.push_back(otemp -> data);
			otemp = otemp -> next;
		}
	}

	LList<T>& operator== (const LList& other){
		//Here we are checking to if the list is itself.
		if(head == other.head){
			return true;
		}
		//setup to traverse the lists.
		node_t<T>* temp = head;
		node_t<T>* otemp = other.head;
		if(temp.size() == otemp.size()){
			while(temp){
				if(temp -> data != otemp -> data){
					return false;
				}
				temp = temp -> next;
				otemp = otemp -> next;
			}
			return true;
		}
		return false;
	}

	LList<T>& operator!= (const LList& other){
		if(head == other.head){
			return false;
		}//setup to traverse the lists.
		node_t<T>* temp = head;
		node_t<T>* otemp = other.head;
		if(temp.size() == otemp.size()){
			while(temp){
				if(temp -> data != otemp -> data){
					return true;
				}
				temp = temp -> next;
				otemp = otemp -> next;
			}
			return false;
		}
		return true;
	}

private:
	unsigned int number_of_nodes;
	node_t<T>* head;
	node_t<T>* tail;

	void validate_input(int& pos) const {
		//Throw an error if there are no nodes to go through.
		if(number_of_nodes == 0){
			throw logic_error("Out of bounds.");
		}
		//Indexing will start at zero
		//temp will be used to traverse the list.
		if(pos < 0){
			pos = number_of_nodes + pos;
		}

		if(pos > number_of_nodes || pos < 0 || pos == number_of_nodes){
			throw logic_error("Out of bounds.");
		}
		return;
	}

	node_t<T>* get_node(int pos) const {
		validate_input(pos);
		node_t<T>* temp;
		if(pos > (int)(number_of_nodes / 2)){
			temp = tail;
			for(int i = number_of_nodes; i > pos + 1; i--){
				temp = temp -> prev;
			}
			return temp;
		}else {
			temp = head;
			for(int i = 0; i < pos; i++){
				temp = temp -> next;
			}
			return temp;
		}
	}

};

template <class T>
ostream& operator<<(ostream& out, const LList<T> other){
	if(other.size() == 0){
    out << "[]" << endl;
    return out;
  }
  out << "[" ;
  for(int i = 0; i < other.size()-1 ; i++){
    cout << other.getAt(i) << ", ";
  }
  cout << other.getAt(-1) << "]";
	return out;
}

#endif // !LLIST_H

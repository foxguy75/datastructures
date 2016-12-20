#ifndef DLIST_H
#define DLIST_H

/*
	Templated Doubly Linked List class.
	Paul Talaga
	October 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct node_t {
  T data;
  node_t<T>* prev;
  node_t<T>* next;
};

// This implementation will use a head and tail pointers,
// allowing O(1) insertion on the front and end.
template <class T>
class DList{

  public:
  DList(){
   head = NULL;
   tail = NULL;
   number_of_nodes = 0;
  }
  
  ~DList(){
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
	
  DList(const DList& other){
    head = NULL;
    tail = NULL;
    number_of_nodes = 0;
    node_t<T>* temp = other.head;
    while(temp){
    	push_back(temp -> data);
    	temp = temp -> next;
    }
  }
	
	// Similar to copy constructor, but check for self
	// assignment, if not, clear and copy all data.
  DList<T>& operator= (const DList& other){  
		if(head == other.head){
			return *this;
		}
		clear();
    node_t<T>* temp = other.head;
    while(temp){
    	push_back(temp -> data);
    	temp = temp -> next;
    }
		return *this;
	}
     
  T getAt(int pos) const{
		if(pos < 0){
			pos = number_of_nodes + pos;
		}
		if (pos >= number_of_nodes || pos < 0 || number_of_nodes == 0){
			throw logic_error("Out of bounds.");
		}
		node_t<T>* temp;
		if (pos > number_of_nodes/2){
			temp = tail;
			for (int i = number_of_nodes; i < pos; i--){
				temp = temp -> prev;
			}
			return temp -> data;
		}
		else{
			temp = head;
			for (int i = 0; i < pos; i++){
				temp = temp -> next;
			}
			return temp -> data;
		}
  }

  unsigned int size() const{return number_of_nodes;}
 
  void push_back(T value){
    node_t<T>* new_node = new node_t<T>;
    new_node -> data = value;
    new_node -> prev = tail;
    new_node -> next = NULL;
    if(tail){
    	tail -> next = new_node;
    }
    if (!head){
    	head = new_node;
    }
    tail = new_node;
    number_of_nodes++;
    return;
  }
  
  void push_front(T value){
    node_t<T>* new_node = new node_t<T>;
    new_node -> data = value;
    new_node -> prev = NULL;
    new_node -> next = head;
    if(head){
    	head -> prev = new_node;
    }
    if(!tail){
    	tail = new_node;
    }
    head = new_node;
    number_of_nodes++;
    return;
  }
	
	void setAt(T value, int pos){
		if(pos < 0){
			pos = number_of_nodes + pos;
		}
		if (pos >= number_of_nodes || pos < 0){
			throw logic_error("Out of Bounds");
		}
		node_t<T>* temp;
		if(pos > number_of_nodes/2){
			temp = tail;
			for (int i = number_of_nodes; i > pos; i--){
				temp = temp -> prev;
			}
			temp -> data = value;
			return;
		}
		else{
			temp = head;
			for (int i = 0; i < pos; i++){
				temp = temp -> next;
			}
			temp -> data = value;
			return;
		}
  }
	
	void remove(int pos){
		if (number_of_nodes == 0){
			throw logic_error("DList is empty");
		}
		if(pos < 0){
			pos = number_of_nodes + pos;
		}
		if (pos > number_of_nodes || pos < 0){
			throw logic_error("Out of Bounds.");
		}
		node_t<T>* temp;
		if (pos > number_of_nodes/2){
			temp = tail;
			for(int i = number_of_nodes - 1; i > pos; i--){
				temp = temp -> prev;
			}
			if (!temp -> next){
				temp -> prev -> next = NULL;
				tail = temp -> prev;
				delete temp;
				number_of_nodes--;
				if (number_of_nodes == 0){
					head = NULL;
					tail = NULL;
				}
				return;
			}
			if (!temp -> prev){
				temp -> next -> prev = NULL;
				head = temp -> next;
				delete temp;
				number_of_nodes--;
				if (number_of_nodes == 0){
					head = NULL;
					tail = NULL;
				}
				return;
			}
			temp -> prev -> next = temp -> next;
			temp -> next -> prev = temp -> prev;
			number_of_nodes--;
			delete temp;
			return;
		}
		else{
			temp = head;
			for (int i = 0; i < pos; i++){
				temp = temp -> next;
			}
			if (!temp -> prev && !temp -> next){
				delete temp;
				head = NULL;
				tail = NULL;
				number_of_nodes--;
				return;
			}
			if (!temp -> prev){
				temp -> next -> prev = NULL;
				head = temp -> next;
				delete temp;
				number_of_nodes--;
				if (number_of_nodes == 0){
					head = NULL;
					tail = NULL;
				}
				return;
			}
			if (!temp -> next){
				temp -> prev -> next = NULL;
				tail = temp -> prev;
				delete temp;
				number_of_nodes--;
				if (number_of_nodes == 0){
					head = NULL;
					tail = NULL;
				}
				return;
			}
			temp -> prev -> next = temp -> next;
			temp -> next -> prev = temp -> prev;
			number_of_nodes--;
			delete temp;
			return;
		}
	}
	
	DList<T> reverse() const{
		DList<T> ret;
		node_t<T>* temp = head;
		for (int i = 0; i < number_of_nodes; i++){
			ret.push_front(temp -> data);
			temp = temp -> next;
		}
		return ret;
	}
	
	DList<T> operator+(const DList<T>& other) const{
		DList ret;
		node_t<T>* temp = head;
		for (int i = 0; i < number_of_nodes; ++i){
			ret.push_back(temp -> data);
			temp = temp -> next;
		}
		temp = other.head;
		for (int i = 0; i < other.number_of_nodes; ++i){
			ret.push_back(temp -> data);
			temp = temp -> next;
		}
		return ret;
	}
	
	bool operator==(const DList<T>& other) const{
		node_t<T>* temp = head;
		node_t<T>* other_temp = other.head;
	  if(number_of_nodes == other.number_of_nodes){
	  	while(temp){
	  		if(temp -> data == other_temp -> data){
	  			temp = temp -> next;
	  			other_temp = other_temp -> next;
	  		}
	  		else{
	  			return false;
	  		}
	  	}
	  	return true;
	  }
	  return false;
	}
	
	bool operator!=(const DList<T>& other) const{
		node_t<T>* temp = head;
		node_t<T>* other_temp = other.head;
	  if(number_of_nodes == other.number_of_nodes){
	  	while(temp){
	  		if(temp -> data == other_temp -> data){
	  			temp = temp -> next;
	  			other_temp = other_temp -> next;
	  		}
	  		else{
	  			return true;
	  		}
	  	}
	  	return false;
	  }
	  return true;
	}
	
	void clear(){
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
	
	// HW additions.
	unsigned int count(T thing){
	  // Fill me in
		return 0;
	}
	
	void splitHalf(DList<T>& a, DList<T>& b){
	  // Fill me in
	}
	
	void splitEveryOther(DList<T>& a, DList<T>& b){
	  // Fill me in
	}
	
	void reverseThis(){
	  // Fill me in
	}
	
	void doubleThis(){
	  // Fill me in
	}
	
	bool setEq(const DList<T>& other){
	  // Fill me in
	  return true;
	}
 
  
  private:
  	node_t<T>* head;
  	node_t<T>* tail;
  	int number_of_nodes;
  
};

// Note this function is O(n^2) because getAt is O(n) and we are
// doing it n times.
template <class T>
ostream& operator<<(ostream& out, const DList<T> other){
	if(other.size() == 0){
    out << "[]" << endl;
    return out;
  }
  out << "[" ;
  for(int i = 0; i < other.size()-1 ; i++){
    cout << other.getAt(i) << ", ";
  }
  cout << other.getAt(-1) << "]" << endl;
	return out;
}

#endif
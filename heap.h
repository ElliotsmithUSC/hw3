#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> nodes;
  int m;
  PComparator c;
  void trickleUp(size_t location);
  void heapify(size_t location);

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  this->m = m;
  this->c = c;
}

template<typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

template<typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(size_t location){
  int parentnode = location/2;
  while(c(nodes[location],nodes[parentnode])){
    T temp = nodes[parentnode];
    nodes[parentnode] = nodes[location];
    nodes[location] = temp;
		location = parentnode;
		parentnode = parentnode/2;
  }
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t location){
	if(nodes.empty()){
		return;
	}
	if(nodes.size()-1 < location*2){
		return;
	}
	int betterChild = location*2;
	if(betterChild == 0){
		betterChild = 1;
	}
	if(nodes.size()-1 > (location*2) + 1){
		int rChild = betterChild++;
		if(c(nodes[rChild], nodes[betterChild])){
			betterChild = rChild;
		}
	}
	if(c(nodes[betterChild],nodes[location])){
		T temp = nodes[location];
		nodes[location] = nodes[betterChild];
		nodes[betterChild] = temp;
		heapify(betterChild);
	}
}

template<typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	nodes.push_back(item);
	int pushlocation =  nodes.size() - 1;
	trickleUp(pushlocation);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::logic_error("the heap is empty");
  }
  return nodes[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::logic_error("the heap is empty");
  }
	nodes[0] = nodes.back();
	nodes.pop_back();
	heapify(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
	if(nodes.size()==0){
		return true;
	}
	else{
		 return false;
	}
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return nodes.size();
}



#endif


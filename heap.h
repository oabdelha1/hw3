#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

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
  Heap(int min=2, PComparator c = PComparator());

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

  //for troubleshooting
  //void print() const;

private:
  /// Add whatever helper functions and data members you need below
    //size_t size;
    std::vector<T> data;
    void heapify(int top);
    size_t m;
    void roll();
    PComparator compare;


};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int min, PComparator c) {
    m = min;
    compare = c;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty");

  }
  //std::cout << "swapping " << data[0] << " and " << data.back() << std::endl;
  std::swap(data[0], data.back());
  //print();
  data.pop_back();
  heapify(0);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int top) {

    size_t t = top;
    if (t >= size()){
        return;
    }
    //std::cout << "Working on " << top << std::endl;
    //We find whichever child is the highest priority, and put the index in child index
    size_t childIndex = (top * m) + 1;
    int defaultChild = childIndex;
    //std::cout << "Current Child: " << childIndex << std::endl;
    //int steps = 0;
    if (childIndex >= size()) return;
    for (size_t i = 0; i < m; i++){
        if ( defaultChild + i >= size()){
            break;
        }
        if (compare(data[defaultChild+i], data[childIndex])){
            //std::cout << "Current and Other: " << data[childIndex] << " " << data[defaultChild + i] << " at indexes " << childIndex <<" and " << defaultChild+i << std::endl;
            childIndex = defaultChild+i;
        }

    }

    //std::cout << "Final child index " << childIndex << std::endl;
//    T topData = data[top];
//    T chiData = data[childIndex];
//    bool lower = !compare(topData, chiData);

    //std::cout << std::boolalpha << data[top] << " > " << chiData << " is " << lower << std::endl;

    if (compare(data[childIndex], data[top])){
        std::swap(data[top], data[childIndex]);
        //print();
        heapify(childIndex);
    }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
    //std::cout << "Push instantiating" << std::endl;
    // T val = item;
    //std::cout << "Push pushing back" << std::endl;
    data.push_back(item);
    //std::cout << "Push rolling" << std::endl;
    roll();
    //std::cout << "Push done" << std::endl;
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::roll(){

    int curIndex = size() - 1;
    int parIndex = (curIndex - 1) / m;

    if (curIndex == 0) return;

    T cur = data.back();
    T par = data[parIndex];

    //std::cout << "Current: " << cur << " at " << curIndex << std::endl;
    //std::cout << "Parent: " << par << " at " << parIndex << std:: endl;

    bool higher = compare(cur, par);

    while (curIndex!=parIndex && higher){
        std::swap(data[curIndex], data[parIndex]);

        curIndex = parIndex;
        parIndex = (curIndex - 1) / m;
        if (curIndex == 0) return;
        cur = data[curIndex];
        par = data[parIndex];

        higher = compare(cur, par);
        //std::cout << "Current: " << cur << " at " << curIndex << std::endl;
        //std::cout << "Parent: " << par << " at " << parIndex << std:: endl;
    }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
    if (size() == 0){
        return true;
    }
    return false;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
    return data.size();
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

/*
template <typename T, typename PComparator>
void Heap<T, PComparator>::print() const {
    for (size_t i = 0; i < data.size(); i++){
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
*/

#endif


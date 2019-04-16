
/**
 * Default constructor has an Array class to store data and initializes the front and 
 * rear as 
 */
template <typename T>
Queue<T>::Queue() :
    arr_(Array<T>()),
    rear_(-1),
    front_(-1)
{

}

/**
 * Copy constructor uses the Array copy constructor and sets the indexing variable to 
 * whatever the other queue has.
 */
template <typename T>
Queue<T>::Queue (const Queue &queue) : 
    arr_(Array<T>(queue.arr_)),
    rear_(queue.rear_),
    front_(queue.front_)
{

}


template <typename T>
Queue<T>::~Queue (){
}

/**
 * Increment the rear_ to indicate that an element has entered the queue then use 
 * Array's resize method to change the size of this queue. Then add an element to
 * the end of the queue.
 */
template <typename T>
void Queue<T>::enqueue (T element){
    if(this->is_full()){
        throw std::logic_error("The Queue is full! Cannot enqueue.");
    }
    else{
        if(this->front_ == -1){
            this->front_ = 0;
        }
        this->rear_ = (this->rear_ + 1) % SIZE;
        this->arr_.set(this->rear_, element);
    }
}

/* Dequeue an element from the front of the queue and return it*/
template <typename T>
T Queue<T>::dequeue(){
    if (this->is_empty()){
        throw std::logic_error("The Queue is empty and cannot be dequeued.");
    }

  // COMMENT You are unnecessarily allocating a new array.
  /* RESPONSE removed Array allocation */

  // COMMENT This design is OK, but it is not the best design. This will be
  // a very expensive array to use if you are dequeing a lot of elements. This
  // is because you are copying N elements each time you dequeue 1 element.
  // Instead, you only want to copy element when necessary. Come up with a better
  // design that is not as expensive for the client to use.
  /**
   *  RESPONSE opted instead for a circular array so I would not have as bad of memory issues
   * using a ton of allocations for a single dequeue.
   */
    /**
     * Save the front of the queue to a variable of the same type and move the front closer
     * to the rear.
     */
    T data = this->arr_.get(this->front_);
    if(this->front_ == this->rear_){
        this->front_ = -1;
        this->rear_ = -1;
    }
    else{
        this->front_ = (this->front_ + 1) % SIZE;
    }
    return data;
  // COMMENT You are unnecessarily allocating a new array.
  /* RESPONSE removed Array allocation */

}

/* Copys one queue object to another, once again using Array class constructors */
template <typename T>
const Queue<T> &Queue<T>::operator = (const Queue &rhs){
    if(this != &rhs){
        this->arr_ = Array<T>(rhs.arr_);
        this->rear_ = rhs.rear_;
        this->front_ = rhs.front_;
    }
    return *this;
}

/* Loops through the queue and dequeues all elements*/
template <typename T>
void Queue<T>::clear(){
  // COMMENT This works, but is a very expensive operation. You should find a
  // why to just reset the state without having the dequeue every element.
  /**
   *  RESPONSE sets the array variable to a new one of the same size
   * effectively clearing the queue. The old Array is on the stack so it deletes itself.
   * Also reset the front and rear. 
   */
  this->arr_ = Array<T>(this->size());
  this->front_ = -1;
  this->rear_ = -1;
}



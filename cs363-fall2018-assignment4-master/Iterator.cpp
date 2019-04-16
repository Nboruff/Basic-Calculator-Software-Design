
template <typename T>
Array_Iterator <T>::Array_Iterator(Array<T> &a) : arr_(a), curr_(0) {}

template <typename T>
Array_Iterator<T>::~Array_Iterator(void) {}

template <typename T>
bool Array_Iterator<T>::is_done(void) { return this->curr_ >= this->arr_.cur_size_; }

template <typename T>
bool Array_Iterator<T>::advance(void) { ++this->curr_; }

template <typename T>
T &Array_Iterator<T>::operator*(void) { return this->arr_.data_[this->curr_]; }

template <typename T>
T *Array_Iterator<T>::operator->(void) { return &this->arr_.data_[this->curr_]; }
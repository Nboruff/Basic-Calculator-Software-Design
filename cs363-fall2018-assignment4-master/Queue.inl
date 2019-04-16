/* Gets size represented by current number of elements */
template <typename T>
inline
size_t Queue<T>::size() const
{
    return this->arr_.size();
}

/* Returns if the queue is empty or not*/
template <typename T>
inline
bool Queue<T>::is_empty() const
{
    return this->rear_ == -1;
}

template <typename T>
inline
bool Queue<T>::is_full() const
{
    return (this->rear_ == this->size() - 1 && this->front_ == 0) || (this->front_ == this->rear_ + 1);
}
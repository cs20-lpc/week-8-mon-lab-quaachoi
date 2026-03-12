template <typename T>
ArrayStack<T>::ArrayStack(int i) {
    this->maxSize = i;
    this->buffer = new T[i];
    this->length = 0;

    for(int j = 0; j < i; j++)
    {
        this->buffer[j] = T{};
    }
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayStack<T>::~ArrayStack() {
    clear();
}

template <typename T>
void ArrayStack<T>::clear() {
    //todo
    delete this->buffer;
    this->buffer = nullptr;
    this->maxSize = 0;
    this->length = 0;
}

template <typename T>
void ArrayStack<T>::copy(const ArrayStack<T>& copyObj) {
    //todo
    int sourceSize = copyObj->getMaxSize();
    this->maxSize = sourceSize;
    this->buffer = new T[sourceSize];
    this->length = copyObj->length;

    for(int i = 0; i < sourceSize; i++)
    {
        this->buffer[i] = copyObj->buffer[i];
    }
}

template <typename T>
int ArrayStack<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayStack<T>::getMaxSize() const {
    return this->maxSize;
}

template <typename T>
bool ArrayStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayStack<T>::isFull() const {
    return this->length == this->maxSize;
}

template <typename T>
T ArrayStack<T>::peek() const {
    // TODO
    return this->buffer[this->length];
}

template <typename T>
void ArrayStack<T>::pop() {
    // TODO
    this->buffer[this->length] = T{};
    this->length--;
}

template <typename T>
void ArrayStack<T>::push(const T& elem) {
    // TODO
    this->length++;
    this->buffer[this->length] = elem;
}

template <typename T>
void ArrayStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TODO
}

template <typename T>
ostream& operator<<(ostream& outStream, const ArrayStack<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "Stack is empty, no elements to display.\n";
    }
    else {
        for (int i = myObj.length; i > 0; i--) {
            outStream << (i == myObj.length ? "top\t" : "\t")
                      << myObj.buffer[i] << endl;
        }
    }

    return outStream;
}

template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);
    n->next = nullptr;
    
    if (head == nullptr) {
        head = n;
        tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
    this->length++;    
}

template <typename T>
void LinkedList<T>::append_old(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    head = nullptr;
    this->length = 0;

    Node* curr = copyObj.head;
    while (curr != nullptr) {
        append(curr->value);
        curr = curr->next;
    }
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO
    if (position < 0 || position >= this->length) {
        throw string("insert: error, position out of bounds");
    }

    typename LinkedList<T>::Node* newNode = new typename LinkedList<T>::Node(elem, nullptr);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        this->length++;
        return;
    }

    typename LinkedList<T>::Node *prev = head;

    for (int i = 1; i < position; i++) {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
    this->length++;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
    typename LinkedList<T>::Node *prev = head;

    if (position < 0 || position >= this->length) {
        throw string("remove: position out of bounds");
    }

    typename LinkedList<T>::Node *to_delete = nullptr;
    if (position == 0) {
        to_delete = head;
        head = head->next;
    } else {
        for (int i = 0; i < position - 1; i++) {
            prev = prev->next;
        }
        to_delete = prev->next;
        prev->next = to_delete->next;
    }

    delete to_delete;
    this->length--;    
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}


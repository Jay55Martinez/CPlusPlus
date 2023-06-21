// Jay Martinez -- assignment 6 -- 6/20/23
#include <queue>
#include <vector>

template<class T>
class Repository {
public:
    // default constructor
    Repository() = default;
    // copy constructor
    Repository(const Repository& other);
    // copy assignment
    Repository<T>& operator=(const Repository& other);
    // move constructor
    Repository(Repository&& other);
    // move assignment
    Repository<T>& operator=(Repository&& other);
    // destructor
    ~Repository() {}

    // adds a single item to the repository
    void add_item(T item);
    // adds multiple items to the repository (overloaded function)
    void add_item(std::vector<T> items);
    // gets the position of an item in the queue
    int get_position(T item) const;
    // removes a single item from the repository
    void rm_item(T item);
    // removes multiple items from the repository (overloaded function)
    void rm_item(std::vector<T> items);
    // gets the size of the queue
    int get_size();

private:
    std::queue<T> l_items;
};

// copy constructor definition
template<class T>
Repository<T>::Repository(const Repository& other) {
    std::queue<T> newQueue = other.l_items;

    while (!newQueue.empty()) {
        l_items.push(newQueue.front());
        newQueue.pop();
    }
}

// copy assignment definition
template<class T>
Repository<T>& Repository<T>::operator=(const Repository& other) {
    if (this != &other) {
        std::queue<T> newQueue = other.l_items;
        std::swap(l_items, newQueue);
    }
    return *this;
}

// move constructor
template<class T>
Repository<T>::Repository(Repository&& other) {
    while (!other.l_items.empty()) {
        l_items.push(other.l_items.front());
        other.l_items.pop();
    }
}

// move assignment operator
template<class T>
Repository<T>& Repository<T>::operator=(Repository&& other) {
    if (this != &other) {
        while (!l_items.empty()) {
            l_items.pop();
        }
        while (!other.l_items.empty()) {
            l_items.push(other.l_items.front());
            other.l_items.pop();
        }
    }
    return *this;
}

// adds a single item to the repository
template<class T>
void Repository<T>::add_item(T item) {
    bool exists = false;

    std::queue<T> temp = l_items;
    while (!temp.empty()) {
        if (temp.front() == item) {
            temp.front() = item;
            exists = true;
            break;
        }
        temp.pop();
    }
    if (!exists) {
        l_items.push(item);
    }
}

// adds multiple items to the repository (overloaded)
template<class T>
void Repository<T>::add_item(std::vector<T> items) {
    for (const auto& item : items) {
        add_item(item);
    }
}

// gets the position of an item in the queue
template<class T>
int Repository<T>::get_position(T item) const {
    std::queue<T> temp = l_items;
    int pos = 0;
    while (!temp.empty()) {
        if (temp.front() == item) {
            return pos;
        }
        temp.pop();
        pos++;
    }
    return -1;  // Item not found
}

// removes a single item from the repository
template<class T>
void Repository<T>::rm_item(T item) {
    std::queue<T> temp;

    while (!l_items.empty()) {
        if (l_items.front() != item) {
            temp.push(l_items.front());
        }
        l_items.pop();
    }

    l_items = temp;
}

// removes multiple items from the repository (overloaded)
template<class T>
void Repository<T>::rm_item(std::vector<T> items) {
    for (const auto& item : items) {
        rm_item(item);
    }
}

// gets the size of the queue
template<class T>
int Repository<T>::get_size() {
    return l_items.size();
}

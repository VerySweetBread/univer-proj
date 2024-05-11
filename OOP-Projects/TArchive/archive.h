#pragma once
#define STEP_CAPACITY 15
#include "icecream.hpp"
#define MAX_CAPACITY 15*100
#define DEBUG

#ifndef DEBUG
    ic.disable();
#endif

enum State { empty, busy, deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }
}

template <typename T>
class TArchive {
    T* _data;                  // динамический массив данных
    State* _states;            // состо€ни€ €чеек
    size_t _capacity;          // реальный размер массива
    size_t _size;              // количество хранимых данных
    size_t _deleted;           // количество "удалЄнных" позиций
public:
    TArchive();
    //TArchive(const TArchive& archive);
    //TArchive(const T* arr, size_t n);
    //TArchive(size_t n, T value);
    //TArchive(const TArchive& archive, size_t pos, size_t n);

    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    //size_t size();
    //size_t capacity();
    //const T* data();

    //void swap(TArchive& archive);

    //TArchive& assign(const TArchive& archive);

    void clear();
    //void resize(size_t n, T value);
    void reserve(size_t n);

    void push_back(T value);             // вставка элемента (в конец)
    T pop_back();                     // удаление элемента (из конца)
    void push_front(T value);            // вставка элемента (в начало)
    T pop_front();                    // удаление элемента (из начала)

    TArchive& insert(const T* arr, size_t n, size_t pos);
    TArchive& insert(T value, size_t pos);

    //TArchive& replace(size_t pos, T new_value);

    //TArchive& erase(size_t pos, size_t n);
    TArchive& remove_all(T value);
    TArchive& remove_first(T value);
    TArchive& remove_last(T value);
    TArchive& remove(size_t pos);

    size_t* find_all(T value) const noexcept;
    size_t find_first(T value) const noexcept;
    size_t find_last(T value) const noexcept;
private:
    size_t count_value(T value) const noexcept;
    void clear_garbage();
};

template <typename T>
TArchive<T>::TArchive() {
    _size = 0;
    _deleted = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
size_t TArchive<T>::count_value(T value) const noexcept {
    size_t out = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy && _data[i] == value)
            out++;
    }
    return out;
}

template <typename T>
void TArchive<T>::clear_garbage() {
    if (_deleted > _size*.15) {
        size_t offset = 0;
        for (size_t i = 0; i < _size; i++) {
            if (_states[i] == State::deleted) {
                offset++;
                continue;
            }
            _data[i] = _data[i+offset];
        }
        _deleted -= offset;
    }
}

template <typename  T>
void TArchive<T>::clear() {
    for (size_t i; i < _size; i++)
        _states[i] = State::deleted;
    _deleted = _size;
}

template <typename T>
TArchive<T>::~TArchive() {
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TArchive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TArchive<T>::full() const noexcept {
    return _size == _capacity;
}

template <typename T>
void TArchive<T>::reserve(size_t n) {
    size_t new_capacity = _capacity + n/STEP_CAPACITY;
    if (n%STEP_CAPACITY) new_capacity += STEP_CAPACITY;

    if (n > MAX_CAPACITY) throw std::logic_error("MAX_CAPACITY reached");
    
    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];
    size_t offset = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::deleted) {
            offset++;
            continue;
        }
        new_data[i] = _data[i+offset];
        new_states[i] = State::busy;
    }
    
    for (size_t i = _capacity; i < new_capacity; i++) new_states[i] = State::empty;
    
    _size -= offset;
    _deleted -= offset;
    delete [] _data; _data = new_data;
    delete [] _states; _states = new_states;
    _capacity = new_capacity;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(const T* arr, size_t n, size_t pos) {
    if (_size < pos)
        throw std::logic_error("Error in function \
            \"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");
    
    if (_size + n > _capacity)
        reserve(_size+n-_capacity);

    for (int i = _size-1+n; i-n <= pos; i--) {
        _data[i] = _data[i-n];
        _states[i] = _states[i-n];
    }

    for (int i = 0; i < n; i++) {
        _data[pos+i] = arr[i];
        _states[pos+i] = State::busy;
    }

    _size += n;
    
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(T value, size_t pos) {
    IC(pos);
    if (_size < pos)
        throw std::logic_error("Error in function \
            \"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");

    if (_deleted) {
        IC();
        
        size_t dBefore = 0;  // Deleted cells before the position
        size_t index = 0;
        size_t i;
        size_t bEnd;
        size_t aStart;
        size_t aEnd;
        for (i = 0; i < _size; i++) {
            if (index == pos) break;
            if (_states[i] == State::deleted) {
                dBefore++;
                bEnd = i;
            } else index++;
            IC(i, dBefore);
        }
        aStart = i;
        aEnd = i;
        for (; i < _size; i++) {
            if (_states[i] == State::deleted) {
                aEnd = i;
                break;
            } 
        }

        size_t offset = 0;
        if (!dBefore) {
            for (i = aEnd; i > aStart; i--) {
                IC(i);
                _data[i] = _data[i-1];
                _states[i] = State::busy;
            }
            
        } else {
            aStart--;
            IC(bEnd, aStart);
            
            for (i = bEnd; i < aStart; i++) {
                IC(i);
                _data[i] = _data[i+1];
                _states[i] = State::busy;
            }
        } 
        _data[aStart] = value;
        _states[aStart] = State::busy;
        _deleted--;
    } else {
        IC();
        
        // действи€ при переполнении
        if (this->full()) {
            this->reserve(1);
        }
    
        for (size_t i = _size; i > pos; i--) {
            _data[i] = _data[i-1];
            _states[i] = State::busy;
        }
        _data[pos] = value;
        _states[pos] = State::busy;
        _size += 1;
    }
    
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove(size_t pos) {
    if (_size <= pos) {
        throw std::logic_error("Error in function \
            \"TArchive<T>& remove(size_t pos)\": wrong position value.");
    }
    size_t i = 0;
    while (_states[i] == State::deleted) i++;

    for (size_t j = 1; i < pos; j++) {
        i++;
        while (_states[i] == State::deleted) i++;  // Skip deleted
    }
    _states[pos] = State::deleted;
    _deleted++;
    
    clear_garbage();
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_first(T value) {
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value && _states[i] == State::busy) {
            remove(i);
            break;
        }
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_last(T value) {
    for (size_t i = _size-1; i >= 0; i--) {
        if (_data[i] == value && _states[i] == State::busy) {
            remove(i);
            break;
        }
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_all(T value) {
    for (size_t i = 0; i < _size; i++) {
        if (_data[i] == value) {
            _states[i] = State::deleted;
            _deleted++;
        }
    }
    clear_garbage();
    return *this;
}

template <typename T>
size_t TArchive<T>::find_first(T value) const noexcept {
    size_t out = -1;
    size_t pos = -1;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy) {
            pos++;
            if(_data[i] == value) {
                out = pos;
                IC(i, out);
                break;
            }
        }
    }
    return out;
}

template <typename T>
size_t TArchive<T>::find_last(T value) const noexcept {
    size_t out = -1;
    size_t pos = -1;
    for (size_t i = _size-1; i >= 0; i--) {
        if (_states[i] == State::busy) {
            out++;
            if (_data[i] == value) {
                out = pos;
                break;
            }
        }
    }
    return out;
}

template <typename T>
size_t* TArchive<T>::find_all (T value) const noexcept {
    size_t count = this->count_value(value);
    if (count == 0) return nullptr;
    size_t* found_positions = new size_t[count + 1];
    found_positions[0] = count;

    size_t index = 1;
    size_t pos = -1;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy) {
            pos++;
            if (_data[i] == value)
                found_positions[index++] = pos;
        }
    }

    return found_positions;
}

template <typename T>
void TArchive<T>::push_back(T value) {
    insert(value, _size);
}

template <typename T>
T TArchive<T>::pop_back() {
    if (!(_size-_deleted)) throw std::logic_error("No elements");
    for (size_t i = _size-1; i>=0; i--) {
        if (_states[i] == State::busy) {
            T value = _data[i];
            remove(i);
            return value;
        }
    }
    
}

template <typename T>
void TArchive<T>::push_front(T value) {
    insert(value, 0);
}

template <typename T>
T TArchive<T>::pop_front() {
    if (!(_size-_deleted)) throw std::logic_error("No elements");
    for (size_t i = 0; i<_size; i++) {
        if (_states[i] == State::busy) {
            T value = _data[i];
            remove(i);
            return value;
        }
    }
}

template <typename T>
void TArchive<T>::print() const noexcept {
    IC(_states);
    IC(_size, _capacity, _deleted);
    
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted)
            std::cout << _data[i] << ", ";
#ifdef DEBUG
        else
            std::cout << "\x1b[31m" << _data[i] << "\x1b[m" << ", ";
#endif
    }
}

/*
// пример реализации с возвратом массива найденных позиций

*/

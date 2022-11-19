#pragma once
#include <string>
#include <cmath>
#include "Lista.h"

using namespace std;

template<class T>
class HashTable {


public:
    HashTable(size_t capacity) : _capacity(capacity) {
        _size = 0;
        _hashTable = new Lista<Element>*[capacity];
        for (int i = 0; i < capacity; ++i) _hashTable[i] = nullptr;
    }
    void insert(std::string key, T value) {
        if (_size == _capacity) throw "Hash table is full";
        int index = _hashFunction(key);
        if (_hashTable[index] == nullptr) _hashTable[index] = new Lista<Element>();
        _hashTable[index]->AgregarInicio(Element{ key,value });
        ++_size;
    }
    T& operator[](std::string key) {
        int index = _hashFunction(key);
        auto list = _hashTable[index];
        T value = _hashTable[index]->getByCriteria([&](Element e) -> bool {
            return e.key = key;
            });
        return value;
    }
    T getCopy(std::string key) {
        int index = _hashFunction(key);
        auto list = _hashTable[index];
        T value = _hashTable[index]->getByCriteria([&](Element e) -> bool {
            return e.key = key;
            });
        return value;
    }
    void displayy(void (*show)(T)) {
        for (unsigned int i = 0; i < _capacity; ++i) {
            if (_hashTable[i] == nullptr)continue;
            if (_hashTable[i] != nullptr) {
                std::cout << "\nBanco: ";
                _hashTable[i]->display([&](Element a) -> void {
                    show(a.value);
                    });
                continue;
            }
            /*_hashTable[i]->display([&](Element a) -> void {
                show(a.value);
                });*/
        }
    }
    void displayk(void (*show)(T),string key) {
        int index = _hashFunction(key);
        if (_hashTable[index] == nullptr) { cout << "No tiene tarjetas con ese banco agregadas"; }
        else if(_hashTable[index] != nullptr) {
            std::cout << "\nBanco: ";
            _hashTable[index]->display([&](Element a) -> void {
                show(a.value);
                });
            
        }
    }
    bool Esvacia() {
        return(_size == 0);
    }
private:
    struct Element {
        string key;
        T value;
    };
    Lista<Element>** _hashTable;
    size_t _size;
    size_t _capacity;
private:
    int _hashFunction(string key) {
        int res = 0;
        for (unsigned int i = 0; i < key.length(); ++i) {
           /* res += pow(static_cast<int>(key[i]), i + 1);*/
            res += static_cast<int>(key[i]);
        }
         // 0´1 1'2 2'3 3'4  
        return res % _capacity;
    }
};

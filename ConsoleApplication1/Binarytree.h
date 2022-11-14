#include <functional>
using namespace std;
template<class T>

class BinarySearchTree {

public:
    BinarySearchTree(function<void(T)> show, function<bool(T, T)> compare,function<void(T)> proce) : _show(show), _compare(compare),_procesar(proce)  {
        _root = nullptr;
        _size = 0ll;
    }
    void insert(T value) {
        _insert(_root, value);
    }
    T getNom() {
        T dato = _root->value;
        return dato;
    }
    bool EsVacia() {
        return (_root == nullptr);
    }
    void preOrder() {
        _preOrder(_root);
    }
    void enOrden() {
        _enOrden(_root);
    }
    void posOrden() {
        _posOrden(_root);
    }
    // Rightmost element
    T max() {
        Node* aux = _root;
        while (aux->rightChild != nullptr) aux = aux->rightChild;
        return aux->value;
    }
    // Leftmost element
    T min() {
        Node* aux = _root;
        while (aux->leftChild != nullptr) aux = aux->leftChild;
        return aux->value;
    }
    void roadTree(function<void(T)> countinRange) {
        _road(_root, countinRange);
    }
private:
    struct Node {
        T value;
        Node* leftChild;
        Node* rightChild;
    };
    Node* _root;
    size_t _size;
    function<void(T)> _show;
    function<void(T)> _procesar;
    function<bool(T, T)> _compare; // lambda a criterio de comparacion
    void(*compEdad)(T); // Puntero a funcion

private:
    void _insert(Node*& n, T value) {
        if (n == nullptr) {
            n = new Node{ value, nullptr, nullptr };
            return;
        }
        if (_compare(n->value, value)) _insert(n->leftChild, value);
        else _insert(n->rightChild, value);
    }
 
    void _preOrder(Node* n) {
        // if(n == nullptr) return;
        if (!n) return;
        _show(n->value); // N
        _preOrder(n->leftChild); // Izq
        _preOrder(n->rightChild); // Der
    }
    void _road(Node* n, std::function<void(T)> countInRange) {
        if (!n) return;
        countInRange(n->value);
        _road(n->leftChild, countInRange);
        _road(n->rightChild, countInRange);

    }
    void _enOrden(Node* n) {
        if (n == nullptr) return;
        _enOrden(n->leftChild);
        _show(n->value);
        _enOrden(n->rightChild);
    }
    void _posOrden(Node* n) {
        if (n == nullptr) return;
        _enOrden(n->leftChild);
        _enOrden(n->rightChild);
        _show(n->value);
    }

    
};
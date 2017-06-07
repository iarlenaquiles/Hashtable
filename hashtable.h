#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "item.h"
#include <iostream>
using namespace std;
template <class T>
class hashtable{
public:
    const float max_aloc = 0.5;

    Item<T> * vet;
    int max;
    int qtd;

    hashtable(int max){
        this->max = max;
        this->qtd = 0;
        this->vet = new Item<T>[max];
    }

    void rebuild(int new_size){
        auto aux = vet;
        vet = new Item<T>[new_size];
        int old_max = max;
        max = new_size;
        qtd = 0;
        for(int i = 0; i < old_max; i++)
            if(aux[i].key != VAZIO)
                insert(aux[i].key, aux[i].value);

        delete [] aux;
    }

    int find(int key){
        int pos = key % max;

        while(vet[pos].key != key && vet[pos].key != VAZIO)
            pos = (pos + 1) % max;
        return pos;
    }

    bool insert(int key, T value){
        int pos = find(key);

        if(vet[pos].key == VAZIO){
            vet[pos] = Item<T>(key, value);
            qtd++;
            if(qtd > (max * max_aloc))
                rebuild(2 * max);
            return true;
        }

        return false;
    }

    bool exist(int key){
        int pos = find(key);
        if(vet[pos].key != VAZIO)
            return true;
        return false;
    }

    T& get(int key){
        return vet[find(key)].value;
    }

    bool erase(int key){
        int pos = find(key);
        if(vet[pos].key != VAZIO){
            vet[pos].key = VAZIO;

            qtd--;

            int posaux = (pos + 1) % max;
            while(vet[posaux].key != VAZIO){
                Item<T> item = vet[posaux];
                vet[posaux].key = VAZIO;
                qtd--;
                insert(item.key, item.value);
            }
            return true;
        }
        return false;
    }

    void show(){
        for(int i = 0; i < max; i++){
            cout << "[" << i << ":" << vet[i].key << "." << vet[i].value << "]";
        }

        cout << endl;
    }

    int size(){
        return qtd;
    }

    int maxQ(){
        return max;
    }
};

#endif // HASHTABLE_H

#ifndef ITEM_H
#define ITEM_H
const int VAZIO = -1;
template <class T>
class Item{
public:
    int key;
    T value;

    Item(int key = VAZIO){
        this->key = key;
    }

    Item(int key, T value){
        this->key = key;
        this->value = value;
    }

};
#endif // ITEM_H

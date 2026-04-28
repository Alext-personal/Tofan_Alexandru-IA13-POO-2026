#include <stdio.h>
#include <utility>

template <class K,class V>
class Map
{
private:
    struct Pair
    {
        K key;
        V value;
        int index;
        Pair& operator=(const Pair& other)
        {
            this -> key = other.key;
            this -> value = other.value;
            this -> index = other.index;
            return *this;
        }
    };
    int maxIndex = 0;
    int size = 0;
    Pair* content;
    void resize(int newSize)
    {
        Pair* newContent = new Pair[newSize];
        for (int i = 0; i < maxIndex; i++)
        {
            newContent[i] = content[i];
        }
        delete[] content;
        content = newContent;
        size = newSize;
    }
    void shiftLeft(int index)
    {
        for (int i = index; i < maxIndex - 1; i++)
            content[i] = content[i + 1];
        maxIndex--;
    }
    int searchKey(K key)
    {
        for (int i = 0; i < maxIndex; i++)
        {
            if (content[i].key == key)
                return i;
        }
        return -1;
    }
public:
    Map()
    {
        maxIndex = 0;
        size = 1;
        content = new Pair[size];
    }
    ~Map()
    {
        delete[] content;
    }
    Pair* begin() const
    {
        return content;
    }
    Pair* end() const
    {
        return content + maxIndex;
    }
    int Set(K key, V value)
    {
        int index = searchKey(key);
        if (index == -1)
        {
            if (maxIndex == size)
                resize(size*2);
            content[maxIndex].key = key;
            content[maxIndex].value = value;
            content[maxIndex].index = maxIndex;
            return maxIndex++;
        }
        else
        {
            content[index].value = value;
            return index;
        }
    }
    bool Get(const K& key, V& value)
    {
        int index = searchKey(key);
        if (index == -1)
            return false;
        value = content[index].value;
        return true;
    }
    int Count()
    {
        return maxIndex;
    }
    void Clear()
    {
        maxIndex = 0;
    }
    bool Delete(const K& key)
    {
        int index = searchKey(key);
        if (index == -1)
            return false;
        shiftLeft(index);
        return true;
    }
    bool Includes(const Map<K,V>& map)
    {
        V tempValue;
        for (auto i:map)
        {
            if (!Get(i.key, tempValue))
                return false;
        }
        return true;
    }
    V& operator[](const K& key)
    {
        int index = Set(key, V());
        return content[index].value;
    }
    
};
int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}

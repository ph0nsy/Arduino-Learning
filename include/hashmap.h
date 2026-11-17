// Compact hashmap implementation as seen in https://xnacly.me/posts/2024/c-hash-map/
#include <hash.h>
#include <assert.h>

using namespace LaMancha;

template <typename T>
struct Map
{ 
    size_t size; 
    size_t cap; 
    T *buckets; 
    
    void put(const char *str, T value) { 
        size++; 
        buckets[Utils::hash(str) & (cap - 1)] = value; 
    };
    T get(const char *str) { 
        return buckets[Utils::hash(str) & (cap - 1)]; 
    };
};

template <typename T>
Map<T> init(size_t cap) {
    Map<T> m = {0,cap};
    m.buckets = (T*)malloc(sizeof(T)*m.cap);
    assert(m.buckets != NULL);
    return m;
};
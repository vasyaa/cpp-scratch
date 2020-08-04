#include <iostream>
using namespace std;

namespace Sum1 {
// template <int... v> int sum()
    template<typename... V>
    double sum(V... v);

//template <int n>
    template<>
    double sum<>() {
        return 0;
    }

    template<typename T, typename... V>
    double sum(T t, V... v) {
        return sum<V...>(v...) + t;
    }
}

namespace Sum2 {
// template <int.. v> struct sum
    template <typename ...V>
    double sum();

//    template <typename T, typename ...V>
//    double sum<T, V...>() {
//
//    }

}

namespace Sum3 {
// template <double ... T>
template <int ...v>
struct sum;

template <int a>
struct sum<a> {
    static const int value = a;
};

template <int a, int ... v>
struct sum<a, v...> {
    static const int value = a + sum<v...>::value;
};

}

// list
// template <typename ... T> struct list;
// struct list::next
template <typename ... T>
struct list;

template <typename T>
struct list<T> {
    T value;
    nullptr_t next;
    list(const T& t):value(t){}
};

template <typename T, typename ... Rest>
struct list<T, Rest...> {
    T value;
    list<Rest...> next;
    list(const T& t, Rest... rest):value(t), next(rest...) {}
};


// in_set

// fib


int main() {
    {
        auto n = Sum1::sum(1, 2, 3, 4.2, 5.7);
        cout << n << endl;
    }
    {
        Sum3::sum<1,2,3,4,5> s;
        auto n = s.value;
        cout << n << endl;

    }
    {
        list <int, int, int, int, int> l(1,2,3,4,5);
        cout << l.value << " ";
        cout << l.next.value << " ";
        cout << l.next.next.value << " ";
        cout << l.next.next.next.value << " ";
        cout << l.next.next.next.next.value << endl;
        cout << l.next.next.next.next.next << endl;

    }
    return 0;
}
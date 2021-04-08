#include <iostream>
#include <utility>
using namespace std;

// negate

// print - tempalte
namespace Print1 {
    void print() {
        std::cout << std::endl;
    }

    template <typename T, typename ... Args>
    void print(const T& t, Args&&... args) {
        std::cout << t << " ";
        print(args...);
    }
}

// print - fold function
namespace Print2 {

template <typename ... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << std::endl;
}

}

namespace Sum1 {
//    template<typename... V>
//    double sum(V... v);

}

namespace Sum2 {
// ?
//    template <typename ...V>
//    double sum();


}

namespace Sum3 {
//    template <int ...v>
//    struct sum;

}

//////////////////////////////////////////
//template <typename ... Types>
//struct list;

template <typename ...Args>
struct list;

template <typename T>
struct list<T> {
    const T value;
    explicit list(T  v): value(std::move(v)) {}
};

template <typename T, typename ...Args>
struct list<T, Args...> {
    const T value;
    list<Args...> next;

//    explicit list(T v, Args... args):value(std::move(v)), next(args...) {}

    template <typename U>
    list(U&& v, Args... args):value(std::forward<U>(v)), next(args...){}
};

template <typename ... Args>
list<Args...> make_list(Args... args) {
    return list<Args...>(std::forward<Args>(args)...);
}

// in_set

// fibonacci

namespace Is_Same {
// template <typename A, typename B>
// is_same
template <typename T, typename U>
struct is_same {
    const bool value = false;
};

template <typename T>
struct is_same<T, T> {
    const bool value = true;
//    enum {value2 = true};
};

}


int main() {
    {
        auto p = "asdfgh";
        Print1::print(1, 2, 3, p);
        Print2::print(1, 2, 3, p);
    }
//    {
//        auto n = Sum1::sum(1, 2, 3, 4.2, 5.7);
//        cout << n << endl;
//    }
//    {
//        Sum3::sum<1,2,3,4,5> s;
//        auto n = s.value;
//        cout << n << endl;
//
//    }
    {
        auto i = 100;
        auto b = "qwerty";
        list <int, int, int, int, std::string, std::string> l(1,2,3, i, "asdf", b);
        cout << l.value << " ";
        cout << l.next.value << " ";
        cout << l.next.next.value << " ";
        cout << l.next.next.next.value << " ";
        cout << l.next.next.next.next.value << endl;
        cout << l.next.next.next.next.next.value << endl;
//        cout << l.next.next.next.next.next << endl;

        auto l2 = make_list(1, 2, i, b);
        cout << l2.value << " ";
        cout << l2.next.value << " ";
        cout << l2.next.next.value << " ";
        cout << l2.next.next.next.value << " ";
        std::cout << std::endl;

    }

    std::cout << is_same<int, std::int32_t>::value << endl;
    std::cout << is_same<int, long>::value << endl;
    return 0;
}

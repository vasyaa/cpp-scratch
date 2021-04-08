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

//template <typename ... T>
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

    explicit list(T v, Args... args):value(std::move(v)), next(args...) {}
};

template <typename ... Args>
list<Args...> make_list(Args... args) {
    return list<Args...>(std::forward<Args>(args)...);
}

// in_set

// fibonacci

// template <typename A, typename B>
// is_same


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
        int i = 100;
        list <int, int, int, int, std::string> l(1,2,3, i, "asdf");
        cout << l.value << " ";
        cout << l.next.value << " ";
        cout << l.next.next.value << " ";
        cout << l.next.next.next.value << " ";
        cout << l.next.next.next.next.value << endl;
//        cout << l.next.next.next.next.next << endl;

        auto l2 = make_list(1,2);
        cout << l2.value << " ";
        cout << l2.next.value << " ";

    }
    return 0;
}

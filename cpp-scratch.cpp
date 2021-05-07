#include <iostream>
#include <utility>
using namespace std;

// negate

// print - tempalte
namespace Print1 {
void print() { std::cout << std::endl; }

template <typename T, typename... Args>
void print(const T& t, Args&&... args) {
    std::cout << t << " ";
    print(args...);
}
}  // namespace Print1

// print - fold function
namespace Print2 {

template <typename... Args>
void print(Args&&... args) {
    (std::cout << ... << args) << std::endl;
}

}  // namespace Print2

namespace Sum1 {
//    template<typename... V>
//    double sum(V... v);

template <typename T>
double sum(T t) {
    return t;
}

template <typename T, typename... Args>
double sum(T t, Args... args) {
    return t + sum(args...);
}
}

namespace Sum2 {
// ?
//    template <typename ...V>
//    double sum();

}

namespace Sum3 {
//    template <int ...v>
//    struct sum;

template <int v, int ...Args>
struct sum {
    static const int value = v + sum<Args...>::value;
};

template <int v>
struct sum<v> {
    static const int value = v;
};
}

namespace Sum4 {

template <typename ...Args>
auto sum(Args... args) {
    return (args + ...);
}

}

namespace Sum5 {

template <typename T>
auto sum(const std::initializer_list<T>& l) {
    T t{};
    for(auto& i : l) {
        t += i;
    }
}

}

namespace List {
//////////////////////////////////////////
// template <typename ... Types>
// struct list;
// method size()

template <typename... Args>
struct list;

template <typename T>
struct list<T> {
    const T value;
    explicit list(T v) : value(std::move(v)) {}
    constexpr size_t size() { return 1; }
};

template <typename T, typename... Args>
struct list<T, Args...> {
    const T value;
    list<Args...> next;

    //    explicit list(T v, Args... args):value(std::move(v)), next(args...) {}

    template <typename U>
    explicit list(U&& v, Args... args) : value(std::forward<U>(v)), next(args...) {}

    constexpr size_t size() { return 1 + next.size(); }
};

template <typename... Args>
list<Args...> make_list(Args... args) {
    return list<Args...>(std::forward<Args>(args)...);
}
}  // namespace List

namespace Tuple {
// template <typename ... Types>
// tuple

template <typename... Types>
struct tuple;

template <typename T>
struct tuple<T> {
    explicit tuple(T& v) : value(v) {}
    T value;
};

template <typename T, typename... Types>
struct tuple<T, Types...> {
    explicit tuple(const T& v, Types... args) : value(v), next(args...) {}
    T value;
    tuple<Types...> next;
};

}  // namespace Tuple

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

}  // namespace Is_Same


namespace List2 {

template <typename ...Args>
struct list;

template <typename T>
struct list<T> {
    explicit list(const T& t):value(t) {}
    const T value;

    size_t size() {
        return 1;
    }
};

template <typename T, typename ...Args>
struct list<T, Args...> {
    explicit list(T t, Args... args):value(t),next(args...) {}
    const T value;
    list<Args...> next;

    size_t size() {
        return next.size() + 1;
    }
};

template <typename ...Args>
auto make_list(Args... args) {
    return list<Args...>(args...);
}

}

template <typename T>
struct is_integer {
    static const bool value = false;
};

template <>
struct is_integer<int> {
    static const bool value = true;
};

int main() {
//    {
//        auto p = "asdfgh";
//        Print1::print(1, 2, 3, p);
//        Print2::print(1, 2, 3, p);
//    }
        {
            auto n = Sum1::sum(1, 2, 3, 4.2, 5.7);
            cout << n << endl;
        }
        {
            auto n = Sum3::sum<1, 2, 3, 4, 5>::value;
            cout << n << endl;
            static_assert(Sum3::sum<1, 2, 3, 4, 5>::value == 15, "Value should be 15");
        }
    {
        auto n = Sum4::sum(1, 2, 3, 4, 5);
        cout << n << endl;
//        assert(n == 15);
    }
    {
        auto i = 100;
        auto b = "qwerty";
        List::list<int, int, int, int, std::string, std::string> l(1, 2, 3, i, "asdf", b);
        cout << l.value << " ";
        cout << l.next.value << " ";
        cout << l.next.next.value << " ";
        cout << l.next.next.next.value << " ";
        cout << l.next.next.next.next.value << endl;
        cout << l.next.next.next.next.next.value << endl;
        cout << "size " << l.size() << endl;
        //        cout << l.next.next.next.next.next << endl;

        auto l2 = List::make_list(1, 2, i, b);
        cout << l2.value << " ";
        cout << l2.next.value << " ";
        cout << l2.next.next.value << " ";
        cout << l2.next.next.next.value << " ";
        std::cout << std::endl;
        cout << "size " << l2.size() << endl;
    }

    {
        Tuple::tuple<int, int> t(1, 2);

        std::cout << t.value << std::endl;
    }

    std::cout << is_same<int, std::int32_t>::value << endl;
    std::cout << is_same<int, long>::value << endl;

    {
        List2::list<int, std::string> l(1, "asasasa");

        auto l2 = List2::make_list(1,2,3,4, "asasasa");
        std::cout << l2.next.next.value << std::endl;
    }

    {
        cout << is_integer<long>::value << std::endl;
        cout << is_integer<short>::value << std::endl;
        cout << is_integer<int>::value << std::endl;
    }
    return 0;
}

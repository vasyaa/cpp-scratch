#include <bits/stdc++.h>

using namespace std;

// negate

// print - tempalte function
namespace Print1 {

}  // namespace Print1

// print - fold function
namespace Print2 {



}  // namespace Print2

namespace Sum1 {
//    template<typename... V>
//    double sum(V... v);

template <typename T>
auto sum(T v) {
    return v;
}

template <typename T, typename ...Args>
auto sum(T v, Args ... args) {
    return v + sum(args...);
}

}

namespace Sum3 {
//    template <int v, int ...Args>
//    struct sum;

template <typename ...Args>
struct sum;

template <typename T>
struct sum<T> {
    explicit sum(T v) : value(v) {}
    const T value;
};

template <typename T, typename ...Args>
struct sum<T, Args...> {
    explicit sum(T v, Args... args) : value(v + sum<Args...>(args...).value) {}
    const T value;
};

template<typename ...Args>
auto make_sum(Args... args) {
    return sum<Args...>(args...);
}

}

namespace Sum5 {

//template <typename T>
//auto sum(const std::initializer_list<T>& l) {

}

namespace List {
//////////////////////////////////////////
// template <typename ... Types>
// struct list;
// function size()
//
// make_list

}  // namespace List

namespace Tuple {
// template <typename ... Types>
// tuple


}  // namespace Tuple

// in_set

// fibonacci

namespace Is_Same {
// template <typename A, typename B>
// is_same

}  // namespace Is_Same


namespace IsInteger {
// struct is_integer {

}

namespace Range {

template <typename T>
struct range {
    T ibegin;
    T iend;
    range(T ibegin, T iend) : ibegin(ibegin), iend(iend) {}

    struct iterator {
        T pos;
        explicit iterator(T pos) : pos(pos) {}
        explicit operator T() {return pos;}
        explicit operator T&() {return pos;}
        T operator*() {return pos;}

        iterator operator++() {
            ++pos;
            return *this;
        }
        friend bool operator==(const iterator& lh, const iterator& rh){
            return lh.pos == rh.pos;
        }
        friend bool operator!=(const iterator& lh, const iterator& rh){
            return !(lh == rh);
        }
    };

    iterator begin() {return iterator(ibegin);}
    iterator end() {return iterator(iend);}
};


}

int main() {
    {
        using namespace Range;
        for(auto i : range(0, 10)) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    {
        Sum3::sum<int, int, int> s(1,2,3);
        std::cout << s.value << std::endl;

        auto s2 = Sum3::make_sum(1.0,2,3,4,5.1);
        std::cout << s2.value << std::endl;
    }
//    {
//        auto p = "asdfgh";
//        Print1::print(1, 2, 3, p);
//        Print2::print(1, 2, 3, p);
//    }
        {
            auto n = Sum1::sum(1, 2, 3, 4.2, 5.7);
            cout << n << endl;
        }
//        {
//            auto n = Sum3::sum<1, 2, 3, 4, 5>::value;
//            cout << n << endl;
//            static_assert(Sum3::sum<1, 2, 3, 4, 5>::value == 15, "Value should be 15");
//        }
//    {
//        auto n = Sum4::sum(1, 2, 3, 4, 5);
//        cout << n << endl;
////        assert(n == 15);
//    }
//    {
//        auto i = 100;
//        auto b = "qwerty";
//        List::list<int, int, int, int, std::string, std::string> l(1, 2, 3, i, "asdf", b);
//        cout << l.value << " ";
//        cout << l.next.value << " ";
//        cout << l.next.next.value << " ";
//        cout << l.next.next.next.value << " ";
//        cout << l.next.next.next.next.value << endl;
//        cout << l.next.next.next.next.next.value << endl;
//        cout << "size " << l.size() << endl;
//        //        cout << l.next.next.next.next.next << endl;
//
//        auto l2 = List::make_list(1, 2, i, b);
//        cout << l2.value << " ";
//        cout << l2.next.value << " ";
//        cout << l2.next.next.value << " ";
//        cout << l2.next.next.next.value << " ";
//        std::cout << std::endl;
//        cout << "size " << l2.size() << endl;
//    }
//
//    {
//        Tuple::tuple<int, int> t(1, 2);
//
//        std::cout << t.value << std::endl;
//    }
//
//    std::cout << is_same<int, std::int32_t>::value << endl;
//    std::cout << is_same<int, long>::value << endl;
//
//    {
//        List2::list<int, std::string> l(1, "asasasa");
//
//        auto l2 = List2::make_list(1,2,3,4, "asasasa");
//        std::cout << l2.next.next.value << std::endl;
//    }
//
//    {
//        cout << is_integer<long>::value << std::endl;
//        cout << is_integer<short>::value << std::endl;
//        cout << is_integer<int>::value << std::endl;
//    }
//
//    {
//        std::unordered_map<int, std::string> m{{1,"asas"},{2, "xcxcxcx"}};
//    }
    return 0;
}

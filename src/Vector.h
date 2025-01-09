#pragma once
#include <iostream>
#include <sol/sol.hpp>

template <typename  T>
struct Vector2{
    T x{};
    T y{};
    Vector2(){}
    Vector2(T x, T y) : x{x}, y{y} {}
    double DistSq(Vector2 other){
        T subX = std::abs(x-other.x);
        T subY = std::abs(y-other.y);
        return subX * subX + subY * subY;
    }
    void Print(){
        tcout<< "(" << x << "," << y <<")";
    }
    static void CreateBindings(sol::state& state, const tstring& name){
        state.new_usertype<Vector2<T>>(
            name,
            sol::constructors<Vector2<T>(),Vector2<T>(T,T)>(),
            "x", &Vector2<T>::x,
            "y", &Vector2<T>::y,
            "print", &Vector2<T>::Print,
            "DistSq", &Vector2<T>::DistSq
	    );
    }
};

typedef Vector2<float> Vector2f;

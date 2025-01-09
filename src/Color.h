#pragma once
#include <cstdint>
#include "GameEngine.h"
#include <windows.h>
#include <sol/sol.hpp>


class Color{
public:
    uint8_t r{},g{},b{};
    Color(){};
    Color(uint8_t r, uint8_t g, uint8_t b) : r{r},g{g},b{b}{}
    
    COLORREF ToColorRef(){
        //convert this color into the usual windows color for the main functions
       return RGB(r, g, b);
    }
    static Color GetColorFromColorRef(COLORREF color){
        return Color(GetRValue(color),GetGValue(color),GetBValue(color));
    }
    static void CreateBindings(sol::state& state){
        state.new_usertype<Color>(
            "Color",
            sol::constructors<Color(),Color(uint8_t,uint8_t,uint8_t)>(),
            "r", &Color::r,
            "g", &Color::g,
            "b", &Color::b
        );
    }
};
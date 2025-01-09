#pragma once
#include <sol/sol.hpp>
#include <windows.h>
#include <cstdint>
#include "GameEngine.h"
#include "Vector.h"

class UtilsBindings{
public:
    static void SetTitle(const tstring& title){GAME_ENGINE->SetTitle(title);}
	static void SetWindowPosition(Vector2f pos){
        GAME_ENGINE->SetWindowPosition(static_cast<int>(pos.x),static_cast<int>(pos.y));
    }
	static void SetFrameRate(int frameRate){GAME_ENGINE->SetFrameRate(frameRate);}
	static void SetWidth(int width){GAME_ENGINE->SetWidth(width);}
	static void SetHeight(int height){GAME_ENGINE->SetHeight(height);}
    static bool GoFullscreen(){return GAME_ENGINE->GoFullscreen();}		
	static bool GoWindowedMode(){return GAME_ENGINE->GoWindowedMode();}
	static void ShowMousePointer(bool value){GAME_ENGINE->ShowMousePointer(value);}
	static void Quit(){GAME_ENGINE->Quit();}
	static bool IsFullscreen(){return GAME_ENGINE->IsFullscreen();}
    static bool IsKeyDown(int key){return GAME_ENGINE->IsKeyDown(key);}
    static tstring GetTitle(){return GAME_ENGINE->GetTitle();}
    static int GetWidth(){return GAME_ENGINE->GetWidth();}
    static int GetHeight(){return GAME_ENGINE->GetHeight();}
    static int GetFrameRate(){return GAME_ENGINE->GetFrameRate();}
    static int GetFrameDelay(){return GAME_ENGINE->GetFrameDelay();}
    static void CreateBindings(sol::state& state){
        state.new_usertype<UtilsBindings>(
            "Utils",
            "SetTitle", &UtilsBindings::SetTitle,
            "SetWindowPos", &UtilsBindings::SetWindowPosition,
            "SetFrameRate", &UtilsBindings::SetFrameRate,
            "SetWidth", &UtilsBindings::SetWidth,
            "SetHeight", &UtilsBindings::SetHeight,
            "GoFullscreen", &UtilsBindings::GoFullscreen,
            "GoWindowedMode", &UtilsBindings::GoWindowedMode,
            "ShowMousePointer", &UtilsBindings::ShowMousePointer,
            "Quit", &UtilsBindings::Quit,
            "IsFullscreen", &UtilsBindings::IsFullscreen,
            "IsKeyDown", &UtilsBindings::IsKeyDown,
            "GetTitle", &UtilsBindings::GetTitle,
            "GetWidth", &UtilsBindings::GetWidth,
            "GetHeight", &UtilsBindings::GetHeight,
            "GetFrameRate", &UtilsBindings::GetFrameRate,
            "GetFrameDelay", &UtilsBindings::GetFrameDelay,
            "CreateBindings", &UtilsBindings::CreateBindings
        );
    }
};
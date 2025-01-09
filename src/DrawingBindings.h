#pragma once
#include <sol/sol.hpp>
#include <windows.h>
#include <cstdint>
#include "GameEngine.h"


class DrawBindings{
public:
    static void SetColor(Color color) {GAME_ENGINE->SetColor(color.ToColorRef());}
    //static void SetFont()
    static bool FillWindowRect(Color color){return GAME_ENGINE->FillWindowRect(color.ToColorRef());}
    static bool DrawLine(Vector2f p1, Vector2f p2){
        return GAME_ENGINE->DrawLine(static_cast<int>(p1.x),static_cast<int>(p1.y),static_cast<int>(p2.x),static_cast<int>(p2.y));
    }
    static bool DrawRect(Vector2f p1, Vector2f p2) {
        return GAME_ENGINE->DrawRect(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y));
    }
    static bool FillRect(Vector2f p1, Vector2f p2, int opacity) {
        return GAME_ENGINE->FillRect(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y), opacity);
    }
    static bool DrawRoundRect(Vector2f p1, Vector2f p2, int radius) {
        return GAME_ENGINE->DrawRoundRect(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y), radius);
    }
    static bool FillRoundRect(Vector2f p1, Vector2f p2, int radius) {
        return GAME_ENGINE->FillRoundRect(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y), radius);
    }
    static bool DrawOval(Vector2f p1, Vector2f p2) {
        return GAME_ENGINE->DrawOval(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y));
    }
    static bool FillOval(Vector2f p1, Vector2f p2, int opacity) {
        return GAME_ENGINE->FillOval(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y), opacity);
    }
    static bool DrawArc(Vector2f p1, Vector2f p2, int startDegree, int angle) {
        return GAME_ENGINE->DrawArc(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y), startDegree, angle);
    }
    static bool FillArc(Vector2f p1, Vector2f p2, int startDegree, int angle) {
        return GAME_ENGINE->FillArc(static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y), startDegree, angle);
    }
    static int DrawString(const tstring& text, Vector2f p) {
        return GAME_ENGINE->DrawString(text, static_cast<int>(p.x), static_cast<int>(p.y));
    }
    static int DrawStretchedString(const tstring& text, Vector2f p1, Vector2f p2) {
        return GAME_ENGINE->DrawString(text, static_cast<int>(p1.x), static_cast<int>(p1.y), static_cast<int>(p2.x), static_cast<int>(p2.y));
    }
    static Color GetDrawColor(){return Color::GetColorFromColorRef(GAME_ENGINE->GetDrawColor());}
    static void Redraw(){GAME_ENGINE->Repaint();};

    static void CreateBindings(sol::state& state){
        state.new_usertype<DrawBindings>(
            "Draw",
            "SetColor",         &DrawBindings::SetColor,
            "FillWindowRect",   &DrawBindings::FillWindowRect,
            "DrawLine",         &DrawBindings::DrawLine,
            "DrawRect",         &DrawBindings::DrawRect,
            "FillRect",         &DrawBindings::FillRect,
            "DrawRoundRect",    &DrawBindings::DrawRoundRect,
            "FillRoundRect",    &DrawBindings::FillRoundRect,
            "DrawOval",         &DrawBindings::DrawOval,
            "FillOval",         &DrawBindings::FillOval,
            "DrawArc",          &DrawBindings::DrawArc,
            "FillArc",          &DrawBindings::FillArc,
            "DrawString",       &DrawBindings::DrawString,
            "DrawStretchedString", &DrawBindings::DrawStretchedString,
            "GetDrawColor",     &DrawBindings::GetDrawColor,
            "Redraw",           &DrawBindings::Redraw
        );
    }
};

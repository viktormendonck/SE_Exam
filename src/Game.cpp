//-----------------------------------------------------------------
// Main Game File
// C++ Source - Game.cpp - version v8_01
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Game.h"
#include <sol/sol.hpp>
#include "Vector.h"
#include "Color.h"
#include "DrawingBindings.h"
#include "UtilsBindings.h"
//-----------------------------------------------------------------
// Game Member Functions																				
//-----------------------------------------------------------------

Game::Game() 																	
{
	// nothing to create
}

Game::~Game()																						
{
	// nothing to destroy
}

void Game::Initialize()			
{
	CreateBindings();
	// Code that needs to execute (once) at the start of the game, before the game window is created

	AbstractGame::Initialize();
	GAME_ENGINE->SetWidth(1024);
	GAME_ENGINE->SetHeight(1024);
    GAME_ENGINE->SetFrameRate(50);
	state.script_file("lua/GameOfLife.lua");
	sol::function solSetup{ state["Init"] };
	solUpdate = sol::function{state["Update"]};
	solDraw = sol::function{state["DrawFunc"]};
	solStart = sol::function{state["Start"]};
	solEnd = sol::function{state["End"]};
	solMouseAction = sol::function{state["MouseButtonAction"]};
	solMouseMove = sol::function{state["MouseMove"]};
	solMouseWheelAction = sol::function{state["MouseWheelAction"]};
	solCheckKeyboard = sol::function{state["CheckKeyboard"]};
	solSetup.call();


}

void Game::Start()
{
	solStart.call();
}

void Game::End()
{
	solEnd.call();
	printf("endTest\n");
}

void Game::Paint(RECT rect) const
{
	
	solDraw.call();
}

void Game::Tick()
{
	
	
	//why does this engine use milliseconds for deltatime, the fuck
	float deltaTime = static_cast<float>(GAME_ENGINE->GetFrameDelay());
	solUpdate.call(deltaTime/1000.f);
}

void Game::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
{	
	solMouseAction.call(isLeft,isDown,Vector2f{static_cast<float>(x),static_cast<float>(y)});
}

void Game::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	solMouseWheelAction.call(Vector2f(static_cast<float>(x),static_cast<float>(y)),distance);
}

void Game::MouseMove(int x, int y, WPARAM wParam)
{	
	solMouseMove.call(Vector2f(static_cast<float>(x),static_cast<float>(y)));
}

void Game::CheckKeyboard()
{	
	solCheckKeyboard.call();
}

void Game::KeyPressed(TCHAR key)
{	

}

void Game::CallAction(Caller* callerPtr)
{
}



void Game::CreateBindings(){
	state.open_libraries(sol::lib::base);

	Vector2<float>::CreateBindings(state,_T("Vector2f"));
	Color::CreateBindings(state);
	DrawBindings::CreateBindings(state);
	UtilsBindings::CreateBindings(state);

}

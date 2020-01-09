#include "Core/Framework/Events/InputEventHandler.h"
#include <stdexcept>

void InputEventHandler::Update( )
{
	SDL_Event event;
	while ( SDL_PollEvent( &event ) )
	{
		switch ( event.type )
		{
			case SDL_QUIT :
				AddQuitEvent();
				break;
			case SDL_KEYDOWN :
			case SDL_KEYUP :
				HandleKeyBoard( event );
				break;
			case SDL_MOUSEBUTTONDOWN :
			case SDL_MOUSEBUTTONUP :
				HandleMouseButton( event );
				break;
			case SDL_MOUSEMOTION :
				HandleMouseMove( event );
				break;
			default :
				break;
		}
	}
}
void InputEventHandler::AddQuitEvent()
{
	quit = true;
	events.push_back( Event( EventType::Quit ) );
}
void InputEventHandler::HandleKeyBoard( const SDL_Event &event )
{
	ButtonState state = ConvertButtonStateFromSDL( event.type, EventType::Keyboard );
	auto temp = keyCode[event.key.keysym.sym];
	if ( state != keyCode[ event.key.keysym.sym ] )
	{
		// Save new state of the button
		keyCode[ event.key.keysym.sym ] = state;

		AddKeyboardEvent( event );

		if ( event.key.keysym.sym == SDLK_ESCAPE )
			AddQuitEvent();
	}
}
void InputEventHandler::HandleMouseButton( const SDL_Event &event )
{
	MouseButton button = ConvertMouseButtonToEnum( event.button.button );
	ButtonState state = ConvertButtonStateFromSDL( event.type, EventType::MouseButton );

	if ( state != mouseButton[ button ] )
	{
		mouseButton[ button ] = state;
		AddMouseEvent( event );
	}
}
void InputEventHandler::HandleMouseMove( const SDL_Event &event )
{
	Event newEvent( EventType::MouseMotion );
	newEvent.mouseMove.newPos.x = event.motion.x;
	newEvent.mouseMove.newPos.y = event.motion.y;

	newEvent.mouseMove.relativePos.x = event.motion.xrel;
	newEvent.mouseMove.relativePos.y = event.motion.yrel;

	events.push_back( newEvent );

	mousePoint = newEvent.mouseMove.newPos;
}
ButtonState InputEventHandler::GetKeyState( SDL_Keycode key ) const
{
	ButtonState state;

	try
	{
		state = keyCode.at( key );
	}
	catch ( std::out_of_range &e )
	{
		state = ButtonState::Up;
	}

	return state;
}
bool InputEventHandler::IsKeyDown( SDL_Keycode key ) const
{
	return GetKeyState( key ) == ButtonState::Down;
}
ButtonState InputEventHandler::GetMouseButtonState(  MouseButton button ) const
{
	ButtonState buttonState;

	try
	{
		buttonState = mouseButton.at( button );
	}
	catch ( std::out_of_range &e )
	{
		buttonState = ButtonState::Up;
	}

	return buttonState;
}
bool InputEventHandler::IsMouseButtonDown( MouseButton button ) const
{
	return GetMouseButtonState( button ) == ButtonState::Down;
}
SDL_Point InputEventHandler::GetMousePoint( ) const
{
	return mousePoint;
}
void InputEventHandler::AddKeyboardEvent( const SDL_Event &event )
{
	events.push_back( CreateKeyboardEvent( event ) );
}
void InputEventHandler::AddMouseEvent( const SDL_Event &event )
{
	events.push_back( CreateMouseEvent( event ) );
}
Event InputEventHandler::CreateKeyboardEvent( const SDL_Event &event ) const
{
	Event keyEvent( EventType::Keyboard );
	keyEvent.keyboard.key = event.key.keysym.sym; 

	if ( event.type == SDL_KEYUP )
		keyEvent.keyboard.eventType = ButtonEventType::Released;
	else
		keyEvent.keyboard.eventType = ButtonEventType::Pressed;

	return keyEvent;
}
Event InputEventHandler::CreateMouseEvent( const SDL_Event &event ) const
{
	Event mouseEvent( EventType::MouseButton );
	mouseEvent.mouseButton.button = ConvertMouseButtonToEnum( event.button.button );

	if ( event.type == SDL_MOUSEBUTTONUP )
		mouseEvent.mouseButton.eventType = ButtonEventType::Released;
	else
		mouseEvent.mouseButton.eventType = ButtonEventType::Pressed;

	return mouseEvent;
}
std::vector< Event > InputEventHandler::GetEvents()
{
	return events;
}
void InputEventHandler::ClearEvents()
{
	//keyPresses.clear();
	events.clear();
}
MouseButton InputEventHandler::ConvertMouseButtonToEnum( uint8_t SDLButtonID ) const
{
	switch ( SDLButtonID )
	{
		case 1 :
			return MouseButton::Left;
		case 2 :
			return MouseButton::Middle;
		case 3 :
			return MouseButton::Right;
		default:
			break;
	}

	return MouseButton::Unknown;
}
uint8_t InputEventHandler::ConvertMouseButtonToID( MouseButton button ) const
{
	if (button == MouseButton::Left ){
            return 1;
	} else if (button == MouseButton::Middle){
            return 2;
	} else if (button == MouseButton::Right){
            return 3;
	}

	return -1;
}
ButtonState InputEventHandler::ConvertButtonStateFromSDL ( uint32_t keyEventID, EventType type ) const
{
	ButtonState state;

	if ( type == EventType::MouseButton )
	{
		if ( keyEventID == SDL_MOUSEBUTTONDOWN )
			state = ButtonState::Down;
		else
			state = ButtonState::Up;
	}
	else if ( type == EventType::Keyboard )
	{
		if ( keyEventID == SDL_KEYDOWN )
			state = ButtonState::Down;
		else
			state = ButtonState::Up;
	}

	return state;
}
uint32_t InputEventHandler::ConvertButtonStateToSDL ( ButtonState button, EventType type ) const
{
	if ( type == EventType::MouseButton )
	{
		if ( button == ButtonState::Down)
			return SDL_MOUSEBUTTONDOWN;
		else
			return SDL_MOUSEBUTTONUP;
	}

	return SDL_MOUSEBUTTONUP;
}

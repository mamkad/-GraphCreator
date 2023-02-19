#pragma once

// sfml 

#include <SFML/Graphics.hpp>

using sf::CircleShape;
using sf::RenderWindow;
using sf::RectangleShape;
using sf::VideoMode;
using sf::Event;
using sf::Vector2f;
using sf::Color;
using sf::Clock;
using sf::Font;
using sf::String;
using sf::Keyboard;
using sf::Mouse;
using sf::Text;

// std 

#include <string>
#include <memory>

using std::string;
using std::invalid_argument;
using std::shared_ptr;
using std::make_shared;

//

using WindowPtr = shared_ptr<RenderWindow>;


class GraphicObjectBase
{
    WindowPtr parentWindow = nullptr;
    
public:

    GraphicObjectBase();
    GraphicObjectBase(WindowPtr const& parentWindow);
    virtual ~GraphicObjectBase();

    bool             IsParentWindowNull() const noexcept; 
    void             SetParentWindow(WindowPtr const& parentWindow);
    WindowPtr const& GetParentWindow();

    Vector2f GetMousePos() const noexcept;

    virtual bool IsContain(Vector2f const& position) = 0;
    virtual void Update(float time = 0.0f)           = 0;
    virtual void Draw()                              = 0;
};
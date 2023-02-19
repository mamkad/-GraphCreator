#include "GraphicObjectBase.hpp"

#include <iostream>

GraphicObjectBase::GraphicObjectBase()
{
    std::cout << "GraphicObjectbase - parentWindow: " << parentWindow << " - created" << '\n';
}

GraphicObjectBase::GraphicObjectBase(WindowPtr const& parentWindow)
{
    SetParentWindow(parentWindow);

    std::cout << "GraphicObjectbase - parentWindow: " << parentWindow << " - created" << '\n';
}

GraphicObjectBase::~GraphicObjectBase()
{
    std::cout << "GraphicObjectbase - parentWindow: " << parentWindow << " - destroyed" << '\n';
}

bool GraphicObjectBase::IsParentWindowNull() const noexcept
{
    return (this->parentWindow == nullptr);
}

void GraphicObjectBase::SetParentWindow(WindowPtr const& parentWindow)
{
    this->parentWindow = parentWindow;
}

WindowPtr const& GraphicObjectBase::GetParentWindow()
{
    return this->parentWindow;
}

Vector2f GraphicObjectBase::GetMousePos() const noexcept
{
    auto position = Mouse::getPosition(*parentWindow);

    return { float(position.x), float(position.y) };    
}
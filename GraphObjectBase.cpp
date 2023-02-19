#include "GraphObjectBase.hpp"

#include <iostream>

GraphObjectBase::GraphObjectBase()
{
    std::cout << "GraphObjectBase - name: " << name << ", id: " << id << " - created" << '\n';
}

GraphObjectBase::GraphObjectBase(string const& name, unsigned long id, WindowPtr const& parentWindow) : GraphicObjectBase(parentWindow)
{
    SetName(name);
    SetId(id);

    std::cout << "GraphObjectBase - name: " << name << ", id: " << id << " - created" << '\n';
}

GraphObjectBase::~GraphObjectBase()
{
    std::cout << "GraphObjectBase - name: " << name << ", id: " << id << " - destroyed" << '\n';
}

bool GraphObjectBase::IsUnset() const noexcept
{
    return (this->name == "Unnamed") && (this->id == 0) && IsParentWindowNull();
}


void GraphObjectBase::SetName(string const& name)
{
    this->name = name;
}

string const& GraphObjectBase::GetName() const noexcept
{
    return this->name;
}


void GraphObjectBase::SetId(unsigned long id)
{
    this->id = id;
}

unsigned long GraphObjectBase::GetId() const noexcept
{
    return this->id;
}

void GraphObjectBase::SetTextValue(string const& strTextValue)
{
    this->strTextValue = strTextValue;
    text_setString( strTextValue.str());
}

bool GraphObjectBase::SetTextFont(string const& fontName)
{
    if (!outTextFont.loadFromFile(fontName)) {
        return false;
    }

    outText.setFont(outTextFont);
}

void GraphObjectBase::SetTextOrigin(float x, gloat y)
{

}

string const&  GraphObjectBase::GetTextValue()
{
    return strTextValue;
}
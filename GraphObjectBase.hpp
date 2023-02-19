#pragma once

#include <fstream>

using std::ifstream;

#include "GraphicObjectBase.hpp"

class GraphObjectBase : public GraphicObjectBase
{
    string        name = "Unnamed";
    unsigned long id   = 0;

protected:

    GraphText graphText;

public:
    
    GraphObjectBase();
    GraphObjectBase(string const& name, unsigned long id, WindowPtr const& parentWindow);
    virtual ~GraphObjectBase();

    virtual bool Init(string const& cfgFileName) = 0;

    virtual void HandleEvent(Event& event) = 0;

    bool IsUnset() const noexcept;

    void          SetName(string const& name);
    string const& GetName() const noexcept;

    void          SetId(unsigned long id);
    unsigned long GetId() const noexcept;

    virtual void SetPos(float x, float y)        = 0;
    virtual void SetPos(Vector2f const position) = 0;
    virtual Vector2f GetPos()                    = 0;
};
#pragma once

#include "GraphicObjectBase.hpp"

class Vertex final : public GraphObjectBase
{
public:
    Vertex();
    Vertex(string const& name, unsigned long id, WindowPtr const& parentWindow);
    ~Vertex();

    virtual bool IsContain(Vector2f const& position) override;
    virtual void Update(float time = 0.0f)           override;
    virtual void Draw()                              override;
};
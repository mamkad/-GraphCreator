#pragma once

#include "GraphObjectBase.hpp"

class NodeText final : public GraphicObjectBase
{
    string strTextValue = "Empty";
    Font   outTextFont
    Text   outText;

public:

    void           SetTextValue(string const& strTextValue);
    bool           SetTextFont(string const& fontName);
    void           SetTextOrigin(float x, float y);
    string const&  GetTextValue();
};

class NodeInput :  public GraphObjectBase
{
    
};

class Node final :  public GraphObjectBase
{
    CircleShape circle;

    float radiusSquare = 0.0f;

    bool isLeftClicked = false, isRightClicked = false;
    bool isSetKeyPressed = false;

public:

    Node();
    Node(string const& name, unsigned long id, WindowPtr const& parentWindow);
    ~Node();

    virtual bool Init(string const& cfgFileName)  override;

    virtual void HandleEvent(Event& event) override;

    virtual void SetPos(float x, float y)        override;
    virtual void SetPos(Vector2f const position) override;
    virtual Vector2f GetPos()                    override;

    virtual bool IsContain(Vector2f const& position) override;
    virtual void Update(float time = 0.0f)           override;
    virtual void Draw()                              override;
};

#include "Node.hpp"

Node::Node()
{

}

Node::Node(string const& name, unsigned long id, WindowPtr const& parentWindow) : GraphObjectBase(name, id, parentWindow)
{

}

Node::~Node()
{

}

bool Node::Init(string const& cfgFileName) 
{
    ifstream cfgFile(cfgFileName);

    if (!cfgFile) {
        return false;
    }

    float radius, pointCount, thicknes,
        fillColorRed, fillColorGreen, fillColorBlue,
        outColorRed,  outColorGreen,  outColorBlue,
        posX, posY;

    if (!(cfgFile >> radius >> pointCount >> thicknes
            >> fillColorRed >> fillColorGreen >> fillColorBlue 
            >> outColorRed  >> outColorGreen  >> outColorBlue
            >> posX >> posY)) {

        return false;
    }

    circle.setRadius(radius);
    circle.setPointCount(pointCount);
	circle.setOrigin(radius, radius);
    circle.setOutlineThickness(thicknes);
	circle.setFillColor(Color(fillColorRed, fillColorGreen, fillColorBlue));
	circle.setOutlineColor(Color(outColorRed, outColorGreen, outColorBlue));
    SetPos(posX, posY);

    cfgFile.close();

    radiusSquare = radius * radius;

    return true;
}

void Node::HandleEvent(Event& event) 
{
    
    if (isSetKeyPressed) {
        // input.HandlerEvent
        // return
    }

    auto type = event.type;
    auto key = event.key.code;

    if (type == Event::MouseButtonPressed) {
        if (key == Mouse::Left) {
            if (IsContain(GetMousePos())) {
                isLeftClicked = true;
            }
        }
        else if (key == Mouse::Right) {

        }  
    }
    else if (type == Event::MouseButtonReleased) {
        if (key == Mouse::Left) {
            isLeftClicked = false;
        }
        else if (key == Mouse::Right) {
        }  
    }
    else if (type == Event::KeyPressed) {
        if(key == Keyboard::S) {
            isSetKeyPressed = true;
        }
    }
}

void Node::SetPos(float x, float y)
{
    circle.setPosition(x, y);
}

void Node::SetPos(Vector2f const position)
{
    circle.setPosition(position.x, position.y);
}

Vector2f Node::GetPos()
{
    return circle.getPosition();
}

bool Node::IsContain(Vector2f const& position) 
{
    float x = position.x - GetPos().x,
          y = position.y - GetPos().y;

    return x * x  + y * y <= radiusSquare;
}

void Node::Update(float time)   
{
    if (isLeftClicked) {
        if (isSetKeyPressed) {

        }
        else {
            SetPos(GetMousePos());
        }
    }
}        

void Node::Draw() 
{
    GetParentWindow()->draw(circle);
}                           
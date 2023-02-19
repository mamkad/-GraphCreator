#include "Node.hpp"

#include <list>

using std::list;

int main()
{
    WindowPtr window = make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML window");

    list<shared_ptr<GraphObjectBase>> g;

    g.push_back(make_shared<Node>("node", 1, window));

    for (auto& n : g) {
        n->Init("Node.ini");
    } 
 
    while (window->isOpen()) {

        Event event;

        while (window->pollEvent(event)){

            if (event.type == Event::Closed)
                window->close();

            for (auto& n : g) {
                n->HandleEvent(event);
            } 
        }

        window->clear();

        for (auto& n : g) {
            n->Update();
            n->Draw();
        } 

        window->display();
    }
    return EXIT_SUCCESS;
}
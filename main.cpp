#include <Box2D\Box2D.h>
#include <SFML\Graphics.hpp>

int main()
{
	b2World* world = new b2World(b2Vec2(10.0f, -10.0f));
	sf::RectangleShape* shape = new sf::RectangleShape();

	delete world;
	delete shape;

	return 0;
}
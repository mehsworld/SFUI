#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Object.hpp"

#include <SFML\Graphics.hpp>

namespace SFUI
{

class IconButton : public Object
{
public:
	IconButton();
	~IconButton();

	sf::RectangleShape shape;

	void setPosition(const sf::Vector2f& pos);
	sf::Vector2f getPosition() { return shape.getPosition(); };

	void setIconTexture(const sf::Texture& texture);
	void setIconTexture(const sf::Texture& texture, const bool resetRect);
	void setButtonSize(const int newSize);
	void setButtonColor(const sf::Color& color);

	void disable();
	bool disabled;
	void enable();
	bool enabled;

	bool depressed = false;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	float multiplier = 1;
	sf::Font font;
	sf::Texture icon;
};

}

#endif /* BUTTON_HPP */
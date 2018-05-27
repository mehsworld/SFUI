#ifndef SFUI_HPP
#define SFUI_HPP

// Widgets
#include "Button.hpp"
#include "CheckBox.hpp"
#include "ComboBox.hpp"
#include "Image.hpp"
#include "Label.hpp"
#include "OptionsBox.hpp"
#include "ProgressBar.hpp"
#include "Slider.hpp"
#include "SpriteButton.hpp"
#include "InputBox.hpp"

// Layouts
#include "Layouts/FormLayout.hpp"
#include "Layouts/HorizontalBoxLayout.hpp"
#include "Layouts/VerticalBoxLayout.hpp"
#include "Layouts/Menu.hpp"

namespace SFUI
{
	class TEST_SFUI_LIB
	{
		void start()
		{
			// Create the main window
			sf::RenderWindow app(sf::VideoMode(400, 400), "SFUI TEST");

			SFUI::Theme::loadFont("resources/interface/tahoma.ttf");
			SFUI::Theme::loadTexture("resources/interface/texture_square.png");
			SFUI::Theme::fontSize = 11;
			SFUI::Theme::click.textColor = SFUI::Theme::hexToRgb("#191B18");
			SFUI::Theme::click.textColorHover = SFUI::Theme::hexToRgb("#191B18");
			SFUI::Theme::click.textColorFocus = SFUI::Theme::hexToRgb("#000000");
			SFUI::Theme::input.textColor = SFUI::Theme::hexToRgb("#000000");
			SFUI::Theme::input.textColorHover = SFUI::Theme::hexToRgb("#000000");
			SFUI::Theme::input.textColorFocus = SFUI::Theme::hexToRgb("#000000");
			SFUI::Theme::windowBgColor = SFUI::Theme::hexToRgb("#dddbde");
			SFUI::Theme::PADDING = 2.f;

			SFUI::Button button("test");
			button.setPosition(sf::Vector2f(10, 10));

			while (app.isOpen())
			{
				sf::Event event;
				while (app.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						app.close();
					else if (event.type == sf::Event::EventType::KeyPressed)
					{
						if (event.key.code == sf::Keyboard::Key::Num1)
							button.onStateChanged(SFUI::State::Default);
						else if (event.key.code == sf::Keyboard::Key::Num2)
							button.onStateChanged(SFUI::State::Hovered);
						else if (event.key.code == sf::Keyboard::Key::Num3)
							button.onStateChanged(SFUI::State::Pressed);
						else if (event.key.code == sf::Keyboard::Key::Num4)
							button.onStateChanged(SFUI::State::Focused);
					}
				}

				app.clear(SFUI::Theme::windowBgColor);

				app.draw(button);

				app.display();
			}
		}
	};
}

#endif // SFUI_HPP

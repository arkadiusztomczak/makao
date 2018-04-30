#include <SFML/Graphics.hpp>
#include "cards.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720),
		"Makao Beta", sf::Style::Close);

	sf::Font titleFont;
	sf::Font OSLight;
	titleFont.loadFromFile("Fonts/f01.ttf");
	OSLight.loadFromFile("Fonts/oslight.ttf");

	sf::Text title;
	title.setFont(titleFont);
	title.setPosition(400, 20);
	title.setCharacterSize(150);
	title.setString("Makao");

	sf::Text pressEnter;
	pressEnter.setFont(OSLight);
	pressEnter.setPosition(400, 200);
	pressEnter.setCharacterSize(20);
	pressEnter.setString("Press ENTER to begin!");

	sf::Texture background;
	background.loadFromFile("Img/bgTable.jpg");
	background.setSmooth(true);


	sf::Sprite bgSprite;
	bgSprite.setTexture(background);
	bgSprite.setScale(sf::Vector2f(2.0f, 2.f));

	int gameBegin = 0;
	int gameGenerated = 0;

	std::vector<sf::Texture> userTxt;
	std::vector<sf::Texture> botTxt;
	std::vector<sf::Texture> stockTxt;

	gamerSets cards;

	Card cardset;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(bgSprite);

		if (gameBegin == 0) {
			window.draw(title);
			window.draw(pressEnter);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) gameBegin = 1;
		}

		if (gameBegin == 1) {
			
			if (gameGenerated == 0) {
				for (cardStruct n : cards.returnUser()) {
					sf::Texture utxt;
					utxt.loadFromFile(n.img);
					userTxt.push_back(utxt);
				}
				for (cardStruct n : cards.returnBot()) {
					sf::Texture btxt;
					btxt.loadFromFile("Img/cardsPack/Red_back.jpg");
					botTxt.push_back(btxt);
				}
				for (cardStruct n : cards.returnStock()) {
					sf::Texture stxt;
					stxt.loadFromFile(n.img);
					stockTxt.push_back(stxt);
				}
				gameGenerated = 1;
			}
			int counter = 0;
			for (auto n : userTxt) {
				sf::Sprite nameSprite;
				nameSprite.setTexture(n);
				nameSprite.setPosition(250+(780 / userTxt.size()) * counter, 500);
				window.draw(nameSprite);
				counter++;
			}
			counter = 0;
			for (auto n : botTxt) {
				sf::Sprite nameSprite;
				nameSprite.setTexture(n);
				nameSprite.setPosition(250 + (780 / botTxt.size()) * counter, 100);
				window.draw(nameSprite);
				counter++;
			}

			for (auto n : stockTxt) {
				sf::Sprite nameSprite;
				nameSprite.setTexture(n);
				nameSprite.setPosition(565, 300);
				window.draw(nameSprite);
				counter++;
			}
			window.display();
			


		}
		if(gameGenerated == 0) window.display();
		

		
	}

	return 0;
}
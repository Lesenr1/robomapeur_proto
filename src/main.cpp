#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>



#define FIELD_W 800
#define FIELD_H 600

#define ROBOT_W 50
#define ROBOT_H 50

#define DIR_l 1
#define DIR_L 50




struct PosSize
{
    sf::Vector2f pos;
    sf::Vector2f size;
    sf::RectangleShape rect;
    sf::Color col;

    PosSize(sf::Vector2f, sf::Vector2f, sf::Color);
};

PosSize::PosSize(sf::Vector2f p, sf::Vector2f s, sf::Color c) : rect(s)
{
    pos = p; size = s;
    rect.setPosition(pos);
    rect.setFillColor(c);
}




int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(FIELD_W, FIELD_H), "SFML window");

    // Load a sprite to display
    // sf::Texture texture;
    // if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
    //     return EXIT_FAILURE;
    // }

	// sf::Texture texture2;
	// if (!texture2.loadFromFile(resourcePath() + "sprite.png")) {
	// 	return EXIT_FAILURE;
	// }
    // sf::Sprite sprite(texture);
	// sf::Sprite sprite2(texture2);
	
	// sprite2.setTextureRect(sf::IntRect(0,0,30,52));

    // Create a graphical text to display
    // sf::Font font;
    // if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
    //     return EXIT_FAILURE;
    // }
    // sf::Text text("Hello SFML", font, 50);
    // text.setColor(sf::Color::Black);

    sf::RectangleShape robot(sf::Vector2f(ROBOT_W, ROBOT_H));
    sf::RectangleShape dir(sf::Vector2f(DIR_l, DIR_L));
    robot.setPosition(FIELD_W/2 - ROBOT_W/2, FIELD_H/2 - ROBOT_H/2);
    dir.setPosition(FIELD_W/2 - DIR_l/2, FIELD_H/2 - DIR_L);

    std::vector<PosSize>obstacles;

    // add obstacles
    obstacles.push_back(PosSize(sf::Vector2f(300, 450), sf::Vector2f(120, 10), sf::Color::Red));
    obstacles.push_back(PosSize(sf::Vector2f(600, 180), sf::Vector2f(80, 80), sf::Color::Red));



    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed) {
            	switch(event.key.code)
            	{
	            	case sf::Keyboard::Escape :
	                	window.close();
	                	break;
	                default: break;
	            }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    std::cout << "Mouse button released : (" << event.mouseButton.x << "," << event.mouseButton.y << ")" << std::endl;
                    robot.setPosition(event.mouseButton.x - ROBOT_W/2, event.mouseButton.y - ROBOT_H/2);
                    dir.setPosition(event.mouseButton.x - DIR_l/2, event.mouseButton.y - DIR_L);
                    // window.close();
                }
            }
        }

        std::vector<PosSize>::iterator obstacles_it;

        // Clear screen
        window.clear();

        window.draw(robot);
        window.draw(dir);

        for(obstacles_it = obstacles.begin(); obstacles_it != obstacles.end(); obstacles_it++)
        {
            window.draw(obstacles_it->rect);
        }
        // Draw the sprite
        // window.draw(sprite);
		
		// window.draw(sprite2);

        // Draw the string
        //window.draw(text);

        // Update the window
        window.display();
    }


    return EXIT_SUCCESS;
}

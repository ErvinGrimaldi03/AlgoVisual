
#include "Render.h"

Render::Render(int width, int height, std::vector<int>& data)
	: width(width), height(height), data(data){}


void Render::drawArray(sf::RenderWindow& window, int highlightIndex1, int highlightIndex2) {
    window.clear();

    size_t n = data.size();
    float barWidth = static_cast<float>(width) / n;

    for (int i = 0; i < n; i++) {
        sf::RectangleShape bin(sf::Vector2f(barWidth - 2, data[i] * 5));
        bin.setPosition(sf::Vector2f(i * barWidth, height - data[i] * 5));

        if (i == highlightIndex1 || i == highlightIndex2) {
            bin.setFillColor(sf::Color::Red);
        }
        else {
            bin.setFillColor(sf::Color::White);
        }

        window.draw(bin);
    }

    window.display();
}


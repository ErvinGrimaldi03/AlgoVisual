#ifndef RENDER_H
#define RENDER_H
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Render {
public:
	Render(int width, int height, std::vector<int>& data);
	void drawArray(sf::RenderWindow& window, int highlightIndex1 = -1, int highlightIndex2 = -1);
private:
	int width, height;
	std::vector<int>& data;
};

#endif

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <vector>
#include <string>
class ResourceManager {
public:
	void loadFont(const std::string& name, const std::string& filename);
	Font& getFont(const std::string& name);
	void loadTexture(const std::string& name, const std::string& filename);
	Texture& getTexture(const std::string& name);
private:
	std::map<std::string, Font> fonts;
	std::map<std::string, Texture> textures;
};
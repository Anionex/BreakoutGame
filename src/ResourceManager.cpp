#include "ResourceManager.hpp"
#include <stdexcept>



void ResourceManager::loadFont(const std::string& name, const std::string& filename)
{
	Font font;
	if (!font.loadFromFile(filename))
	{
		throw std::runtime_error("ResourceManager::loadFont - 加载失败 " + filename);
	}
	fonts[name] = font;
}

Font& ResourceManager::getFont(const std::string& name)
{
	auto it = fonts.find(name);
	if (it == fonts.end()) {
		throw std::runtime_error("ResourceManager::getFont - 没有加载字体 " + name);
	}
	else {
		return it->second;
	}
}

void ResourceManager::loadTexture(const std::string& name, const std::string& filename) {
	Texture font;
	if (!font.loadFromFile(filename))
	{
		throw std::runtime_error("ResourceManager::loadTexture - 加载失败 " + filename);
	}
	textures[name] = font;
}

Texture& ResourceManager::getTexture(const std::string& name)
{
	auto it = textures.find(name);
	if (it == textures.end()) {
		throw std::runtime_error("ResourceManager::getFont - 没有加载纹理 " + name);
	}
	else {
		return it->second;
	}
}

#include "headers/VideoMode.hpp"

namespace video {
  static sf::VideoMode* VideoModeHandler::getVideoModes() {
    sf::VideoMode* res = malloc(this->VideoModeCount * sizeof(sf::VideoMode));
    for (int i = 0; i < this->VideoModeCount; i++)
      res[i] = sf::VideoMode::GetMode(i);
  }
}

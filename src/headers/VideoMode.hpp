#include <SFML/Window.hpp>

#ifndef VIDEO_LOADER
#define VIDEO_LOADER  1
#define BEST_MODE 0
// define video mode classes
namespace video {
  class VideoModeHandler
  {
public:
    static sf::VideoMode* getVideoModes();
    static sf::VideoMode getBestMode() {
      return sf::VideoMode::GetMode(BEST_MODE);
    }
private:
    unsigned int VideoModeCount = sf::VideoMode::GetModesCount();
  };
}
#endif

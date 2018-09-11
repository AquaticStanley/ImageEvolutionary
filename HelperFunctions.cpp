#include "HelperFunctions.h"

std::ostream& operator <<(std::ostream& os, sf::Vector2u& vect)
{
  os << "(" << vect.x << ", " << vect.y << ")" << std::endl;
  return os;
}
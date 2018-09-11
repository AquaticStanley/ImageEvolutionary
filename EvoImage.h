#pragma once

#include <SFML/Graphics.hpp>

struct EvoImage
{
  sf::Image image;
  int fitness;

  void evaluateFitness(const sf::Image& rhs);
};
#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <exception>
#include "Config.h"
#include <SFML/Graphics.hpp>
#include <utility>

class EvolutionarySearch
{
private:
  std::vector<sf::Image> mu;
  std::vector<sf::Image> lambda;
  int pixelClusterSize;
  sf::Image actualImage;

public:
  EvolutionarySearch(Config config);

  // Generate initial population
  void initialPopulation();

  // Generic functions to call from main
  std::function<std::vector<std::pair<int, int>>()> getParentIndices;

  std::function<void()> getSurvivalIndices;

  // Implementations that generic functions depend on
  // Parent selection
  std::vector<std::pair<int, int>> fitProportionalParentSelect() const;

  std::vector<std::pair<int, int>> kTournamentParentSelect(int tournamentSize) const;

  std::vector<std::pair<int, int>> uniformRandomParentSelect() const;

  // Survival selection
  void truncationSurvivalSelect() const;

  void kTournamentSurvivalSelect(int tournamentSize) const;

  void fitProportionalSurvivalSelect() const;

};

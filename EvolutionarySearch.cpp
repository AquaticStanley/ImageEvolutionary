#include "EvolutionarySearch.h"

EvolutionarySearch::EvolutionarySearch(Config config)
{
  if(!actualImage.loadFromFile(config.imagePath))
  {
    throw std::domain_error("Image could not be loaded - exiting.");
  }

  pixelClusterSize = config.pixelClusterSize;

  // Assign parent selection function
  switch(config.parentSelectionInd)
  {
    case 0:
      getParentIndices = [this] () {
        return this->fitProportionalParentSelect(); 
      };
      break;

    case 1:
    {
      int tournamentSize = config.parentTournamentSize;
      getParentIndices = [this, tournamentSize] () {
        return this->kTournamentParentSelect(tournamentSize);
      };
      break;
    }

    case 2:
      getParentIndices = [this] () {
        return this->uniformRandomParentSelect();
      };
      break;

    default:
      break;
  }

  // Assign survival selection function
  switch(config.survivalSelectionInd)
  {
    case 0:
      getSurvivalIndices = [this] () {
        return this->truncationSurvivalSelect();
      };
      break;

    case 1:
    {
      int tournamentSize = config.survivalTournamentSize;
      getSurvivalIndices = [this, tournamentSize] () {
        return this->kTournamentSurvivalSelect(tournamentSize);
      };
      break;
    }

    case 2:
      getSurvivalIndices = [this] () {
        return this->fitProportionalSurvivalSelect();
      };
      break;

    default:
      break;
  }
}

void EvolutionarySearch::initialPopulation()
{

}

std::vector<std::pair<int, int>> EvolutionarySearch::fitProportionalParentSelect() const
{ 
  std::vector<std::pair<int, int>> indexPairs;
  std::cout << "Using fitness proportional parent selection" << std::endl;
  return indexPairs;
}

std::vector<std::pair<int, int>> EvolutionarySearch::kTournamentParentSelect(int tournamentSize) const
{
  std::vector<std::pair<int, int>> indexPairs;
  std::cout << "Using k tournament parent selection\n";
  std::cout << "Tournament size: " << tournamentSize << std::endl; 
  return indexPairs;
}

std::vector<std::pair<int, int>> EvolutionarySearch::uniformRandomParentSelect() const 
{ 
  std::vector<std::pair<int, int>> indexPairs;
  std::cout << "Using uniform random parent selection" << std::endl; 
  return indexPairs;
}

void EvolutionarySearch::truncationSurvivalSelect() const
{
  std::cout << "Using truncation survival selection" << std::endl;
}

void EvolutionarySearch::kTournamentSurvivalSelect(int tournamentSize) const
{
  std::cout << "Using k tournament survival selection" << std::endl;
  std::cout << "Tournament size: " << tournamentSize << std::endl;
}

void EvolutionarySearch::fitProportionalSurvivalSelect() const
{
  std::cout << "Using fitness proportional survival selection" << std::endl;
}
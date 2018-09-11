#pragma once

#include <iostream>
#include <fstream>

struct Config
{
  Config(std::string filename);

  // Basic parameters
  std::string imagePath;
  int rngSeed;
  int runsPerExperiment;
  std::string logfile;
  std::string solfile;
  int algorithmInd;

  // Problem specific parameters
  int colorDistanceInd;
  int pixelClusterSize;

  // Evolutionary parameters
  int parentSelectionInd;
  int survivalSelectionInd;
  int terminationInd;
  int mu;
  int lambda;
  int parentTournamentSize;
  int survivalTournamentSize;
  int mutationRate;
  int numEvals;
};
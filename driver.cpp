// Dependencies
#include <iostream>
#include <SFML/Graphics.hpp>
#include "HelperFunctions.h"
#include "Config.h"
#include <ctime>
#include <cstdlib>
#include "EvolutionarySearch.h"

// Convenient outputting
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[])
{
  //Seed RNG
  srand(time(NULL));

  // Get filename to read config in from
  std::string filename = "";
  if(argc <= 1)
  {
    filename = "default.cfg";
  }
  else
  {
    filename = argv[1];
  }

  Config config(filename);

  // Apply a search strategy
  if(config.algorithmInd == 0)
  {
    // Random Search
  }
  else if(config.algorithmInd == 1)
  {
    // Evolutionary Search
    EvolutionarySearch evoSearch(config);

    // For all runs in experiment
    for(int r = 0; r < config.runsPerExperiment; r++)
    {
      // Initialize number of evals to initial population size
      int numEvals = config.mu;

      // Generate initial population and evaluate them

      // Run main evolutionary loop
      while(numEvals < config.numEvals)
      {
        

        numEvals += config.lambda;
      }






    }

    // evoSearch.getParentIndices();
    // evoSearch.getSurvivalIndices();
  }


  // sf::Vector2u size = image.getSize();
  // cout << size << endl;

	// sf::RenderWindow window(sf::VideoMode(200, 200), "Image window");
 //  sf::CircleShape shape(100.f);
 //  shape.setFillColor(sf::Color::Green);

 //  while (window.isOpen())
 //  {
 //      sf::Event event;
 //      while (window.pollEvent(event))
 //      {
 //          if (event.type == sf::Event::Closed)
 //              window.close();
 //      }

 //      window.clear();
 //      window.draw(shape);
 //      window.display();
 //  }

  return 0;
}
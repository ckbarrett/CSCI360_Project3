#include <PrioritizedSearch.h>

vector<Path> PrioritizedSearch::find_solution() {

  int num_of_agents = a_star.ins.num_of_agents;
    vector<Path> paths(num_of_agents);

    // assign priority ordering to agents
    // By default, we use the index ordering of the agents where
    // the first always has the highest priority.
    list<int> priorities;
    for (int i = 0; i < num_of_agents; i++) {
        priorities.push_back(i);
    }

    // plan paths
    for (int i : priorities) {
      // TODO: Transform already planned paths into constraints
      //  Replace the following line with something like paths[i] = a_star.find_path(i, constraints);

      paths[i] = a_star.find_path(i);

        if (paths[i].empty()) {
          paths.resize(i);
          return paths;
        }
    }
    return paths;
}



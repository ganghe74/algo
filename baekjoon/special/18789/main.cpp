#include <bits/stdc++.h>
#include "chromosome.cpp"

using namespace std;

class GeneticAlgorithm {
public:
    vector<Chromosome> population;
    int threshold;
    int max_generations;
    double mutation_chance;
    double crossover_chance;
    GeneticAlgorithm(vector<Chromosome> initial_population, int threshold, int max_generations, double mutation_chance, double crossover_chance)
        : population(initial_population), threshold(threshold), max_generations(max_generations), mutation_chance(mutation_chance),
        crossover_chance(crossover_chance) {}

    // Generate next_population
    // Using Roulette Wheel
    void reproduce_and_replace() {
        // sort(population.rbegin(), population.rend());
        vector<Chromosome> next_population;
        // Best Chromosome is always sended to next genration, without mutation.
        next_population.push_back(*max_element(population.begin(), population.end()));
        next_population.push_back(get_random_one());
        discrete_distribution<int> dist(population.begin(), population.end());
        while (next_population.size() < population.size()) {
            if (rand_double1(gen) < crossover_chance) {
                int i = dist(gen);
                int j = dist(gen);
                if (i == j) next_population.push_back(population[i]);
                else next_population.push_back(population[i].crossover(population[j]));
            }
            else {
                int i = dist(gen);
                next_population.push_back(population[i]);
            }
        }
        population = next_population;
    }

    // Mutate Population
    void mutate() {
        // First Chromosome is best and immutable
        for (unsigned int i=1;i<population.size();++i)
            if (rand_double1(gen) < mutation_chance)
                population[i].mutate();
    }

    Chromosome run() {
        Chromosome best = *max_element(population.begin(), population.end());
        for (int gen=0;gen<max_generations;++gen) {
            if (best.fitness() > threshold)
                return best;
            Chromosome &highest = *max_element(population.begin(), population.end());
            double mean = accumulate(population.begin(), population.end(), 0) / population.size();
            cout << "세대 " << gen << "/" << max_generations << " "
                << highest.fitness() << "(" << highest.score() << ", " << highest.surface() << ") 개체수: " << population.size()
                << " 평균: " << mean << endl;
            cout << population[0];
            if (highest.fitness() > best.fitness())
                best = highest;
            reproduce_and_replace();
            mutate();
        }
        return best;
    }

};

int main() {
    vector<array<array<int, 14>, 8>> datas = {
    // array<array<int,14>, 8> a = {{
        // {1, 8, 1, 3, 7, 8, 5, 7, 4, 5, 3, 5, 4, 2},
        // {3, 7, 5, 5, 1, 7, 1, 1, 9, 6, 1, 1, 3, 8},
        // {4, 9, 1, 0, 6, 6, 6, 2, 0, 4, 2, 3, 6, 8},
        // {8, 1, 4, 0, 5, 8, 7, 4, 2, 1, 7, 0, 8, 2},
        // {9, 2, 5, 8, 3, 1, 4, 5, 5, 6, 7, 9, 1, 1},
        // {3, 0, 7, 5, 3, 3, 4, 9, 9, 8, 7, 5, 9, 2},
        // {4, 1, 0, 9, 7, 6, 5, 8, 2, 7, 2, 6, 3, 4},
        // {1, 4, 9, 7, 7, 6, 8, 9, 8, 2, 3, 1, 6, 3}}};
    // {{ // 1298
        // {4, 8, 2, 1, 4, 8, 7, 3, 3, 2, 1, 6, 7, 4}, 
        // {9, 7, 0, 2, 3, 7, 1, 1, 9, 6, 1, 8, 4, 0}, 
        // {8, 9, 1, 3, 6, 6, 4, 8, 0, 8, 5, 3, 3, 8}, 
        // {2, 6, 4, 0, 5, 9, 7, 4, 1, 1, 7, 0, 8, 1}, 
        // {9, 2, 5, 0, 6, 4, 3, 2, 5, 9, 7, 9, 1, 7}, 
        // {3, 0, 7, 5, 1, 1, 4, 5, 8, 6, 0, 5, 7, 2}, 
        // {8, 1, 0, 4, 4, 6, 9, 5, 8, 5, 2, 2, 9, 2}, 
        // {9, 2, 1, 0, 0, 3, 9, 9, 6, 6, 6, 1, 6, 4}}},
    // array<array<int, 14>, 8> a = {{ // 337
        // {1, 0, 2, 0, 3, 3, 4, 4, 5, 3, 6, 4, 7, 3}, 
        // {0, 1, 0, 2, 0, 1, 2, 2, 0, 1, 0, 2, 0, 1}, 
        // {4, 3, 3, 4, 5, 1, 6, 1, 0, 0, 8, 3, 9, 0}, 
        // {0, 0, 0, 0, 9, 8, 7, 2, 3, 6, 1, 4, 0, 0}, 
        // {0, 2, 0, 0, 2, 4, 2, 3, 4, 7, 0, 0, 2, 1}, 
        // {5, 5, 6, 6, 0, 1, 4, 5, 1, 0, 0, 2, 8, 9}, 
        // {7, 8, 9, 0, 5, 5, 6, 6, 7, 0, 0, 1, 8, 9}, 
        // {0, 2, 7, 7, 9, 7, 8, 9, 1, 0, 0, 0, 7, 7}}};
    // array<array<int, 14>, 8> a = {{
        // {1, 8, 7, 3, 2, 4, 3, 8, 4, 5, 5, 8, 4, 8},
        // {3, 7, 5, 5, 1, 4, 9, 1, 4, 2, 0, 1, 3, 2},
        // {7, 9, 1, 0, 6, 6, 6, 2, 0, 7, 2, 3, 6, 2},
        // {4, 1, 4, 3, 2, 8, 7, 0, 2, 1, 7, 0, 9, 5},
        // {9, 2, 5, 8, 3, 1, 4, 5, 4, 6, 8, 9, 1, 1},
        // {8, 0, 7, 8, 9, 4, 6, 9, 1, 8, 2, 5, 6, 2},
        // {3, 1, 0, 9, 1, 6, 0, 8, 1, 5, 2, 9, 3, 7},
        // {1, 4, 2, 3, 7, 1, 4, 3, 3, 2, 1, 4, 4, 1}}};
    // array<array<int, 14>, 8> a = {{
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1}}};
    // array<array<int, 14>, 8> a = {{ // 102
        // {7, 0, 8, 6, 8, 8, 8, 8, 7, 6, 2, 7, 0, 9},
        // {2, 5, 2, 6, 8, 5, 4, 9, 2, 8, 5, 2, 3, 5},
        // {2, 5, 2, 1, 6, 1, 3, 9, 3, 2, 2, 4, 7, 8},
        // {2, 2, 7, 6, 1, 2, 7, 3, 9, 7, 4, 9, 0, 4},
        // {1, 3, 1, 5, 7, 0, 0, 8, 4, 4, 3, 4, 7, 6},
        // {7, 3, 2, 4, 7, 8, 4, 2, 0, 8, 6, 6, 8, 8},
        // {6, 2, 6, 3, 8, 4, 6, 1, 5, 1, 8, 4, 9, 4},
        // {8, 6, 6, 6, 0, 4, 5, 7, 5, 9, 1, 2, 5, 5} }};
     {{ // 3003
        {2, 8, 7, 3, 2, 8, 0, 9, 1, 5, 5, 8, 2, 8},
        {3, 7, 5, 5, 1, 4, 9, 1, 4, 2, 6, 1, 3, 2},
        {7, 9, 1, 0, 6, 6, 6, 2, 0, 7, 2, 3, 6, 2},
        {4, 1, 4, 3, 2, 8, 7, 0, 2, 1, 7, 0, 9, 7},
        {9, 2, 5, 4, 3, 1, 4, 5, 4, 6, 8, 9, 1, 1},
        {8, 0, 7, 8, 1, 4, 6, 9, 1, 8, 2, 5, 6, 2},
        {3, 1, 0, 9, 3, 8, 2, 8, 4, 5, 2, 9, 3, 7},
        {1, 7, 2, 3, 8, 5, 5, 9, 3, 2, 1, 4, 4, 1}}},
     {{ // 3354
        {3, 6, 7, 3, 2, 8, 0, 3, 1, 5, 5, 8, 8, 0},
        {2, 7, 5, 5, 1, 4, 9, 1, 4, 6, 2, 1, 3, 0},
        {0, 9, 1, 0, 6, 6, 6, 2, 0, 7, 2, 3, 6, 2},
        {6, 1, 4, 3, 2, 8, 7, 0, 2, 1, 7, 0, 9, 7},
        {9, 2, 5, 4, 3, 1, 4, 5, 4, 6, 8, 9, 1, 1},
        {8, 0, 7, 8, 1, 4, 6, 9, 1, 8, 2, 5, 6, 2},
        {3, 1, 0, 9, 9, 8, 2, 1, 3, 5, 7, 2, 3, 7},
        {4, 2, 2, 3, 6, 5, 0, 7, 4, 0, 0, 4, 4, 1}}},
     {{ // 3462
        {3, 3, 7, 3, 2, 8, 0, 3, 1, 5, 5, 8, 8, 0},
        {2, 7, 5, 5, 1, 4, 9, 1, 4, 6, 2, 1, 3, 0},
        {0, 9, 1, 0, 6, 6, 6, 2, 0, 7, 2, 3, 6, 2},
        {6, 1, 4, 3, 2, 8, 7, 0, 2, 1, 7, 0, 9, 7},
        {9, 2, 5, 4, 3, 1, 4, 5, 4, 6, 8, 9, 1, 1},
        {8, 0, 7, 8, 1, 4, 6, 9, 1, 8, 2, 5, 6, 2},
        {3, 1, 0, 9, 9, 8, 2, 1, 3, 5, 0, 2, 3, 7},
        {4, 2, 2, 3, 3, 5, 7, 7, 4, 0, 9, 4, 4, 3}}}
    };

    vector<Chromosome> initial_population;
    for (auto &data : datas) initial_population.push_back(data);
    while (initial_population.size() < 100) initial_population.push_back(get_random_one());

    int threshold = 10000;
    int max_generations = 30000;
    double mutation_chance = 0.7;
    double crossover_chance = 0.7;

    GeneticAlgorithm ga(initial_population, threshold, max_generations, mutation_chance, crossover_chance);
    Chromosome best = ga.run();
    cout << best;
}

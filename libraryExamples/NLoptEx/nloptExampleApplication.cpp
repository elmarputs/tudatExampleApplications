// NLopt example application using the Pagmo interface headers.

#include <iostream>

#include <nlopt.h>

#include <pagmo/algorithms/nlopt.hpp>
#include <pagmo/archipelago.hpp>
#include <pagmo/problems/schwefel.hpp>

int main()
{
    using namespace pagmo;

    algorithm algo{nlopt("cobyla")};

    problem prob{schwefel(5)};

    archipelago archi{5, algo, prob, 5};

    archi.evolve();

    std::cout << "Running evolution...\n";

    archi.wait_check();

    for (const auto &isl : archi)
    {
        std::cout << isl.get_population().champion_f()[0] << '\n';
    }

    std::cout << "Hello NLopt!\n";

    return 0;
}

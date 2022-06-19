#include <iostream>
#include <fstream>
#include <vector>

#include "Kruskal.hpp"
#include "Prim.hpp"
#include "MatrixGraph.hpp"
#include "ListGraph.hpp"
#include "RandomGraphGenerator.hpp"
#include "Timer.hpp"
#include "Djikstra.hpp"
#include "AverageTimeMeasure.hpp"
#include "RandomGraphGenerator.hpp"
#include "BellmanFord.hpp"

using namespace std;




long long getDataFromUser()
{
    long long val;
    //cout << "Podaj wartosc:\n";
    cin >> val;

    // Clear any garbage
    cin.clear();
    cin.ignore(10000, '\n');

    return val;
}

char getOptionFromUser()
{
    char input;
    std::cin >> input;

    // Clear any garbage
    cin.clear();
    cin.ignore(10000, '\n');

    return input;
}

void mstMenu()
{
    char input;
    ListGraph listGraph(false);
    MatrixGraph matrixGraph(false);

repeat:
    cout << "r - odczyt z pliku\n"
        << "x - losowy graf\n"
        << "k - Kruskal\n"
        << "p - Prima\n"
        << "l - wypisz graf\n"
        << "q - wyjscie\n";
    input = getOptionFromUser();

    switch (input) {
    case 'q':
        return;
        break;
    case 'r':
        listGraph.clear();
        matrixGraph.clear();
        //readFromFile(listGraph, matrixGraph);
        break;
    case 'x': {
        listGraph.clear();
        matrixGraph.clear();
        cout << "Count: \n";
        auto count = getDataFromUser();
        cout << "Fill %: \n";
        auto fill = getDataFromUser();
        RandomGraphGenerator::random(matrixGraph, listGraph, count, fill, false);
        break;
    }
    case 'k': {
        listGraph.print();
        ListGraph kruskal_list = Kruskal::generateMST(listGraph);
        kruskal_list.print();
        matrixGraph.print();
        MatrixGraph kruskal_matrix = Kruskal::generateMST(matrixGraph);
        kruskal_matrix.print();
        break;
    }
    case 'p': {
        listGraph.print();
        ListGraph prim_list = Prim::generateMST(listGraph);
        prim_list.print();
        matrixGraph.print();
        MatrixGraph matrix_prim = Prim::generateMST(matrixGraph);
        matrix_prim.print();
        break;
    }
    case 'l':
        matrixGraph.print();
        listGraph.print();
        std::cin.get();
        break;
    }

    goto repeat;
}

void shortestPathMenu()
{
    ListGraph listGraph(true);
    MatrixGraph matrixGraph(true);
    char input;

repeat:
    cout << "r - odczyt z pliku\n"
        << "x - losowy graf\n"
        << "d - Dijkstra\n"
        << "b - Bellman-Ford\n"
        << "l - wypisz graf\n"
        << "q - wyjscie\n";
    input = getOptionFromUser();

    switch (input) {
    case 'q':
        return;
        break;
    case 'r':
        listGraph.clear();
        matrixGraph.clear();
        readFromFile(listGraph, matrixGraph);
        break;
    case 'x': {
        listGraph.clear();
        matrixGraph.clear();
        cout << "Count: \n";
        auto count = getDataFromUser();
        cout << "Fill %: \n";
        auto fill = getDataFromUser();
        RandomGraphGenerator::random(matrixGraph, listGraph, count, fill,true);
        break;
    }
    case 'b': {
        cout << "From: \n";
        auto from = getDataFromUser();
        cout << "To: \n";
        auto to = getDataFromUser();

        Node bellman_list = BellmanFord::getShortestPathTo(listGraph, from,to);
        Node bellman_matrix = BellmanFord::getShortestPathTo(matrixGraph, from, to);

        resultL.print();
        resultM.print();

        break;
    }
    case 'd': {
        cout << "From: \n";
        auto from = getDataFromUser();
        cout << "To: \n";
        auto to = getDataFromUser();

        auto resultL = Dijkstra::getShortestPathFromTo(listGraph, from, to);
        auto resultM = Dijkstra::getShortestPathFromTo(matrixGraph, from, to);

        resultL.print();
        resultM.print();

        break;
    }
    case 'l':
        matrixGraph.print();
        listGraph.print();
        std::cin.get();
        break;
    }

    goto repeat;
}

int menu()
{
    char input;
    cout << "SDiZO Projekt 2.\n"
        << "b - test automatyczny\n"
        << "m - test manualny\n";
    input = getOptionFromUser();

    if (input == 'b') {
        TimeBenchmark bench;
        bench.run();
        return 0;
    }

    cout << "Wybierz problem:\n"
        << "m - MST\n"
        << "l - Shortest path\n";
    input = getOptionFromUser();

    switch (input) {
    case 'm':
        mstMenu();
        break;
    case 'l':
        shortestPathMenu();
        break;
    }

    return 0;
}
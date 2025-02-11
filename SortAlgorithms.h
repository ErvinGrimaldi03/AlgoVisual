#ifndef SORT_H
#define SORT_H
#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <SFML/System.hpp>
#include "Render.h"

class Sorter {
protected:
    std::vector<int> vec;
public:
    const std::string name;

    Sorter(std::string my_name) : name(my_name) {}
    void print(std::ostream& out);
    virtual void sort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) = 0;
};

class BubbleSort : public Sorter {
public:
    BubbleSort() : Sorter("BubbleSort") {}
    void bubblesort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed);
    void sort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) override;
private:
    void swap(std::vector<int>& v, int i, int j);
};

#endif

//+++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++MERGE+++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++

class MergeSort : public Sorter {
public:
    MergeSort() : Sorter("MergeSort") {}
    void mergesort(std::vector<int>& vec, int left, int right, Render& renderer, sf::RenderWindow& window, int& speed);
    void merge(std::vector<int>& vec, int left, int mid, int right, Render& renderer, sf::RenderWindow& window, int& speed);
    void sort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) override;
};



//+++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++HEAP+++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++

class HeapSort : public Sorter {
public:
    HeapSort() : Sorter("HeapSort") {}
    void sort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) override;
private:
    void heapify(std::vector<int>& vec, int n, int i, Render& renderer, sf::RenderWindow& window, int& speed);

};






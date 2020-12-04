#ifndef ULTIMATEMOVIESEARCH_SORT_H
#define ULTIMATEMOVIESEARCH_SORT_H

#include "Movie.h"
#include "Search.h"
#include <vector>
using namespace std;

void quickSort(vector<Movie>& arr, int left, int right)
{
    int i = left, j = right;
    Movie temp;
    string pivot = arr[(left + right) / 2].getTitle();

    //partition
    while (i <= j) {
        while (arr[i].getTitle() < pivot)
            i++;
        while (arr[j].getTitle() > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    //recursion
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

#endif //ULTIMATEMOVIESEARCH_SORT_H

#ifndef ULTIMATEMOVIESEARCH_SORT_H
#define ULTIMATEMOVIESEARCH_SORT_H

#include "Movie.h"
#include "Search.h"
#include <vector>
using namespace std;

void quickSortFunc(vector<Movie>& arr, int left, int right)
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
        quickSortFunc(arr, left, j);
    if (i < right)
        quickSortFunc(arr, i, right);
}

//------------Sort using MergeSort------


vector<Movie> merge(vector<Movie> leftArr,vector<Movie> rightArr){
    vector<Movie> sortedArr;
    while((int)leftArr.size()>0 && (int)rightArr.size()>0){
        if(leftArr.front().getTitle() <= rightArr.front().getTitle()){
            sortedArr.push_back(leftArr.front());
            leftArr.erase(leftArr.begin());
        }else{
            sortedArr.push_back(rightArr.front());
            rightArr.erase(rightArr.begin());
        }
    }

    while((int)leftArr.size()>0){
        sortedArr.push_back(leftArr.front());
        leftArr.erase(leftArr.begin());
    }
    while((int)rightArr.size()>0){
        sortedArr.push_back(rightArr.front());
        rightArr.erase(rightArr.begin());
    }
    return sortedArr;

}

//this bottom one is the one you call but it returns a completely new vector with the movies sorted didn't know how to modify it in place
vector<Movie> mergeSortFunc(vector<Movie> arr){
    if(arr.size()<2)
        return arr;
    vector<Movie> leftArr,rightArr, sortedArr;

    int mid=((int)arr.size()+1)/2;

    for(int i=0;i<mid;i++)
        leftArr.push_back(arr[i]);
    for(int j=mid;j<arr.size();j++)
        rightArr.push_back(arr[j]);

    leftArr=mergeSortFunc(leftArr);
    rightArr=mergeSortFunc(rightArr);
    sortedArr = merge(leftArr,rightArr);
    return sortedArr;


}

#endif //ULTIMATEMOVIESEARCH_SORT_H

#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

/** Заполняю массив длинны size случайными числами в промежутке [minVal, maxVal] **/
void fillArray(int *array, int size, const int minVal, const int maxVal){
    std::mt19937 generator(time(0));
    std::uniform_int_distribution<int> distribution(minVal, maxVal);
    for(int i = 0; i < size; ++i)
        array[i] = distribution(generator);
}

/** Печатает в консоль массив длинны size **/
void printArray(int* array, int size){
    size = (size < 50 ) ? size : 50;
    for(int i = 0; i < size; ++i)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}

/** Линейный поиск элемента в массиве **/
int Search(const int *array, const int size, const int value) {
    for(int i = 0; i < size; ++i)
        if(array[i] == value)
            return i;
    return -1;
}

/** Рекурсивная реализация бинарного поискав массиве **/
int recursionBSearch(int* array, int value, const int left, const int right) {
    if (right < left)
        return -1;
    int mid = (left + right) / 2;
    if (array[mid] == value)
        return mid;
    if (value < array[mid])
        return recursionBSearch(array, value, left, mid - 1);
    else
        return recursionBSearch(array, value, mid + 1, right);
}

/** Не рекурсивная реализация бинарного поискав массиве **/
int iterativeBSearch(const int* array, const int value, int left, int right){
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == value)
            return mid;
        if (value < array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int section(int* arr, int start, int end) {
    int axis = arr[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++)
        if (arr[j] < axis) {
            i++;
            swap(&arr[i], &arr[j]);
        }

    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}
/** Рекурсивная реализация сортировки quickSort в массиве **/
void recursionQuickSort(int* arr, int start, int end) {
    if (start < end) {
        int pi = section(arr, start, end);

        recursionQuickSort(arr, start, pi - 1);
        recursionQuickSort(arr, pi + 1, end);
    }

}

/** Не рекурсивная реализация сортировки quickSort в массиве **/
void iterativeQuickSort(int *array, int start, int end) {
    int stackElems[end - start + 1];
    int top = -1;
    stackElems[++top] = start;
    stackElems[++top] = end;

    while (top >= 0) {
        end = stackElems[top--];
        start = stackElems[top--];
        int p = section(array, start, end);

        if (p - 1 > start) {
            stackElems[++top] = start;
            stackElems[++top] = p - 1;
        }
        if (p + 1 < end) {
            stackElems[++top] = p + 1;
            stackElems[++top] = end;
        }
    }
}

int main() {
    //Алгоритм поиск Search() в неотсортированном массиве
    int result;
    const int searchSize = 1000;
    int searchArray[searchSize];
    fillArray(searchArray, searchSize, -1000, 1000);
    printArray(searchArray, searchSize);
    result = Search(searchArray, searchSize, 124);
    std::cout << ((result == -1) ? "Element not found" : "Item found at position "+result) << std::endl;

    //Алгоритм рекурсивной сортировки recursionQuickSort() массива
    int sortSize = 100;
    int sortedArray[sortSize];
    fillArray(sortedArray, sortSize, -10, 10);
    printArray(sortedArray, sortSize);
    recursionQuickSort(sortedArray, 0, sortSize);
    printArray(sortedArray, sortSize);

    //Алгоритм не рекурсивной сортировки iterativeQuickSort() массива
    fillArray(sortedArray, sortSize, -10, 10);
    printArray(sortedArray, sortSize);
    iterativeQuickSort(sortedArray, 0, sortSize);
    printArray(sortedArray, sortSize);

    //Алгоритм рекурсивного бинарного поиска recursionBSearch() массива
    result = recursionBSearch(sortedArray, 6, 0, sortSize);
    std::cout << ((result == -1) ? "Element not found" : "Item found at position "+result) << std::endl;

    //Алгоритм не рекурсивного бинарного поиска iterativeBSearch() массива
    result = iterativeBSearch(sortedArray, 6, 0, sortSize);
    std::cout << ((result == -1) ? "Element not found" : "Item found at position "+result) << std::endl;

    //Сравнение скороости выполнения поиска элемента
    int array[searchSize];
    fillArray(array, searchSize, -1000, 1000);
    printArray(array, searchSize);

    auto startTimeForUnsortedLinear = std::chrono::steady_clock::now();
    Search(array, searchSize, 22);
    auto endTimeForUnsortedLinear = std::chrono::steady_clock::now();

    auto startTimeForSortedBS = std::chrono::steady_clock::now();
    iterativeBSearch(array, 22, 0, searchSize);
    auto endTimeForSortedBS = std::chrono::steady_clock::now();

    auto startTimeForSortedRBS = std::chrono::steady_clock::now();
    recursionBSearch(array, 22, 0, searchSize);
    auto endTimeForSortedRBS = std::chrono::steady_clock::now();

    std::cout << "The linear unsorted search time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeForUnsortedLinear - startTimeForUnsortedLinear).count() << " ns"<<std::endl;
    std::cout << "The binary iterable sorted time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeForSortedBS - startTimeForSortedBS).count() << " ns"<<std::endl;
    std::cout << "The binary recursive sorted  time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTimeForSortedRBS - startTimeForSortedRBS).count() << " ns"<<std::endl;
    return 0;
}

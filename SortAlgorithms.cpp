#include "SortAlgorithms.h"
#include "Render.h"

void BubbleSort::bubblesort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) {
    size_t size = vec.size();
    bool swapped;

    for (int i = 0; i < size - 1; ++i) {
        swapped = false;

        for (int j = 0; j < size - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                swap(vec, j, j + 1);
                swapped = true;

                // Render updated state after swap
                renderer.drawArray(window, j, j + 1);

                // Introduce delay for visualization
                sf::sleep(sf::milliseconds(speed));
            }
        }

        // Stop if no swaps occurred (array already sorted)
        if (!swapped) break;
    }
}

void BubbleSort::swap(std::vector<int>& v, int i, int j) {
    std::swap(v[i], v[j]);
}

// Update sort function to include rendering
void BubbleSort::sort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) {
    bubblesort(vec, renderer, window, speed);
}


void MergeSort::sort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) {
    mergesort(vec, 0, vec.size() - 1, renderer, window, speed);
}


void MergeSort::mergesort(std::vector<int>& vec, int left, int right, Render& renderer, sf::RenderWindow& window, int& speed) {

    if (left >= right) { return; }
    int middle = left + (right - left) / 2;

    mergesort(vec, left, middle, renderer, window, speed);
    mergesort(vec, middle + 1, right, renderer, window, speed);

    merge(vec, left, middle, right, renderer, window, speed);
}

void MergeSort::merge(std::vector<int>& vec, int left, int mid, int right,
    Render& renderer, sf::RenderWindow& window, int& speed) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    std::vector<int> leftArr(leftSize), rightArr(rightSize);

    // Copy values to temporary arrays
    for (int i = 0; i < leftSize; i++) leftArr[i] = vec[left + i];
    for (int i = 0; i < rightSize; i++) rightArr[i] = vec[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merge sorted arrays
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            vec[k] = leftArr[i];
            i++;
        }
        else {
            vec[k] = rightArr[j];
            j++;
        }
        k++;

        // Render the current state for the whole merge segment.
        renderer.drawArray(window, left, right);
        sf::sleep(sf::milliseconds(speed));
    }

    // Copy remaining elements from leftArr
    while (i < leftSize) {
        vec[k] = leftArr[i];
        i++; k++;
        renderer.drawArray(window, left, right);
        sf::sleep(sf::milliseconds(speed));
    }

    // Copy remaining elements from rightArr
    while (j < rightSize) {
        vec[k] = rightArr[j];
        j++; k++;
        renderer.drawArray(window, left, right);
        sf::sleep(sf::milliseconds(speed));
    }
}




//+++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++HEAP+++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++


void HeapSort::heapify(std::vector<int>& vec, int n, int i, Render& renderer, sf::RenderWindow& window, int& speed) {
    int largest = i;            
    int left = 2 * i + 1;          
    int right = 2 * i + 2;         

    if (left < n && vec[left] > vec[largest])
        largest = left;

    if (right < n && vec[right] > vec[largest])
        largest = right;

    if (largest != i) {
        std::swap(vec[i], vec[largest]);

        renderer.drawArray(window, i, largest);
        sf::sleep(sf::milliseconds(speed));

        heapify(vec, n, largest, renderer, window, speed);
    }
}

// HeapSort sort function
void HeapSort::sort(std::vector<int>& vec, Render& renderer, sf::RenderWindow& window, int& speed) {
    int n = vec.size();

    // Build a max heap. The last non-leaf node is at index n/2 - 1.
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(vec, n, i, renderer, window, speed);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(vec[0], vec[i]);

        // Visualize the swap between the root and the element at index i.
        renderer.drawArray(window, 0, i);
        sf::sleep(sf::milliseconds(speed));

        // Call heapify on the reduced heap.
        heapify(vec, i, 0, renderer, window, speed);
    }
}

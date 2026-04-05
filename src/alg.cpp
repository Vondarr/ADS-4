// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}
int countPairs2(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;
        int found = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                found = mid;
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (found != -1) {
            k++;
            int temp = found - 1;
            while (temp > i && arr[temp] == target) {
                k++;
                temp--;
            }
            temp = found + 1;
            while (temp < len && arr[temp] == target) {
                k++;
                temp++;
            }
        }
    }
    return k;
}
int countPairs3(int* arr, int len, int value) {
    int k = 0;
    int i = 0;
    int j = len - 1;
    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == value) {
            k++;
            i++;
            j--;
        } else if (sum < value) {
            i++;
        } else {
            j--;
        }
    }
    return k;
}

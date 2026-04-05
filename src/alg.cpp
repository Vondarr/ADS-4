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
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        k++;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
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
      if (arr[i] == arr[j]) {
        int n = j - i + 1;
        k += n * (n - 1) / 2;
        break;
      } else {
        int countLeft = 1;
        while (i + 1 < j && arr[i] == arr[i + 1]) {
          countLeft++;
          i++;
        }
        int countRight = 1;
        while (j - 1 > i && arr[j] == arr[j - 1]) {
          countRight++;
          j--;
        }
        k += countLeft * countRight;
        i++;
        j--;
      }
    } else if (sum < value) {
      i++;
    } else {
      j--;
    }
  }
  return k;
}

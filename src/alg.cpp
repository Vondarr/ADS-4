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
    int first = -1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] >= target) {
        if (arr[mid] == target) first = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (first != -1) {
      left = first;
      right = len - 1;
      int last = first;
      while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target) {
          if (arr[mid] == target) last = mid;
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      k += (last - first + 1);
    }
  }
  return k / 2;
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
        int leftVal = arr[i];
        int rightVal = arr[j];
        int leftCount = 0;
        int rightCount = 0;
        while (i <= j && arr[i] == leftVal) {
          leftCount++;
          i++;
        }
        while (i <= j && arr[j] == rightVal) {
          rightCount++;
          j--;
        }
        k += leftCount * rightCount;
      }
    } else if (sum < value) {
      i++;
    } else {
      j--;
    }
  }
  return k;
}

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
    int idx = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        right = mid - 1;
        idx = mid;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (idx > 0) {
      int tmp = idx;
      while (tmp < len && arr[tmp] == target) {
        k++;
        tmp++;
      }
    }
  }
  return k;
}
int countPairs3(int* arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int k = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum > value) {
      right--;
    } else if (sum < value) {
      left++;
    } else if (arr[left] == arr[right]) {
      int n = right - left + 1;
      k += n * (n - 1) / 2;
      break;
    } else {
      int leftVal = arr[left];
      int rightVal = arr[right];
      int leftCnt = 0;
      int rightCnt = 0;
      while (left <= right && arr[left] == leftVal) {
        left++;
        leftCnt++;
      }
      while (left < right && arr[right] == rightVal) {
        right--;
        rightCnt++;
      }
      k += leftCnt * rightCnt;
    }
  }
  return k;
}

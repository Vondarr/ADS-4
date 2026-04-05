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
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k++;
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

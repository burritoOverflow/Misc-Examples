const assert = require('assert');

recursiveLinearSearch = (arr, n, val) => {
  if (n <= 0) {
    // value not found
    return false
  }
  if (arr[n] === val) {
    return true
  }
  return recursiveLinearSearch(arr, n - 1, val)
}


const arr = [12, 13, 67, 78, 891, 90, 41, 54];

arr.forEach((value) => {
  assert(recursiveLinearSearch(arr, arr.length, value));
});

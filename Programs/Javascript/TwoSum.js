// time complexity =  O(n); space complexity = O(n)
var twoSum = function (nums, target) {
  const map = new Map();

  for (let i = 0; i < nums.length; i++) {
    const number = nums[i];
    const complement = target - number;

    if (map.has(complement)) {
      return [i, map.get(complement)];
    }

    map.set(number, i);
  }
};

twoSum();

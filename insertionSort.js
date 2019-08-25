// both the min and max are inclusive
function getRandomIntInclusive(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min + 1)) + min; 
}

function populateArrayRandom(size) {
    var randomArr = [];
    for(var i = 0; i < size; i++) {
        randomArr.push(getRandomIntInclusive(0, 1000));
    }
    return randomArr;
}

arr = populateArrayRandom(500);
console.log(`Array before sorting ${arr}`);

for (var i = 1; i < arr.length; i++) {
    var key = arr[i];
    var j = i - 1;
    while(j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

console.log(`Array after sorting ${arr}`);

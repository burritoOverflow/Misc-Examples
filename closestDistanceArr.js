const values = [12, 41, 90, 93, 2, 4, 8, 21, 54];
values.sort();

let min = Infinity;

for(let i = 0; i < values.length - 1; i++) {
	min = Math.min(min, Math.abs(values[i+1] - values[i]));
}

console.log(min);
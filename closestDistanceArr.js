const values = [12, 41, 90, 93, 2, 4, 8, 21, 54];

let sortNumber = (a, b) => {
	return a - b;
}

values.sort(sortNumber);

let min = Infinity;

for(let i = 0; i < values.length - 1; i++) {
	let difference = Math.abs(values[i + 1] - values[i]);
	min = Math.min(min, difference);
}

console.log(min);

'''
	Given a list of intervals, find start times that are independent (not within another interval)
'''

def find_non_overlap_start(interval_list):
	count = 0
	prev_start_time = 0
	prev_end_time = 0
	# those times where the start doesn't overlap
	valid_start_times = []
	# sort list by interval start time (index 0)
	interval_list = sorted(interval_list, key=lambda k: k[0])
	for interval in interval_list:
		if interval[0] > prev_start_time and interval[0] < prev_end_time:
			# overlaps
			print('Overlap {}'.format(interval[0]))
		else:
			count += 1
			valid_start_times.append(interval[0])
		prev_start_time = interval[0]
		prev_end_time = interval[1]
	return (count, valid_start_times)

interval_list = [(1, 3), (2, 4), (9, 12), (5, 7), (3, 7)]

print(find_non_overlap_start(interval_list))

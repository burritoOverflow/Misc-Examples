# Returns a list of those intervals where
# there is no overlap
def overlapping_intervals(interval_list):
    '''
        type: list of tuples representing intervals,
        where the tuple[0] represents start time
        and tuple[1] represents end time.
    '''
    # sort the interval list by start time
    interval_list = sorted(interval_list, key=lambda k: k[0])
    non_overlap_intervals = []
    previous_start_time = interval_list[0][0]
    previous_end_time = interval_list[0][1]
    for interval in interval_list[1:]:
        if interval[0] > previous_start_time and interval[0] < previous_end_time:
            # overlap
            print('Overlap: ({}, {}) with ({},{})'.format(previous_start_time,
                    previous_end_time, interval[0], interval[1]))
        else:
            print('Non Overlap ({}, {})'.format(interval[0], interval[1]))
            non_overlap_intervals.append((interval[0], interval[1]))
        previous_start_time = interval[0]
        previous_end_time = interval[1]
    return non_overlap_intervals


interval_list = [(1, 3), (2, 4), (9, 12), (5, 7)]
print(overlapping_intervals(interval_list))

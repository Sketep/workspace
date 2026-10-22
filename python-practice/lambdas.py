from collections import Counter

intervals = [[5, 7], [1, 3], [2, 4], [1, 2]]

intervals.sort()
print(intervals)
intervals.sort(key=lambda ls: (ls[0], ls[-1]))
print(intervals)


def sortByFrequency(string):
    counter = Counter(string)
    return "".join(sorted(string, reverse=True, key=lambda char: (counter[char], char)))


print(sortByFrequency("tree"))
print(sortByFrequency("abab"))

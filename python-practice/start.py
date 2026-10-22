s = "assessment"

# The string reversed
print(s[::-1])

# First 3 characters
print(s[0:3])

# Every other character, starting at index o
print(s[0::2])

nums = [4, 7, 1]
i = 0
while i < len(nums):
    print(i)
    print(nums[i])
    i += 1

b = "banana"
frequency_map = {}
for i in range(len(b)):
    if b[i] in frequency_map:
        frequency_map[b[i]] += 1
    else:
        frequency_map[b[i]] = 1

print(frequency_map)

for k, v in frequency_map.items():
    print("Char ", k, "appears", v, "times")

nums2 = [1, 2, 3, 4, 5, 6]

squares = [x * x for x in nums2 if x % 2 == 0]

print(squares)

words = ["kiwi", "fig", "banana"]

words.sort(key=len)
print(words)

grid = [[0] * 3] * 3
grid[0][0] = 1
print(grid)


def reverseAndClean(string):
    wordsList = []
    currentWord = ""
    i = 0
    while i < len(string):
        if string[i] == " ":
            i += 1
            continue
        j = 0
        currentWord = ""
        while j + i < len(string) and string[j + i] != " ":
            currentWord += string[i + j]
            j += 1
        wordsList += [currentWord]
        i += j
    return " ".join(wordsList[::-1])


broken = "  the quick  brown fox"

print(reverseAndClean(broken))

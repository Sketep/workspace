from collections import Counter, defaultdict


def isValidAnagram(string1, string2):
    if len(string1) != len(string2):
        return False
    counter1 = Counter(string1)
    counter2 = Counter(string2)
    for k, v in counter1.items():
        if v != counter2[k]:
            return False
    return True


def isValidAnagramOneLiner(string1, string2):
    return Counter(string1) == Counter(string2)


print(isValidAnagram("moloko", "koolom"))
print(isValidAnagram("koolom", "motoko"))
print(isValidAnagram("moloko", "molokos"))
print(isValidAnagram("molokos", "moloko"))


def groupAnagrams(listOfStrings):
    anagrams = defaultdict(list)
    for string in listOfStrings:
        anagrams["".join(sorted(string))].append(string)
        # anagrams[Counter(string)].append(string)
    return list(anagrams.values())


print(groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))

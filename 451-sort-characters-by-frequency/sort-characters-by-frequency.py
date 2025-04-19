from collections import Counter

class Solution:
    def frequencySort(self, s: str) -> str:
        # Count the frequency of each character using Counter
        freq_map = Counter(s)

        # Sort the characters based on their frequency (highest first)
        sorted_chars = sorted(freq_map.items(), key=lambda x: x[1], reverse=True)

        # Construct the result string by repeating characters according to their frequency
        result = ''.join([char * freq for char, freq in sorted_chars])

        return result

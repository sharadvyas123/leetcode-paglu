class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)
        counts = Counter(s)

        prefix_matched = []

        for char in target:
            if counts[char] > 0:
                prefix_matched.append(char)
                counts[char] -= 1
            else:
                break
        
        matched_len = len(prefix_matched)

        for i in range(matched_len, -1, -1):
            if i < n:
                target_char = target[i]
                for c in sorted(counts.keys()):
                    if c > target_char and counts[c] > 0:
                        res = prefix_matched[:i] + [c]
                        counts[c] -= 1
                        
                        for rem_c in sorted(counts.keys()):
                            res.extend([rem_c] * counts[rem_c])
                            
                        return "".join(res)
            if i > 0:
                removed_char = prefix_matched.pop()
                counts[removed_char] += 1
        
        
        return ""